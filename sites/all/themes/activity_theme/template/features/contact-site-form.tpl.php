				<h1>Contact Activity</h1>
				<p class="lead">
					 Cu affert populo neglegentur has, labore nostrum periculis ius in, singulis electram ad vel labore nostrum periculis ius in.
				</p>

				<hr>
                <div id="message-contact"></div>
				<form method="post" action="assets/contact.php" id="contactform">
					<div class="row">
						<div class="col-md-6 col-sm-6">
							<div class="form-group">
								<?php print $fname; ?>
							</div>
						</div>
						<div class="col-md-6 col-sm-6">
							<div class="form-group">
								<?php print $lname; ?>
							</div>
						</div>
					</div>
                    
					<div class="row">
						<div class="col-md-6 col-sm-6">
							<div class="form-group">
								<?php print $email; ?>
							</div>
						</div>
						<div class="col-md-6 col-sm-6">
							<div class="form-group">
								<?php print $phone; ?>
							</div>
						</div>
					</div>

                    <div class="row">
						<div class="col-md-12">
							<div class="form-group">
								<?php print $subject; ?>
							</div>
						</div>
					</div>                     

					<div class="row">
						<div class="col-md-12">
							<div class="form-group">
								<?php print $message; ?>
							</div>
						</div>
					</div>
                                        
					<div class="row">
						<div class="col-md-12">
							<div class="form-group">
								<?php print $everything_eles; ?>
							</div>
						</div>
					</div>
				</form>