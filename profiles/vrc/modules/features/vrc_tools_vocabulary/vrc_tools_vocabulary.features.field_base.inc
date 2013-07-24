<?php
/**
 * @file
 * vrc_tools_vocabulary.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function vrc_tools_vocabulary_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_guid'
  $field_bases['field_guid'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
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
    'locked' => 1,
    'module' => 'text',
    'settings' => array(
      'max_length' => 255,
    ),
    'translatable' => 1,
    'type' => 'text',
  );

  // Exported field_base: 'field_synonym'
  $field_bases['field_synonym'] = array(
    'active' => 1,
    'cardinality' => 0,
    'deleted' => 0,
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
    'locked' => 1,
    'module' => 'text',
    'settings' => array(
      'max_length' => 255,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  return $field_bases;
}
