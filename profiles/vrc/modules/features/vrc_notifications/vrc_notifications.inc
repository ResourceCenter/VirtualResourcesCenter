<?php

/*  OBJECT TYPES
 * -------------------------------------------------------------------------- */
class VRC_Notifications_Node_Question extends Notifications_Node {
  public $type = 'question';
}

/*  EVENT
 * -------------------------------------------------------------------------- */
class VRC_Notifications_Question_Answer_Insert_Event extends Notifications_Node_Event {
  public function get_name() {
    return t('New answer for question [node:title]');
  }
}

class VRC_Notifications_Question_Answer_Update_Event extends Notifications_Node_Event {
  public function get_name() {
    return t('Answer update for question [node:title]');
  }
}

class VRC_Notifications_Question_Answer_Best_Event extends Notifications_Node_Event {
  public function get_name() {
    return t('Best answer selected for question [node:title]');
  }
}

class VRC_Notifications_Tag_Question_Insert_Event extends Notifications_Node_Event {
  public function get_name() {
    return t('New question [node:title]');
  }
}

class VRC_Notifications_Tag_Article_Insert_Event extends Notifications_Node_Event {
  public function get_name() {
    return t('New article [node:title]');
  }
}

/*  TEMPLATES
 * -------------------------------------------------------------------------- */

/**
 * Custom messaging template for the new answer event
 *
 * Doesn't support digest yet.
 *
 * @see: Notifications_Node_Event_Template
 * @see: Notifications_Message_Template
 * @see: Messaging_Message_Template
 */
class VRC_Notifications_Question_Answer_Template extends Notifications_Node_Insert_Template {
  public function get_subject($options) {
    return '';
  }
  function default_text($type, $options) {
    switch ($type) {
      case 'subject':
        return array(
          '#tokens' => TRUE,
          '#markup' => $this->get_subject($options),
        );
      case 'content':
        return array(
          '#type' => 'messaging_template_text',
          '#tokens' => TRUE,
          'header' => $this->get_subject($options),
          'header_break' => array('#type' => 'messaging_break'),
          'question_header' => t('Question:', array(), $options),
          'question' => t('[question:body]', array(), $options),
          'answer_header' => t('Answer:', array(), $options),
          'answer' => '[node:field_answer_body]',
          'more' => array(
            '#type' => 'messaging_link',
            '#text' => t('Read more', array(), $options),
            '#url' => '[question:url]', // TODO: better be the url alias.
          ),
        );
      default:
        return parent::default_text($type, $options);
    }
  }
}

class VRC_Notifications_Question_Answer_Insert_Template extends VRC_Notifications_Question_Answer_Template {
  public function get_title() {
    return t('Template for new answer');
  }
  public function get_subject($options) {
    return t('New answer added to question: [question:title]', array(), $options);
  }
}

class VRC_Notifications_Question_Answer_Update_Template extends VRC_Notifications_Question_Answer_Template {
  public function get_title() {
    return t('Template for updated answer');
  }
  public function get_subject($options) {
    return t('An answer updated for question: [question:title]', array(), $options);
  }
}

class VRC_Notifications_Question_Answer_Best_Template extends VRC_Notifications_Question_Answer_Template {
  public function get_title() {
    return t('Template for best answer selected');
  }
  public function get_subject($options) {
    return t('A best answer is selected for question: [question:title]', array(), $options);
  }
}

/**
 * .
 *
 * Doesn't support digest yet.
 */
class VRC_Notifications_Tag_Question_Insert_Template extends Notifications_Node_Insert_Template {
  public function get_title() {
    return t('Template for a new question posted');
  }
  function default_text($type, $options) {
    switch ($type) {
      case 'subject':
        return array(
          '#tokens' => TRUE,
          '#markup' => t('A new question is posted: [node:title]', array(), $options),
        );
      case 'content':
        return array(
          '#type' => 'messaging_template_text',
          '#tokens' => TRUE,
          'header' => t('A new question is posted: [node:title]', array(), $options),
          'header_break' => array('#type' => 'messaging_break'),
          'question_header' => t('Question:', array(), $options),
          'question' => t('[node:body]', array(), $options),
          'more' => array(
            '#type' => 'messaging_link',
            '#text' => t('Read more', array(), $options),
            '#url' => '[node:url]', // TODO: better be the url alias.
          ),
        );
      default:
        return parent::default_text($type, $options);
    }
  }
}

