<?php
/**
 * @file
 * vrc_answers.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function vrc_answers_user_default_permissions() {
  $permissions = array();

  // Exported permission: create answer content.
  $permissions['create answer content'] = array(
    'name' => 'create answer content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'no email' => 'no email',
    ),
    'module' => 'node',
  );

  // Exported permission: create field_question_pending.
  $permissions['create field_question_pending'] = array(
    'name' => 'create field_question_pending',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: create field_tool.
  $permissions['create field_tool'] = array(
    'name' => 'create field_tool',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'support' => 'support',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: create field_toolbox_categories.
  $permissions['create field_toolbox_categories'] = array(
    'name' => 'create field_toolbox_categories',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'support' => 'support',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: create question content.
  $permissions['create question content'] = array(
    'name' => 'create question content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'no email' => 'no email',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any answer content.
  $permissions['delete any answer content'] = array(
    'name' => 'delete any answer content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any question content.
  $permissions['delete any question content'] = array(
    'name' => 'delete any question content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own answer content.
  $permissions['delete own answer content'] = array(
    'name' => 'delete own answer content',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
      'editor' => 'editor',
      'no email' => 'no email',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own question content.
  $permissions['delete own question content'] = array(
    'name' => 'delete own question content',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
      'editor' => 'editor',
      'no email' => 'no email',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any answer content.
  $permissions['edit any answer content'] = array(
    'name' => 'edit any answer content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any question content.
  $permissions['edit any question content'] = array(
    'name' => 'edit any question content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: edit field_question_pending.
  $permissions['edit field_question_pending'] = array(
    'name' => 'edit field_question_pending',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit field_tool.
  $permissions['edit field_tool'] = array(
    'name' => 'edit field_tool',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'support' => 'support',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit field_toolbox_categories.
  $permissions['edit field_toolbox_categories'] = array(
    'name' => 'edit field_toolbox_categories',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'support' => 'support',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit own answer content.
  $permissions['edit own answer content'] = array(
    'name' => 'edit own answer content',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
      'editor' => 'editor',
      'no email' => 'no email',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own field_question_pending.
  $permissions['edit own field_question_pending'] = array(
    'name' => 'edit own field_question_pending',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit own field_tool.
  $permissions['edit own field_tool'] = array(
    'name' => 'edit own field_tool',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'support' => 'support',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit own field_toolbox_categories.
  $permissions['edit own field_toolbox_categories'] = array(
    'name' => 'edit own field_toolbox_categories',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'support' => 'support',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit own question content.
  $permissions['edit own question content'] = array(
    'name' => 'edit own question content',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
      'editor' => 'editor',
      'no email' => 'no email',
    ),
    'module' => 'node',
  );

  // Exported permission: view field_question_pending.
  $permissions['view field_question_pending'] = array(
    'name' => 'view field_question_pending',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view field_tool.
  $permissions['view field_tool'] = array(
    'name' => 'view field_tool',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
      'no email' => 'no email',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view field_toolbox_categories.
  $permissions['view field_toolbox_categories'] = array(
    'name' => 'view field_toolbox_categories',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
      'editor' => 'editor',
      'no email' => 'no email',
      'support' => 'support',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view own field_question_pending.
  $permissions['view own field_question_pending'] = array(
    'name' => 'view own field_question_pending',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view own field_tool.
  $permissions['view own field_tool'] = array(
    'name' => 'view own field_tool',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
      'no email' => 'no email',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view own field_toolbox_categories.
  $permissions['view own field_toolbox_categories'] = array(
    'name' => 'view own field_toolbox_categories',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
      'editor' => 'editor',
      'no email' => 'no email',
      'support' => 'support',
    ),
    'module' => 'field_permissions',
  );

  return $permissions;
}
