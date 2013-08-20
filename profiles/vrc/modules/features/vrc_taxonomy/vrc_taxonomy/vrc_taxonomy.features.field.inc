<?php
/**
 * @file
 * vrc_taxonomy.features.field.inc
 */

/**
 * Implements hook_field_default_fields().
 */
function vrc_taxonomy_field_default_fields() {
  $fields = array();

  // Exported field: 'taxonomy_term-taxonomy_categories-field_guid'.
  $fields['taxonomy_term-taxonomy_categories-field_guid'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_type' => 'taxonomy_term',
      'entity_types' => array(),
      'field_name' => 'field_guid',
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'locked' => '1',
      'module' => 'text',
      'settings' => array(
        'max_length' => 255,
      ),
      'translatable' => '1',
      'type' => 'text',
    ),
    'field_instance' => array(
      'bundle' => 'taxonomy_categories',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => 'Unique global identifier for this term. Usually an URL or URI, but need not be resolvable.',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => '0',
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
        'weight' => '0',
      ),
    ),
  );

  // Exported field: 'taxonomy_term-taxonomy_categories-field_synonym'.
  $fields['taxonomy_term-taxonomy_categories-field_synonym'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '0',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_synonym',
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'locked' => '1',
      'module' => 'text',
      'settings' => array(
        'max_length' => 255,
      ),
      'translatable' => '0',
      'type' => 'text',
    ),
    'field_instance' => array(
      'bundle' => 'taxonomy_categories',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => 'Alternative names for this term. Note that this data has no special meaning unless extended with other Drupal extensions.',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '2',
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
        'weight' => '2',
      ),
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Alternative names for this term. Note that this data has no special meaning unless extended with other Drupal extensions.');
  t('GUID');
  t('Synonyms');
  t('Unique global identifier for this term. Usually an URL or URI, but need not be resolvable.');

  return $fields;
}
