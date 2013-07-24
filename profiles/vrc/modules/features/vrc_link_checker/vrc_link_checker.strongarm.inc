<?php
/**
 * @file
 * vrc_link_checker.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function vrc_link_checker_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'linkchecker_scan_nodetypes';
  $strongarm->value = array(
    'documentation' => 'documentation',
    'answer' => 0,
    'article' => 0,
    'page' => 0,
    'long_answer' => 0,
    'matching' => 0,
    'multichoice' => 0,
    'question' => 0,
    'quiz' => 0,
    'quiz_directions' => 0,
    'scale' => 0,
    'short_answer' => 0,
    'truefalse' => 0,
  );
  $export['linkchecker_scan_nodetypes'] = $strongarm;

  return $export;
}
