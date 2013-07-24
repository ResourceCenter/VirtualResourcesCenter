<?php
/**
 * @file
 * vrc_quicktabs.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function vrc_quicktabs_user_default_permissions() {
  $permissions = array();

  // Exported permission: administer quicktabs.
  $permissions['administer quicktabs'] = array(
    'name' => 'administer quicktabs',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'quicktabs',
  );

  return $permissions;
}
