<?php

/**
 * Implementation of hook_drush_command().
 */
function vsdg_drush_command() {
  $items = array();

  $items['vrc-generate-users'] = array(
    'description' => 'Generate some dummy users.',
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL,
    'arguments' => array(
      'number' => 'Number of users to generate',
      'time_range' => 'How most far back in time should the users be dated',
    ),
  );

  $items['vrc-generate-articles'] = array(
    'description' => 'Generate some dummy articles.',
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL,
    'drupal dependencies' => array('devel_generate'),
    'arguments' => array(
      'number' => 'Number of search records to generate',
      'time_range' => 'How most far back in time should the records be dated',
    ),
  );

  $items['vrc-generate-questions'] = array(
    'description' => 'Generate some dummy questions.',
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL,
    'drupal dependencies' => array('devel_generate'),
    'drush dependencies' => array('devel_generate'),
    'arguments' => array(
      'number' => 'Number of search records to generate',
      'time_range' => 'How far back in time should the records be dated',
    ),
  );

  $items['vrc-generate-answers'] = array(
    'description' => 'Generate some dummy answers.',
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL,
    'drupal dependencies' => array('devel_generate'),
    'arguments' => array(
      'number' => 'Number of answers to generate',
      'time_range' => 'How most far back in time should the answers be dated',
    ),
  );

  $items['vrc-generate-resolved-questions'] = array(
    'description' => "Make some questions resolved in a range of time.",
    'arguments' => array(
      'number' => 'Number of resolved questions to generate',
      'time_range' => 'How most far back in time should the questions be dated',
    ),
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL,
  );

  $items['vrc-generate-votes'] = array(
    'description' => 'Generate some dummy votes.',
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL,
    'options' => array(
      'kill' => 'Delete all existing votes before generating new ones.',
    ),
  );

  $items['vrc-generate-daily-searches'] = array(
    'description' => 'Generate some fake search records.',
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL,
    'arguments' => array(
      'number' => 'Number of search records to generate',
      'time_range' => 'How far back in time should the record be dated',
    ),
    'options' => array(
      'kill' => 'Delete all history search records before generating new content records.',
    ),
    'examples' => array(
      'drush vrc-generate-searches 10 2592000' => 'Generate 10 search records that date back to the last 30 days.',
    ),
  );

  $items['vrc-generate-question-resolution-ratio'] = array(
    'description' => 'Generate some daily logging messages for the question resolution ratio.',
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL,
  );

  $items['vrc-generate-question-resolution-ratio-by-role'] = array(
    'description' => 'Generate some daily logging messages for the question resolution ratio by role.',
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL,
  );

  return $items;
}

/**
 * Implements drush_COMMANDFILE_COMMAND()
 *
 * @param $number
 *   The number of resolved questions, default to 100
 * @param $time_range
 *   How far back in time was the resolved quesiton created, time in second.
 *     1 day              - 86,400
 *     1 month (30 days)  - 2,592,000
 *     2 month (60 days)  - 5,184,000
 *     1 year (365 days)  - 31,536,000
 *   Default to 2 months (60 days)
 */
function drush_vsdg_vrc_generate_resolved_questions($number = 100, $time_range = 5184000) {
  if (drush_generate_is_number($number) == FALSE || $number <= 0) {
    return drush_set_error('DEVEL_GENERATE_INVALID_INPUT', dt('Invalid number of questions.'));
  }

  drush_print(str_repeat('-', 80));
  drush_print(dt('Generating !number resolved questions...', array('!number' => $number)));

  for($i=0; $i<$number; $i++) {
    // Create a question
    $random_user = vsdg_get_random_user();

    // See devel_generate_content_form() for the available keys
    $form_state = array();
    $form_state['values'] = array(
      'node_types' => array('question' => 'quesiton'),
      'num_nodes' => 1,
      'title_length' => '20',
      'max_comments' => 0,
       // Note: The author of the quesiton is not controllable,
      'time_range' => $time_range,
      'vsdg_generate_resolved_question' => TRUE,
      'vsdg_generate',
    );

    module_load_include('inc', 'devel_generate');
    devel_generate_content($form_state);
  }
}

/**
 * Generate some test users for testing the chart
 */
function drush_vsdg_vrc_generate_users($number = 100, $time_range = 5184000) {
  // Status message
  drush_print(str_repeat('-', 80));
  drush_print(dt('Generating !number users...', array('!number' => $number)));

  for ($i = 1; $i <= $number; $i++) {
    $roles = user_roles(TRUE);
    unset($roles[DRUPAL_AUTHENTICATED_RID]);
    $role_ids = !empty($roles) ? array_keys($roles) : array();

    // For now, just assign one role
    if (!empty($roles)) {
      $role_ids = array_keys($roles);
      $role_ids = array($role_ids[array_rand($role_ids)]);
    }
    else {
      $role_ids = array();
    }

    module_load_include('inc', 'devel_generate');
    devel_create_users(1, FALSE, $time_range, $role_ids);
  }
}

