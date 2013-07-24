<?php
/**
 * @file
 * vrc_settings.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function vrc_settings_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu:<front>
  $menu_links['main-menu:<front>'] = array(
    'menu_name' => 'main-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Home',
    'options' => array(
      'attributes' => array(
        'title' => 'Back to home page',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
  );
  // Exported menu link: main-menu:articles
  $menu_links['main-menu:articles'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'articles',
    'router_path' => 'articles',
    'link_title' => 'Articles',
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
    'weight' => -48,
  );
  // Exported menu link: main-menu:toolbox
  $menu_links['main-menu:toolbox'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'toolbox',
    'router_path' => 'toolbox',
    'link_title' => 'Toolbox',
    'options' => array(
      'attributes' => array(
        'title' => 'All toolbox content',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
  );
  // Exported menu link: menu-main-menu-for-visitors:<front>
  $menu_links['menu-main-menu-for-visitors:<front>'] = array(
    'menu_name' => 'menu-main-menu-for-visitors',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Home',
    'options' => array(
      'attributes' => array(
        'title' => 'Back to home page',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
  );
  // Exported menu link: menu-main-menu-for-visitors:all_questions
  $menu_links['menu-main-menu-for-visitors:all_questions'] = array(
    'menu_name' => 'menu-main-menu-for-visitors',
    'link_path' => 'all_questions',
    'router_path' => 'all_questions',
    'link_title' => 'All Questions',
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
    'weight' => -47,
  );
  // Exported menu link: menu-main-menu-for-visitors:articles
  $menu_links['menu-main-menu-for-visitors:articles'] = array(
    'menu_name' => 'menu-main-menu-for-visitors',
    'link_path' => 'articles',
    'router_path' => 'articles',
    'link_title' => 'Articles',
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
    'weight' => -48,
  );
  // Exported menu link: menu-main-menu-for-visitors:toolbox
  $menu_links['menu-main-menu-for-visitors:toolbox'] = array(
    'menu_name' => 'menu-main-menu-for-visitors',
    'link_path' => 'toolbox',
    'router_path' => 'toolbox',
    'link_title' => 'Toolbox',
    'options' => array(
      'attributes' => array(
        'title' => 'All toolbox content',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
  );
  // Exported menu link: menu-main-menu-for-visitors:user/register
  $menu_links['menu-main-menu-for-visitors:user/register'] = array(
    'menu_name' => 'menu-main-menu-for-visitors',
    'link_path' => 'user/register',
    'router_path' => 'user/register',
    'link_title' => 'Register to post a question',
    'options' => array(
      'attributes' => array(
        'title' => 'Register an account to post a question',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -46,
  );
  // Exported menu link: menu-secondary-menu:user/register
  $menu_links['menu-secondary-menu:user/register'] = array(
    'menu_name' => 'menu-secondary-menu',
    'link_path' => 'user/register',
    'router_path' => 'user/register',
    'link_title' => 'Create an account',
    'options' => array(
      'attributes' => array(
        'title' => 'Create an authenticated user account',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 1,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('All Questions');
  t('Articles');
  t('Create an account');
  t('Home');
  t('Register to post a question');
  t('Toolbox');


  return $menu_links;
}
