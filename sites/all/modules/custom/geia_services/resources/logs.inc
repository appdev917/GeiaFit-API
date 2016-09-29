<?php

function geia_services_logs_index_access() {
    return TRUE;
}

/**
 * @file
 * Contains the resource callbacks for profile.
 */


/**
 * Returns a collection of questions.
 *
 * @see geia_services_index_entities()
 */
function geia_services_logs_index($type = 'characteristics',$uid,$start = 0, $end = '7') {
	
	$user = user_load($uid);
	if(!$user){
       $data = array(
       	'success' => 0,
		'message' => 'user: '.$uid.' not found'
       );		
		return $data;
	
	}
	
	if($type == 'characteristics'){
		$query = db_select('characteristics', 'c');
		$query->fields('c');
		$query->condition('c.uid',$uid,'=');
		$result = $query->execute();
		$ch = array();
		$i = 1;
		while($record = $result->fetchAssoc()) {
			$data[] = $record;
		
			$i++;
	    }
	}
	elseif($type == 'health_points'){
		if(!(isset($end))){
			$end = 7;
		}
		
		if(!(isset($start))){
			$start = 0;
		}
		
		$data = array();
		$query = db_select('health_points', 'h');
		//$query->fields('h', array('daily_points'));
		$query->condition('h.uid',$uid,'=');
		$query->addExpression('sum(h.daily_points)', 'total_points');
	
		$result = $query->execute()->fetchObject();
		
		
		$data['total_points'] = $result->total_points;
		
		$query = db_select('health_points', 'c');
		$query->fields('c');
		$query->condition('c.uid',$uid,'=');
		$query->orderBy('pt_date', 'DESC');//ORDER BY created
		$query->range($start,$end);
		$result = $query->execute();

		$i = 1;
		while($record = $result->fetchAssoc()) {
			$data['daily'][] = $record;
		
			$i++;
	    }

		
	}else{
		
		$query = db_select('activity_logs', 'c');
		$query->fields('c');
		$query->condition('c.uid',$uid,'=');
		$result = $query->execute();
		$ch = array();
		$i = 1;
		while($record = $result->fetchAssoc()) {
			$data[] = $record;
		
			$i++;
	    }
	
	}
	
 
  
  return $data;
}

function geia_services_logs_update($type,$uid,$data) {
	
	$user = user_load($uid);
	if(!$user){
       $data = array(
       	'success' => 0,
		'message' => 'user: '.$uid.' not found'
       );		
		return $data;
	
	}
	

   if($type == 'activity'){
	  
	   $result =  _activity_logs($uid,$data);
   }else{
	   
	   $result =  _nutrition_logs($uid,$data);
   }
   
   
   $rows = array();
   if($result){
     $rows['success'] = 1;
 	 $rows['message'] = 'updated logs';
   }else{
     $rows['success'] = 0;
 	 $rows['message'] = 'Something went wrong';
   }
  
   return $rows;
	
}

function _activity_logs($uid,$data){
	
	$user = user_load($uid);
	if(!$user){
       $data = array(
       	'success' => 0,
		'message' => 'user: '.$uid.' not found'
       );		
		return $data;
	
	}
	

   watchdog('activity logs', "UID  = " . $uid. "<br><pre>".print_r($data, TRUE)."</pre>");

   if(isset($data['date'])){
   
   //single record
   
   //
   
	$date = "'".gmdate("Y-m-d", $data["date"])."'";

	$query = db_select('activity_logs', 'a');
	$query->fields('a');
	$query->condition('a.uid',$uid,'=');
	$query->where("from_unixtime(date, '%Y-%M-%D') = from_unixtime(:adate, '%Y-%M-%D')", array(':adate' => $data['date']));
	$result = $query->execute();

	while($rdata = $result->fetchAssoc()) {
		$id = $rdata['id'];
    }

    if ($id == 0){
	$data['uid'] = $uid;
    $data['created'] = time();
	$data['updated'] = time();
	$id = db_insert('activity_logs')
	      ->fields($data)
	      ->execute();
	  watchdog('activity logs', "ID  = " . $id);
    }else{
		$data['updated'] = time();
		$id = db_update('activity_logs')
		      ->fields($data)
		      ->condition('id',$id,'=')
		      ->execute();
    }
	$data['uid'] = $uid;
    _calculate_points($data);
   
   return true;
   
   
   
   
   }else{
	    if(isset($data['activePoints'])){
		   
		    $data = $data['activePoints'];
		}
	 	$i = 1;
	   foreach($data as $record){
	 
	 	$id = 0; 
	
	 	
	
	
	    $record['date'] = floor($record['date']);
		$rdate = "'".gmdate("Y-m-d", $record["date"])."'";
		
	 	$query = db_select('activity_logs', 'a');
	 	$query->fields('a');
	 	$query->condition('a.uid',$uid,'=');
	 	$query->where("from_unixtime(date, '%Y-%M-%D') = from_unixtime(:adate, '%Y-%M-%D')", array(':adate' => $record['date']));
	 	$result = $query->execute();
    
	 	while($rdata = $result->fetchAssoc()) {
	 		$id = $rdata['id'];
	     }
	
	   if ($id == 0){
	    $record['created'] = $record['date'];
		$record['updated'] = $record['date'];
	 	$record['uid'] = $uid;
	 	$id = db_insert('activity_logs')
	 	      ->fields($record)
	 	      ->execute();
	 	  watchdog('activity_logs', 'UID  = ' . $uid . ' for: '.$rdate  );
	     }else{
			watchdog('activity_logs', ' UPDATE UID  = ' . $uid . ' for: '.$rdate  );
			$data['updated'] = time();
	 		$id = db_update('activity_logs')
	 		      ->fields($record)
	 		      ->condition('id',$id,'=')
	 		      ->execute();
	     }
	    $record['uid'] = $uid;
	    _calculate_points($record);
	   }
	     
	     return true;
   
   }
  
  

}


