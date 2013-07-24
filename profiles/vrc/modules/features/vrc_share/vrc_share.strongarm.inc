<?php
/**
 * @file
 * vrc_share.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function vrc_share_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'service_links_gpo_type';
  $strongarm->value = 'medium';
  $export['service_links_gpo_type'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'service_links_node_types';
  $strongarm->value = array(
    'article' => 'article',
    'documentation' => 'documentation',
    'question' => 'question',
    'answer' => 0,
    'page' => 0,
    'long_answer' => 0,
    'matching' => 0,
    'multichoice' => 0,
    'quiz' => 0,
    'quiz_directions' => 0,
    'scale' => 0,
    'short_answer' => 0,
    'truefalse' => 0,
  );
  $export['service_links_node_types'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'service_links_show';
  $strongarm->value = array(
    'delicious' => 0,
    'digg' => 0,
    'stumbleupon' => 0,
    'twitter' => 0,
    'pingthis' => 0,
    'reddit' => 0,
    'slashdot' => 0,
    'newsvine' => 0,
    'furl' => 0,
    'facebook' => 0,
    'myspace' => 0,
    'google' => 0,
    'yahoo' => 0,
    'linkedin' => 0,
    'technorati' => 0,
    'technorati_favorite' => 0,
    'icerocket' => 0,
    'misterwong' => 0,
    'google_buzz' => 0,
    'mixx' => 0,
    'box' => 0,
    'blinklist' => 0,
    'identica' => 0,
    'newskicks' => 0,
    'diigo' => 0,
    'facebook_widget' => 0,
    'twitter_widget' => 1,
    'facebook_like' => 1,
    'digg_smart_button' => 0,
    'google_plus_one' => 1,
    'linkedin_share_button' => 0,
  );
  $export['service_links_show'] = $strongarm;

  return $export;
}
