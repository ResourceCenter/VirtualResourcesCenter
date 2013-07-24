<?php
/**
 * @file
 * vrc_voting.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function vrc_voting_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'rate_widgets';
  $strongarm->value = array(
    1 => (object) array(
      'name' => 'plusminus',
      'tag' => 'vote',
      'title' => 'PlusMinus',
      'node_types' => array(),
      'comment_types' => array(),
      'options' => array(
        0 => array(
          0 => '1',
          1 => '+',
        ),
        1 => array(
          0 => '-1',
          1 => '-',
        ),
      ),
      'template' => 'custom',
      'node_display' => '1',
      'teaser_display' => FALSE,
      'comment_display' => '1',
      'node_display_mode' => '1',
      'teaser_display_mode' => '1',
      'comment_display_mode' => '1',
      'roles' => array(
        3 => '3',
        2 => '2',
        4 => '4',
        5 => '5',
        1 => 0,
        6 => 0,
      ),
      'allow_voting_by_author' => 1,
      'noperm_behaviour' => '3',
      'displayed' => '1',
      'displayed_just_voted' => '1',
      'description' => '',
      'description_in_compact' => TRUE,
      'delete_vote_on_second_click' => NULL,
      'use_source_translation' => TRUE,
      'value_type' => 'points',
      'translate' => TRUE,
    ),
    2 => (object) array(
      'name' => 'post_useful',
      'tag' => 'vote4useful',
      'title' => 'PostUseful',
      'node_types' => array(
        0 => 'answer',
      ),
      'comment_types' => array(),
      'options' => array(
        0 => array(
          0 => '1',
          1 => 'yes',
        ),
        1 => array(
          0 => '2',
          1 => 'no',
        ),
      ),
      'template' => 'yesno',
      'node_display' => '2',
      'teaser_display' => TRUE,
      'comment_display' => '2',
      'node_display_mode' => '1',
      'teaser_display_mode' => '1',
      'comment_display_mode' => '1',
      'roles' => array(
        2 => '2',
        3 => 0,
        1 => 0,
        4 => 0,
        5 => 0,
        6 => 0,
      ),
      'allow_voting_by_author' => 1,
      'noperm_behaviour' => '2',
      'displayed' => '1',
      'displayed_just_voted' => '2',
      'description' => 'Was this post useful to you?',
      'description_in_compact' => TRUE,
      'delete_vote_on_second_click' => '0',
      'use_source_translation' => TRUE,
      'value_type' => 'option',
      'theme' => 'rate_template_yesno',
      'css' => 'profiles/vrc/modules/contrib/rate/templates/yesno/yesno.css',
      'translate' => TRUE,
    ),
    3 => (object) array(
      'name' => 'post_interesting',
      'tag' => 'post_interesting',
      'title' => 'PostInteresting',
      'node_types' => array(
        0 => 'article',
        1 => 'documentation',
        2 => 'question',
      ),
      'comment_types' => array(),
      'options' => array(
        0 => array(
          0 => '1',
          1 => 'Yes',
        ),
        1 => array(
          0 => '-1',
          1 => 'No',
        ),
      ),
      'template' => 'post_interesting',
      'node_display' => '2',
      'teaser_display' => FALSE,
      'comment_display' => '2',
      'node_display_mode' => '1',
      'teaser_display_mode' => '1',
      'comment_display_mode' => '1',
      'roles' => array(
        3 => '3',
        2 => '2',
        4 => '4',
        5 => '5',
        1 => 0,
        6 => 0,
      ),
      'allow_voting_by_author' => 1,
      'noperm_behaviour' => '2',
      'displayed' => '2',
      'displayed_just_voted' => '2',
      'description' => 'Was this post interesting? ',
      'description_in_compact' => TRUE,
      'delete_vote_on_second_click' => '0',
      'use_source_translation' => TRUE,
      'value_type' => 'points',
      'theme' => 'rate_post_interesting',
      'css' => 'profiles/vrc/modules/features/vrc_voting/templates/post_interesting/post-interesting.css',
      'js' => 'profiles/vrc/modules/features/vrc_voting/templates/post_interesting/post-interesting.js',
      'translate' => TRUE,
    ),
    5 => (object) array(
      'name' => 'answer_useful',
      'tag' => 'vote',
      'title' => 'answer_useful',
      'node_types' => array(
        0 => 'answer',
      ),
      'comment_types' => array(),
      'options' => array(
        0 => array(
          0 => '1',
          1 => 'Yes',
        ),
        1 => array(
          0 => '-1',
          1 => 'No',
        ),
      ),
      'template' => 'custom',
      'node_display' => '0',
      'teaser_display' => FALSE,
      'comment_display' => '0',
      'node_display_mode' => '1',
      'teaser_display_mode' => '1',
      'comment_display_mode' => '1',
      'roles' => array(
        3 => '3',
        2 => '2',
        4 => '4',
        5 => '5',
        1 => 0,
        6 => 0,
      ),
      'allow_voting_by_author' => 1,
      'noperm_behaviour' => '1',
      'displayed' => '1',
      'displayed_just_voted' => '2',
      'description' => 'Was this post useful to you?',
      'description_in_compact' => TRUE,
      'delete_vote_on_second_click' => '0',
      'use_source_translation' => TRUE,
      'value_type' => 'points',
      'translate' => FALSE,
    ),
  );
  $export['rate_widgets'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'votingapi_anonymous_window';
  $strongarm->value = '86400';
  $export['votingapi_anonymous_window'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'votingapi_calculation_schedule';
  $strongarm->value = 'immediate';
  $export['votingapi_calculation_schedule'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'votingapi_last_cron';
  $strongarm->value = 1339528570;
  $export['votingapi_last_cron'] = $strongarm;

  return $export;
}
