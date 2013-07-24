<?php
/**
 * @file
 * vrc_notifications.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function vrc_notifications_user_default_permissions() {
  $permissions = array();

  // Exported permission: administer notifications.
  $permissions['administer notifications'] = array(
    'name' => 'administer notifications',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'notifications',
  );

  // Exported permission: create subscriptions.
  $permissions['create subscriptions'] = array(
    'name' => 'create subscriptions',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
      'no email' => 'no email',
    ),
    'module' => 'notifications',
  );

  // Exported permission: maintain own subscriptions.
  $permissions['maintain own subscriptions'] = array(
    'name' => 'maintain own subscriptions',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'no email' => 'no email',
    ),
    'module' => 'notifications',
  );

  // Exported permission: manage all subscriptions.
  $permissions['manage all subscriptions'] = array(
    'name' => 'manage all subscriptions',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'notifications',
  );

  // Exported permission: skip notifications.
  $permissions['skip notifications'] = array(
    'name' => 'skip notifications',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'no email' => 'no email',
    ),
    'module' => 'notifications',
  );

  // Exported permission: subscribe to content.
  $permissions['subscribe to content'] = array(
    'name' => 'subscribe to content',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
      'no email' => 'no email',
    ),
    'module' => 'notifications_content',
  );

  // Exported permission: subscribe to content type.
  $permissions['subscribe to content type'] = array(
    'name' => 'subscribe to content type',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
      'no email' => 'no email',
    ),
    'module' => 'notifications_content',
  );

  // Exported permission: subscribe to taxonomy terms.
  $permissions['subscribe to taxonomy terms'] = array(
    'name' => 'subscribe to taxonomy terms',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
      'editor' => 'editor',
      'no email' => 'no email',
    ),
    'module' => 'notifications_tags',
  );

  // Exported permission: subscribe to taxonomy vocabulary.
  $permissions['subscribe to taxonomy vocabulary'] = array(
    'name' => 'subscribe to taxonomy vocabulary',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
      'no email' => 'no email',
    ),
    'module' => 'notifications_tags',
  );

  return $permissions;
}
