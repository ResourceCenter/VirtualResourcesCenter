<?php

/**
 * @file
 * Contains the highcharts style plugin.
 */

/**
 * Style plugin uses views ui to configure views data for rendering highcharts.
 *
 * @ingroup views_style_plugins
 */
class highcharts_views_plugin_style_highcharts extends views_plugin_style {

  /**
   * Initialize the style plugin.
   */
  function init(&$view, &$display, $options = NULL) {
    parent::init($view, $display, $options);
  }

  /**
   * Set default options.
   */
  function option_definition() {
    $options = parent::option_definition();

    $options['format'] = array(
      'contains' => array(
        // Do not set a default chart series type.
        'chart_template' => array('default' => 0),
      ),
    );

    $options['attributes'] = array(
      'contains' => array(
        'class' => array('default' => ''),
        'style' => array('default' => ''),
      ),
    );

    // Do not set default values for 'object'. These are advanced options which
    // override the selected template only if a value is set.
    // $options['object'] = array();
  }

  /**
   * Provide a form to edit options for this plugin.
   */
  function options_form(&$form, &$form_state) {
    // Chart templates for basic settings.
    $chart_templates = array('0' => t('None (use advanced settings only)'));
    // Allow modules to add chart templates.
    foreach (module_invoke_all('highcharts_views_charts') as $key => $chart_template) {
      $chart_templates[$key] = $chart_template['title'];
    }

    // Get fields for selection.
    $chart_handlers = $this->display->handler->get_handlers('field');
    $chart_fields = array();
    foreach ($chart_handlers as $key => $value) {
      $chart_fields[$key] = $value->options['ui_name'] ? $value->options['ui_name'] : $value->options['field'];
    }

    // Basic settings.
    $form['format'] = array(
      '#title' => t('Basic settings'),
      '#type' => 'fieldset',
    );
    $form['format']['chart_template'] = array(
      '#title' => t('Chart Template'),
      '#type' => 'select',
      '#options' => $chart_templates,
      '#multiple' => FALSE,
      '#required' => TRUE,
      '#default_value' => $this->options['format']['chart_template'],
      '#id' => 'format_chart_type'
    );

    // HTML attributes.
    // @see theme_highcharts_chart()
    $form['attributes'] = array(
      "#title" => t('Container attributes'),
      "#type" => "fieldset",
    );

    $form['attributes']['class'] = array(
      "#title" => t('Class'),
      "#type" => 'textfield',
      '#default_value' => $this->options['attributes']['class'],
    );

    $form['attributes']['style'] = array(
      "#title" => t('Style'),
      "#type" => 'textfield',
      '#default_value' => $this->options['attributes']['style'],
    );

    // @todo add override options object form.
  }

  /**
   * Validate the options form.
   * @todo what can we really validate here?
   */
  function options_validate(&$form, &$form_state) {

  }

  /**
   * Handle any special handling on the validate form.
   */
  function options_submit(&$form, &$form_state) {

  }

  /**
   * Hijack rendering Views data for Highcharts display.
   *
   * See highcharts_views_get_view_result() for rationale.
   */
  function render() {
    // Initialize the Highcharts options object from view options_form settings.
    // These may or may not be overridden by the selected chart type callback.
    $options = new stdClass();

    // Get an array of view data and labels.
    $data = highcharts_views_get_view_result($this->view);

    // Allow other modules to specify chart types.
    $chart_templates = module_invoke_all('highcharts_views_charts');
    $chart_template = $this->options['format']['chart_template'];
    $file = $chart_templates[$chart_template]['file'];
    if ($file) {
      include_once($file);
    }
    if (function_exists($chart_template)) {
      $options = $chart_template($data, $options);
    }

    // Override the Highcharts options object returned by the selected chart
    // type callback, using the view options_form() settings.
    if (!empty($this->options['object'])) {
      $options = highcharts_views_options_override($options, $this->options['object']);
    }

    // Highcharts container HTML attributes.
    // Note this option differs from the built-in Highcharts options object
    // settings (height, className, style, etc), which sets those attributes on
    // the SVG element. The container height attribute keeps the chart from
    // overflowing beyond other JS-calculated containers such as Homebox.
    $attributes = $this->options['attributes'];

    // Flag ajax requests so JS does not load again.
    $ajax = $_REQUEST['q'] == 'views/ajax';

    return highcharts_render($options, $attributes, $ajax);
  }

}
