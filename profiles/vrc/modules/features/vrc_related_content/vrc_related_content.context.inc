<?php
/**
 * @file
 * vrc_related_content.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function vrc_related_content_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'related_content';
  $context->description = 'Add related content blocks to Documentation, Articles, Questions';
  $context->tag = 'Blocks';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'article' => 'article',
        'documentation' => 'documentation',
        'question' => 'question',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-vrc_related_content-block' => array(
          'module' => 'views',
          'delta' => 'vrc_related_content-block',
          'region' => 'sidebar_first',
          'weight' => '-9',
        ),
        'views-vrc_related_content-block_1' => array(
          'module' => 'views',
          'delta' => 'vrc_related_content-block_1',
          'region' => 'sidebar_first',
          'weight' => '-8',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Add related content blocks to Documentation, Articles, Questions');
  t('Blocks');
  $export['related_content'] = $context;

  return $export;
}
