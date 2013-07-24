<?php
/**
 * @file
 * vrc_facebook_comment.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function vrc_facebook_comment_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'facebook_comments_appid';
  $strongarm->value = '212476912222029';
  $export['facebook_comments_appid'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'facebook_comments_applyall';
  $strongarm->value = 1;
  $export['facebook_comments_applyall'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'facebook_comments_types';
  $strongarm->value = array(
    'article' => 'article',
    'quiz' => 0,
    'long_answer' => 0,
    'matching' => 0,
    'multichoice' => 0,
    'quiz_directions' => 0,
    'scale' => 0,
    'short_answer' => 0,
    'truefalse' => 0,
    'answer' => 0,
    'question' => 0,
    'documentation' => 0,
    'page' => 0,
  );
  $export['facebook_comments_types'] = $strongarm;

  return $export;
}
