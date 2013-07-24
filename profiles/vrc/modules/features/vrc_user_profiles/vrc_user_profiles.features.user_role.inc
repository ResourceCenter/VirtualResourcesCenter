<?php
/**
 * @file
 * vrc_user_profiles.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function vrc_user_profiles_user_default_roles() {
  $roles = array();

  // Exported role: support.
  $roles['support'] = array(
    'name' => 'support',
    'weight' => 5,
  );

  return $roles;
}
