<?php
/**
 * @file
 * vrc_dashboard.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function vrc_dashboard_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu:support_manager_dashboard
  $menu_links['main-menu:support_manager_dashboard'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'support_manager_dashboard',
    'router_path' => 'support_manager_dashboard',
    'link_title' => 'Dashboard',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Dashboard');


  return $menu_links;
}
