<?php
/**
 * @file
 * vrc_feeds.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function vrc_feeds_feeds_importer_default() {
  $export = array();

   $feeds_importer = new stdClass();
  $feeds_importer->disabled = TRUE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'content_documentation_from_file';
  $feeds_importer->config = array(
    'name' => 'Content: Documentation from file - language neutral',
    'description' => 'Feed import of Documentation from file - language neutral',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'direct' => FALSE,
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
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'content_type' => 'documentation',
        'expire' => '-1',
        'author' => '1',
        'mappings' => array(
          0 => array(
            'source' => 'title',
            'target' => 'title',
            'unique' => 0,
          ),
          1 => array(
            'source' => 'status',
            'target' => 'status',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'comment',
            'target' => 'comment',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'promote',
            'target' => 'promote',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'sticky',
            'target' => 'sticky',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'language',
            'target' => 'language',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'Sponsoring-org',
            'target' => 'field_sponsoring_organization:title',
            'unique' => FALSE,
          ),
          7 => array(
            'source' => 'Sponsoring-org-url',
            'target' => 'field_sponsoring_organization:url',
            'unique' => FALSE,
          ),
          8 => array(
            'source' => 'Website-title',
            'target' => 'field_website:title',
            'unique' => FALSE,
          ),
          9 => array(
            'source' => 'Website-url',
            'target' => 'field_website:url',
            'unique' => FALSE,
          ),
          10 => array(
            'source' => 'Description',
            'target' => 'body',
            'unique' => FALSE,
          ),
          11 => array(
            'source' => 'Compatibilities',
            'target' => 'field_compatibilities',
            'unique' => FALSE,
          ),
          12 => array(
            'source' => 'Theme',
            'target' => 'field_theme',
            'unique' => FALSE,
          ),
          13 => array(
            'source' => 'Tool',
            'target' => 'field_tool',
            'unique' => FALSE,
          ),
          14 => array(
            'source' => 'Toolbox Categories',
            'target' => 'field_toolbox_categories',
            'unique' => FALSE,
          ),
          15 => array(
            'source' => 'ContentGUID',
            'target' => 'field_content_guid',
            'unique' => FALSE,
          ),
          16 => array(
            'source' => 'GUID',
            'target' => 'guid',
            'unique' => 1,
          ),
        ),
        'update_existing' => '1',
        'input_format' => 'filtered_html',
        'authorize' => 0,
        'skip_hash_check' => 0,
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['content_documentation_from_file'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = TRUE; /* Edit this to true to make a default feeds_importer disabled initially */
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
        'force_update' => 0,
        'mappings' => array(
          0 => array(
            'source' => 'Parent-GUID',
            'target' => 'parentguid',
            'unique' => 0,
          ),
          1 => array(
            'source' => 'EN-term',
            'target' => 'name',
            'unique' => 0,
          ),
          2 => array(
            'source' => 'EN-desc',
            'target' => 'description',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'Weight',
            'target' => 'weight',
            'unique' => 0,
          ),
          4 => array(
            'source' => 'GUID',
            'target' => 'guid',
            'unique' => 1,
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

  return $export;
}
