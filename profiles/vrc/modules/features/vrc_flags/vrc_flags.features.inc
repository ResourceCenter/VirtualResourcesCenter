<?php
/**
 * @file
 * vrc_flags.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function vrc_flags_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function vrc_flags_views_api() {
  return array("api" => "3.0");
}

/**
 * Implements hook_flag_default_flags().
 */
function vrc_flags_flag_default_flags() {
  $flags = array();
  // Exported flag: "Comment Abuse".
  $flags['abuse_comment'] = array(
    'content_type' => 'comment',
    'title' => 'Comment Abuse',
    'global' => 0,
    'types' => array(
      0 => 'comment_node_article',
      1 => 'comment_node_page',
      2 => 'comment_node_documentation',
    ),
    'flag_short' => 'Flag as offensive',
    'flag_long' => 'Flag this content as offensive.',
    'flag_message' => '',
    'unflag_short' => 'Flag as non-offensive',
    'unflag_long' => 'Flag this content as non-offensive.',
    'unflag_message' => '',
    'unflag_denied_text' => 'This comment has been flagged for review by an editor',
    'link_type' => 'confirm',
    'roles' => array(
      'flag' => array(
        0 => 2,
        1 => 5,
        2 => 4,
        3 => 3,
        4 => 6,
      ),
      'unflag' => array(
        0 => 2,
        1 => 5,
        2 => 4,
        3 => 3,
        4 => 6,
      ),
    ),
    'weight' => 0,
    'show_on_form' => 0,
    'access_author' => '',
    'show_on_comment' => 1,
    'flag_confirmation' => 'Are you sure you want to flag this content as offensive?',
    'unflag_confirmation' => 'Are you sure you want to flag this content as non-offensive?',
    'module' => 'vrc_flags',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 2,
  );
  // Exported flag: "Node Abuse".
  $flags['abuse_node'] = array(
    'content_type' => 'node',
    'title' => 'Node Abuse',
    'global' => 0,
    'types' => array(
      0 => 'answer',
      1 => 'article',
      2 => 'question',
      3 => 'quiz',
    ),
    'flag_short' => 'Flag as offensive',
    'flag_long' => 'Flag this content as offensive.',
    'flag_message' => '',
    'unflag_short' => 'Flag as non-offensive',
    'unflag_long' => 'Flag this content as non-offensive.',
    'unflag_message' => '',
    'unflag_denied_text' => 'This flagged content will be reviewed by an editor.',
    'link_type' => 'confirm',
    'roles' => array(
      'flag' => array(
        0 => 2,
      ),
      'unflag' => array(
        0 => 2,
      ),
    ),
    'weight' => 0,
    'show_on_form' => 0,
    'access_author' => '',
    'show_on_page' => 1,
    'show_on_teaser' => 0,
    'show_contextual_link' => 0,
    'i18n' => 0,
    'flag_confirmation' => 'Are you sure you want to flag this content as offensive?',
    'unflag_confirmation' => 'Are you sure you want to flag this content as non-offensive?',
    'module' => 'vrc_flags',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 2,
  );
  // Exported flag: "User Abuse".
  $flags['abuse_user'] = array(
    'content_type' => 'user',
    'title' => 'User Abuse',
    'global' => 0,
    'types' => array(),
    'flag_short' => 'User Abuse',
    'flag_long' => 'Report User',
    'flag_message' => 'Report this user as offensive.',
    'unflag_short' => 'Remove Report',
    'unflag_long' => 'Remove your report about this user.',
    'unflag_message' => '',
    'unflag_denied_text' => '',
    'link_type' => 'confirm',
    'roles' => array(
      'flag' => array(
        0 => 2,
        1 => 5,
        2 => 4,
        3 => 3,
        4 => 6,
      ),
      'unflag' => array(
        0 => 2,
        1 => 5,
        2 => 4,
        3 => 3,
        4 => 6,
      ),
    ),
    'weight' => 0,
    'show_on_entity' => FALSE,
    'show_on_form' => 0,
    'access_author' => '',
    'show_on_profile' => 1,
    'access_uid' => '',
    'flag_confirmation' => 'Are you sure you want to report this user as offensive?',
    'unflag_confirmation' => 'Are you sure you want to remove your report of this user?',
    'module' => 'vrc_flags',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 2,
  );
  // Exported flag: "Bookmarks".
  $flags['bookmarks'] = array(
    'content_type' => 'node',
    'title' => 'Bookmarks',
    'global' => 0,
    'types' => array(
      0 => 'article',
    ),
    'flag_short' => 'Bookmark this',
    'flag_long' => 'Add this post to your bookmarks',
    'flag_message' => 'This post has been added to your bookmarks',
    'unflag_short' => 'Unbookmark this',
    'unflag_long' => 'Remove this post from your bookmarks',
    'unflag_message' => 'This post has been removed from your bookmarks',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'roles' => array(
      'flag' => array(
        0 => 2,
        1 => 5,
        2 => 4,
        3 => 3,
        4 => 6,
      ),
      'unflag' => array(
        0 => 2,
        1 => 5,
        2 => 4,
        3 => 3,
        4 => 6,
      ),
    ),
    'weight' => 0,
    'show_on_form' => 1,
    'access_author' => '',
    'show_on_page' => 1,
    'show_on_teaser' => 1,
    'show_contextual_link' => 0,
    'i18n' => 0,
    'module' => 'vrc_flags',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 2,
  );
  // Exported flag: "Comment Abuse".
  $flags['flag_comment'] = array(
    'content_type' => 'comment',
    'title' => 'Comment Abuse',
    'global' => 0,
    'types' => array(
      0 => 'comment_node_article',
      1 => 'comment_node_page',
      2 => 'comment_node_documentation',
    ),
    'flag_short' => 'Flag as offensive',
    'flag_long' => 'Flag this content as offensive.',
    'flag_message' => '',
    'unflag_short' => 'Flag as non-offensive',
    'unflag_long' => 'Flag this content as non-offensive.',
    'unflag_message' => '',
    'unflag_denied_text' => 'This comment has been flagged for review by an editor',
    'link_type' => 'confirm',
    'roles' => array(
      'flag' => array(
        0 => 2,
        1 => 5,
        2 => 4,
        3 => 3,
        4 => 6,
      ),
      'unflag' => array(
        0 => 2,
        1 => 5,
        2 => 4,
        3 => 3,
        4 => 6,
      ),
    ),
    'weight' => 0,
    'show_on_form' => 0,
    'access_author' => '',
    'show_on_comment' => 1,
    'flag_confirmation' => 'Are you sure you want to flag this content as offensive?',
    'unflag_confirmation' => 'Are you sure you want to flag this content as non-offensive?',
    'module' => 'vrc_flags',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 2,
  );
  return $flags;

}
