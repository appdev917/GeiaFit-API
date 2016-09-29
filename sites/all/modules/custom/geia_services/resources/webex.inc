<?php

/**
 * @file
 * Contains the resource callbacks for webex.
 */

function geia_services_webex_update_access() {
    return TRUE;
}

function geia_services_webex_delete_access() {
    return TRUE;
}

/**
 * Returns a collection of exercisses.
 *
 * @see geia_services_index_entities()
 */

 function geia_services_webex_rx($uid){
	 
 	$user = user_load($uid);
 	if(!$user){
        $data = array(
        	'success' => 0,
 		'message' => 'user: '.$uid.' not found'
        );		
 		return $data;
	
 	}
 	$profile = profile2_load_by_user($user,'main');
 	$data['profile'] = $profile;
 	$data['account'] = $user;

 	//$webex_url = create_webexercise_account($data);

 	//$webex_rx = json_decode(get_webexercise_rx($data));

	$exercises = geia_pt_get_exercises($uid,'active');
	//get all for now
	//$exercises = geia_pt_get_exercises($uid);
	$webex_rx['comments'] = '';
	$webex_rx['patient_id'] = $profile->field_webex_patient_id['und'][0]['value'];

	$stoday = '';
 	$today =  date("w");

    switch ($today) {
        case "0":
            $stoday = 'sun';
             break;
        case "1":
             $stoday = 'mon';
             break;
        case "2":
             $stoday = 'tue';
             break;
         case "3":
             $stoday = 'wed';
             break;
         case "4":
            $stoday = 'thu';
            break;
         case "6":
            $stoday = 'fri';
            break;
         case "6":
            $stoday = 'sat';
            break;
    }

	foreach($exercises as $pexercise){
	   $exercise['peid'] = $pexercise['pe_id'];
	   $exercise['title'] = $pexercise['title'];
	   $exercise['comments'] = $pexercise['comments'];
	   $exercise['code'] = $pexercise['webexcode'];
	   $exercise['reps'] = $pexercise['reps'];
	   if(isset($pexercise['sets']) && $pexercise['sets'] > 0){
		    $exercise['sets'] = $pexercise['sets'];
	   }else{
		    $exercise['sets'] = '1';
	   }

	   $exercise['rest'] = $pexercise['rest'];

	   if(isset($pexercise['daily']) && $pexercise['daily'] > 0){
		    $exercise['daily'] = $pexercise['daily'];
	   }else{
		    $exercise['daily'] = '1';
	   }



	   $weekly = array(
	   'sun' => 0,
	   'mon' => 0,
	   'tue' => 0,
	   'wed' => 0,
	   'thu' => 0,
	   'fri' => 0,
	   'sat' => 0
	  );


	   $days = unserialize($pexercise['weekly']);

	   //return $days;
	   $exercise['today'] = 0;
	   $exercise['alldays'] = 0;
	   foreach($days as $day){

		  if($day != false){


		  if($stoday == (string)$day){

		     $exercise['today'] = 1;
		  }

		   switch ($day) {
		       case "sun":
		           $weekly['sun'] = 1;
		            break;
		       case "mon":
		            $weekly['mon'] = 1;
		            break;
		       case "tue":
		            $weekly['tue'] = 1;
		            break;
	           case "wed":
	               $weekly['wed'] = 1;
	               break;
	           case "thu":
	              $weekly['thu'] = 1;
	              break;
	           case "fri":
	              $weekly['fri'] = 1;
	              break;
               case "sat":
                  $weekly['sat'] = 1;
                  break;
		   }
		  }
	   }


	   if(array_sum($weekly) == 7){
		   $exercise['alldays'] = 1;
	   }

	   $exercise['weekly'] = $weekly;

	   $exercise['mp4'] = $pexercise['mp4'];
	   $exercise['webm'] = $pexercise['webm'];
	   $exercise['mov'] = $pexercise['mov'];

	   $exercise['thumb1'] = $pexercise['image1'];
	   $exercise['thumb2'] = $pexercise['image2'];

	   $webex_rx['exercises'][] = $exercise;
	}


    if(isset($webex_rx)){
		return $webex_rx;
	}else{
	    $data = array(
		'success' => 0,
		'message' => "Your RX is not yet ready",
		);

		return $data;

	}


 }

