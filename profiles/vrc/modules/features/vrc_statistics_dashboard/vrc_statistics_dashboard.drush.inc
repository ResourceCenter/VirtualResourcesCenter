<?php

/**
 * @file
 *
 * Drush command for collecting/processing the VRC statistics
 *
 * This script use the following date format as paramters:
 * Y-m-d (example: 2012-12-22)
 *
 */


/**
 * Implements of hook_drush_command().
 */
function vrc_statistics_dashboard_drush_command() {
  $items = array();
  $items['process_daily_statistics'] = array(
    'description' => 'Process the daily statistics',
    'aliases' => array('vpds'),
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL,
    'arguments' => array(
      'timestamp' => 'The timestamp representing the time the cron is invoked, change this to process data of a eariler day',
    ),
  );
  return $items;
}

/**
 * Implements drush_hook_COMMAND
 *
 * This is a quite important phase
 */
function drush_vrc_statistics_dashboard_process_daily_statistics($timestamp = REQUEST_TIME) {
  $timestamp = min($timestamp, REQUEST_TIME);

//   These are the message types available in the system
//   These messages types are records instantly once a user performs some action,
//   and need no cron jobs for them:
//   - user_add_answer
//   - user_add_question
//   - user_add_question
//   - site_search
//   - question_gets_first_answer
//   - question_gets_resolved
//   - user_register
//   However, the following messages types need the cron job at the day's end to
//   create new entries. We create a new entry to decrease the processing time as
//   the log entries expand. Make sure there is a sub-job for them:
//   - new_questions_daily
//   - new_answers_daily
//   - new_articles_daily
//   - question_resolution_ratio_by_role_daily
//   - question_resolution_ratio_daily
//   - site_search_count_daily
//   - site_vote_count_daily

  $date_string = format_date($timestamp - 86400, 'custom', 'Y-m-d');
  drush_print(str_repeat('=', 80));
  drush_print(dt('Begin to process the statisitics of date: !date', array('!date' => $date_string)), 2);

  _vrc_statistics_dashboard_process_new_questions_daily($date_string);
  _vrc_statistics_dashboard_process_new_answers_daily($date_string);
  _vrc_statistics_dashboard_process_new_articles_daily($date_string);

  _vrc_statistics_dashboard_process_daily_question_resoltion_ratio($date_string);
  _vrc_statistics_dashboard_process_question_resolution_by_role($date_string);

  _vrc_statistics_dashboard_process_daily_site_search($date_string);
  _vrc_statistics_dashboard_process_site_vote_count_daily($date_string);
}

/**
 * Process yesterday's site search statistics
 *
 * @param int $ts The timestamp of the time the process begins
 */
function _vrc_statistics_dashboard_process_daily_site_search($date_string) {
  // Some status message
  drush_print(str_repeat('-', 80));
  drush_print(dt('Processing the daily \'site_search_count_daily\' message...'));

  // Select the timestamps of the day's start and end
  $ts_start = vrc_dashboard_statistics_get_day_start_timestamp($date_string);
  $ts_end   = vrc_dashboard_statistics_get_day_end_timestamp($date_string);

  // Select the seach count within that day
  $query = db_select('message', 'm');
  $query->addExpression('COUNT(m.mid)', 'count');
  $query->condition('m.timestamp', $ts_start, '>=');
  $query->condition('m.timestamp', $ts_end, '<=');
  $query->condition('m.type', 'site_search');
  $count = $query->execute()->fetchField();

  drush_print(dt('Found !count site search records between !ts_start and !ts_end.', array(
    '!count' => $count,
    '!ts_start' => format_date($ts_start, 'custom', 'Y-m-d H:i:s'),
    '!ts_end' => format_date($ts_end, 'custom', 'Y-m-d H:i:s'))), 2);

  $message_type = 'site_search_count_daily';
  $loaded_message = vrc_statistics_dashboard_load_message_by_record_date($message_type, $ts_start);

  if ($loaded_message) {
    $message = $loaded_message;
    drush_print(dt('A [!type] message for the same day found. The value of it will be updated.', array(
      '!type' => $message_type)), 2);
  }
  else {
    drush_print(dt('No [!type] message for the same day found. A new message will be created.', array(
      '!type' => $message_type)), 2);
    $message = message_create($message_type);
  }

  $wrapper = entity_metadata_wrapper('message', $message);
  $wrapper->field_search_count->set($count);
  $wrapper->field_message_record_date->set($ts_start);
  $wrapper->save();

  drush_print(dt('Done.'), 2);
}

