<?php
/**
 * @file
 * vrc_share.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function vrc_share_user_default_permissions() {
  $permissions = array();

  // Exported permission: access service links.
  $permissions['access service links'] = array(
    'name' => 'access service links',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
      'no email' => 'no email',
    ),
    'module' => 'service_links',
  );

  return $permissions;
}
