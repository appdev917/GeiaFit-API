<div class="col-md-12">
  <div class="profile-image">
	<img class="img-circle styled" src="<?php print image_style_url($style, $image_uri) ?>">
  </div>
  <div class="profile-info">
	  <h4>
		  <?php print $first_name;?> <?php print $last_name;?></h4>
		   DOB:<small><?php print $dob;?></small></br>
		   Gender:<small><?php print $gender;?></small></br>
		   Email:<small><?php print $email;?></small></br>
		   Gems:<small><?php print $gems;?></small></br>
		   Goals:<small><ul><?php foreach($goals as $goal){
			   print '<li>'.$goal.'</li>';
			
		   }?></ul></small></br>
	  
  </div>
</div>