/**
 * Task callback
 */
function _vrc_statistics_dashboard_process_daily_new_article_by_category($date_string) {
  // Select the timestamps of the day's start and end
  $ts_start = vrc_dashboard_statistics_get_day_start_timestamp($date_string);
  $ts_end   = vrc_dashboard_statistics_get_day_end_timestamp($date_string);

  // Make sure there are terms in the cateogory vocabulary
  $category_vocab = taxonomy_vocabulary_machine_name_load('taxonomy_categories');
  $terms = vrc_statistics_dashboard_get_terms_by_vid($category_vocab->vid);
  if (empty($terms)) {
    return;
  }
  $terms = taxonomy_term_load_multiple(array_keys($terms));

  // Traverse all category terms, find any articles posted within the day, and
  // create a log for it (stupid way, maybe a little slow)
  foreach ($terms as $tid => $term) {
    // Select out all the articles created within the day
    $query = db_select('node', 'n');
    $query->fields('n', array('nid'));
    $query->innerJoin('field_data_field_toolbox_categories', 'fc', 'fc.entity_id = n.nid');
    $query
      ->condition('n.type', 'article')
      ->condition('n.status', 1);

    $created_cond = db_and();
    $created_cond->condition('n.created', $ts_start, '>=');
    $created_cond->condition('n.created', $ts_end, '<=');
    $query->condition($created_cond);

    $query
      ->condition('fc.entity_type', 'node')
      ->condition('fc.bundle', 'article')
      ->condition('fc.deleted', 0)
      ->condition('fc.field_toolbox_categories_tid', $tid);
    $result = $query->execute()->fetchCol();

    // Prevent duplicate message created for a same category on the same day
    $loaded_message = vrc_dashboard_statistics_load_message_by_category_and_date($date_string, $tid);
    if ($loaded_message) {
      $message = $loaded_message;
      drush_print(dt('A [!type] message for the same day found. The value of it will be updated.', array(
        '!type' => $message_type)), 2);
    }
    else {
      drush_print(dt('No [!type] message for the same day found. A new message will be created.', array(
        '!type' => $message_type)), 2);
      $message = message_create('articles_by_category_daily');
    }

    // Create/update the message
    $wrapper = entity_metadata_wrapper('message', $message);
    $wrapper->field_article_category->set($term);
    $wrapper->field_message_record_date->set($ts_start);
    if (!empty($result)) {
      $nids = array_unique($result);
      $articles = node_load_multiple($nids);
      foreach ($articles as $article) {
        $wrapper->field_article_refs[] = $article;
      }
    }
    $wrapper->save();
  }

  drush_print(dt('Done.'));
}

/**
 * Process the ration of question resolution
 */
