<?php
$pclass = '';
$aclass = '';
$nclass = '';
$tclass = '';
$wclass = '';
$cclass = '';
$alclass = '';
$nlclass = '';
$mclass = '';
$gclass = '';
$lclass = '';

if(arg(3) == 'posture-data'){
	$pclass = 'active';
}else if(arg(3) == 'activity_goals'){
	$aclass = 'active';
	$gclass = 'active';
}else if(arg(3) == 'nutrition_goals'){
	$nclass = 'active';
	$gclass = 'active';
}else if(arg(3) == 'threshold'){
	$tclass = 'active';
}else if(arg(3) == 'webex'){
	$wclass = 'active';
}else if(arg(3) == 'characteristics'){
	$cclass = 'active';
}else if(arg(3) == 'activity_log'){
	$alclass = 'active';
	$lclass = 'active';
}else if(arg(3) == 'nutrition_log'){
	$nlclass = 'active';
	$lclass = 'active';
}else if(arg(3) == 'messages'){
	$mclass = 'active';
}

$count = _unread_messages($uid);

?>
<nav class="navbar navbar-default" role="navigation">
 <div class="container-fluid">
	 
	 <div class="navbar-header">
	       <button type="button" class="navbar-toggle" data-toggle="collapse" data-target="#pt-patient-navbar">
	         <span class="sr-only">Toggle navigation</span>
	         <span class="icon-bar"></span>
	         <span class="icon-bar"></span>
	         <span class="icon-bar"></span>
	       </button>
	     </div>
	 
	 
 	<div class"navbar-collapse collapse" id="pt-patient-navbar">
		<ul class="menu nav nav-pills">
			<li><a href="/pt/dashboard">Back to Dashboard</a></li>
			<li class="<?php print $alclass;?>"><a href="/pt/patient/<?php print $uid;?>/activity_log">Activity Log</a></li>
			<li class="<?php print $aclass;?>"><a href="/pt/patient/<?php print $uid;?>/activity_goals">Set Activity Goals</a></li>
			<li class="<?php print $tclass;?>"><a href="/pt/patient/<?php print $uid;?>/threshold">Set Thresholds</a></li>
			<li class="<?php print $wclass;?>"><a href="/pt/patient/<?php print $uid;?>/webex">Set Exercise Program</a></li>
			<li class="<?php print $pclass;?>"><a href="/pt/patient/<?php print $uid;?>/posture-data">Review Snapshots</a></li>
			<li class="<?php print $cclass;?>"><a href="/pt/patient/<?php print $uid;?>/characteristics">Vitals</a></li>
			<li class="<?php print $mclass;?>"><a href="/pt/patient/<?php print $uid;?>/messages">Messages 
				<?php if($count > 0):?>
				<span class="badge"><?php print $count;?></span>
			<?php endif;?>
			
			</a></li>
	        <li><a href="/user/logout">Logout</a></li>
									
		</ul>
	</div>
 </div>
</nav>
