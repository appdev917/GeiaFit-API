<div class="flexslider">
	<ul class="slides">
		<?php 
		//dsm($images);
	
		foreach ($images as $key => $image) {
		//
			if(is_numeric($key)){
				//print '<li style="background: url(http://activity.drupal.gobtan.com/sites/all/themes/custom/activity_theme/img/0'.$key.'.jpg) center"></li> ';
				print '<li style="background: url('.url($image).') center"></li>';
			}
		}

		?>
	</ul>
</div><!-- End slider -->

<div id="calculators_home">
	<div class="container" >
		<div class="row">

			<?php print render($calculators); ?>

		</div><!-- End row --> 
	</div><!-- End container -->
</div><!--calculators_home -->
