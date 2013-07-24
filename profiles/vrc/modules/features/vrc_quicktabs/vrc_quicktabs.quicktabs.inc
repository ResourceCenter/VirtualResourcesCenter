<?php
/**
 * @file
 * vrc_quicktabs.quicktabs.inc
 */

/**
 * Implements hook_quicktabs_default_quicktabs().
 */
function vrc_quicktabs_quicktabs_default_quicktabs() {
  $export = array();

  $quicktabs = new stdClass();
  $quicktabs->disabled = FALSE; /* Edit this to true to make a default quicktabs disabled initially */
  $quicktabs->api_version = 1;
  $quicktabs->machine_name = 'all_questions';
  $quicktabs->ajax = 0;
  $quicktabs->hide_empty_tabs = FALSE;
  $quicktabs->default_tab = 0;
  $quicktabs->title = 'All Questions';
  $quicktabs->tabs = array(
    0 => array(
      'vid' => 'questions_for_front_page',
      'display' => 'block_4',
      'args' => '',
      'title' => 'Hottest questions',
      'weight' => '-100',
      'type' => 'view',
    ),
    1 => array(
      'vid' => 'questions_for_front_page',
      'display' => 'block_5',
      'args' => '',
      'title' => 'Last Answered',
      'weight' => '-99',
      'type' => 'view',
    ),
    2 => array(
      'vid' => 'questions_for_front_page',
      'display' => 'block_6',
      'args' => '',
      'title' => 'Open Questions',
      'weight' => '-98',
      'type' => 'view',
    ),
    3 => array(
      'vid' => 'questions_for_front_page',
      'display' => 'block_7',
      'args' => '',
      'title' => 'My Questions',
      'weight' => '-97',
      'type' => 'view',
    ),
  );
  $quicktabs->renderer = 'quicktabs';
  $quicktabs->style = 'Zen';
  $quicktabs->options = array();

  // Translatables
  // Included for use with string extractors like potx.
  t('All Questions');
  t('Hottest questions');
  t('Last Answered');
  t('My Questions');
  t('Open Questions');

  $export['all_questions'] = $quicktabs;

  $quicktabs = new stdClass();
  $quicktabs->disabled = FALSE; /* Edit this to true to make a default quicktabs disabled initially */
  $quicktabs->api_version = 1;
  $quicktabs->machine_name = 'questions';
  $quicktabs->ajax = 0;
  $quicktabs->hide_empty_tabs = FALSE;
  $quicktabs->default_tab = 0;
  $quicktabs->title = 'Questions';
  $quicktabs->tabs = array(
    0 => array(
      'vid' => 'questions_for_front_page',
      'display' => 'block',
      'args' => '',
      'title' => 'Hot questions',
      'weight' => '-100',
      'type' => 'view',
    ),
    1 => array(
      'vid' => 'questions_for_front_page',
      'display' => 'block_2',
      'args' => '',
      'title' => 'Open Questions',
      'weight' => '-99',
      'type' => 'view',
    ),
    2 => array(
      'vid' => 'questions_for_front_page',
      'display' => 'block_3',
      'args' => '',
      'title' => 'Last Answered',
      'weight' => '-98',
      'type' => 'view',
    ),
  );
  $quicktabs->renderer = 'quicktabs';
  $quicktabs->style = 'Zen';
  $quicktabs->options = array();

  // Translatables
  // Included for use with string extractors like potx.
  t('Hot questions');
  t('Last Answered');
  t('Open Questions');
  t('Questions');

  $export['questions'] = $quicktabs;

  return $export;
}
