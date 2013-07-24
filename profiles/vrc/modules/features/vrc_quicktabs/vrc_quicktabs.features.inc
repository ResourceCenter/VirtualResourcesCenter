<?php
/**
 * @file
 * vrc_quicktabs.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function vrc_quicktabs_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "quicktabs" && $api == "quicktabs") {
    return array("version" => "1");
  }
}
