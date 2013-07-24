<?php
/**
 *  When not logged in:
 *    Inform the user to login to give feedback
 *
 * - When logged in:
 *    - Before voting
 *      - Rating infomation(description and buttons)
 *
 *    - After voting
 *      - Rating infomation(description and buttons)
 *      - Show the user's description
 *
 */
?>

<div class="post-interesting">
  <?php print '<span class="rate-description">' . $display_options['description'] . '</span>'; ?>
  <?php if (!empty($rate_summary)): ?>
    <?php print $rate_summary; ?>
  <?php endif; ?>
  <?php if (user_is_logged_in()): ?>
    <?php if (!$just_voted): ?>
      <?php foreach ($buttons as $button): ?>
        <?php print $button; ?>
      <?php endforeach; ?>
    <?php else: ?>
      <?php print 'Thanks for your feedback';?>
    <?php endif; ?>

  <?php else: ?>
    <?php print $login_text; ?>
  <?php endif; ?>

</div>
