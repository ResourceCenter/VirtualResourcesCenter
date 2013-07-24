<?php
/**
 * @file
 * vrc_userpoints.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function vrc_userpoints_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'userpoints_category_default_tid';
  $strongarm->value = '0';
  $export['userpoints_category_default_tid'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'userpoints_category_default_vid';
  $strongarm->value = '7';
  $export['userpoints_category_default_vid'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'userpoints_category_profile_display_tid';
  $strongarm->value = array(
    'uncategorized' => 'uncategorized',
    'all' => 'all',
  );
  $export['userpoints_category_profile_display_tid'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'userpoints_display_message';
  $strongarm->value = 1;
  $export['userpoints_display_message'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'userpoints_expireafter_date';
  $strongarm->value = '';
  $export['userpoints_expireafter_date'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'userpoints_expireon_date';
  $strongarm->value = array(
    'month' => '1',
    'day' => '1',
    'year' => '1980',
  );
  $export['userpoints_expireon_date'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'userpoints_expiry_description';
  $strongarm->value = '';
  $export['userpoints_expiry_description'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'userpoints_nc_category';
  $strongarm->value = '0';
  $export['userpoints_nc_category'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'userpoints_nc_category_answer';
  $strongarm->value = '0';
  $export['userpoints_nc_category_answer'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'userpoints_nc_category_question';
  $strongarm->value = '0';
  $export['userpoints_nc_category_question'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'userpoints_nc_comment_category';
  $strongarm->value = '0';
  $export['userpoints_nc_comment_category'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'userpoints_nc_comment_category_answer';
  $strongarm->value = '0';
  $export['userpoints_nc_comment_category_answer'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'userpoints_nc_comment_category_question';
  $strongarm->value = '0';
  $export['userpoints_nc_comment_category_question'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'userpoints_nc_comment_delete_deduct';
  $strongarm->value = 0;
  $export['userpoints_nc_comment_delete_deduct'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'userpoints_nc_comment_delete_deduct_answer';
  $strongarm->value = 0;
  $export['userpoints_nc_comment_delete_deduct_answer'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'userpoints_nc_comment_delete_deduct_question';
  $strongarm->value = 0;
  $export['userpoints_nc_comment_delete_deduct_question'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'userpoints_nc_comment_enabled';
  $strongarm->value = 1;
  $export['userpoints_nc_comment_enabled'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'userpoints_nc_comment_enabled_answer';
  $strongarm->value = 1;
  $export['userpoints_nc_comment_enabled_answer'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'userpoints_nc_comment_enabled_question';
  $strongarm->value = 1;
  $export['userpoints_nc_comment_enabled_question'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'userpoints_nc_comment_ownership_deduct';
  $strongarm->value = 1;
  $export['userpoints_nc_comment_ownership_deduct'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'userpoints_nc_comment_ownership_deduct_answer';
  $strongarm->value = 1;
  $export['userpoints_nc_comment_ownership_deduct_answer'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'userpoints_nc_comment_ownership_deduct_question';
  $strongarm->value = 1;
  $export['userpoints_nc_comment_ownership_deduct_question'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'userpoints_nc_comment_points';
  $strongarm->value = '3';
  $export['userpoints_nc_comment_points'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'userpoints_nc_comment_points_answer';
  $strongarm->value = '1';
  $export['userpoints_nc_comment_points_answer'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'userpoints_nc_comment_points_question';
  $strongarm->value = '1';
  $export['userpoints_nc_comment_points_question'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'userpoints_nc_comment_published_only';
  $strongarm->value = 1;
  $export['userpoints_nc_comment_published_only'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'userpoints_nc_delete_deduct';
  $strongarm->value = 0;
  $export['userpoints_nc_delete_deduct'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'userpoints_nc_delete_deduct_answer';
  $strongarm->value = 0;
  $export['userpoints_nc_delete_deduct_answer'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'userpoints_nc_delete_deduct_question';
  $strongarm->value = 0;
  $export['userpoints_nc_delete_deduct_question'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'userpoints_nc_enabled';
  $strongarm->value = 1;
  $export['userpoints_nc_enabled'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'userpoints_nc_enabled_answer';
  $strongarm->value = 1;
  $export['userpoints_nc_enabled_answer'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'userpoints_nc_enabled_question';
  $strongarm->value = 1;
  $export['userpoints_nc_enabled_question'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'userpoints_nc_ownership_deduct';
  $strongarm->value = 1;
  $export['userpoints_nc_ownership_deduct'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'userpoints_nc_ownership_deduct_answer';
  $strongarm->value = 1;
  $export['userpoints_nc_ownership_deduct_answer'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'userpoints_nc_ownership_deduct_question';
  $strongarm->value = 1;
  $export['userpoints_nc_ownership_deduct_question'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'userpoints_nc_points';
  $strongarm->value = '2';
  $export['userpoints_nc_points'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'userpoints_nc_points_answer';
  $strongarm->value = '10';
  $export['userpoints_nc_points_answer'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'userpoints_nc_points_question';
  $strongarm->value = '2';
  $export['userpoints_nc_points_question'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'userpoints_nc_published_only';
  $strongarm->value = 1;
  $export['userpoints_nc_published_only'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'userpoints_points_moderation';
  $strongarm->value = '0';
  $export['userpoints_points_moderation'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'userpoints_report_displayzero';
  $strongarm->value = '1';
  $export['userpoints_report_displayzero'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'userpoints_report_limit';
  $strongarm->value = '10';
  $export['userpoints_report_limit'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'userpoints_report_usercount';
  $strongarm->value = '30';
  $export['userpoints_report_usercount'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'userpoints_transaction_timestamp';
  $strongarm->value = 1;
  $export['userpoints_transaction_timestamp'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'userpoints_trans_lcpoint';
  $strongarm->value = 'point';
  $export['userpoints_trans_lcpoint'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'userpoints_trans_lcpoints';
  $strongarm->value = 'points';
  $export['userpoints_trans_lcpoints'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'userpoints_trans_ucpoint';
  $strongarm->value = 'Point';
  $export['userpoints_trans_ucpoint'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'userpoints_trans_ucpoints';
  $strongarm->value = 'Points';
  $export['userpoints_trans_ucpoints'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'userpoints_trans_uncat';
  $strongarm->value = 'General';
  $export['userpoints_trans_uncat'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'userpoints_truncate';
  $strongarm->value = '30';
  $export['userpoints_truncate'] = $strongarm;

  return $export;
}
