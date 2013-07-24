<?php
/**
 * @file
 * vrc_userpoints.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function vrc_userpoints_user_default_permissions() {
  $permissions = array();

  // Exported permission: add userpoints.
  $permissions['add userpoints'] = array(
    'name' => 'add userpoints',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'userpoints',
  );

  // Exported permission: administer userpoints.
  $permissions['administer userpoints'] = array(
    'name' => 'administer userpoints',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'userpoints',
  );

  // Exported permission: edit userpoints.
  $permissions['edit userpoints'] = array(
    'name' => 'edit userpoints',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'userpoints',
  );

  // Exported permission: moderate userpoints.
  $permissions['moderate userpoints'] = array(
    'name' => 'moderate userpoints',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'support' => 'support',
    ),
    'module' => 'userpoints',
  );

  // Exported permission: view own userpoints.
  $permissions['view own userpoints'] = array(
    'name' => 'view own userpoints',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
      'editor' => 'editor',
      'no email' => 'no email',
    ),
    'module' => 'userpoints',
  );

  // Exported permission: view userpoints.
  $permissions['view userpoints'] = array(
    'name' => 'view userpoints',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'support' => 'support',
    ),
    'module' => 'userpoints',
  );

  return $permissions;
}
