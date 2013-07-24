<?php
/**
 * @file
 * vrc_tools_vocabulary.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function vrc_tools_vocabulary_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'taxonomy_term-taxonomy_categories-field_guid'
  $field_instances['taxonomy_term-taxonomy_categories-field_guid'] = array(
    'bundle' => 'taxonomy_categories',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Unique global identifier for this term. Usually an URL or URI, but need not be resolvable.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => -1,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_guid',
    'label' => 'GUID',
    'required' => FALSE,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 0,
    ),
  );

  // Exported field_instance: 'taxonomy_term-taxonomy_categories-field_synonym'
  $field_instances['taxonomy_term-taxonomy_categories-field_synonym'] = array(
    'bundle' => 'taxonomy_categories',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Alternative names for this term. Note that this data has no special meaning unless extended with other Drupal extensions.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 2,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => -1,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_synonym',
    'label' => 'Synonyms',
    'required' => FALSE,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'taxonomy_term-tool-field_toolbox_categories'
  $field_instances['taxonomy_term-tool-field_toolbox_categories'] = array(
    'bundle' => 'tool',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 6,
      ),
      'full' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_toolbox_categories',
    'label' => 'Toolbox Categories',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 13,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Alternative names for this term. Note that this data has no special meaning unless extended with other Drupal extensions.');
  t('GUID');
  t('Synonyms');
  t('Toolbox Categories');
  t('Unique global identifier for this term. Usually an URL or URI, but need not be resolvable.');

  return $field_instances;
}