function _vrc_statistics_dashboard_process_daily_question_resoltion_ratio($date_string) {
  // Some status message
  drush_print(str_repeat('-', 80));
  drush_print(dt('Processing the daily \'question_resolution_ratio_daily\' message...'));

  // Get the starting timestamp of the day
  $ts_start = vrc_dashboard_statistics_get_day_start_timestamp($date_string);

  // @TODO: Add some validation
  $count_unresolved = vrc_statistics_dashboard_get_unresolved_questions_count($ts_start);
  $count_total = vrc_statistics_dashboard_get_questions_count($ts_start);
  $count_resolved = $count_total - $count_unresolved;

  // Prevent duplicate
  $loaded_message = _vrc_statistics_dashboard_load_message_question_resolution_ratio_daily($ts_start);
  $message_type = 'question_resolution_ratio_daily';

  if ($loaded_message) {
    $message = $loaded_message;
    drush_print(dt('A [!type] message for the same day found. The value of it will be updated.', array(
      '!type' => $message_type)), 2);
  }
  else {
    $message = message_create($message_type);
    drush_print(dt('No [!type] message for the same day found. A new message will be created.', array(
      '!type' => $message_type)), 2);
  }

  $wrapper = entity_metadata_wrapper('message', $message);
  $wrapper->field_resolved_question_count->set($count_resolved);
  $wrapper->field_unresolved_question_count->set($count_unresolved);
  $wrapper->field_message_record_date->set($ts_start);
  $wrapper->save();

  drush_print(dt('Created a message for !date, with resolved/unresolved set to !ratio', array(
    '!date' => format_date($ts_start, 'custom', VSDG_DATE_FORMAT_DEFAULT), '!ratio' => $count_resolved . '/' . $count_unresolved)), 2);
  drush_print(dt('Done.'), 2);
}

/**
 * Process the daily vote count
 */
function _vrc_statistics_dashboard_process_site_vote_count_daily($date_string) {
  // Some status message
  drush_print(str_repeat('-', 80));
  drush_print(dt('Processing the daily \'site_vote_count_daily\' message...'));

  // Select the timestamps of the day's start and end
  $ts_start = vrc_dashboard_statistics_get_day_start_timestamp($date_string);
  $ts_end   = vrc_dashboard_statistics_get_day_end_timestamp($date_string);

  $count = vrc_statistics_dashboard_get_vote_count_in_time_range($ts_start, $ts_end);

  $loaded_message = vrc_statistics_dashboard_load_message_site_vote_count_daily_by_date($ts_start);
  if ($loaded_message) {
    $message = $loaded_message;
  }
  else {
    $message = message_create('site_vote_count_daily');
  }

  $wrapper = entity_metadata_wrapper('message', $message);
  $wrapper->field_vote_count->set($count);
  $wrapper->field_message_record_date->set($ts_start);
  $wrapper->save();

  drush_print(dt('The message of date [!date] is saved with the vote count set to !count',
    array('!date' => format_date($ts_start, 'custom', VSDG_DATE_FORMAT_DEFAULT), '!count' => $count)));
  drush_print(dt('Done.'), 2);
}

/**
 * Process the resolution ratio by role
 */
function _vrc_statistics_dashboard_process_question_resolution_by_role($date_string) {
  // Some status message
  drush_print(str_repeat('-', 80));
  drush_print(dt('Processing the daily \'question_resolution_ratio_by_role_daily\' message...'));

  // Get the starting timestamp of the day
  $ts_start = vrc_dashboard_statistics_get_day_start_timestamp($date_string);
  $nids = vrc_statistics_dashboard_get_resolved_questions_nids();

  $cnt_by_normal_users = 0;
  $cnt_by_system_users = 0;

  // Calculate the ratio of the resolved questions by the normal users and sytem
  // users
  if (!empty($nids)) {
    $nodes = node_load_multiple($nids);

    foreach ($nodes as $node) {
      $wrapper = entity_metadata_wrapper('node', $node);
      $author = $wrapper->field_best_answer->author->value();
      if (vrs_statistic_dashboard_is_normal_user($author)) {
        ++$cnt_by_normal_users;
      }
      else {
        ++$cnt_by_system_users;
      }
    }
  }
  $message_type = 'question_resolution_ratio_by_role_daily';
  $loaded_message = vrc_statistics_dashboard_load_message_question_resolution_ratio_by_role_daily_by_date($ts_start);
  if ($loaded_message) {
    $message = $loaded_message;
    drush_print(dt('A [!type] message for the same day found. The value of it will be updated.', array(
      '!type' => $message_type)), 2);
  }
  else {
    $message = message_create($message_type);
    drush_print(dt('No [!type] message for the same day found. A new message will be created.', array(
      '!type' => $message_type)), 2);
  }

  $wrapper = entity_metadata_wrapper('message', $message);
  $wrapper->field_by_normal_users_count->set($cnt_by_normal_users);
  $wrapper->field_by_system_users_count->set($cnt_by_system_users);
  $wrapper->field_message_record_date->set($ts_start);
  $wrapper->save();

  drush_print(dt('Created a message for !date, with normal users/system users set to !ratio', array(
    '!date' => format_date($ts_start, 'custom', VSDG_DATE_FORMAT_DEFAULT), '!ratio' => $cnt_by_normal_users . '/' . $cnt_by_system_users)), 2);
  drush_print(dt('Done.'), 2);
}

