<?php
/**
 * @file.
 */

/**
 * Implements hook_install_tasks().
 */
function vrc_install_tasks($install_state) {
  $tasks = array();

  $tasks['vrc_configure'] = array(
    'display_name' => st('Other configurations'),
    'type' => 'batch',
  );

  return $tasks;
}

/**
 * Implements hook_form_FORM_ID_alter().
 */
function vrc_form_install_configure_form_alter(&$form, $form_state) {
  // Pre-populate the site name with the server name.
  $form['site_information']['site_name']['#default_value'] = $_SERVER['SERVER_NAME'];
}

/**
 * Tasks.
 */

/**
 * Task callback.
 */
function vrc_configure(&$install_state) {
  $batch = array();
  $batch['title'] = st('Configuring @drupal', array('@drupal' => drupal_install_profile_distribution_name()));

  // Revert features.
  $batch['operations'][] = array('vrc_revert_features', array());
  $batch['operations'][] = array('vrc_flush_cache', array());

  // .
  $batch['operations'][] = array('vrc_create_default_users', array());
  $batch['operations'][] = array('vrc_flush_cache', array());

  // .
  $batch['operations'][] = array('vrc_set_locale_content', array());
  $batch['operations'][] = array('vrc_flush_cache', array());

  // .
  $batch['operations'][] = array('vrc_set_theme_settings', array());
  $batch['operations'][] = array('vrc_flush_cache', array());

  // .
  $batch['operations'][] = array('vrc_install_trigger_assignments', array());
  $batch['operations'][] = array('vrc_flush_cache', array());

  $batch['error_message'] = st('The configuration has encountered an error.');
  $batch['finished'] = 'vrc_configure_finished';
  return $batch;
}

/**
 * Batch finished callback.
 */
function vrc_configure_finished($success, $results, $operations) {
  // Aegir enables this.
  if (module_exists('update')) {
    module_disable(array('update'), FALSE);
  }

  // Done.
  drupal_flush_all_caches();
}

/**
 * Flush caches.
 */
function vrc_flush_cache(&$batch_context) {
  drupal_flush_all_caches();
  drupal_get_schema(NULL, TRUE);
}

/**
 * Revert all features.
 *
 * Difference with features_revert().
 * - call features_get_component_states() with $rebuild_only = FALSE and $reset = TRUE.
 */
function vrc_revert_features(&$batch_context) {
  if (!module_exists('features')) {
    return;
  }

  module_load_include('inc', 'features', 'features.export');
  features_include();

  $restore_states = array(FEATURES_OVERRIDDEN, FEATURES_REBUILDABLE, FEATURES_NEEDS_REVIEW);

  $items = array();
  $states = features_get_component_states(array(), FALSE, TRUE);
  foreach ($states as $module_name => $components) {
    foreach ($components as $component => $state) {
      if (in_array($state, $restore_states)) {
        $items[$module_name][] = $component;
      }
    }
  }

  return features_revert($items);
}

/**
 * Setup assignments for triggers to actions.
 */
function vrc_install_trigger_assignments(&$batch_context) {
  if (!module_exists('vrc_notifications')) {
    return;
  }
  // Cleanup.
  db_truncate('trigger_assignments')->execute();
  // .
  module_load_install('notifications_content');
  notifications_content_install_trigger_action('question_answer_best',   'vrc_notifications_question_answer_best_action');
  notifications_content_install_trigger_action('question_answer_insert', 'vrc_notifications_question_answer_action');
  notifications_content_install_trigger_action('question_answer_update', 'vrc_notifications_question_answer_action');
  notifications_content_install_trigger_action('tag_article_insert',     'vrc_notifications_tag_node_insert_action');
  notifications_content_install_trigger_action('tag_question_insert',    'vrc_notifications_tag_node_insert_action');
}
