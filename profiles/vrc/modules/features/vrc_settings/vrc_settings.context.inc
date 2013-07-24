<?php
/**
 * @file
 * vrc_settings.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function vrc_settings_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'default';
  $context->description = 'Default blocks all pages';
  $context->tag = '--THEME';
  $context->conditions = array(
    'user' => array(
      'values' => array(
        'administrator' => 'administrator',
        'authenticated user' => 'authenticated user',
        'editor' => 'editor',
        'no email' => 'no email',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'system-main-menu' => array(
          'module' => 'system',
          'delta' => 'main-menu',
          'region' => 'menu_bar',
          'weight' => '-20',
        ),
        'logintoboggan-logintoboggan_logged_in' => array(
          'module' => 'logintoboggan',
          'delta' => 'logintoboggan_logged_in',
          'region' => 'menu_bar',
          'weight' => '-10',
        ),
        'menu-menu-secondary-menu' => array(
          'module' => 'menu',
          'delta' => 'menu-secondary-menu',
          'region' => 'footer',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('--THEME');
  t('Default blocks all pages');
  $export['default'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'default_anonymous';
  $context->description = 'Menus to display for visitors';
  $context->tag = '--THEME';
  $context->conditions = array(
    'user' => array(
      'values' => array(
        'anonymous user' => 'anonymous user',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'menu-menu-main-menu-for-visitors' => array(
          'module' => 'menu',
          'delta' => 'menu-main-menu-for-visitors',
          'region' => 'menu_bar',
          'weight' => '-80',
        ),
        'user-login' => array(
          'module' => 'user',
          'delta' => 'login',
          'region' => 'menu_bar',
          'weight' => '-10',
        ),
        'menu-menu-secondary-menu' => array(
          'module' => 'menu',
          'delta' => 'menu-secondary-menu',
          'region' => 'footer',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('--THEME');
  t('Menus to display for visitors');
  $export['default_anonymous'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'front_page';
  $context->description = 'Blocks that display on the front page';
  $context->tag = '--THEME';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '<front>' => '<front>',
      ),
    ),
    'views' => array(
      'values' => array(
        'front' => 'front',
        'front:page' => 'front:page',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views--exp-site_search-page' => array(
          'module' => 'views',
          'delta' => '-exp-site_search-page',
          'region' => 'content',
          'weight' => '-10',
        ),
        'quicktabs-questions' => array(
          'module' => 'quicktabs',
          'delta' => 'questions',
          'region' => 'content',
          'weight' => '-9',
        ),
        'views-vrc_taxonomy_cloud-block' => array(
          'module' => 'views',
          'delta' => 'vrc_taxonomy_cloud-block',
          'region' => 'sidebar_first',
          'weight' => '-9',
        ),
        'views-vrc_tool_list-block_1' => array(
          'module' => 'views',
          'delta' => 'vrc_tool_list-block_1',
          'region' => 'sidebar_first',
          'weight' => '-8',
        ),
        'views-articles-block' => array(
          'module' => 'views',
          'delta' => 'articles-block',
          'region' => 'sidebar_first',
          'weight' => '-7',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('--THEME');
  t('Blocks that display on the front page');
  $export['front_page'] = $context;

  return $export;
}