/**
 * Process the 'new_articles_daily' message
 *
 * This function check the newly created nodes within the day and create an new
 * message, record all the newly created nodes in the message
 *
 * Note: The drush command `drush vrc-generate-articles 100 86400` can be used
 * to generate 100 new articles for the last 24 hours for testing
 */
function _vrc_statistics_dashboard_process_new_articles_daily($date_string) {
  // Some status message
  drush_print(str_repeat('-', 80));
  drush_print(dt('Processing the daily \'new_articles_daily\' message...'));

  // Select the timestamps of the day's start and end
  $ts_start = vrc_dashboard_statistics_get_day_start_timestamp($date_string);
  $ts_end   = vrc_dashboard_statistics_get_day_end_timestamp($date_string);

  drush_print(dt('Looking up articles posted between !ts_start and !ts_end...', array(
    '!ts_start' => format_date($ts_start, 'custom', 'Y-m-d h:i:s'),
    '!ts_end' => format_date($ts_end, 'custom', 'Y-m-d h:i:s'))), 2);

  $message_type = 'new_articles_daily';
  $content_type = 'article';

  $loaded_message = vrc_statistics_dashboard_load_message_by_record_date($message_type, $ts_start);
  if ($loaded_message) {
    $message = $loaded_message;
    drush_print(dt('A [!type] message for the same day found. The value of it will be updated.', array(
      '!type' => $message_type)), 2);
  }
  else {
    $message = message_create('new_articles_daily');
    drush_print(dt('No [!type] message for the same day found. A new message for the day will be created.', array(
      '!type' => $message_type)), 2);
  }

  $wrapper = entity_metadata_wrapper('message', $message);
  $wrapper->field_message_record_date->set($ts_start);

  // Get the articles newly created within the day
  $nodes = vrs_statistic_dashboard_get_nodes_in_time_range($content_type, $ts_start, $ts_end);

  // Clear the value first anyway
  $wrapper->field_message_article_refs->set(array());

  if (!empty($nodes)) {
    drush_print(dt('!count articles found.', array('!count' => count($nodes))), 2);
    foreach ($nodes as $node) {
      $wrapper->field_message_article_refs[] = $node;
    }
  }
  else {
    drush_print(dt('No new articles found.'), 2);
  }

  $wrapper->save();
  drush_print(dt('Done.'), 2);
}

/**
 * Process the 'new_questions_daily' message
 *
 * This function check the newly created nodes within the day and create an new
 * message, record all the newly created nodes in the message
 *
 * Note: `drush vrc-generate-questions 100 86400` can be used to generate 100
 * new question for the last 24 hours for testing
 */