/**
 * .
 *
 * Doesn't support digest yet.
 */
class VRC_Notifications_Tag_Article_Insert_Template extends Notifications_Node_Insert_Template {
  public function get_title() {
    return t('Template for a new article posted');
  }
  function default_text($type, $options) {
    switch ($type) {
      case 'subject':
        return array(
          '#tokens' => TRUE,
          '#markup' => t('A new article is posted: [node:title]', array(), $options),
        );
      case 'content':
        return array(
          '#type' => 'messaging_template_text',
          '#tokens' => TRUE,
          'header' => t('A new article is posted: [node:title]', array(), $options),
          'header_break' => array('#type' => 'messaging_break'),
          'question_header' => t('Article:', array(), $options),
          'question' => t('[node:body]', array(), $options),
          'more' => array(
            '#type' => 'messaging_link',
            '#text' => t('Read more', array(), $options),
            '#url' => '[node:url]', // TODO: better be the url alias.
          ),
        );
      default:
        return parent::default_text($type, $options);
    }
  }
}

/*  SUBSCRIPTION
 * -------------------------------------------------------------------------- */
class VRC_Notifications_Question_Subscription extends Notifications_Node_Subscription {
  /**
   * Set all the fields we can from node
   */
  public function set_node($node) {
    $node_mapping = array(
      'question:nid' => $node->nid,
    );
    foreach ($node_mapping as $index => $value) {
      // For the 'question:nid', it will return VRC_Notifications_Question_Field
      if ($field = $this->get_field($index)) {
        $field->set_value($value);
      }
    }
    return $this;
  }

  /**
   * Get a proper name for this type
   */
  public function get_name() {
    if (isset($this->name)) {
      return $this->name;
    }
    elseif ($node = $this->get_field('question:nid')->drupal_object()) {
        return $node->title;
    }
    else {
      return parent::get_name();
    }
  }

  /**
   * Get link element
   *
   * @see Notifications_Subscription::element_link()
   *
   * Shame that parent::element_link() doesn't work for me.
   */
  public function element_link($operation = NULL, $options = array()) {
    $type = $this->get_link_type($operation);
    $options += $this->get_link_options($type, $options);
    $path = $this->get_path($type, $options);
    // For users without email address, subscribe with simple send method.
    global $user;
    if ($type == 'subscribe' && !empty($user->uid) && in_array('no email', $user->roles)) {
      $options['query']['send_method'] = 'simple';
    }
    return array(
      '#type' => 'link',
      '#title' => $this->get_link_text($type),
      '#href'  => $path,
      '#options' => notifications_url_options($path, $options) + array('html' => TRUE),
      '#description' => $this->get_description(),
    );
  }
}

class VRC_Notifications_Tag_Subscription extends Notifications_Taxonomy_Term_Subscription {
  /**
   * Get proper name
   */
  public function get_name() {
    if (isset($this->name)) {
      return $this->name;
    }
    elseif ($term = $this->get_field('term:tid')->drupal_object()) {
      return $term->name;
    }
    else {
      parent::get_name();
    }
  }

  /**
   * Get link element
   */
  public function element_link($operation = NULL, $options = array()) {
    $type = $this->get_link_type($operation);
    $options += $this->get_link_options($type, $options);
    $path = $this->get_path($type, $options);
    // For users without email address, subscribe with simple send method.
    global $user;
    if ($type == 'subscribe' && !empty($user->uid) && in_array('no email', $user->roles)) {
      $options['query']['send_method'] = 'simple';
    }
    return array(
      '#type' => 'link',
      '#title' => $this->get_link_text($type),
      '#href'  => $path,
      '#options' => notifications_url_options($path, $options) + array('html' => TRUE),
      '#description' => $this->get_description(),
    );
  }
}

/*  FIELD
 * -------------------------------------------------------------------------- */
class VRC_Notifications_Question_Field extends Notifications_Node_Field {
  public $type = 'question:nid';
  public $object_type = 'question';

  /**
   * Get field name
   */
  function get_title() {
    return t('Question');
  }
  /**
   * Get description
   */
  function get_description() {
    return t('Question');
  }

  /**
   * Get system path
   */
  function get_path() {
    return isset($this->value) ? 'node/' . $this->value : '';
  }
}
