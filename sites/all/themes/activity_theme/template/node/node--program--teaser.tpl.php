<?php //dsm($content); ?>

<div class="col-md-6">
    <div class="thumbnail">
    	<a href="<?php print $node_url; ?>">
        <div class="course-item-image-container">
        <?php print render($content['field_thumb_image']);?>
        </div>
        <div class="caption color">
            <div class="transit-to-top">
                <h4 class="p-title"><?php print $title ; ?></h4>
                <div class="widget_nav_menu">- Read more -</div><!-- End widget_nav_menu -->
            </div><!-- transition top -->
        </div><!-- caption -->
        </a>
    </div><!-- End thumbnail -->
</div><!-- End col-md-6-->
                            
                     