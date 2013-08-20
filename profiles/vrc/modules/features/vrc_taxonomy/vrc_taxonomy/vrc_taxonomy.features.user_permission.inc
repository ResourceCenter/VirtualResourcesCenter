<?php
/**
 * @file
 * vrc_taxonomy.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function vrc_taxonomy_user_default_permissions() {
  $permissions = array();

  // Exported permission: delete terms in compatibilities.
  $permissions['delete terms in compatibilities'] = array(
    'name' => 'delete terms in compatibilities',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: delete terms in question_type.
  $permissions['delete terms in question_type'] = array(
    'name' => 'delete terms in question_type',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: delete terms in release_type.
  $permissions['delete terms in release_type'] = array(
    'name' => 'delete terms in release_type',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: delete terms in themes.
  $permissions['delete terms in themes'] = array(
    'name' => 'delete terms in themes',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in compatibilities.
  $permissions['edit terms in compatibilities'] = array(
    'name' => 'edit terms in compatibilities',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in question_type.
  $permissions['edit terms in question_type'] = array(
    'name' => 'edit terms in question_type',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in release_type.
  $permissions['edit terms in release_type'] = array(
    'name' => 'edit terms in release_type',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in themes.
  $permissions['edit terms in themes'] = array(
    'name' => 'edit terms in themes',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  return $permissions;
}
