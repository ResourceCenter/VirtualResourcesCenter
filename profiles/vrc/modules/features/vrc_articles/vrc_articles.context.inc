<?php
/**
 * @file
 * vrc_articles.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function vrc_articles_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'article';
  $context->description = '';
  $context->tag = '--CONTENT TYPE';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'article' => 'article',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
  );
  $context->reactions = array();
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('--CONTENT TYPE');
  $export['article'] = $context;

  return $export;
}
