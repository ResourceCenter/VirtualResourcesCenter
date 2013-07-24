<?php
/**
 * @file
 * vrc_feeds.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function vrc_feeds_user_default_permissions() {
  $permissions = array();

  // Exported permission: administer feeds.
  $permissions['administer feeds'] = array(
    'name' => 'administer feeds',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'feeds',
  );

  // Exported permission: administer feeds_tamper.
  $permissions['administer feeds_tamper'] = array(
    'name' => 'administer feeds_tamper',
    'roles' => array(),
    'module' => 'feeds_tamper',
  );

  // Exported permission: clear content_documentation feeds.
  $permissions['clear content_documentation feeds'] = array(
    'name' => 'clear content_documentation feeds',
    'roles' => array(),
    'module' => 'feeds',
  );

  // Exported permission: clear content_documentation_from_file feeds.
  $permissions['clear content_documentation_from_file feeds'] = array(
    'name' => 'clear content_documentation_from_file feeds',
    'roles' => array(),
    'module' => 'feeds',
  );

  // Exported permission: clear mailhandler_nodes_to_questions feeds.
  $permissions['clear mailhandler_nodes_to_questions feeds'] = array(
    'name' => 'clear mailhandler_nodes_to_questions feeds',
    'roles' => array(),
    'module' => 'feeds',
  );

  // Exported permission: clear taxonomy_tools_categories_en feeds.
  $permissions['clear taxonomy_tools_categories_en feeds'] = array(
    'name' => 'clear taxonomy_tools_categories_en feeds',
    'roles' => array(),
    'module' => 'feeds',
  );

  // Exported permission: import content_documentation feeds.
  $permissions['import content_documentation feeds'] = array(
    'name' => 'import content_documentation feeds',
    'roles' => array(),
    'module' => 'feeds',
  );

  // Exported permission: import content_documentation_from_file feeds.
  $permissions['import content_documentation_from_file feeds'] = array(
    'name' => 'import content_documentation_from_file feeds',
    'roles' => array(),
    'module' => 'feeds',
  );

  // Exported permission: import mailhandler_nodes_to_questions feeds.
  $permissions['import mailhandler_nodes_to_questions feeds'] = array(
    'name' => 'import mailhandler_nodes_to_questions feeds',
    'roles' => array(),
    'module' => 'feeds',
  );

  // Exported permission: import taxonomy_tools_categories_en feeds.
  $permissions['import taxonomy_tools_categories_en feeds'] = array(
    'name' => 'import taxonomy_tools_categories_en feeds',
    'roles' => array(),
    'module' => 'feeds',
  );

  // Exported permission: tamper content_documentation.
  $permissions['tamper content_documentation'] = array(
    'name' => 'tamper content_documentation',
    'roles' => array(),
    'module' => 'feeds_tamper',
  );

  // Exported permission: tamper content_documentation_from_file.
  $permissions['tamper content_documentation_from_file'] = array(
    'name' => 'tamper content_documentation_from_file',
    'roles' => array(),
    'module' => 'feeds_tamper',
  );

  // Exported permission: tamper mailhandler_nodes_to_questions.
  $permissions['tamper mailhandler_nodes_to_questions'] = array(
    'name' => 'tamper mailhandler_nodes_to_questions',
    'roles' => array(),
    'module' => 'feeds_tamper',
  );

  // Exported permission: tamper taxonomy_tools_categories_en.
  $permissions['tamper taxonomy_tools_categories_en'] = array(
    'name' => 'tamper taxonomy_tools_categories_en',
    'roles' => array(),
    'module' => 'feeds_tamper',
  );

  // Exported permission: unlock content_documentation feeds.
  $permissions['unlock content_documentation feeds'] = array(
    'name' => 'unlock content_documentation feeds',
    'roles' => array(),
    'module' => 'feeds',
  );

  // Exported permission: unlock content_documentation_from_file feeds.
  $permissions['unlock content_documentation_from_file feeds'] = array(
    'name' => 'unlock content_documentation_from_file feeds',
    'roles' => array(),
    'module' => 'feeds',
  );

  // Exported permission: unlock mailhandler_nodes_to_questions feeds.
  $permissions['unlock mailhandler_nodes_to_questions feeds'] = array(
    'name' => 'unlock mailhandler_nodes_to_questions feeds',
    'roles' => array(),
    'module' => 'feeds',
  );

  // Exported permission: unlock taxonomy_tools_categories_en feeds.
  $permissions['unlock taxonomy_tools_categories_en feeds'] = array(
    'name' => 'unlock taxonomy_tools_categories_en feeds',
    'roles' => array(),
    'module' => 'feeds',
  );

  return $permissions;
}
