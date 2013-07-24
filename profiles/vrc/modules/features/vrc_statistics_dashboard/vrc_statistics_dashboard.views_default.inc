<?php
/**
 * @file
 * vrc_statistics_dashboard.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function vrc_statistics_dashboard_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'statistics_dashboard_user';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'users';
  $view->human_name = 'statistics_dashboard_user';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Active Users';
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access user profiles';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Relationship: User: The user's latest messages */
  $handler->display->display_options['relationships']['latest_message_mid']['id'] = 'latest_message_mid';
  $handler->display->display_options['relationships']['latest_message_mid']['table'] = 'users';
  $handler->display->display_options['relationships']['latest_message_mid']['field'] = 'latest_message_mid';
  $handler->display->display_options['relationships']['latest_message_mid']['required'] = TRUE;
  $handler->display->display_options['relationships']['latest_message_mid']['message_types'] = array(
    'user_add_question' => 'user_add_question',
    'user_add_answer' => 'user_add_answer',
    'example_create_comment' => 0,
    'example_create_node' => 0,
    'example_user_register' => 0,
  );
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  /* Field: Message: User Answer count */
  $handler->display->display_options['fields']['field_user_answer_count']['id'] = 'field_user_answer_count';
  $handler->display->display_options['fields']['field_user_answer_count']['table'] = 'field_data_field_user_answer_count';
  $handler->display->display_options['fields']['field_user_answer_count']['field'] = 'field_user_answer_count';
  $handler->display->display_options['fields']['field_user_answer_count']['relationship'] = 'latest_message_mid';
  $handler->display->display_options['fields']['field_user_answer_count']['label'] = 'Answer count';
  $handler->display->display_options['fields']['field_user_answer_count']['empty'] = 'n/a';
  $handler->display->display_options['fields']['field_user_answer_count']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Field: Message: User Question Count */
  $handler->display->display_options['fields']['field_user_question_count']['id'] = 'field_user_question_count';
  $handler->display->display_options['fields']['field_user_question_count']['table'] = 'field_data_field_user_question_count';
  $handler->display->display_options['fields']['field_user_question_count']['field'] = 'field_user_question_count';
  $handler->display->display_options['fields']['field_user_question_count']['relationship'] = 'latest_message_mid';
  $handler->display->display_options['fields']['field_user_question_count']['label'] = 'Question Count';
  $handler->display->display_options['fields']['field_user_question_count']['empty'] = 'n/a';
  $handler->display->display_options['fields']['field_user_question_count']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Field: Message: Timestamp */
  $handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['table'] = 'message';
  $handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['relationship'] = 'latest_message_mid';
  $handler->display->display_options['fields']['timestamp']['label'] = 'Last Activity';
  $handler->display->display_options['fields']['timestamp']['date_format'] = 'time ago';

  /* Display: acitve_users */
  $handler = $view->new_display('block', 'acitve_users', 'block');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_always'] = TRUE;
  $handler->display->display_options['defaults']['use_more_text'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'show more';
  $handler->display->display_options['defaults']['link_display'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'name' => 'name',
    'field_user_answer_count' => 'field_user_answer_count',
    'field_user_question_count' => 'field_user_question_count',
    'timestamp' => 'timestamp',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_user_answer_count' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_user_question_count' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'timestamp' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $translatables['statistics_dashboard_user'] = array(
    t('Master'),
    t('Active Users'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('Latest Message'),
    t('Name'),
    t('Answer count'),
    t('n/a'),
    t('Question Count'),
    t('Last Activity'),
    t('acitve_users'),
    t('show more'),
  );
  $export['statistics_dashboard_user'] = $view;

  return $export;
}