/**
 * Generate some dummy articles for aiding the highchart development
 */
function drush_vsdg_vrc_generate_articles($number = 200, $time_range = 5184000) {
  drush_print(str_repeat('-', 80));
  drush_print(dt('Generating !number articles...', array('!number' => $number)));

  $form_state = array();
  $form_state['values'] = array(
    'node_types' => array('article' => 'article'),
    'num_nodes' => $number,
    'title_length' => '20',
    // Note: The author of the quesiton is not controllable,
    'time_range' => $time_range,
    'vsdg_generate_article' => TRUE,
  );

  module_load_include('inc', 'devel_generate');
  devel_generate_content($form_state);

  // Updating the logging messages
  drush_print(dt('Updating \'site_vote_count_daily\' messages...'));

  $ts_now = REQUEST_TIME;
  $ts_start_today = strtotime('today', $ts_now);
  $ts_start_ago = strtotime('today', $ts_now - $time_range);
  for ($t = $ts_start_ago; $t <= $ts_now - 86400; $t += 86400 ) {
    $date_str = format_date($t, 'custom', VSDG_DATE_FORMAT_DEFAULT);
    _vrc_statistics_dashboard_process_new_articles_daily($date_str);
  }
}

/**
 * Generate some dummy questions for for aiding the highchart development
 */
function drush_vsdg_vrc_generate_questions($number = 100, $time_range = 5184000) {
  drush_print(str_repeat('-', 80));
  drush_print(dt('Generating !number questions...', array('!number' => $number)));

  $form_state = array();
  $form_state['values'] = array(
    'node_types' => array('question' => 'question'),
    'num_nodes' => $number,
    'title_length' => '20',
    // Note: The author of the quesiton is not controllable,
    'time_range' => $time_range,
    'vsdg_generate_questions' => TRUE,
  );

  module_load_include('inc', 'devel_generate');
  devel_generate_content($form_state);

  // Updating the logging messages
  drush_print(dt('Updating \'new_questions_daily\' messages...'));

  $ts_now = REQUEST_TIME;
  $ts_start_today = strtotime('today', $ts_now);
  $ts_start_ago = strtotime('today', $ts_now - $time_range);
  for ($t = $ts_start_ago; $t <= $ts_now - 86400; $t += 86400 ) {
    $date_str = format_date($t, 'custom', VSDG_DATE_FORMAT_DEFAULT);
    _vrc_statistics_dashboard_process_new_questions_daily($date_str);
  }
}

/**
 * Generate some answers aiding the testing the chart
 */
function drush_vsdg_vrc_generate_answers($number = 100, $time_range = 5184000) {
  // This looks stupid
  module_load_include('inc', 'devel_generate');
  module_load_include('inc', 'devel_generate', 'devel_generate.fields');
  module_load_include('inc', 'devel_generate', 'text.devel_generate');

  // Print some status message
  drush_print(str_repeat('-', 80));
  drush_print(dt('Generating !number answers...', array('!number' => $number)));

  // Decide the language code we are gonna use for the answer and its fields
  $default_lang_code = language_default('language');
  $lang_code =  $default_lang_code == 'en' ? LANGUAGE_NONE : $default_lang_code;

  // Create the dummy answers
  for ($i = 1; $i <= $number; $i++) {
    // Get a random question
    $question = vsdg_get_random_node('question');

    $node = new stdClass();
    $node->nid = NULL;
    node_object_prepare($node);
    $node->type = 'answer';
    $node->language = $lang_code;
    $node->uid = vsdg_get_random_user()->uid;
    $node->title = '';
    // Make sure the creation time of the answer is later than the question's
    // posting time
    $node->created = mt_rand($question->created, REQUEST_TIME) ? mt_rand($question->created, REQUEST_TIME) : REQUEST_TIME;
    // Question field
    $node->field_answer_question[$lang_code][] = array('nid' => $question->nid);
    // Answer body field
    $field = field_info_field('field_answer_body');
    $field_instance = field_info_instance('node', 'field_answer_body', 'answer');
    $node->field_answer_body[$lang_code][] = text_devel_generate($node, $field, $field_instance, NULL);
    $node->vsdg_generate_answer = TRUE;
    $node->vsdg_generate = TRUE;
    node_save($node);
  }

  drush_print('Done.');

  // Updating the logging messages
  drush_print(dt('Updating \'new_answers_daily\' messages...'));

  $ts_now = REQUEST_TIME;
  $ts_start_today = strtotime('today', $ts_now);
  $ts_start_ago = strtotime('today', $ts_now - $time_range);
  for ($t = $ts_start_ago; $t <= $ts_now - 86400; $t += 86400 ) {
    $date_str = format_date($t, 'custom', VSDG_DATE_FORMAT_DEFAULT);
    _vrc_statistics_dashboard_process_new_answers_daily($date_str);
  }
}

