<?php
/**
 * @file
 * vrc_answers.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function vrc_answers_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu:ask-a-question
  $menu_links['main-menu:ask-a-question'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'ask-a-question',
    'router_path' => 'ask-a-question',
    'link_title' => 'Ask a question',
    'options' => array(),
    'module' => 'system',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '0',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Ask a question');


  return $menu_links;
}
