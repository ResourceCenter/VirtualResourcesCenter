<?php
/**
 * @file
 * vrc_statistics_dashboard.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function vrc_statistics_dashboard_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "boxes" && $api == "box") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function vrc_statistics_dashboard_views_api() {
  return array("api" => "3.0");
}

/**
 * Implements hook_homebox().
 */
function vrc_statistics_dashboard_homebox() {
  $homeboxes = array();

  $homeboxes['statistic_dashboard'] = array (
    'regions' => 1,
    'cache' => 0,
    'color' => 0,
    'colors' => 
    array (
      0 => '#E4F0F8',
      1 => '#E4F0F8',
      2 => '#E4F0F8',
      3 => '#E4F0F8',
      4 => '#E4F0F8',
      5 => '#E4F0F8',
    ),
    'blocks' => 
    array (
      'views_statistics_dashboard_user-block' => 
      array (
        'module' => 'views',
        'delta' => 'statistics_dashboard_user-block',
        'region' => 1,
        'movable' => 1,
        'status' => 1,
        'open' => 1,
        'closable' => 1,
        'title' => '',
        'weight' => -89,
      ),
      'vrc_statistics_dashboard_vsd_question_first_answer_time' => 
      array (
        'module' => 'vrc_statistics_dashboard',
        'delta' => 'vsd_question_first_answer_time',
        'region' => 1,
        'movable' => 1,
        'status' => 1,
        'open' => 1,
        'closable' => 1,
        'title' => '',
        'weight' => -92,
      ),
      'vrc_statistics_dashboard_vsd_question_closing_time' => 
      array (
        'module' => 'vrc_statistics_dashboard',
        'delta' => 'vsd_question_closing_time',
        'region' => 1,
        'movable' => 1,
        'status' => 1,
        'open' => 1,
        'closable' => 1,
        'title' => '',
        'weight' => -91,
      ),
      'vrc_statistics_dashboard_vsd_closing_answer_author_ratio' => 
      array (
        'module' => 'vrc_statistics_dashboard',
        'delta' => 'vsd_closing_answer_author_ratio',
        'region' => 1,
        'movable' => 1,
        'status' => 1,
        'open' => 1,
        'closable' => 1,
        'title' => '',
        'weight' => -90,
      ),
      'vrc_statistics_dashboard_vsd_search_performed_count' => 
      array (
        'module' => 'vrc_statistics_dashboard',
        'delta' => 'vsd_search_performed_count',
        'region' => 1,
        'movable' => 1,
        'status' => 1,
        'open' => 1,
        'closable' => 1,
        'title' => '',
        'weight' => -94,
      ),
      'vrc_statistics_dashboard_vsd_site_votes_count' => 
      array (
        'module' => 'vrc_statistics_dashboard',
        'delta' => 'vsd_site_votes_count',
        'region' => 1,
        'movable' => 1,
        'status' => 1,
        'open' => 1,
        'closable' => 1,
        'title' => '',
        'weight' => -95,
      ),
      'vrc_statistics_dashboard_vsd_answer_posted_number' => 
      array (
        'module' => 'vrc_statistics_dashboard',
        'delta' => 'vsd_answer_posted_number',
        'region' => 1,
        'movable' => 1,
        'status' => 1,
        'open' => 1,
        'closable' => 1,
        'title' => '',
        'weight' => -96,
      ),
      'vrc_statistics_dashboard_vsd_article_posted_number' => 
      array (
        'module' => 'vrc_statistics_dashboard',
        'delta' => 'vsd_article_posted_number',
        'region' => 1,
        'movable' => 1,
        'status' => 1,
        'open' => 1,
        'closable' => 1,
        'title' => '',
        'weight' => -98,
      ),
      'vrc_statistics_dashboard_vsd_question_posted_number' => 
      array (
        'module' => 'vrc_statistics_dashboard',
        'delta' => 'vsd_question_posted_number',
        'region' => 1,
        'movable' => 1,
        'status' => 1,
        'open' => 1,
        'closable' => 1,
        'title' => '',
        'weight' => -97,
      ),
      'vrc_statistics_dashboard_vsd_registered_users_dr' => 
      array (
        'module' => 'vrc_statistics_dashboard',
        'delta' => 'vsd_registered_users_dr',
        'region' => 1,
        'movable' => 1,
        'status' => 1,
        'open' => 1,
        'closable' => 1,
        'title' => '',
        'weight' => -99,
      ),
      'vrc_statistics_dashboard_vsd_question_resolution_ratio' => 
      array (
        'module' => 'vrc_statistics_dashboard',
        'delta' => 'vsd_question_resolution_ratio',
        'region' => 1,
        'movable' => 1,
        'status' => 1,
        'open' => 1,
        'closable' => 1,
        'title' => '',
        'weight' => -93,
      ),
    ),
    'widths' => 
    array (
      1 => 100,
    ),
    'title' => 'Statistics Dashboard',
    'path' => 'statistics_dashboard',
    'menu' => 1,
    'enabled' => 1,
    'auto_save' => 1,
    'full' => 0,
    'roles' => 
    array (
      0 => 'administrator',
      1 => 'support',
    ),
  );


  return $homeboxes;
}

