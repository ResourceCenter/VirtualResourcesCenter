<?php
/**
 * @file
 * vrc_documentation.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function vrc_documentation_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'documentation';
  $context->description = 'Display options for Documentation';
  $context->tag = '--CONTENT TYPE';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'documentation' => 'documentation',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-tools_related_questions-block' => array(
          'module' => 'views',
          'delta' => 'tools_related_questions-block',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'views-tools_related_content-block' => array(
          'module' => 'views',
          'delta' => 'tools_related_content-block',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('--CONTENT TYPE');
  t('Display options for Documentation');
  $export['documentation'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'documentation_page';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'documentation' => 'documentation',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'vrc_related_content-tool_available_res' => array(
          'module' => 'vrc_related_content',
          'delta' => 'tool_available_res',
          'region' => 'content_aside',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;
  $export['documentation_page'] = $context;

  return $export;
}
