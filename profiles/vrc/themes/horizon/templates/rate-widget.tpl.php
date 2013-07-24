<?php
/**
 * @file
 * VRC version of the Rate widget theme for yesno questions
*/

print theme('item_list', array('items' => $buttons));

/* print $results['rating'] . " votes"; */
print "<div id='rating-score' title='Rate this content up if you found it usefull, or down if you found it irrelevant, wrong or inaccurate.'>";
print $results['rating'] . " Votes";
print "</div>";

/*
 print theme('item_list', array(
      'text' => $links[0]['text'],
      'href' => $links[0]['href']
      )
    );
    print theme('item_list', array(
      'text' => $links[1]['text'],
      'href' => $links[1]['href']
      )
    );


/*
if ($info) {
  print '<div class="rate-info">' . $info . '</div>';
}

if ($display_options['description']) {
  print '<div class="rate-description">' . $display_options['description'] . '</div>';
}
*/
