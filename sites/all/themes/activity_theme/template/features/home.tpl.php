<?php dsm($variables);?>
<?php if($variables['is_front']):?>
<div class="flexslider">
          <ul class="slides">
	            <li style="background: url(img/01.jpg) center"></li> 	  	    	
                <li style="background: url(img/02.jpg) center"></li>
                <li style="background: url(img/03.jpg) center"></li>
                <li style="background: url(img/04.jpg) center"></li>
          </ul>
   	  	</div><!-- End slider -->
        
        <div id="calculators_home">
            	<div class="container" >
                <div class="row">
                <div class="col-md-3 col-sm-6 col-xs-6">
                 <div class="box_calculator">
                        <a href="daily-calorie-calculator.html">
                        <img src="img/icon-1.png" alt="" data-retina="true">
                        <h3>Daily Calorie<br>Calculator</h3>
                        </a>
                    </div><!-- End box-calculator -->
                </div><!-- End col-md-3 -->
                
                <div class="col-md-3 col-sm-6 col-xs-6">
                    <div class="box_calculator">
                        <a href="calories-burned-by-heart-rate.html">
                        <img src="img/icon-2.png" alt="" data-retina="true">
                        <h3>Calorie Burned<br>by heart/rate</h3>
                        </a>
                    </div><!-- End box-calculator -->
                </div><!-- End col-md-3 -->
                
                <div class="col-md-3 col-sm-6 col-xs-6">
                    <div class="box_calculator">
                        <a href="calories-burned-by-activities.html">
                        <img src="img/icon-3.png" alt="" data-retina="true">
                        <h3>Calorie Burned<br>by activities</h3>
                        </a>
                    </div><!-- End box-calculator -->
                </div><!-- End col-md-3 -->
                
                <div class="col-md-3 col-sm-6 col-xs-6">
                    <div class="box_calculator">
                        <a href="BMI-body-mass-calculator.html">
                        <img src="img/icon-4.png" alt="" data-retina="true">
                        <h3>Bmi Body mass<br>Calculator</h3>
                        </a>
                    </div><!-- End box-calculator -->
                </div><!-- End col-md-3 -->
              
             </div><!-- End row --> 
            </div><!-- End container -->
            </div><!--calculators_home -->
<?php endif; ?>