<?php
/**
 * @file
 * vrc_settings.box.inc
 */

/**
 * Implements hook_default_box().
 */
function vrc_settings_default_box() {
  $export = array();

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'what_is_vrc';
  $box->plugin_key = 'simple';
  $box->title = 'What is VRC?';
  $box->description = 'What is VRC';
  $box->options = array(
    'body' => array(
      'value' => '<p>Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry\'s standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book. It has survived not only five centuries, but also the leap into electronic typesetting, remaining essentially unchanged. It was popularised in the 1960s with the release of Letraset sheets containing Lorem Ipsum passages, and more recently with desktop publishing software like Aldus PageMaker including versions of Lorem Ipsum.</p>',
      'format' => 'filtered_html',
    ),
  );
  $export['what_is_vrc'] = $box;

  return $export;
}
