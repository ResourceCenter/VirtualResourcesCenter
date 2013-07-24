<?php
/**
 * @file
 * vrc_search.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function vrc_search_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'search_page';
  $context->description = '';
  $context->tag = 'Search';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'site_search' => 'site_search',
        'site_search:page' => 'site_search:page',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-site_search-top_article' => array(
          'module' => 'views',
          'delta' => 'site_search-top_article',
          'region' => 'secondary_content',
          'weight' => '-10',
        ),
        'views-site_search-top_tool' => array(
          'module' => 'views',
          'delta' => 'site_search-top_tool',
          'region' => 'secondary_content',
          'weight' => '-10',
        ),
        'views-site_search-top_doc' => array(
          'module' => 'views',
          'delta' => 'site_search-top_doc',
          'region' => 'secondary_content',
          'weight' => '-10',
        ),
        'views-site_search-top_question' => array(
          'module' => 'views',
          'delta' => 'site_search-top_question',
          'region' => 'secondary_content',
          'weight' => '-10',
        ),
        'views--exp-site_search-page' => array(
          'module' => 'views',
          'delta' => '-exp-site_search-page',
          'region' => 'highlight',
          'weight' => '-10',
        ),
        'facetapi-QNJXmpAQRe6NcqGalVOSZPTIh0bVigI1' => array(
          'module' => 'facetapi',
          'delta' => 'QNJXmpAQRe6NcqGalVOSZPTIh0bVigI1',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'facetapi-YPUrUZPurfHll2g4bKD2iwMq4jLoCOII' => array(
          'module' => 'facetapi',
          'delta' => 'YPUrUZPurfHll2g4bKD2iwMq4jLoCOII',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'facetapi-WvwQWHCUzK0jBQ1IKdgzHcYYSyCbbNI3' => array(
          'module' => 'facetapi',
          'delta' => 'WvwQWHCUzK0jBQ1IKdgzHcYYSyCbbNI3',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'facetapi-XqrzqD3eOtzsfIGOhYXmmzYCcQ8uR7pc' => array(
          'module' => 'facetapi',
          'delta' => 'XqrzqD3eOtzsfIGOhYXmmzYCcQ8uR7pc',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'facetapi-vQqy8fZOg9t5WrwVZ3ygzYmy0szWptif' => array(
          'module' => 'facetapi',
          'delta' => 'vQqy8fZOg9t5WrwVZ3ygzYmy0szWptif',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Search');
  $export['search_page'] = $context;

  return $export;
}
