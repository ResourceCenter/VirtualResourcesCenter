<?php
// VRC theme, based on Pixture Reloaded by Adaptivethemes.com

/**
 * Override or insert variables into the html template.
 */
function horizon_preprocess_html(&$vars) {
  global $theme_key;

  $theme_name = 'horizon';
  $path_to_theme = drupal_get_path('theme', $theme_name);

  // Load the media queries styles
  $media_queries_css = array(
    $theme_name . '.responsive.style.css',
    $theme_name . '.responsive.gpanels.css'
  );
  load_subtheme_media_queries($media_queries_css, $theme_name);

  // Add a class for the active color scheme
  if (module_exists('color')) {
    $class = check_plain(get_color_scheme_name($theme_key));
    $vars['classes_array'][] = 'color-scheme-' . drupal_html_class($class);
  }

  // Add class for the active theme
  $vars['classes_array'][] = drupal_html_class($theme_key);

  // Add theme settings classes
  $settings_array = array(
    'font_size',
    'box_shadows',
    'body_background',
    'menu_bullets',
    'menu_bar_position',
    'corner_radius',
    'image_alignment',
  );
  foreach ($settings_array as $setting) {
    $vars['classes_array'][] = theme_get_setting($setting);
  }

  // Fonts
  $fonts = array(
    'bf'  => 'base_font',
    'snf' => 'site_name_font',
    'ssf' => 'site_slogan_font',
    'ptf' => 'page_title_font',
    'ntf' => 'node_title_font',
    'ctf' => 'comment_title_font',
    'btf' => 'block_title_font'
  );
  $families = get_font_families($fonts, $theme_key);
  if (!empty($families)) {
    foreach ($families as $family) {
      $vars['classes_array'][] = $family;
    }
  }

  // Add Noggin module settings extra classes, not all designs can support header images
  if (module_exists('noggin')) {
    if (variable_get('noggin:use_header', FALSE)) {
      $va = theme_get_setting('noggin_image_vertical_alignment');
      $ha = theme_get_setting('noggin_image_horizontal_alignment');
      $vars['classes_array'][] = 'ni-a-' . $va . $ha;
      $vars['classes_array'][] = theme_get_setting('noggin_image_repeat');
      $vars['classes_array'][] = theme_get_setting('noggin_image_width');
    }
  }

  // Special case for PIE htc rounded corners, not all themes include this
  if (theme_get_setting('ie_corners') == 1) {
    drupal_add_css($path_to_theme . '/css/ie-htc.css', array(
      'group' => CSS_THEME,
      'browsers' => array(
        'IE' => 'lte IE 8',
        '!IE' => FALSE,
        ),
      'preprocess' => FALSE,
      )
    );
  }

  // Headings styles
  if (theme_get_setting('headings_styles_caps') == 1) {
    $vars['classes_array'][] = 'hs-caps';
  }
  if (theme_get_setting('headings_styles_weight') == 1) {
    $vars['classes_array'][] = 'hs-fwn';
  }
  if (theme_get_setting('headings_styles_shadow') == 1) {
    $vars['classes_array'][] = 'hs-ts';
  }
}

/**
 * Override or insert variables into the html template.
 */
function horizon_process_html(&$vars) {
  // Hook into color.module
  if (module_exists('color')) {
    _color_html_alter($vars);
  }
}

/**
 * Override or insert variables into the page template.
 */
function horizon_process_page(&$vars) {
  // Hook into color.module
  if (module_exists('color')) {
    _color_page_alter($vars);
  }
}

/**
 * Implements THEMENAME_preprocess_page()
 */
function horizon_preprocess_page(&$vars) {
  // Set breadcrumb for node full page
  if (!empty($vars['node']) && !empty($vars['node']->nid)) {
    $node = $vars['node'];
    if (in_array($node->type, array('article', 'documentation'))) {
      $breadcrumb[] = l(t('Home'), '<front>');
      switch ($node->type) {
        case 'article':
          $breadcrumb[] = l(t('Articles'), 'articles');
          break;
        case 'documentation':
          $breadcrumb[] = l(t('Toolbox'), 'toobox');
          break;
        default:
          // $type_name = node_type_get_name($node);
          // $breadcrumb[] = t($type_name);
          break;
      }

      $breadcrumb[] = l($node->title, 'node/' . $node->nid);
      drupal_set_breadcrumb($breadcrumb);
    }
    else {
      drupal_set_breadcrumb(array());
    }
  }
  else {
    drupal_set_breadcrumb(array());
  }
}

