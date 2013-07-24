<?php
/**
 * @file
 * vrc_user_profiles.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function vrc_user_profiles_user_default_permissions() {
  $permissions = array();

  // Exported permission: create field_user_bio.
  $permissions['create field_user_bio'] = array(
    'name' => 'create field_user_bio',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'editor' => 'editor',
      'support' => 'support',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: create field_user_fullname.
  $permissions['create field_user_fullname'] = array(
    'name' => 'create field_user_fullname',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'support' => 'support',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: create field_user_gender.
  $permissions['create field_user_gender'] = array(
    'name' => 'create field_user_gender',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'editor' => 'editor',
      'support' => 'support',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit field_user_bio.
  $permissions['edit field_user_bio'] = array(
    'name' => 'edit field_user_bio',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit field_user_fullname.
  $permissions['edit field_user_fullname'] = array(
    'name' => 'edit field_user_fullname',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit field_user_gender.
  $permissions['edit field_user_gender'] = array(
    'name' => 'edit field_user_gender',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit own field_user_bio.
  $permissions['edit own field_user_bio'] = array(
    'name' => 'edit own field_user_bio',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'editor' => 'editor',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit own field_user_fullname.
  $permissions['edit own field_user_fullname'] = array(
    'name' => 'edit own field_user_fullname',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'support' => 'support',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit own field_user_gender.
  $permissions['edit own field_user_gender'] = array(
    'name' => 'edit own field_user_gender',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'editor' => 'editor',
      'support' => 'support',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view field_user_bio.
  $permissions['view field_user_bio'] = array(
    'name' => 'view field_user_bio',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
      'editor' => 'editor',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view field_user_fullname.
  $permissions['view field_user_fullname'] = array(
    'name' => 'view field_user_fullname',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
      'editor' => 'editor',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view field_user_gender.
  $permissions['view field_user_gender'] = array(
    'name' => 'view field_user_gender',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
      'editor' => 'editor',
      'support' => 'support',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view own field_user_bio.
  $permissions['view own field_user_bio'] = array(
    'name' => 'view own field_user_bio',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'editor' => 'editor',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view own field_user_fullname.
  $permissions['view own field_user_fullname'] = array(
    'name' => 'view own field_user_fullname',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'support' => 'support',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view own field_user_gender.
  $permissions['view own field_user_gender'] = array(
    'name' => 'view own field_user_gender',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'editor' => 'editor',
      'support' => 'support',
    ),
    'module' => 'field_permissions',
  );

  return $permissions;
}
