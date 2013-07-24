<?php
/**
 * @file
 * vrc_settings.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function vrc_settings_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: main-menu.
  $menus['main-menu'] = array(
    'menu_name' => 'main-menu',
    'title' => 'Main menu',
    'description' => 'The <em>Main</em> menu is used on many sites to show the major sections of the site, often in a top navigation bar.',
  );
  // Exported menu: menu-main-menu-for-visitors.
  $menus['menu-main-menu-for-visitors'] = array(
    'menu_name' => 'menu-main-menu-for-visitors',
    'title' => 'Main menu for Visitors',
    'description' => 'Main menu to display for anonymous users',
  );
  // Exported menu: menu-secondary-menu.
  $menus['menu-secondary-menu'] = array(
    'menu_name' => 'menu-secondary-menu',
    'title' => 'secondary menu',
    'description' => '',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Main menu');
  t('Main menu for Visitors');
  t('Main menu to display for anonymous users');
  t('The <em>Main</em> menu is used on many sites to show the major sections of the site, often in a top navigation bar.');
  t('secondary menu');


  return $menus;
}
