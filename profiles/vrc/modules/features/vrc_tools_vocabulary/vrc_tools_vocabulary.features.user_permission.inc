<?php
/**
 * @file
 * vrc_tools_vocabulary.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function vrc_tools_vocabulary_user_default_permissions() {
  $permissions = array();

  // Exported permission: delete terms in taxonomy_categories.
  $permissions['delete terms in taxonomy_categories'] = array(
    'name' => 'delete terms in taxonomy_categories',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: delete terms in tool.
  $permissions['delete terms in tool'] = array(
    'name' => 'delete terms in tool',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in taxonomy_categories.
  $permissions['edit terms in taxonomy_categories'] = array(
    'name' => 'edit terms in taxonomy_categories',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in tool.
  $permissions['edit terms in tool'] = array(
    'name' => 'edit terms in tool',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  return $permissions;
}
