<div class="wrapper full-page-wrapper page-auth page-login text-center">
 <div class="inner-page">
	 <div class="login-box center-block">
		 
	    

	  	<?php print drupal_render($form['name']); ?>
		
		
	  	<?php print drupal_render($form['pass']);?>
		
		
		
		
		
		
		

	    
		 
	     <?php
	         // render login button
	 	print drupal_render($form['form_build_id']);
	 	print drupal_render($form['form_id']);
	 	print drupal_render($form['actions']);
	     ?>
		 
 	      <div class="user-login-links links">
 	  	<span class="password-link"><a href="/user/password">Forget your password?</a></span>
 	      </div>
	 
	 </div>
 </div>
</div>
			
			





   
  

   

<!-- /user-login-custom-form -->