/**
 * Implements hook_default_message_type().
 */
function vrc_statistics_dashboard_default_message_type() {
  $items = array();
  $items['articles_by_category_daily'] = entity_import('message_type', '{
    "name" : "articles_by_category_daily",
    "description" : "Articles by Category (daily)",
    "argument_keys" : [],
    "argument" : [],
    "category" : "message_type",
    "data" : { "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" } },
    "language" : "en",
    "arguments" : null,
    "message_text" : { "en" : [
        {
          "value" : "\\u003Cp\\u003Edefault text\\u003C\\/p\\u003E",
          "format" : "filtered_html",
          "safe_value" : "\\u003Cp\\u003Edefault text\\u003C\\/p\\u003E\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  $items['new_answers_daily'] = entity_import('message_type', '{
    "name" : "new_answers_daily",
    "description" : "New Answers Daily",
    "argument_keys" : [],
    "argument" : [],
    "category" : "message_type",
    "data" : { "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" } },
    "language" : "en",
    "arguments" : null,
    "message_text" : { "en" : [
        {
          "value" : "\\u003Cp\\u003Edefault text\\u003C\\/p\\u003E",
          "format" : "filtered_html",
          "safe_value" : "\\u003Cp\\u003Edefault text\\u003C\\/p\\u003E\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  $items['new_articles_daily'] = entity_import('message_type', '{
    "name" : "new_articles_daily",
    "description" : "New Articles Daily",
    "argument_keys" : [],
    "argument" : [],
    "category" : "message_type",
    "data" : { "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" } },
    "language" : "en",
    "arguments" : null,
    "message_text" : { "en" : [
        {
          "value" : "default text",
          "format" : "filtered_html",
          "safe_value" : "\\u003Cp\\u003Edefault text\\u003C\\/p\\u003E\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  $items['new_questions_daily'] = entity_import('message_type', '{
    "name" : "new_questions_daily",
    "description" : "New Questions Daily",
    "argument_keys" : [],
    "argument" : [],
    "category" : "message_type",
    "data" : { "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" } },
    "language" : "en",
    "arguments" : null,
    "message_text" : { "en" : [
        {
          "value" : "\\u003Cp\\u003Edefault text\\u003C\\/p\\u003E",
          "format" : "filtered_html",
          "safe_value" : "\\u003Cp\\u003Edefault text\\u003C\\/p\\u003E\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  $items['question_gets_first_answer'] = entity_import('message_type', '{
    "name" : "question_gets_first_answer",
    "description" : "Question Gets First Answer",
    "argument_keys" : [],
    "argument" : [],
    "category" : "message_type",
    "data" : { "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" } },
    "language" : "en",
    "arguments" : null,
    "message_text" : { "en" : [
        {
          "value" : "\\u003Cp\\u003Edefault text\\u003C\\/p\\u003E",
          "format" : "filtered_html",
          "safe_value" : "\\u003Cp\\u003Edefault text\\u003C\\/p\\u003E\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  $items['question_gets_resolved'] = entity_import('message_type', '{
    "name" : "question_gets_resolved",
    "description" : "Question Gets Resolved",
    "argument_keys" : [],
    "argument" : [],
    "category" : "message_type",
    "data" : { "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" } },
    "language" : "en",
    "arguments" : null,
    "message_text" : { "en" : [
        {
          "value" : "default text",
          "format" : "filtered_html",
          "safe_value" : "\\u003Cp\\u003Edefault text\\u003C\\/p\\u003E\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  $items['question_resolution_ratio_by_role_daily'] = entity_import('message_type', '{
    "name" : "question_resolution_ratio_by_role_daily",
    "description" : "Question resolution Ratio by Role (daily)",
    "argument_keys" : [],
    "argument" : [],
    "category" : "message_type",
    "data" : { "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" } },
    "language" : "en",
    "arguments" : null,
    "message_text" : { "en" : [
        {
          "value" : "default text",
          "format" : "plain_text",
          "safe_value" : "\\u003Cp\\u003Edefault text\\u003C\\/p\\u003E\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  $items['question_resolution_ratio_daily'] = entity_import('message_type', '{
    "name" : "question_resolution_ratio_daily",
    "description" : "Question Resolution Ration (daily)",
    "argument_keys" : [],
    "argument" : [],
    "category" : "message_type",
    "data" : { "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" } },
    "language" : "en",
    "arguments" : null,
    "message_text" : { "en" : [
        {
          "value" : "\\u003Cp\\u003Edefault text\\u003C\\/p\\u003E",
          "format" : "filtered_html",
          "safe_value" : "\\u003Cp\\u003Edefault text\\u003C\\/p\\u003E\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  $items['site_search'] = entity_import('message_type', '{
    "name" : "site_search",
    "description" : "Site Search",
    "argument_keys" : [],
    "argument" : [],
    "category" : "message_type",
    "data" : { "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" } },
    "language" : "en",
    "arguments" : null,
    "message_text" : { "en" : [
        {
          "value" : "\\u003Cp\\u003Edefault text\\u003C\\/p\\u003E",
          "format" : "filtered_html",
          "safe_value" : "\\u003Cp\\u003Edefault text\\u003C\\/p\\u003E\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  $items['site_search_count_daily'] = entity_import('message_type', '{
    "name" : "site_search_count_daily",
    "description" : "Site Search Count (daily)",
    "argument_keys" : [],
    "argument" : [],
    "category" : "message_type",
    "data" : { "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" } },
    "language" : "en",
    "arguments" : null,
    "message_text" : { "en" : [
        {
          "value" : "\\u003Cp\\u003Edefault text\\u003C\\/p\\u003E",
          "format" : "filtered_html",
          "safe_value" : "\\u003Cp\\u003Edefault text\\u003C\\/p\\u003E\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  $items['site_vote_count_daily'] = entity_import('message_type', '{
    "name" : "site_vote_count_daily",
    "description" : "Site Vote Count (daily)",
    "argument_keys" : [],
    "argument" : [],
    "category" : "message_type",
    "data" : { "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" } },
    "language" : "en",
    "arguments" : null,
    "message_text" : { "en" : [
        {
          "value" : "\\u003Cp\\u003Edefault text\\u003C\\/p\\u003E",
          "format" : "filtered_html",
          "safe_value" : "\\u003Cp\\u003Edefault text\\u003C\\/p\\u003E\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  $items['user_register'] = entity_import('message_type', '{
    "name" : "user_register",
    "description" : "User - Register",
    "argument_keys" : [],
    "argument" : [],
    "category" : "message_type",
    "data" : { "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" } },
    "language" : "en",
    "arguments" : null,
    "message_text" : { "en" : [
        {
          "value" : "\\u003Cp\\u003EUser register\\u003C\\/p\\u003E",
          "format" : "filtered_html",
          "safe_value" : "\\u003Cp\\u003EUser register\\u003C\\/p\\u003E\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  return $items;
}
