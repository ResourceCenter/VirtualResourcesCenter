<?php
/**
 * @file
 * vrc_answers.quicktabs.inc
 */

/**
 * Implements hook_quicktabs_default_quicktabs().
 */
function vrc_answers_quicktabs_default_quicktabs() {
  $export = array();

  $quicktabs = new stdClass();
  $quicktabs->disabled = FALSE; /* Edit this to true to make a default quicktabs disabled initially */
  $quicktabs->api_version = 1;
  $quicktabs->machine_name = 'answer_listing';
  $quicktabs->ajax = 0;
  $quicktabs->hide_empty_tabs = TRUE;
  $quicktabs->default_tab = 0;
  $quicktabs->title = 'Answers';
  $quicktabs->tabs = array(
    0 => array(
      'vid' => 'answer_listing',
      'display' => 'sort_by_vote',
      'args' => '',
      'title' => 'Vote',
      'weight' => '-100',
      'type' => 'view',
    ),
    1 => array(
      'vid' => 'answer_listing',
      'display' => 'by_date',
      'args' => '',
      'title' => 'Oldest',
      'weight' => '-99',
      'type' => 'view',
    ),
  );
  $quicktabs->renderer = 'quicktabs';
  $quicktabs->style = 'Zen';
  $quicktabs->options = array();

  // Translatables
  // Included for use with string extractors like potx.
  t('Answers');
  t('Oldest');
  t('Vote');

  $export['answer_listing'] = $quicktabs;

  return $export;
}
