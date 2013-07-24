<?php

/**
 * This plugin is not being used, too complex to get the highcharts render so
 * something we want.
 */

/**
 * Simple custom text box.
 *
 * For the detailed options the highcharts need, see:
 * @see http://api.highcharts.com/highcharts
 */
class vrc_statistics_dashboard_highcharts_linechart_box extends boxes_box {
  /**
   * Implementation of boxes_box::options_defaults().
   */
  public function options_defaults() {
    return array(
      'title'=>'',
      'highcharts' => array(
        'chart' => array(
          'renderTo' => '',
          'type' => 'line',
          'marginLeft' => '',
          'marginRight' => '',
          'marginTop' => '',
          'marginBottom' => '',
        ),
        'title' => array(
          'text' => '',
          'align' => 'center',
        ),
        'subtitle' => array(
          'text' => '',
          'align' => 'center',
        ),
        'tooltip' => array(
          'formatter' => "function() {
            return '<b>'+ this.series.name +'</b><br/>'+
            this.x +': '+ this.y +'°C';
          }",
        ),
        'legend' => array(
          'layout' => 'vertical',
          'align' => 'right',
          'verticalAlign' => 'right',
          'x' => '-10',
          'y' => '100',
          'borderWidth' => '0',
        ),
      ),
    );
  }

  /**
   * Implementation of boxes_box::options_form().
   */
  public function options_form(&$form_state) {
    $form = array();
    $form['highcharts'] = array(
      '#type' => 'fieldset',
      '#title' => 'Highcharts options',
      '#tree' => TRUE,
    );

    // [title] section
    $form['highcharts']['title'] = array(
      '#type' => 'fieldset',
      '#title' => 'title',
      '#tree' => TRUE,
      '#description' => t('The chart\'s main title.'),
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
    );
    $form['highcharts']['title']['text'] = array(
      '#type' => 'textfield',
      '#title' => 'text',
      '#description' => t('The title of the chart. To disable the title, set the text to null. Defaults to Chart title.'),
      '#default_value' => $this->options['highcharts']['title']['text'],
    );
    $form['highcharts']['title']['align'] = array(
      '#type' => 'select',
      '#title' => 'align',
      '#options' => drupal_map_assoc(array('left', 'center', 'right')),
      '#description' => t('The horizontal alignment of the title. Can be one of "left", "center" and "right". Defaults to center.'),
      '#default_value' => $this->options['highcharts']['title']['align'],
    );

    // [subtitle] section
    $form['highcharts']['subtitle'] = array(
      '#type' => 'fieldset',
      '#title' => 'subtitle',
      '#tree' => TRUE,
      '#description' => t('The chart\'s subtitle'),
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
    );
    $form['highcharts']['subtitle']['text'] = array(
      '#type' => 'textfield',
      '#title' => 'text',
      '#description' => t('The subtitle of the chart.'),
      '#default_value' => $this->options['highcharts']['subtitle']['text'],
    );
    $form['highcharts']['subtitle']['align'] = array(
      '#type' => 'select',
      '#title' => 'align',
      '#options' => drupal_map_assoc(array('left', 'center', 'right')),
      '#description' => t('The horizontal alignment of the title. Can be one of "left", "center" and "right". Defaults to center.'),
      '#default_value' => $this->options['highcharts']['subtitle']['align'],
    );

    // [chart] section
    $form['highcharts']['chart'] = array(
      '#type' => 'fieldset',
      '#title' => 'Chart',
      '#tree' => TRUE,
      '#description' => t('Options regarding the chart area and plot area as well as general chart options.'),
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
    );
    $form['highcharts']['chart']['renderTo'] = array(
      '#type' => 'textfield',
      '#title' => 'renderTo',
      '#description' => t('The HTML element where the chart will be rendered.'),
      '#default_value' => $this->options['highcharts']['chart']['renderTo'],
    );
    $chart_types = array(
      'line',
      'spline',
      'area',
      'areaspline',
      'column',
      'bar',
      'pie',
      'scatter',
    );
    $form['highcharts']['chart']['type'] = array(
      '#type' => 'select',
      '#title' => 'type',
      '#options' => drupal_map_assoc($chart_types),
      '#description' => t('The default series type for the chart. '),
      '#default_value' => $this->options['highcharts']['chart']['renderTo'],
    );
    $form['highcharts']['chart']['marginBottom'] = array(
      '#type' => 'textfield',
      '#title' => 'marginBottom',
      '#description' => t('The margin between the bottom outer edge of the chart and the plot area. Use this to set a fixed pixel value for the margin as opposed to the default dynamic margin. See also spacingBottom.'),
      '#default_value' => $this->options['highcharts']['chart']['marginBottom'],
    );
    $form['highcharts']['chart']['marginLeft'] = array(
      '#type' => 'textfield',
      '#title' => 'marginLeft',
      '#description' => t('The margin between the left outer edge of the chart and the plot area. Use this to set a fixed pixel value for the margin as opposed to the default dynamic margin. See also spacingLeft.'),
      '#default_value' => $this->options['highcharts']['chart']['marginLeft'],
    );
    $form['highcharts']['chart']['marginRight'] = array(
      '#type' => 'textfield',
      '#title' => 'marginRight',
      '#description' => t('The margin between the right outer edge of the chart and the plot area. Use this to set a fixed pixel value for the margin as opposed to the default dynamic margin. See also spacingRight.'),
      '#default_value' => $this->options['highcharts']['chart']['marginRight'],
    );
    $form['highcharts']['chart']['marginTop'] = array(
      '#type' => 'textfield',
      '#title' => 'marginTop',
      '#description' => t('The margin between the top outer edge of the chart and the plot area. Use this to set a fixed pixel value for the margin as opposed to the default dynamic margin. See also spacingTop.'),
      '#default_value' => $this->options['highcharts']['chart']['marginTop'],
    );

    // [tooltip] section
    $form['highcharts']['tooltip'] = array(
      '#type' => 'fieldset',
      '#title' => 'tooltip',
      '#tree' => TRUE,
      '#description' => t('Options for the tooltip that appears when the user hovers over a series or point.'),
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
    );
    $form['highcharts']['tooltip']['formatter'] = array(
      '#type' => 'textarea',
      '#title' => 'formatter',
      '#tree' => TRUE,
      '#description' => t('Callback function to format the text of the tooltip. Return false to disable tooltip for a specific point on series.'),
      '#default_value' => $this->options['highcharts']['tooltip']['formatter'],
    );

    // [legent] section
    $form['highcharts']['legend'] = array(
      '#type' => 'fieldset',
      '#title' => 'legend',
      '#tree' => TRUE,
      '#description' => t('The legend is a box containing a symbol and name for each series item or point item in the chart.'),
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
    );
    $form['highcharts']['legend']['layout'] = array(
      '#type' => 'select',
      '#title' => 'layout',
      '#options' => drupal_map_assoc(array('horizontal', 'vertical')),
      '#description' => t('The layout of the legend items.'),
      '#default_value' => $this->options['highcharts']['legend']['layout'],
    );
    $form['highcharts']['legend']['align'] = array(
      '#type' => 'select',
      '#title' => 'align',
      '#options' => drupal_map_assoc(array('center', 'right', 'left')),
      '#description' => t('The horizontal alignment of the legend box within the chart area. '),
      '#default_value' => $this->options['highcharts']['legend']['align'],
    );
    $form['highcharts']['legend']['verticalAlign'] = array(
      '#type' => 'select',
      '#title' => 'verticalAlign',
      '#options' => drupal_map_assoc(array('top', 'middle', 'bottom')),
      '#description' => t('The vertical alignment of the legend box'),
      '#default_value' => $this->options['highcharts']['legend']['verticalAlign'],
    );
    $form['highcharts']['legend']['x'] = array(
      '#type' => 'textfield',
      '#title' => 'x',
      '#description' => t('The x offset of the legend relative to it\'s horizontal alignment align within chart.spacingLeft and chart.spacingRight. Negative x moves it to the left, positive x moves it to the right. The default value of 15 together with align: "center" puts it in the center of the plot area. Defaults to 0.0.'),
      '#default_value' => $this->options['highcharts']['legend']['x'],
    );
    $form['highcharts']['legend']['y'] = array(
      '#type' => 'textfield',
      '#title' => 'y',
      '#description' => t('The vertical offset of the legend relative to it\'s vertical alignment verticalAlign within chart.spacingTop and chart.spacingBottom. Negative y moves it up, positive y moves it down. Defaults to 0.0.'),
      '#default_value' => $this->options['highcharts']['legend']['y'],
    );
    $form['highcharts']['legend']['borderWidth'] = array(
      '#type' => 'textfield',
      '#title' => 'borderWidth',
      '#tree' => TRUE,
      '#description' => t('The width of the drawn border around the legend. Defaults to 1.0.'),
      '#default_value' => $this->options['highcharts']['legend']['borderWidth'],
    );
    return $form;
  }

  /**
   * Implementation of boxes_box::render().
   */
  public function render() {
    $content = 'Hello world';
    $title = isset($this->title) ? $this->title : NULL;
    $options = $this->options['highcharts'];

    // Allow specifying other missing data for this chart
    drupal_alter('highcharts_linechart_box_options', $options, $this);

    $attributes = array(
      'id' => $this->options['highcharts']['chart']['renderTo'],
    );
    $options = $this->preprocessOptions($options);
    $options = $this->arrayToObject($options);

    if ($this->validateOptions($options)) {
      $content = highcharts_render($options, $attributes);
    }
    else {
      $content = t('Can\'t generate the graph.Please check the options.');
    }

    return array(
      'delta' => $this->delta,
      'title' => $title,
      'subject' => $title,
      'content' => $content,
    );
  }

  /**
   * Validate the options
   */
  function validateOptions($options) {
    return TRUE;
  }

  function preprocessOptions($options) {
    $options['legend']['x'] = (int)$options['legend']['x'];
    $options['legend']['y'] = (int)$options['legend']['y'];
    $options['legend']['borderWidth'] = (int) $options['legend']['borderWidth'];

    return $options;
  }

  /**
   * Convert array to object
   */
  public function arrayToObject($data) {
    return json_decode(json_encode($data));
  }

  /**
   * Generate an array of month names, either in full names or shorthanded
   */
  public function generateMonthNames($abbreviated = TRUE) {
    $month_names = array();
    $format = ($abbreviated) ? 'M' : 'F';
    foreach(range(1, 12) as $i) {
      $month_names[] = date($format, strtotime("2000-$i-01"));
    }
    return $month_names;
  }

  public function toIntArray($array) {
    return array_map('intval', array_values($array));
  }
}
