<?php
global $user;
?>
<div class="pt_dashboard pt-forms">
	<div class="row">
		<div class="col-md-12">
			<div class="section-area">
				<div class="row">
					<div class="col-md-12">
						<div class="section-header">
							<h4 class="section-header"><?php print t("Welcome to your Dashboard, ".$fname." ".$lname); ?></h4>
						</div>
					</div>
                </div>
			</div>
		</div>
	</div>
	
	
	<div class="row">
		
		<?php foreach($patients as $patient){ ?>
		<div class="col-md-4 col-sm-4 text-center dashboard-profile">
		<a href="/pt/patient/<?php print $patient['uid'];?>/activity_log">
		<div class="text-center  easy-pie-chart <?php print $patient['pie_color'];?>" data-percent="<?php print $patient['emotion'];?>">
		
			<div class="profile-image">
				<img class="img-circle styled" src="<?php print image_style_url('user_profile', $patient['image_uri']) ?>">
			</div>
		  	<?php if ($patient['unread_messages']): ?>
		  		<div class="unread-messages"><?php print $patient['unread_messages']; ?></div>
		  	<?php endif; ?>
	   </div>
		 </a> 
		 <div class="activity-info">
			 <div class="text-center  activity-pie-chart lightblue" data-percent="<?php print $patient['low'];?>">
				 <span class="percent"></span><br>
				 Light
			 </div>
			 
			 <div class="text-center  activity-pie-chart blue" data-percent="<?php print $patient['medium'];?>">
				 <span class="percent"></span><br>Moderate
			 </div>
			 
			 <div class="text-center  activity-pie-chart darkblue" data-percent="<?php print $patient['high'];?>">
				 <span class="percent"></span><br>Vigorous
			 </div>
			
		 </div>
		 <div class="exercise-info">
			 <div class="text-center  activity-pie-chart yellow" data-percent="<?php print $patient['ex7'];?>">
				 <span class="percent"></span><br>Ex last 7 days
			 </div>

			 <div class="text-center  activity-pie-chart orange" data-percent="<?php print $patient['ex30'];?>">
				 <span class="percent"></span><br>Ex Last 30 days
			 </div>
		 </div>
		  <div class="profile-info">
			  <h5><a href="/pt/patient/<?php print $patient['uid'];?>/activity_goals"><?php print $patient['fname'];?> <?php print $patient['lname'];?></a></h5>
              <p><?php echo l(t('Edit Patient'), "/pt/patient/{$patient['uid']}/edit"); ?></p>
		      Last Emotion Update: <small><?php print $patient['vitals_entered'];?></small><br>
		      Last Activity Synch: <small><?php print $patient['last_accessed'];?></small>
          </div>
	    </div>
		
		<?php }?>
		
	</div>
	
	
</div>
