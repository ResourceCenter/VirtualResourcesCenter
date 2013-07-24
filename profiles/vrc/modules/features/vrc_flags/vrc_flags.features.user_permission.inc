<?php
/**
 * @file
 * vrc_flags.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function vrc_flags_user_default_permissions() {
  $permissions = array();

  // Exported permission: administer flags.
  $permissions['administer flags'] = array(
    'name' => 'administer flags',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'flag',
  );

  // Exported permission: use flag import.
  $permissions['use flag import'] = array(
    'name' => 'use flag import',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'flag',
  );

  return $permissions;
}
