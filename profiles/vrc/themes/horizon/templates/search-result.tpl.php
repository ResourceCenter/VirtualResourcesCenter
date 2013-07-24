<li class="search-result">
  <h3 class="title"><a href="<?php print $url; ?>"><?php print $title; ?></a></h3>
  <?php if ($snippet or $info_split): ?>
    <div class="search-snippet-info">
      <?php if ($snippet) : ?>
        <p class="search-snippet"><?php print $snippet; ?></p>
      <?php endif; ?>

      <?php if ($info_split) : ?>
        <p class="search-info">
          <?php $separator = ''; ?>

            <span class="search-info-type">

            <?php //Substitute icons for content types
              if( !isset($result['node']->field_resource_type['und'][0]['value']) ) {
                if( isset($info_split['type']) && $info_split['type'] == "Question" || $info_split['type'] == "Answer"  ) { ?>
                  <img src="/en/profiles/vrc/themes/vrc/images/question.png" alt="question" width="64" height="64" /> 
                  <?php }
                elseif( isset($info_split['type']) && $info_split['type'] == "Article" ) { ?>
                <img src="/en/profiles/vrc/themes/vrc/images/article.png" alt="article" width="64" height="64" />
                <?php ;} else print $info_split['type']."here"; ?>

              <?php ;} elseif ($result['node']->field_resource_type['und'][0]['value'] =="User Documentation" ) { ?>
              <img src="/en/profiles/vrc/themes/vrc/images/documentation.png" alt="documentation" width="64" height="64" />
              <?php ;} elseif ($result['node']->field_resource_type['und'][0]['value'] =="Tool" ) { ?>
              <img src="/en/profiles/vrc/themes/vrc/images/tool.png" alt="tool" width="64" height="64" />
              <?php ;} elseif ($result['node']->field_resource_type['und'][0]['value'] =="Development Documentation" ) { ?>
              <img src="/en/profiles/vrc/themes/vrc/images/Development-icon.png" alt="devdoc" width="64" height="64" />
              <?php ;} elseif ($result['node']->field_resource_type['und'][0]['value'] =="General Guide" ) { ?>
              <img src="/en/profiles/vrc/themes/vrc/images/book-icon.png" alt="general guide" width="64" height="64" />
              <?php ;} elseif ($result['node']->field_resource_type['und'][0]['value'] =="Video Tutorial" ) { ?>
              <img src="/en/profiles/vrc/themes/vrc/images/movie-icon.png" alt="videotuto" width="64" height="64" />
              <?php ;}
            ?>
            </span>

            <?php $separator = $info_separator; ?>
        </p>
      <?php endif; ?>
      
      <?php if( isset( $result['node']->field_toolbox_categories["und"] )) : ?>
        <div class="views-field views-field-term-node-tid searchtaxonomy">
            <?php $outputtaxonomy = "";
            foreach( $result['node']->field_toolbox_categories['und'] as $category )
              { $arrayname[] =  $category['taxonomy_term']->name ;
                $arraytid[] =  $category['taxonomy_term']->tid ; 
                $outputtaxonomy .= "<a href='/en/taxonomy/term/".$category['taxonomy_term']->tid."''>";
                $outputtaxonomy .= $category['taxonomy_term']->name;
                $outputtaxonomy .="</a>, ";
              }
            print substr($outputtaxonomy,0,-2); ?>
         </div><?php endif; ?>

<div class="views-field views-field-created question-post-date">
  on <?php print format_date($result['node']->created, 'short' ) ?>
</div>
    </div>
  <?php endif; ?>
  <!-- <a href="<?php print $url; ?>" class="search-more"><strong><? print t('more...'); ?></strong></a> -->
</li>