/**
 *
 * Override of theme_node_preview()
 * @see: theme_node_preview()
 */
function horizon_node_preview($variables) {
  $node = $variables['node'];
  // Add special theming for the answer preview block
  if ($node->type == 'answer') {
    $output = '<div class="preview answer-preview">';
    $output .= '<h3>' . t('Your answer\'s preview:') . '</h3>';
    // The answer doesn't have a full-page mode
    $elements = node_view(clone $node, 'teaser');
    $teaser_output = drupal_render($elements);
    $output .= $teaser_output;

    $output .= "</div>\n";
  }
  else {
    $output = theme_node_preview($variables);
  }

  return $output;
}

/**
 * Override of theme('breadcrumb', ...)
 * @see: adaptivetheme_breadcrumb()
 */
function horizon_breadcrumb($vars) {
  $output = '';
  $breadcrumb = $vars['breadcrumb'];

  // Don't show breadcrumb if it's disabled in the theme settings
  $show_breadcrumb = theme_get_setting('breadcrumb_display');
  if ($show_breadcrumb == 'yes') {
    // Hide 'Home' if it's configured in theme settings
    $show_breadcrumb_home = theme_get_setting('breadcrumb_home');
    if (!$show_breadcrumb_home) {
      array_shift($breadcrumb);
    }

    if (!empty($breadcrumb)) {
      $separator = filter_xss(theme_get_setting('breadcrumb_separator'));
      if (empty($separator)) {
        $separator = '&nbsp;&raquo;&nbsp;';
      }

      $output .= '<h2 class="element-invisible">' . t('You are here') . '</h2>';
      $output .= '<ol id="crumbs">';
      foreach ($breadcrumb as $key => $val) {
        if ($key == 0) {
          $output .= '<li class="crumb">' . $val . '</li>';
        }
        else {
          $output .= '<li class="crumb"><span>' . $separator . '</span>' . $val . '</li>';
        }
      }
      $output .= '</ol>';
    }
  }

  return $output;
}

/**
 * Implements THEMENAME_preprocess_node()
 */
function horizon_preprocess_node(&$vars) {
  switch ($vars['type']) {
    case 'article':
      if ($vars['view_mode'] == 'full') {
        // Change the submited info while in article's full mode
        $byline = t('By !username', array('!username' => $vars['name']));
        // Append fullname if it exists
        $fullname = horizon_get_user_fullname_by_uid($vars['uid']);
        if (!empty($fullname)) {
          $byline .= ' <span class="fullname">(' . $fullname . ')</span>';
        }
        $date = t('Published: !datetime', array('!datetime' => format_date($vars['created'], 'custom', 'M d, Y')));
        $vars['submitted'] = "<div class='byline'>{$byline}</div><div class='date'>$date</div>";
      }

      // For curated aritcle, link the node title to the original article
      $type = horizon_get_article_type($vars['node']);
      if ($type == 'curated') {
        $source_link = horizon_get_article_original_article_link($vars['node']);
        $vars['title_suffix']['article_source_link'] = $source_link;
      }
      break;

    case 'answer':
      static $question = null;
      static $can_set_best_answer = null;

      // Change submitted message
      $vars['submitted'] = t('Answered by !username !timeago', array('!username' => $vars['name'], '!timeago' => horizon_time_ago($vars['created'])));

      // Add edit/delete link
      if (node_access('update', $vars['node'])) {
        $vars['edit_link'] = l('edit', 'answer-edit/' . $vars['node']->nid);
      }
      if (node_access('delete', $vars['node'])) {
        $vars['delete_link'] = l('delete', 'node/' . $vars['node']->nid . '/delete');
      }
      break;
  }
}

/**
 * Override or insert variables into the block template.
 */
function horizon_preprocess_block(&$vars) {
  if($vars['block']->module == 'superfish' || $vars['block']->module == 'nice_menu') {
    $vars['content_attributes_array']['class'][] = 'clearfix';
  }
}

/**
 * Preprocess rate widget
 */
function horizon_preprocess_rate_widget(&$vars) {
  if (!empty($vars['content_type']) && $vars['content_type'] == 'node' &&
      !empty($vars['content_id'])) {
    $node = node_load($vars['content_id']);

    if (!empty($node) && $node->type == 'question') {
      if (!user_is_logged_in()) {
        $login_text = l(t('Login or register'), 'user/login', array('query' => array(drupal_get_destination())));
        $vars['display_options']['description'] .=  $login_text . t(' to give feedback.');
      }
    }
  }
}

