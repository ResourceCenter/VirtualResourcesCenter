<article id="article-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>
  <div class="rate-widgets">
    <?php if (!empty($content['rate_post_useful'])): ?>
      <?php print render($content['rate_post_useful']); ?>
    <?php endif; ?>
  </div>
    <?php if (!empty($content['rate_answer_vote'])): ?>
      <?php print render($content['rate_answer_vote']); ?>
    <?php endif; ?>

  <?php print render($content); ?>

  <div class="edit-links">
    <?php if (!empty($edit_link)): ?>
      <?php print $edit_link; ?>
    <?php endif; ?>

    <?php if (!empty($delete_link)): ?>
      <?php print $delete_link; ?>
    <?php endif; ?>
  </div>

  <div class="submitted">
    <?php print $submitted; ?>
  </div>
</article>

