<?php
/**
 * @file
 * vrc_quiz.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function vrc_quiz_user_default_permissions() {
  $permissions = array();

  // Exported permission: access quiz.
  $permissions['access quiz'] = array(
    'name' => 'access quiz',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
      'editor' => 'editor',
      'no email' => 'no email',
    ),
    'module' => 'quiz',
  );

  // Exported permission: administer quiz configuration.
  $permissions['administer quiz configuration'] = array(
    'name' => 'administer quiz configuration',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'support' => 'support',
    ),
    'module' => 'quiz',
  );

  // Exported permission: assign any action to quiz events.
  $permissions['assign any action to quiz events'] = array(
    'name' => 'assign any action to quiz events',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'quiz',
  );

  // Exported permission: create quiz content.
  $permissions['create quiz content'] = array(
    'name' => 'create quiz content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'support' => 'support',
    ),
    'module' => 'node',
  );

  // Exported permission: create quiz_directions content.
  $permissions['create quiz_directions content'] = array(
    'name' => 'create quiz_directions content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'support' => 'support',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any quiz content.
  $permissions['delete any quiz content'] = array(
    'name' => 'delete any quiz content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'support' => 'support',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any quiz results.
  $permissions['delete any quiz results'] = array(
    'name' => 'delete any quiz results',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'support' => 'support',
    ),
    'module' => 'quiz',
  );

  // Exported permission: delete any quiz_directions content.
  $permissions['delete any quiz_directions content'] = array(
    'name' => 'delete any quiz_directions content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'support' => 'support',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own quiz content.
  $permissions['delete own quiz content'] = array(
    'name' => 'delete own quiz content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'support' => 'support',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own quiz_directions content.
  $permissions['delete own quiz_directions content'] = array(
    'name' => 'delete own quiz_directions content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'support' => 'support',
    ),
    'module' => 'node',
  );

  // Exported permission: delete results for own quiz.
  $permissions['delete results for own quiz'] = array(
    'name' => 'delete results for own quiz',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'support' => 'support',
    ),
    'module' => 'quiz',
  );

  // Exported permission: edit any quiz content.
  $permissions['edit any quiz content'] = array(
    'name' => 'edit any quiz content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'support' => 'support',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any quiz_directions content.
  $permissions['edit any quiz_directions content'] = array(
    'name' => 'edit any quiz_directions content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'support' => 'support',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own quiz content.
  $permissions['edit own quiz content'] = array(
    'name' => 'edit own quiz content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'support' => 'support',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own quiz_directions content.
  $permissions['edit own quiz_directions content'] = array(
    'name' => 'edit own quiz_directions content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'support' => 'support',
    ),
    'module' => 'node',
  );

  // Exported permission: edit question titles.
  $permissions['edit question titles'] = array(
    'name' => 'edit question titles',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'quiz',
  );

  // Exported permission: manual quiz revisioning.
  $permissions['manual quiz revisioning'] = array(
    'name' => 'manual quiz revisioning',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'quiz',
  );

  // Exported permission: score any quiz.
  $permissions['score any quiz'] = array(
    'name' => 'score any quiz',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'support' => 'support',
    ),
    'module' => 'quiz',
  );

  // Exported permission: score own quiz.
  $permissions['score own quiz'] = array(
    'name' => 'score own quiz',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'support' => 'support',
    ),
    'module' => 'quiz',
  );

  // Exported permission: view any quiz question correct response.
  $permissions['view any quiz question correct response'] = array(
    'name' => 'view any quiz question correct response',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'quiz',
  );

  // Exported permission: view any quiz results.
  $permissions['view any quiz results'] = array(
    'name' => 'view any quiz results',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'support' => 'support',
    ),
    'module' => 'quiz',
  );

  // Exported permission: view own quiz results.
  $permissions['view own quiz results'] = array(
    'name' => 'view own quiz results',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
      'editor' => 'editor',
      'no email' => 'no email',
    ),
    'module' => 'quiz',
  );

  // Exported permission: view quiz question outside of a quiz.
  $permissions['view quiz question outside of a quiz'] = array(
    'name' => 'view quiz question outside of a quiz',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
      'editor' => 'editor',
      'no email' => 'no email',
    ),
    'module' => 'quiz',
  );

  // Exported permission: view results for own quiz.
  $permissions['view results for own quiz'] = array(
    'name' => 'view results for own quiz',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
      'editor' => 'editor',
      'no email' => 'no email',
    ),
    'module' => 'quiz',
  );

  return $permissions;
}