function geia_services_webex_create($uid, $data) {
	$user = user_load($uid);
	if(!$user){
       $data = array(
       	'success' => 0,
		'message' => 'user: '.$uid.' not found'
       );		
		return $data;
	
	}
	
    $profile = profile2_load_by_user($user,'main');
    $data['profile'] = $profile;
    $data['account'] = $user;

    $name = $data['video_name'];

    $video_name = $data['video_name'];
    $video_name = str_replace(' ', '',preg_replace("/[^A-Za-z0-9 ]/", '', $name)).'-'.$uid.'-'.$video_name.'.mp4';
    $video_name = str_replace(' ', '',$video_name);
    $videoData = base64_decode($data['video_data']);
    $video = file_save_data($videoData, 'public://'.$video_name, FILE_EXISTS_REPLACE);

    $video_image_name = $data['video_image_name'];
    $video_image_name = str_replace(' ', '',preg_replace("/[^A-Za-z0-9 ]/", '', $name)).'-'.$uid.'-'.$video_image_name.'.jpg';
    $videoimageData = base64_decode($data['video_image']);
    $image = file_save_data($videoimageData, 'public://'.$video_image_name, FILE_EXISTS_REPLACE);

    $video_url = file_create_url($video->uri);
    $image_url = image_style_url('video_image', $image->uri);

    if (isset($data['video_image_name2'])) {
    	$video_image_name2 = $data['video_image_name2'];
    	$video_image_name2 = str_replace(' ', '',preg_replace("/[^A-Za-z0-9 ]/", '', $name)).'-'.$uid.'-'.$video_image_name2.'.jpg';
    	$videoimageData2 = base64_decode($data['video_image2']);
    	$image2 = file_save_data($videoimageData2, 'public://'.$video_image_name, FILE_EXISTS_REPLACE);

    	$image2_url = image_style_url('video_image2', $image2->uri);
    } else {
        $image2_url = $image_url;
    }

    $record['owner'] = $uid;
    $record['webexcode'] = $video_name;
    $record['title'] = $name;
    $record['created'] = time();
    $record['updated'] = time();

    $recordv['mp4'] = $video_url;
    $recordv['created'] = time();
    $recordv['updated'] = time();

    $recordi['image1'] = $image_url;
    $recordi['image2'] = $image2_url;
    $recordi['created'] = time();
    $recordi['updated'] = time();

    $recordp['active'] = 1;
    $recordp['uid'] = $uid;
    $recordp['reps'] = $data['reps'];
    $recordp['sets'] = $data['sets'];
    $recordp['rest'] = isset($data['rest']) ? $data['rest'] : 0;
    $recordp['daily'] = $data['daily'];
    $recordp['weekly'] = geia_services_process_week_days($data['week_days']);
    $recordp['webexcode'] = $video_name;
    $recordp['comments'] = isset($data['comments']) ? $data['comments'] : '';
    $recordp['created'] = time();
    $recordp['updated'] = time();

    $id = 0;

    $query = db_select('exercises', 'e');
    $query->fields('e');
    $query->condition('e.owner',$uid,'=');
    $query->condition('e.webexcode',$video_name,'=');
    $result = $query->execute();

    while ($rdata = $result->fetchAssoc()) {
    	$id = $rdata['id'];
    }
    if ($id == 0) {
        $record['created'] = time();
        $record['updated'] = time();
        	$id = db_insert('exercises')
        	      ->fields($record)
        	      ->execute();
        watchdog('exercises', "ID  = " . $id);

        //add video
        $recordv['exid'] = $id;
        db_insert('exercise_videos')
            ->fields($recordv)
            ->execute();
        watchdog('exercise_video', "ID  = " . $id);

        //add image

        $recordi['exid'] = $id;
        db_insert('exercise_images')
            ->fields($recordi)
            ->execute();
        watchdog('exercise_image', "ID  = " . $id);

        //insert patient prescription

        $recordp['exid'] = $id;
        db_insert('patient_exercises')
            ->fields($recordp)
            ->execute();
        watchdog('patient_exercises', "ID  = " . $id);

    } else {
        $record['updated'] = time();
        db_update('exercises')
            ->fields($record)
            ->condition('id',$id,'=')
            ->execute();

        //videos
        db_update('exercise_videos')
            ->fields($recordv)
            ->condition('exid',$id,'=')
            ->execute();

        //images
        db_update('exercise_images')
            ->fields($recordi)
            ->condition('exid',$id,'=')
            ->execute();

        //prescription
        db_update('patient_exercises')
            ->fields($recordp)
            ->condition('exid',$id,'=')
            ->execute();
    }

    return array(
        'success' => 1,
        'message' => 'Custom Exercise Data Saved',
    );
}