/**
 * Implements hook_preprocess_node()
 * The adaptive theme make it so hard to make some small customizations.
 * @see: adaptivetheme/templates/node.tpl.php
 * @see: adaptivetheme_process_node()
 */
function horizon_process_node(&$vars) {
  // When documention's sticky field is TRUE, it's of content type 'tool'
  // By default, the documentation and the tool nodes has the same classes, so
  // we change the classes of the tool node so we could differentiate them in
  // in the frontend
  if ($vars['type'] == 'documentation') {
    $classes = explode(' ', $vars['classes']);
    if ($vars['sticky']) {
      if ($index = array_search('article-type-documentation', $classes)) {
        unset($classes[$index]);
        $classes[] = 'article-type-tool';
      }
    }
    $vars['classes'] = implode(' ', $classes);
  }
}

/**
 * Override or insert variables into the field template.
 */
function horizon_preprocess_field(&$vars) {
  $element = $vars['element'];
  $vars['classes_array'][] = 'view-mode-' . $element['#view_mode'];
  $vars['image_caption_teaser'] = FALSE;
  $vars['image_caption_full'] = FALSE;
  if (theme_get_setting('image_caption_teaser') == 1) {
    $vars['image_caption_teaser'] = TRUE;
  }
  if (theme_get_setting('image_caption_full') == 1) {
    $vars['image_caption_full'] = TRUE;
  }
  $vars['field_view_mode'] = '';
  $vars['field_view_mode'] = $element['#view_mode'];
}


/**
 * Implements hook_theme()
 */
function horizon_theme($existing, $type, $theme, $path) {
  $items['user_login_block'] = array(
    'render element' => 'form',
  );
  return $items;
}

/**
 * Implements hook_theme_registry_alter()
 */
function horizon_theme_registry_alter(&$theme_registry) {
  // dpm(func_get_args());
}

/**
 * Custom theming for form 'user_login_block'
 * @see: _logintoboggan_toggleboggan()
 */
function horizon_user_login_block($vars) {
  $form = $vars['form'];
  $output = '';

  // Modify the html layout for easier CSS styling
  $options = array(
    'attributes' => array(
      'id' => 'toboggan-login-link',
      'class' => array('toboggan-login-link')
     ),
    'query' => drupal_get_destination(),
  );
  $pre = l(theme('lt_login_link'), 'user/login', $options);
  $pre .= '<div id="toboggan-container" class="toboggan-container">';
  //the block that will be toggled
  $pre .= '<div id="toboggan-login" class="user-login-block">';
  $form['pre']['#markup'] = $pre;

  $items = array('pre', 'name', 'pass', 'actions', 'links', 'post');
  foreach ($items as $item) {
    $output .= drupal_render($form[$item]);
  }
  $output .= drupal_render_children($form);
  return $output;
}

/******************************************************************************
 *                          Helper Functions                                  *
 ******************************************************************************/

/**
 * Get a user's fullname
 */
function horizon_get_user_fullname_by_uid($uid) {
  $user = user_load($uid);
  if (empty($user)) return;

  $items = field_get_items('user', $user, 'field_user_fullname');
  if (!empty($items) && is_array($items)) {
    $fullname = reset($items);
    if (!empty($fullname['safe_value'])) {
      return $fullname['safe_value'];
    }
  }
  return;
}

/**
 * Get an article's type
 */
function horizon_get_article_type($node) {
  $items = field_get_items('node', $node, 'field_article_type');
  if (!empty($items)) {
    // Single value field
    $item = reset($items);
    if (!empty($item['value'])) {
      return trim($item['value']);
    }
  }
  return;
}

/**
 * Get the url of the source
 */
function horizon_get_article_original_article_link($node) {
  $items = field_get_items('node', $node, 'field_original_article');
  if (!empty($items)) {
    $item = reset($items);
    if (!empty($item['url'])) {
      return array(
        '#theme' => 'link',
        '#text' => t('Original article'),
        '#path' => $item['url'],
        '#options' => array(
          'attributes' => array('class' => 'article-source-link'),
          'html' => TRUE,
        ),
      );
    }
  }
}

/**
 * Simple function to return time ago string
 */
function horizon_time_ago($timestamp, $granularity = 2) {
  $interval = format_interval((REQUEST_TIME - $timestamp) , $granularity);
  return t('@interval ago', array('@interval' => $interval));
}
