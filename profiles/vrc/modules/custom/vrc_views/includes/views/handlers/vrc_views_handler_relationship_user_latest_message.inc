<?php

/**
 * Relationship handler to return the latest messages of the user
 */
class vrc_views_handler_relationship_user_latest_message extends views_handler_relationship {
  function option_definition() {
    $options = parent::option_definition();
    $options['message_types'] = array('default' => array());
    return $options;
  }

  function options_form(&$form, &$form_state) {
    $message_types = message_type_load();
    $options = array();
    if (!empty($message_types)) {
      foreach ($message_types as $type) {
        $options[$type->name] = $type->description;
      }
    }

    $form['message_types'] = array(
      '#type' => 'checkboxes',
      '#title' => t('Message Types'),
      '#options' => $options,
      '#default_value' => $this->options['message_types'],
      '#description' => t('Choose which message types you wish to relate.'),
    );
    parent::options_form($form, $form_state);
  }

  function query() {
    $this->ensure_my_table();
    $def = $this->definition;

    $def['table'] = 'message';
    $def['left_table'] = $this->table_alias;
    $def['left_field'] = 'uid';
    $def['field'] = 'uid';
    $def['type'] = empty($this->options['required']) ? 'LEFT' : 'INNER';

    $query = db_select('message', 'm');
    // This is the subquery's example result:
    // mysql> SELECT uid, max(timestamp) FROM message GROUP BY uid;
    // +------+----------------+
    // | uid  | max(timestamp) |
    // +------+----------------+
    // |    1 |     1358495431 |
    // |    2 |     1358413352 |
    // |    3 |     1294967295 |
    // |    4 |     1358413322 |
    // +------+----------------+
    $subquery = db_select('message', 'mt');
    $subquery->addField('mt', 'uid');
    $subquery->addExpression('MAX(timestamp)', 'm_timestamp');
    $subquery->groupBy('mt.uid');
    $subquery->orderBy('m_timestamp', 'desc');
    $query->join($subquery, 'mt', 'm.uid = mt.uid AND m.timestamp = mt.m_timestamp');
    $query->condition('m.type', array_filter($this->options['message_types']));
    $query->fields('m');
    $def['table formula'] = $query;

    $join = new views_join();
    $join->definition = $def;
    $join->construct();
    $join->adjusted = TRUE;

    // use a short alias for this:
    $alias = 'latest_message_mid_' . $this->table;

    $this->alias = $this->query->add_relationship($alias, $join, 'message', $this->relationship);
  }
}
