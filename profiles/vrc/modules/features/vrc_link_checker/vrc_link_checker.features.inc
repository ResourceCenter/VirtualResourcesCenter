<?php
/**
 * @file
 * vrc_link_checker.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function vrc_link_checker_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
