<?php

/**
 * Implements hook_views_data_alter()
 */
function vrc_views_views_data_alter(&$data) {
  $data['users']['latest_message_mid'] = array(
    'title' => t('The user\'s latest messages'),
    'real field' => 'uid',
    'help' => t('Relate users to the latest messages'),
    'relationship' => array(
      'handler' => 'vrc_views_handler_relationship_user_latest_message',
      'label' => t('Latest Message'),
      'base' => 'message',
    ),
  );
}
