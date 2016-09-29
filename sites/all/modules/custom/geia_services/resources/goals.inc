<?php

/**
 * @file
 * Contains the resource callbacks for goals.
 */

/**
 * Returns a collection of profile.
 *
 * @see geia_services_index_entities()
 */
function geia_services_goals_index($type,$uid) {


	if($type == 'activity'):
	  return _get_activity_goals($uid,$limit);
	elseif($type == 'nutrition'):
	  return _get_nutrition_goals($uid,$limit);
	elseif($type == 'tresholds'):
	  return _get_activity_tresholds($uid);
	endif;

}

function _get_activity_goals($uid){
  $user = user_load($uid);

  $query = db_select('activity_goals', 'ag');
  $query->fields('ag');
  $query->condition('ag.uid',$uid,'=');
  $query->orderby('date','DESC');
  $result = $query->execute();
  $rows = array();
  while($record = $result->fetchAssoc()) {
        $data[] = array(
		  'id' => $record['id'],
          'goal_date' => $record['date'],
          'total_steps' => $record['total_steps'],
          'time_active_high' => $record['time_active_high'],
	      'time_active_medium' => $record['time_active_medium'],
	      'time_active_low' => $record['time_active_low'],
	      'instructions' => $record['instructions'],
   );


  }
   $data[0]['exercise'] = geia_pt_get_patients_daily_exercises($uid);
   $rows = array('data' => $data);
  if(count($rows) > 0){
    $rows['success'] = 1;
	$rows['message'] = 'Found  goals';
  }else{
    $rows['success'] = 0;
	$rows['message'] = 'No Activity goals have been set up for this user';
  }

  return $rows;
}


function _get_nutrition_goals($uid){
  $user = user_load($uid);


    $query = db_select('nutrition_goals', 'ng');
    $query->fields('ng');
    $query->condition('ng.uid',$uid,'=');
    $result = $query->execute();
    $rows = array();
    while($record = $result->fetchAssoc()) {
          $data[] = array(
		  'id' => $record['id'],
          'goal_date' => $record['date'],
          'total_calories' => $record['calories'],
          'fat_percent' => $record['fat'],
  	      'carbs_percent' => $record['carbohydrates'],
  	      'protein_percent' => $record['protein'],
  	      'instructions' => $record['instructions'],
		  'weight' => '0'
     );


    }

  $rows = array('data' => $data);

  if(count($rows) > 0){
    $rows['success'] = 1;
	$rows['message'] = 'Found  goals';
  }else{
    $rows['success'] = 0;
	$rows['message'] = 'No Goals have been set up for this user';
  }

  return $rows;
}

function _get_activity_tresholds($uid){

	$user = user_load($uid);
	$account = profile2_load_by_user($user,'main');

	$dob = $account->field_date_of_birth['und']['0']['value'];

    $low = 0;
	$high = 0;
	$age = 0;



	$age = DateTime::createFromFormat('Y-m-d h:m:s', $dob)
	     ->diff(new DateTime('now'))
	     ->y;

    $max_rate = 220 - $age;

	$high = round(($max_rate/100)*80);
	$low = round(($max_rate/100)*70);

    $data = array(
      'steps_low' => 85,
      'steps_high' => 105,
	  'hr_low' => $low,
	  'hr_high' => $high,
      );



      $query = db_select('treshhold_levels', 'tl');
      $query->fields('tl');
      $query->condition('tl.uid',$uid,'=');
      $result = $query->execute();
      $rows = array();
      while($record = $result->fetchAssoc()) {
	    $data = array(
	      'steps_min' => '5',
	      'steps_low' => $record['steps_low'],
	      'steps_high' => $record['steps_high'],
		  'hr_low' => $record['hr_low'],
		  'hr_high' => $record['hr_high'],
        );
	  }


    $rows = array('data' => $data);


    if(count($rows) > 0){
      $rows['success'] = 1;
  	$rows['message'] = 'Found  thresholds';
    }else{
      $rows['success'] = 0;
  	$rows['message'] = 'No treshholds were found for the user';
    }

    return $rows;
}

function geia_services_goals_update_access() {
    return TRUE;
}

function geia_services_goals_update($type, $uid, $data) {
    switch ($type) {
        case 'tresholds':
            _update_threshold_goal($uid, $data);
            break;
        case 'activity':
            _update_activity_goal($uid, $data);
            break;
    }
}

function _update_threshold_goal($uid, $data) {
    db_update('treshhold_levels')
      ->fields(array(
        'steps_low' => $data['steps_low'],
        'steps_high' => $data['steps_high'],
        'hr_low' => $data['hr_low'],
        'hr_high' => $data['hr_high'],
      ))
      ->condition('uid', $uid, '=')
      ->execute();
}

function _update_activity_goal($uid, $data) {
    db_insert('activity_goals')
      ->fields(array(
          'uid' => $uid,
          'total_steps' => $data['total_steps'],
          'time_active_high' => $data['time_active_high'],
          'time_active_medium' => $data['time_active_medium'],
          'time_active_low' => $data['time_active_low'],
          'instructions' => $data['instructions'],
          'created' => time(),
          'updated' => time(),
      ))
      ->execute();
}
