<?php
/**
 * @file
 * vrc_facebook_comment.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function vrc_facebook_comment_user_default_permissions() {
  $permissions = array();

  // Exported permission: administer facebook comments.
  $permissions['administer facebook comments'] = array(
    'name' => 'administer facebook comments',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'facebook_comments',
  );

  // Exported permission: moderate facebook comments.
  $permissions['moderate facebook comments'] = array(
    'name' => 'moderate facebook comments',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'facebook_comments',
  );

  return $permissions;
}
