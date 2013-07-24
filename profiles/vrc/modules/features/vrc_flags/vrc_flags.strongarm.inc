<?php
/**
 * @file
 * vrc_flags.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function vrc_flags_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'flag_default_flag_status';
  $strongarm->value = array(
    'abuse_node' => TRUE,
    'abuse_comment' => TRUE,
    'bookmarks' => TRUE,
    'abuse_user' => TRUE,
  );
  $export['flag_default_flag_status'] = $strongarm;

  return $export;
}