function _vrc_statistics_dashboard_process_new_questions_daily($date_string) {
  // Some status message
  drush_print(str_repeat('-', 80));
  drush_print(dt('Processing the daily \'new_questions_daily\' message...'));

  // Get the timestamps of the day's start and end
  $ts_start = vrc_dashboard_statistics_get_day_start_timestamp($date_string);
  $ts_end   = vrc_dashboard_statistics_get_day_end_timestamp($date_string);

  drush_print(dt('Looking up question posted between !ts_start and !ts_end...', array(
    '!ts_start' => format_date($ts_start, 'custom', 'Y-m-d h:i:s'),
    '!ts_end' => format_date($ts_end, 'custom', 'Y-m-d h:i:s'))), 2);
  $message_type = 'new_questions_daily';
  $content_type = 'question';

  $loaded_message = vrc_statistics_dashboard_load_message_by_record_date($message_type, $ts_start);
  if ($loaded_message) {
    $message = $loaded_message;
    drush_print(dt('A [!type] message for the same day found. The value of it will be updated.', array(
      '!type' => $message_type)), 2);
  }
  else {
    $message = message_create($message_type);
    drush_print(dt('No [!type] message for the same day found. A new message for the day will be created.', array(
      '!type' => $message_type)), 2);
  }

  $wrapper = entity_metadata_wrapper('message', $message);
  $wrapper->field_message_record_date->set($ts_start);

  // Get the articles newly created within the day
  $nodes = vrs_statistic_dashboard_get_nodes_in_time_range($content_type, $ts_start, $ts_end);

  // Clear the value first, anyway
  $wrapper->field_message_question_refs->set(array());

  if (!empty($nodes)) {
    drush_print(dt('!count questions found.', array('!count' => count($nodes))), 2);
    foreach ($nodes as $node) {
      $wrapper->field_message_question_refs[] = $node;
    }
  }
  else {
    drush_print(dt('No new questions found.'), 2);
  }

  $wrapper->save();
  drush_print('Done.', 2);
}

/**
 * Process the 'new_answers_daily' message
 *
 * This function check the newly created nodes within the day and create an new
 * message, record all the newly created nodes in the message
 *
 * Note: The drush command `vrc-generate-answers` can be used to generate 100
 * dummy answers for the last 24 hours for testing this processor function.
 */
function _vrc_statistics_dashboard_process_new_answers_daily($date_string) {
  // Some status message
  drush_print(str_repeat('-', 80));
  drush_print(dt('Processing the daily \'new_answers_daily\' message...'));


  // Select the timestamps of the day's start and end
  $ts_start = vrc_dashboard_statistics_get_day_start_timestamp($date_string);
  $ts_end   = vrc_dashboard_statistics_get_day_end_timestamp($date_string);

  drush_print(dt('Looking up answers posted between !ts_start and !ts_end...', array(
    '!ts_start' => format_date($ts_start, 'custom', 'Y-m-d h:i:s'),
    '!ts_end' => format_date($ts_end, 'custom', 'Y-m-d h:i:s'))), 2);

  $message_type = 'new_answers_daily';
  $content_type = 'answer';

  $loaded_message = vrc_statistics_dashboard_load_message_by_record_date($message_type, $ts_start);
  if ($loaded_message) {
    $message = $loaded_message;
    drush_print(dt('A [!type] message for the same day found. The value of it will be updated.', array(
      '!type' => $message_type)), 2);
  }
  else {
    drush_print(dt('No [!type] message for the same day found. A new message for the day will be created.', array(
      '!type' => $message_type)), 2);
    $message = message_create($message_type);
  }

  $wrapper = entity_metadata_wrapper('message', $message);
  $wrapper->field_message_record_date->set($ts_start);

  // Get the articles newly created within the day
  $nodes = vrs_statistic_dashboard_get_nodes_in_time_range($content_type, $ts_start, $ts_end);

  // Clear the value first anyway
  $wrapper->field_message_answer_refs->set(array());

  if (!empty($nodes)) {
    drush_print(dt('!count answers found.', array('!count' => count($nodes))), 2);
    foreach ($nodes as $node) {
      $wrapper->field_message_answer_refs[] = $node;
    }
  }
  else {
    drush_print(dt('No new answers found.'), 2);
  }

  $wrapper->save();
  drush_print(dt('Done.'), 2);
}