function _exercise_logs($uid,$data){
	

   watchdog('exercise logs', "UID  = " . $uid. "<br><pre>".print_r($data, TRUE)."</pre>");

   if(isset($data['date'])){
   
   //single record
   
   //
   
	$date = "'".gmdate("Y-m-d", $data["date"])."'";

	$query = db_select('exercise_logs', 'a');
	$query->fields('a');
	$query->condition('a.uid',$uid,'=');
	$query->where("from_unixtime(date, '%Y-%M-%D') = from_unixtime(:adate, '%Y-%M-%D')", array(':adate' => $data['date']));
	$result = $query->execute();

	while($rdata = $result->fetchAssoc()) {
		$id = $rdata['id'];
    }

    if ($id == 0){
	$data['uid'] = $uid;
    $data['created'] = time();
	$data['updated'] = time();
	$id = db_insert('activity_logs')
	      ->fields($data)
	      ->execute();
	  watchdog('activity logs', "ID  = " . $id);
    }else{
		$data['updated'] = time();
		$id = db_update('activity_logs')
		      ->fields($data)
		      ->condition('id',$id,'=')
		      ->execute();
    }
   
   
   return true;
   
   
   
   
   }else{
	    if(isset($data['activePoints'])){
		   
		    $data = $data['activePoints'];
		}
	 	$i = 1;
	   foreach($data as $record){
	 
	 	$id = 0; 
	
	 	
	
	
	    $record['date'] = floor($record['date']);
		$rdate = "'".gmdate("Y-m-d", $record["date"])."'";
		
	 	$query = db_select('activity_logs', 'a');
	 	$query->fields('a');
	 	$query->condition('a.uid',$uid,'=');
	 	$query->where("from_unixtime(date, '%Y-%M-%D') = from_unixtime(:adate, '%Y-%M-%D')", array(':adate' => $record['date']));
	 	$result = $query->execute();
    
	 	while($rdata = $result->fetchAssoc()) {
	 		$id = $rdata['id'];
	     }
	
	   if ($id == 0){
	    $record['created'] = $record['date'];
		$record['updated'] = $record['date'];
	 	$record['uid'] = $uid;
	 	$id = db_insert('activity_logs')
	 	      ->fields($record)
	 	      ->execute();
	 	  watchdog('activity_logs', 'UID  = ' . $uid . ' for: '.$rdate  );
	     }else{
			watchdog('activity_logs', ' UPDATE UID  = ' . $uid . ' for: '.$rdate  );
			$data['updated'] = time();
	 		$id = db_update('activity_logs')
	 		      ->fields($record)
	 		      ->condition('id',$id,'=')
	 		      ->execute();
	     }
	
	
	   }	
	     return true;
   
   }
  
  

}




