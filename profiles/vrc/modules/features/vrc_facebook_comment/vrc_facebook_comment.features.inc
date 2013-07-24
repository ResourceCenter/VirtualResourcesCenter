<?php
/**
 * @file
 * vrc_facebook_comment.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function vrc_facebook_comment_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
