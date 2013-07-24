<?php
/**
 * @file
 * vrc_answers.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function vrc_answers_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'all_questions';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'all_questions' => 'all_questions',
      ),
    ),
    'views' => array(
      'values' => array(
        'questions_list:all_questions_blank' => 'questions_list:all_questions_blank',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'quicktabs-all_questions' => array(
          'module' => 'quicktabs',
          'delta' => 'all_questions',
          'region' => 'content',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;
  $export['all_questions'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'answer_edit';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'answer-edit/*' => 'answer-edit/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-answer_question-block' => array(
          'module' => 'views',
          'delta' => 'answer_question-block',
          'region' => 'content',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;
  $export['answer_edit'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'question_page';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'question' => 'question',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'quicktabs-answer_listing' => array(
          'module' => 'quicktabs',
          'delta' => 'answer_listing',
          'region' => 'content_aside',
          'weight' => '-10',
        ),
        'vrc_answers-vrc_post_new_answer' => array(
          'module' => 'vrc_answers',
          'delta' => 'vrc_post_new_answer',
          'region' => 'content_aside',
          'weight' => '-9',
        ),
        'notifications_ui-subscriptions' => array(
          'module' => 'notifications_ui',
          'delta' => 'subscriptions',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;
  $export['question_page'] = $context;

  return $export;
}