function geia_services_webex_update($uid, $data) {
	
	
	$user = user_load($uid);
	if(!$user){
       $data = array(
       	'success' => 0,
		'message' => 'user: '.$uid.' not found'
       );		
		return $data;
	
	}
	
	
    $row = array(
        'reps' => $data['reps'],
        'sets' => $data['sets'],
        'rest' => $data['rest'],
        'daily' => $data['daily'],
        'weekly' => geia_services_process_week_days($data['week_days']),
        'comments' => $data['comments'],
        'updated' => time(),
    );
    $n = db_update('patient_exercises')
        ->fields($row)
        ->condition('id', $data['peid'], '=')
        ->execute();
    return array(
        'success' => $n > 0,
        'message' => $n ? t('Custom exercise saved') : t('Error on update'),
    );
}

function geia_services_webex_delete($uid, $peid) {
	
	$user = user_load($uid);
	if(!$user){
       $data = array(
       	'success' => 0,
		'message' => 'user: '.$uid.' not found'
       );		
		return $data;
	
	}
	
    $n = db_delete('patient_exercises')
        ->condition('id', $peid, '=')
        ->execute();
    return array(
        'success' => $n > 0,
        'message' => $n ? t('Custom exercise deleted') : t('Error on delete'),
    );
}

function geia_services_process_week_days($week_days) {
    $days = array('sun', 'mon', 'tue', 'wed', 'thu', 'fri', 'sat');
    $weekly = array();
    foreach ($days as $day) {
        $weekly[$day] = 0;
    }
    foreach ($week_days as $week_day) {
        $day = $days[$week_day['day']];
        if ($week_day['on'] == 1) {
            $weekly[$day] = $day;
        }
    }
    return serialize($weekly);
}

 function geia_services_webex_record($uid,$peid,$date){
	 
 	$user = user_load($uid);
 	if(!$user){
        $data = array(
        	'success' => 0,
 		'message' => 'user: '.$uid.' not found'
        );		
 		return $data;
	
 	}

	 $exercise = array(
		 'uid' => $uid,
		 'peid' => $peid,
		 'date' => $date,
		 'created' => time()
	 );

 	  $id = db_insert('exercise_tracking')
 	      ->fields($exercise)
 	      ->execute();
 	  watchdog('exercise tracking', "UID  = " . $uid);

	   $data = array(
	   'success' => 1,
	   'message' => 'Your exercise was logged');


	   return $data;
 }
 
 function geia_services_webex_ptlib($uid){
	 
 	$user = user_load($uid);
 	if(!$user){
        $data = array(
        	'success' => 0,
 		'message' => 'user: '.$uid.' not found'
        );		
 		return $data;
	
 	}
	
	
	 global $user;
	 
 	$query = db_select('exercises', 'e');
 	$query->join('exercise_videos', 'ev', 'e.id = ev.exid');
 	$query->join('exercise_images', 'ei', 'e.id = ei.exid');
 	$query->fields('e');
 	// $query->addField('pe', 'id', 'pe_id');
 	$query->fields('ev');
 	$query->fields('ei');
 	// if($type == 'active'){
//  		$query->condition('pe.active', 1, '=');
//  	}
 	$query->condition('e.owner', $uid, '=');
	
 	$result = $query->execute();
 	$exercises = array();
 	while ($record = $result->fetchAssoc()) {
 		$exercises[] = $record;
 	}
	
 	return $exercises;
	
	
	
 }
