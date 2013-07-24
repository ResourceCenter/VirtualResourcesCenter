<?php
/**
 * @file
 * vrc_settings.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function vrc_settings_user_default_roles() {
  $roles = array();

  // Exported role: administrator.
  $roles['administrator'] = array(
    'name' => 'administrator',
    'weight' => 4,
  );

  // Exported role: editor.
  $roles['editor'] = array(
    'name' => 'editor',
    'weight' => 3,
  );

  // Exported role: no email.
  $roles['no email'] = array(
    'name' => 'no email',
    'weight' => 1,
  );

  return $roles;
}
