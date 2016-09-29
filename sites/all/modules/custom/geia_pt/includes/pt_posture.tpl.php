<div class="col-sm-4">
    <div class="panel panel-default">
        <div class="panel-heading">
            <h3 class="panel-title">Patients Reports</h3>
        </div>
        <div class="panel-body">
            <?php print theme_links($links); ?>
        </div>
    </div>
</div>
<?php if (!empty($posture)) : ?>
    <div class="col-sm-8">
        <div class="panel panel-default">
            <div class="panel-heading">
                <h3 class="panel-title"><?php print $posture->title; ?> <?php print format_date($posture->created, 'custom', 'd/m/Y') ?></h3>
            </div>
            <div class="panel-body">
                <?php 
				if($posture->type == 'posture'){
				
				$image_types = array('front', 'left', 'right', 'back', 'other'); ?>
                <?php foreach ($image_types as $image_type): ?>
                    <?php
                        $field_name = "field_{$image_type}_image";
                        $field = field_view_field('node', $posture, $field_name, array('settings' => array('image_style' => 'posture_image')));
                    ?>
                    <?php if (empty($field)): ?>
                        <?php continue; ?>
                    <?php else : ?>
                        <div class="panel panel-default">
                            <div class="panel-body row">
                                <div class="col-sm-6">
                                    <?php print render($field); ?>
                                </div>
                                <?php 
                                    $field_name = "field_{$image_type}_report_image";
                                    $field = field_view_field('node', $posture, $field_name, array('settings' => array('image_style' => 'posture_image')));
                                    $url = "/pt/patient/posture-image/{$posture->nid}/{$image_type}";
                                ?>
                                <?php if (empty($field)): ?>
                                    <?php print l(t('Analyze image'), $url); ?>
                                <?php else: ?>
                                    <div class="col-sm-6">
                                        <a href="<?php print $url ?>">
                                            <?php print render($field); ?>
                                        </a>
                                    </div>
                                <?php endif; ?>
                            </div>
                        </div>
                    <?php endif; ?>
                <?php endforeach; 
			    } else{ 
                    $field_name = "field_custom_video";
					$display = array('type' => 'video');
					$video_id = $posture->field_custom_video['und'][0]['fid'];
					$video_file = file_load($video_id);
                    $vf = file_view_file($video_file, 'default', '');
					?>
                    <div class="panel panel-default">
                        <div class="panel-body row">
                            <div class="col-sm-6">
                                <?php print render($vf); ?>
                            </div>
						 </div>
						 
						<div class="panel-body row"> 
                           <div class="col-sm-6">
                             <?php 
							$c_field_name = "field_video_description";
							$cfield = field_view_field('node', $posture, $c_field_name);
							print render($cfield); ?>
                          </div>
						</div>
						 
					</div>
			    <?php }?>
                <?php print drupal_render($form); ?>
            </div>
        </div>
    </div>
<?php endif; ?>
