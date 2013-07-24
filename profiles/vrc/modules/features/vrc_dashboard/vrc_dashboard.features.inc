<?php
/**
 * @file
 * vrc_dashboard.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function vrc_dashboard_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function vrc_dashboard_views_api() {
  return array("api" => "3.0");
}

/**
 * Implements hook_homebox().
 */
function vrc_dashboard_homebox() {
  $homeboxes = array();

  $homeboxes['support_manager_dashboard'] = array (
    'regions' => 4,
    'cache' => 0,
    'color' => 1,
    'colors' => 
    array (
      0 => '#E4F0F8',
      1 => '#74B46F',
      2 => '#37DEDE',
      3 => '#F2F268',
      4 => '#EE68F2',
      5 => '#68C4F2',
    ),
    'blocks' => 
    array (
      'views_dashboard_content-block_1' => 
      array (
        'module' => 'views',
        'delta' => 'dashboard_content-block_1',
        'region' => 1,
        'movable' => 1,
        'status' => 1,
        'open' => 1,
        'closable' => 1,
        'title' => '',
        'weight' => 0,
      ),
      'views_dashboard_content-block_2' => 
      array (
        'module' => 'views',
        'delta' => 'dashboard_content-block_2',
        'region' => 2,
        'movable' => 1,
        'status' => 1,
        'open' => 1,
        'closable' => 1,
        'title' => '',
        'weight' => 0,
      ),
      'views_dashboard_content-block_5' => 
      array (
        'module' => 'views',
        'delta' => 'dashboard_content-block_5',
        'region' => 3,
        'movable' => 1,
        'status' => 1,
        'open' => 1,
        'closable' => 1,
        'title' => '',
        'weight' => 99,
      ),
      'views_dashboard_content-block_6' => 
      array (
        'module' => 'views',
        'delta' => 'dashboard_content-block_6',
        'region' => 3,
        'movable' => 1,
        'status' => 1,
        'open' => 1,
        'closable' => 1,
        'title' => '',
        'weight' => 99,
      ),
      'views_dashboard_user-block' => 
      array (
        'module' => 'views',
        'delta' => 'dashboard_user-block',
        'region' => 2,
        'movable' => 1,
        'status' => 1,
        'open' => 1,
        'closable' => 1,
        'title' => '',
        'weight' => 2,
      ),
    ),
    'widths' => 
    array (
      1 => 100,
      2 => 50,
      3 => 50,
      4 => 100,
    ),
    'title' => 'Support Manager Dashboard',
    'path' => 'support_manager_dashboard',
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
function vrc_dashboard_default_message_type() {
  $items = array();
  $items['user_add_answer'] = entity_import('message_type', '{
    "name" : "user_add_answer",
    "description" : "User - Add Answer",
    "argument_keys" : [],
    "argument" : [],
    "category" : "message_type",
    "data" : { "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" } },
    "language" : "en",
    "arguments" : null,
    "message_text" : { "en" : [
        {
          "value" : "\\u003Cp\\u003Euser add a answer\\u003C\\/p\\u003E",
          "format" : "filtered_html",
          "safe_value" : "\\u003Cp\\u003Euser add a answer\\u003C\\/p\\u003E\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  $items['user_add_question'] = entity_import('message_type', '{
    "name" : "user_add_question",
    "description" : "User -  Add Question",
    "argument_keys" : [],
    "argument" : [],
    "category" : "message_type",
    "data" : { "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" } },
    "language" : "en",
    "arguments" : null,
    "message_text" : { "en" : [
        {
          "value" : "\\u003Cp\\u003EUser add a question\\u003C\\/p\\u003E",
          "format" : "filtered_html",
          "safe_value" : "\\u003Cp\\u003EUser add a question\\u003C\\/p\\u003E\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  return $items;
}