function _nutrition_logs($uid,$data){

   if(isset($data['date'])){
   
   //single record
   
   
   
	$date = "'".gmdate("Y-m-d", $data["date"])."'";

	$query = db_select('nutrition_logs', 'a');
	$query->fields('a');
	$query->condition('a.uid',$uid,'=');
	$query->where("from_unixtime(date, '%Y-%M-%D') = from_unixtime(:adate, '%Y-%M-%D')", array(':adate' => $data['date']));
	$result = $query->execute();

	while($rdata = $result->fetchAssoc()) {
		$id = $rdata['id'];
    }

    if ($id == 0){
    $data['created'] = time();
	$data['updated'] = time();
	$data['uid'] = $uid;
	$id = db_insert('nutrition_logs')
	      ->fields($data)
	      ->execute();
	  watchdog('nutrition_logs', "ID  = " . $id);
    }else{
		$data['updated'] = time();
		$id = db_update('nutrition_logs')
		      ->fields($data)
		      ->condition('id',$id,'=')
		      ->execute();
    }
   
   
   return true;
   
   
   
   
   }else{
	   
	 	$i = 1;
	   foreach($data as $record){
	 
	 	$id = 0; 
	
	 	$date = "'".gmdate("Y-m-d", $record["date"])."'";
	
	 	$query = db_select('nutrition_logs', 'a');
	 	$query->fields('a');
	 	$query->condition('a.uid',$uid,'=');
	 	$query->where("from_unixtime(date, '%Y-%M-%D') = from_unixtime(:adate, '%Y-%M-%D')", array(':adate' => $data['date']));
	 	$result = $query->execute();
    
	 	while($rdata = $result->fetchAssoc()) {
	 		$id = $rdata['id'];
	     }
	
	     if ($id == 0){
		$data['created'] = time();
	 	$data['updated'] = time();
	 	$record['uid'] = $uid;
	 	$id = db_insert('nutrition_logs')
	 	      ->fields($record)
	 	      ->execute();
	 	  watchdog('nutrition_logs', "ID  = " . $id);
	     }else{
			$data['updated'] = time();
	 		$id = db_update('nutrition_logs')
	 		      ->fields($record)
	 		      ->condition('id',$id,'=')
	 		      ->execute();
	     }
	
	
	   }	
	     return true;
   
   }
  
  

}

function _calculate_points($data){
	

    $a = 0;
	$act = 0;
	//formula
	$daily_challenge = $data['daily_challenge_goal'] * 10;
	if($data['total_steps_goal'] > 0){
		$steps = round(($data['total_steps']/$data['total_steps_goal']) * 100);
		$act++;
	}else{
		$steps = 0;
	}
	if($data['time_active_high_goal'] > 0){
		$high = round(($data['time_active_high']/$data['time_active_high_goal']) * 100);
		$a++;
	}else{
		$high = 0;
	}
	
	if($data['time_medium_high_goal'] > 0){
		$medium = round(($data['time_active_medium']/$data['time_medium_high_goal']) * 100);
		$a++;
	}else{
		$medium = 0;
	}
	
	if($data['time_low_high_goal'] > 0){
		$low = round(($data['time_active_low']/$data['time_low_high_goal']) * 100);
		$a++;
	}else{
		$low = 0;
	}
	
	
	if($data['exercise_goal'] > 0){
		$exercise = round(($data['total_exercise']/$data['exercise_goal']) * 100);
	}else{
		$exercise = 0;
	}
	
	if($steps > 100){
		$steps = 100;
	}
	
	if($exercise > 100){
		$exercise = 100;
	}
	
	if($low > 100){
		$low = 100;
	}
	
	if($medium > 100){
		$medium = 100;
	}
	
	if($high > 100){
		$high = 100;
	}
	
	if($a > 0){
		$activity = round(($low + $meduim + $high )/$a);
	}else{
		$activity = 0;
	}
	
	
	if($a > 0){
		$act++;
	}
	

	if($act > 0){
		$total_activity = round(($activity + $steps)/$act);
	}

	
	$day_points =  $total_activity + $exercise + $daily_challenge;

	$goals = 0;
	
		
	$points = array(
		'uid' => $data['uid'],
		'pt_date' => $data['date'],
		'activity' => $total_activity,
		'exercises' => $exercise,
		'daily_challenge' => $daily_challenge,
		'goals' => $goals,
		'daily_points' => $day_points,
		'updated' => time()
		
	);
	
	$id = 0;
	
	$date = "'".gmdate("Y-m-d", $data["date"])."'";

	$query = db_select('health_points', 'a');
	$query->fields('a');
	$query->condition('a.uid',$data['uid'],'=');
	$query->where("from_unixtime(pt_date, '%Y-%M-%D') = from_unixtime(:adate, '%Y-%M-%D')", array(':adate' => $data['date']));
	$result = $query->execute();

	while($rdata = $result->fetchAssoc()) {
		$id = $rdata['id'];
    }
	
	if($id == 0){
		$points['created'] = time();
	 	$id = db_insert('health_points')
	 	      ->fields($points)
	 	      ->execute();
	}else{
		$points['updated'] = time();
		$id = db_update('health_points')
		      ->fields($points)
		      ->condition('id',$id,'=')
		      ->execute();
		
	}
 	
	$row['data'] = $data;
	$row['points'] = $points;
		
	return $row;
	
	
	
}