/**
 * Generate some dummy votes for aiding the highchart development
 */
function drush_vsdg_vrc_generate_votes($time_range = 5184000) {
  if (drush_get_option('kill')) {
    drush_invoke_process('@self', 'votingapi-flush', array('node'));
  }

  drush_print(str_repeat('-', 80));
  $nodes_types = array('question', 'answer', 'documentation', 'article');

  // Each iteration will generate 100 votes
  for ($i = 1; $i <= 10; $i++) {
    drush_invoke_process('@self', 'generate-votes', array('node', 'percent'),
      array('kill' => 'FALSE', 'age' => $time_range, 'node_types' => $nodes_types));
  }

  $ts_now = REQUEST_TIME;
  $ts_start_today = strtotime('today', $ts_now);
  $ts_start_ago = strtotime('today', $ts_now - $time_range);

  for ($t = $ts_start_ago; $t <= $ts_now - 86400; $t += 86400 ) {
    $date_str = format_date($t, 'custom', VSDG_DATE_FORMAT_DEFAULT);
    _vrc_statistics_dashboard_process_site_vote_count_daily($date_str);
  }
}

/**
 * Generate some fake search records for aiding the highchart development
 * @see: vrc_statistics_dashboard_search_api_query_alter()
 *
 * @TODO: This need be fixed.
 */
function drush_vsdg_vrc_generate_daily_searches($number = 100, $time_range = 5184000) {
  drush_print(str_repeat('-', 80));
  $message_type = 'site_search_count_daily';

  // Elimilate all history records
  if (drush_get_option('kill')) {
    $types = array('site_search_count_daily', 'site_search');
    foreach ($types as $type) {
      $old_messages = message_load_multiple(FALSE, array('type' => $type));
      if (!empty($old_messages)) {
        drush_print(dt('Removing !count history search records of type [!type]...', array('!count' => count($old_messages), '!type' => $type)));
        message_delete_multiple(array_keys($old_messages));
        drush_print(dt('Done.'), 2);
      }
    }
  }

  // Print some status message
  drush_print(dt('Generating !number daily search records...', array('!number' => $number)));

  for ($i = 1; $i <= $number; $i++) {
    // At a random time
    $created_time = REQUEST_TIME - mt_rand(0, $time_range);
    $ts_start = strtotime('today', $created_time);

    $message = message_create('site_search', array('timestamp' => $created_time));
    $wrapper = entity_metadata_wrapper('message', $message);
    $wrapper->field_search_time->set($created_time);
    $wrapper->save();

    drush_print(dt('Created a search record at date time [!time]',
      array('!time' => format_date($created_time, 'custom', VSDG_DATE_FORMAT_DEFAULT))), 2);
  }

  drush_print(dt('Done.'), 2);

  $ts_now = REQUEST_TIME;
  $ts_start_today = strtotime('today', $ts_now);
  $ts_start_ago = strtotime('today', $ts_now - $time_range);
  for ($t = $ts_start_ago; $t <= $ts_now - 86400; $t += 86400 ) {
    $date_str = format_date($t, 'custom', VSDG_DATE_FORMAT_DEFAULT);
    _vrc_statistics_dashboard_process_daily_site_search($date_str);
  }
}

/**
 * This function will generate some messages of type
 * 'question_resolution_ratio_daily' for chart demo/testing
 */
function drush_vsdg_vrc_generate_question_resolution_ratio($time_range = 5184000) {
  drush_print(str_repeat('-', 80));
  drush_print(dt('Generating \'question_resolution_ratio_daily messages\' of !time', array('!time' => format_interval($time_range))));
  $ts_now = REQUEST_TIME;
  $ts_start_today = strtotime('today', $ts_now);
  $ts_start_ago = strtotime('today', $ts_now - $time_range);

  for ($t = $ts_start_ago; $t <= $ts_now - 86400; $t += 86400 ) {
    $date_str = format_date($t, 'custom', VSDG_DATE_FORMAT_DEFAULT);
    _vrc_statistics_dashboard_process_daily_question_resoltion_ratio($date_str);
  }
}

/**
 * This function will generate some messages of type
 * 'question_resolution_ratio_daily_by_role' for chart demo/testing
 */
function drush_vsdg_vrc_generate_question_resolution_ratio_by_role($time_range = 5184000) {
  drush_print(str_repeat('-', 80));
  drush_print(dt('Generating \'question_resolution_ratio_daily_by_role\' messages of !time', array('!time' => format_interval($time_range))));
  $ts_now = REQUEST_TIME;
  $ts_start_today = strtotime('today', $ts_now);
  $ts_start_ago = strtotime('today', $ts_now - $time_range);

  for ($t = $ts_start_ago; $t <= $ts_now - 86400; $t += 86400 ) {
    $date_str = format_date($t, 'custom', VSDG_DATE_FORMAT_DEFAULT);
    _vrc_statistics_dashboard_process_question_resolution_by_role($date_str);
  }
}
