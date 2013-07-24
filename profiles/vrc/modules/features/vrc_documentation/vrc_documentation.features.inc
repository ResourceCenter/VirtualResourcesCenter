<?php
/**
 * @file
 * vrc_documentation.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function vrc_documentation_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function vrc_documentation_views_api() {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function vrc_documentation_node_info() {
  $items = array(
    'documentation' => array(
      'name' => t('Documentation'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Documentation Title'),
      'help' => '',
    ),
  );
  return $items;
}
