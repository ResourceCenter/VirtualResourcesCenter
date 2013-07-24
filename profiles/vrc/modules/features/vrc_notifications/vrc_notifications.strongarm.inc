<?php
/**
 * @file
 * vrc_notifications.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function vrc_notifications_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'messaging_default_method';
  $strongarm->value = 'htmlmail';
  $export['messaging_default_method'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'messaging_mail_default_from';
  $strongarm->value = 'admin@example.com';
  $export['messaging_mail_default_from'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'messaging_mail_returnpath';
  $strongarm->value = 'admin@example.com';
  $export['messaging_mail_returnpath'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'messaging_mail_sender_format';
  $strongarm->value = '[name] <[mail]>';
  $export['messaging_mail_sender_format'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'messaging_method_enabled';
  $strongarm->value = array(
    'htmlmail' => 'htmlmail',
    'mail' => 'mail',
    'simple' => 'simple',
  );
  $export['messaging_method_enabled'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'messaging_method_htmlmail';
  $strongarm->value = array(
    'name' => 'HTML mail',
    'queue' => 0,
    'log' => 0,
  );
  $export['messaging_method_htmlmail'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'messaging_method_mail';
  $strongarm->value = array(
    'name' => 'Mail',
    'queue' => 0,
    'log' => 0,
  );
  $export['messaging_method_mail'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'messaging_method_simple';
  $strongarm->value = array(
    'name' => 'Web',
    'queue' => 0,
    'log' => 0,
  );
  $export['messaging_method_simple'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'notifications_content_per_type';
  $strongarm->value = '0';
  $export['notifications_content_per_type'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'notifications_content_type';
  $strongarm->value = array(
    'answer' => 0,
    'article' => 0,
    'page' => 0,
    'documentation' => 0,
    'long_answer' => 0,
    'matching' => 0,
    'multichoice' => 0,
    'question' => 0,
    'quiz' => 0,
    'quiz_directions' => 0,
    'scale' => 0,
    'short_answer' => 0,
    'truefalse' => 0,
  );
  $export['notifications_content_type'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'notifications_option_subscribe_links';
  $strongarm->value = '1';
  $export['notifications_option_subscribe_links'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'notifications_option_subscription_types_content_thread';
  $strongarm->value = array(
    'subscriptions_block' => 0,
    'node_links' => 0,
    'teaser_links' => 0,
    'enabled' => 0,
  );
  $export['notifications_option_subscription_types_content_thread'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'notifications_option_subscription_types_content_type';
  $strongarm->value = array(
    'subscriptions_block' => 0,
    'node_links' => 0,
    'teaser_links' => 0,
    'enabled' => 0,
  );
  $export['notifications_option_subscription_types_content_type'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'notifications_option_subscription_types_content_type_term';
  $strongarm->value = array(
    'subscriptions_block' => 0,
    'enabled' => 0,
  );
  $export['notifications_option_subscription_types_content_type_term'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'notifications_option_subscription_types_taxonomy_term';
  $strongarm->value = array(
    'subscriptions_block' => 0,
    'enabled' => 0,
  );
  $export['notifications_option_subscription_types_taxonomy_term'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'notifications_option_subscription_types_taxonomy_term_multiple';
  $strongarm->value = array(
    'subscriptions_block' => 0,
    'enabled' => 0,
  );
  $export['notifications_option_subscription_types_taxonomy_term_multiple'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'notifications_option_subscription_types_taxonomy_vocabulary';
  $strongarm->value = array(
    'subscriptions_block' => 0,
    'enabled' => 0,
  );
  $export['notifications_option_subscription_types_taxonomy_vocabulary'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'notifications_option_subscription_types_vrc_question';
  $strongarm->value = array(
    'enabled' => 1,
    'subscriptions_block' => 1,
    'node_links' => 0,
    'teaser_links' => 1,
  );
  $export['notifications_option_subscription_types_vrc_question'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'notifications_option_subscription_types_vrc_tag';
  $strongarm->value = array(
    'enabled' => 1,
    'subscriptions_block' => 1,
  );
  $export['notifications_option_subscription_types_vrc_tag'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'notifications_option_unsubscribe_links';
  $strongarm->value = '1';
  $export['notifications_option_unsubscribe_links'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'notifications_sendself';
  $strongarm->value = 0;
  $export['notifications_sendself'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'notifications_tags_showsubscribed';
  $strongarm->value = 0;
  $export['notifications_tags_showsubscribed'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'notifications_tags_vocabularies';
  $strongarm->value = array(
    'taxonomy_categories' => 'taxonomy_categories',
    'compatibilities' => 'compatibilities',
    'question_type' => 'question_type',
    'release_type' => 'release_type',
    'themes' => 'themes',
    'tool' => 'tool',
    'userpoints' => 0,
  );
  $export['notifications_tags_vocabularies'] = $strongarm;

  return $export;
}
