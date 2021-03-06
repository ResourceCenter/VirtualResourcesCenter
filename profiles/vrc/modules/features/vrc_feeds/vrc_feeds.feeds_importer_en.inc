<?php
/**
 * @file vrc_feeds.feeds_importer_en.inc
 * English language taxonomy importers
 * Included by vrc_feeds.feeds_importer_default.inc
 */

$feeds_importer = new stdClass();
$feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
$feeds_importer->api_version = 1;
$feeds_importer->id = 'taxonomy_compatibility_en';
$feeds_importer->config = array(
  'name' => 'Taxonomy: Compatibility import - English',
  'description' => 'Feed import of Compatibilities - English',
  'fetcher' => array(
    'plugin_key' => 'FeedsHTTPFetcher',
    'config' => array(
      'auto_detect_feeds' => FALSE,
      'use_pubsubhubbub' => FALSE,
      'designated_hub' => '',
    ),
  ),
  'parser' => array(
    'plugin_key' => 'FeedsCSVParser',
    'config' => array(
      'delimiter' => ',',
      'no_headers' => 0,
    ),
  ),
  'processor' => array(
    'plugin_key' => 'FeedsTermProcessor',
    'config' => array(
      'vocabulary' => 'compatibilities',
      'force_update' => 1,
      'mappings' => array(
        0 => array(
          'source' => 'GUID',
          'target' => 'guid',
          'unique' => 1,
        ),
        1 => array(
          'source' => 'Parent-GUID',
          'target' => 'parentguid',
          'unique' => 0,
        ),
        2 => array(
          'source' => 'EN-term',
          'target' => 'name',
          'unique' => 0,
        ),
        3 => array(
          'source' => 'EN-desc',
          'target' => 'description',
          'unique' => FALSE,
        ),
        4 => array(
          'source' => 'Weight',
          'target' => 'weight',
          'unique' => 0,
        ),
      ),
      'update_existing' => '2',
      'input_format' => 'plain_text',
    ),
  ),
  'content_type' => '',
  'update' => 0,
  'import_period' => '-1',
  'expire_period' => 3600,
  'import_on_create' => 1,
  'process_in_background' => 0,
);
$export['taxonomy_compatibility_en'] = $feeds_importer;

$feeds_importer = new stdClass();
$feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
$feeds_importer->api_version = 1;
$feeds_importer->id = 'taxonomy_tools_categories_en';
$feeds_importer->config = array(
  'name' => 'Taxonomy: Tools Categories import - English',
  'description' => 'Feed import of Tools Categories - English',
  'fetcher' => array(
    'plugin_key' => 'FeedsHTTPFetcher',
    'config' => array(
      'auto_detect_feeds' => 0,
      'use_pubsubhubbub' => 0,
      'designated_hub' => '',
    ),
  ),
  'parser' => array(
    'plugin_key' => 'FeedsCSVParser',
    'config' => array(
      'delimiter' => ',',
      'no_headers' => 0,
    ),
  ),
  'processor' => array(
    'plugin_key' => 'FeedsTermProcessor',
    'config' => array(
      'vocabulary' => 'taxonomy_categories',
      'force_update' => 1,
      'mappings' => array(
        0 => array(
          'source' => 'GUID',
          'target' => 'guid',
          'unique' => 1,
        ),
        1 => array(
          'source' => 'Parent-GUID',
          'target' => 'parentguid',
          'unique' => 0,
        ),
        2 => array(
          'source' => 'EN-term',
          'target' => 'name',
          'unique' => 0,
        ),
        3 => array(
          'source' => 'EN-desc',
          'target' => 'description',
          'unique' => FALSE,
        ),
        4 => array(
          'source' => 'Weight',
          'target' => 'weight',
          'unique' => 0,
        ),
      ),
      'update_existing' => '2',
      'input_format' => 'plain_text',
    ),
  ),
  'content_type' => '',
  'update' => 0,
  'import_period' => '-1',
  'expire_period' => 3600,
  'import_on_create' => 1,
  'process_in_background' => 0,
);
$export['taxonomy_tools_categories_en'] = $feeds_importer;

$feeds_importer = new stdClass();
$feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
$feeds_importer->api_version = 1;
$feeds_importer->id = 'taxonomy_tools_en';
$feeds_importer->config = array(
  'name' => 'Taxonomy: Tools import - English',
  'description' => 'Feed import of Tools - English',
  'fetcher' => array(
    'plugin_key' => 'FeedsHTTPFetcher',
    'config' => array(
      'auto_detect_feeds' => FALSE,
      'use_pubsubhubbub' => FALSE,
      'designated_hub' => '',
    ),
  ),
  'parser' => array(
    'plugin_key' => 'FeedsCSVParser',
    'config' => array(
      'delimiter' => ',',
      'no_headers' => 0,
    ),
  ),
  'processor' => array(
    'plugin_key' => 'FeedsTermProcessor',
    'config' => array(
      'vocabulary' => 'tool',
      'force_update' => 1,
      'mappings' => array(
        0 => array(
          'source' => 'Tool',
          'target' => 'name',
          'unique' => 0,
        ),
        1 => array(
          'source' => 'EN_category_term',
          'target' => 'field_toolbox_categories',
          'unique' => FALSE,
        ),
        2 => array(
          'source' => 'GUID',
          'target' => 'guid',
          'unique' => 1,
        ),
      ),
      'update_existing' => '0',
      'input_format' => 'plain_text',
    ),
  ),
  'content_type' => '',
  'update' => 0,
  'import_period' => '-1',
  'expire_period' => 3600,
  'import_on_create' => 1,
  'process_in_background' => 0,
);
$export['taxonomy_tools_en'] = $feeds_importer;

$feeds_importer = new stdClass();
$feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
$feeds_importer->api_version = 1;
$feeds_importer->id = 'taxonomy_themes_en';
$feeds_importer->config = array(
  'name' => 'Taxonomy: Themes import - English',
  'description' => 'Feed import of Themes - English',
  'fetcher' => array(
    'plugin_key' => 'FeedsHTTPFetcher',
    'config' => array(
      'auto_detect_feeds' => FALSE,
      'use_pubsubhubbub' => FALSE,
      'designated_hub' => '',
    ),
  ),
  'parser' => array(
    'plugin_key' => 'FeedsCSVParser',
    'config' => array(
      'delimiter' => ',',
      'no_headers' => 0,
    ),
  ),
  'processor' => array(
    'plugin_key' => 'FeedsTermProcessor',
    'config' => array(
      'vocabulary' => 'themes',
      'force_update' => 1,
      'mappings' => array(
        0 => array(
          'source' => 'GUID',
          'target' => 'guid',
          'unique' => 1,
        ),
        1 => array(
          'source' => 'Parent-GUID',
          'target' => 'parentguid',
          'unique' => 0,
        ),
        2 => array(
          'source' => 'Weight',
          'target' => 'weight',
          'unique' => 0,
        ),
        3 => array(
          'source' => 'EN_term',
          'target' => 'name',
          'unique' => FALSE,
        ),
        4 => array(
          'source' => 'EN_desc',
          'target' => 'description',
          'unique' => FALSE,
        ),
      ),
      'update_existing' => '2',
      'input_format' => 'plain_text',
    ),
  ),
  'content_type' => '',
  'update' => 0,
  'import_period' => '-1',
  'expire_period' => 3600,
  'import_on_create' => 1,
  'process_in_background' => 0,
);
$export['taxonomy_themes_en'] = $feeds_importer;