<?php


function geia_services_posture($uid){
	
	$user = user_load($uid);
	if(!$user){
       $data = array(
       	'success' => 0,
		'message' => 'user: '.$uid.' not found'
       );		
		return $data;
	
	}

       $url = '';
	   $sql = "select entity_id from field_data_field_patient where (bundle = 'posture' or bundle = 'posture_video') and field_patient_uid = :uid";

       $result = db_query($sql, array(':uid' => $uid));
       $data = array();
	   foreach($result as $record) {
       $report = array();
	     $nid = $record->entity_id;
		 
		 
  	     $node = node_load($nid);
		 
		 if($node->status == 1){  
		     $report['status'] = "Reported";
		 }else{
		 	 $report['status'] = "Pending";
		 }
			 if($node->type == 'posture'){
				 $report['type'] = 'images';
				 $report['report_created'] = $node->created;
				 $report['report_comments'] = $node->field_report_summary['und'][0]['value'];
		 
				 $images = array();
			 
				 if(isset($node->field_front_report_image['und'])){
				 
					 $images[]['name'] = $node->field_front_report_image['und'][0]['filename'];
					 $images[]['url'] = file_create_url($node->field_front_report_image['und'][0]['uri']);
					 $images[]['comments'] = $node->field_front_image_comments['und'][0]['value'];
				 
				 }
			 
				 if(isset($node->field_left_report_image['und'])){
				 
					 $images[]['name'] = $node->field_left_report_image['und'][0]['filename'];
					 $images[]['url'] = file_create_url($node->field_left_report_image['und'][0]['uri']);
					 $images[]['comments'] = $node->field_left_image_comments['und'][0]['value'];
				 
				 }
			 
				 if(isset($node->field_right_report_image['und'])){
				 
					 $images[]['name'] = $node->field_right_report_image['und'][0]['filename'];
					 $images[]['url'] = file_create_url($node->field_right_report_image['und'][0]['uri']);
					 $images[]['comments'] = $node->field_right_image_comments['und'][0]['value'];
				 
				 }
			 
				 if(isset($node->field_back_report_image['und'])){
				 
					 $images[]['name'] = $node->field_back_report_image['und'][0]['filename'];
					 $images[]['url'] = file_create_url($node->field_back_report_image['und'][0]['uri']);
					 $images[]['comments'] = $node->field_back_image_comments['und'][0]['value'];
				 
				 }
			 
				 if(isset($node->field_other_report_image['und'])){
				 
					 $images[]['name'] = $node->field_other_report_image['und'][0]['filename'];
					 $images[]['url'] = file_create_url($node->field_other_report_image['und'][0]['uri']);
					 $images[]['comments'] = $node->field_other_image_comments['und'][0]['value'];
				 
				 }
		 
			 

		 
				 $report['images'] = $images;
		 
				 $data[] = $report;
			 }else{
				 //video
				 $report['type'] = 'video';
				 $report['report_created'] = $node->created;
				 $report['report_comments'] = $node->field_report_summary['und'][0]['value'];
				 
				 $images = array();
			 
				 if(isset($node->field_video_image['und'])){
				 
					 $images[]['name'] = $node->field_video_image['und'][0]['filename'];
					 $images[]['url'] = file_create_url($node->field_video_image['und'][0]['uri']);
					 $images[]['comments'] = $node->field_report_summary['und'][0]['value'];
					 $images[]['video_url'] = file_create_url($node->field_custom_video['und'][0]['uri']);
					 $images[]['video_name'] = $node->field_custom_video['und'][0]['filename'];
				 
				 }
				 
				 $videos = array();
				 
				 if(isset($node->field_custom_video['und'])){
				 
					 $videos[]['name'] = $node->field_custom_video['und'][0]['filename'];
					 $videos[]['url'] = file_create_url($node->field_custom_video['und'][0]['uri']);
					 
				 
				 }
				
				
		 
				 $report['images'] = $images;
				 $report['videos'] = $videos;
		 
				 $data[] = $report;
			 }
			 
			 
		 
		 
		 
	   }
       
	   
       if(count($data) == 0){
		  $data = array(
		  'success' => 0,
		  'message' => "Posture Data not available",
		  );
		  return $data;
       }else{
		 $data['success'] = 1;
       	 return $data;
       }

}


function geia_services_posture_create($uid,$type = 'images' ,$data){
	
	$user = user_load($uid);
	if(!$user){
       $data = array(
       	'success' => 0,
		'message' => 'user: '.$uid.' not found'
       );		
		return $data;
	
	}

 global $user;
 
 

 
 //get patients PT 
 $ptuid = geia_get_patients_pt($uid);
 $therapist = user_load($ptuid);
 
 
 if($type == 'video'){
	 
	$data = _posture_video($ptuid,$uid,$data);
 	
 }else{
	 
 	$data = _posture_image($ptuid,$uid,$data);
	
 }

     return $data;


}
function _posture_video($ptuid,$uid,$data){
	$user = user_load($uid);
	if(!$user){
       $data = array(
       	'success' => 0,
		'message' => 'user: '.$uid.' not found'
       );		
		return $data;
	
	}
	
    $profile = profile2_load_by_user($user,'main');
    if(isset($ptuid) && (count($data) > 0)){
       //create posture node with images
        $node = new stdClass();
		if($data['name'] <>''){
			$node->title = 'Video for: '.$profile->field_last_name['und'][0]['value'].': '.$data['name'];
		}else{
			$node->title = 'Video for: '.$profile->field_first_name['und'][0]['value'].' '.$profile->field_last_name['und'][0]['value'];
		}
		
        
        $node->type = 'posture_video';
        $node->uid =  $ptuid; 
        $node->status = 0; //(1 or 0): published or not
   	    $node->field_patient['und'][0]['uid'] = $uid;

	 
	
	
   
   	  	$image_data = base64_decode($data['video_image']);   
   		$image_name = $data['video_image_name'];
	
   	
   	  	$file = file_save_data($image_data, 'public://'.$image_name, FILE_EXISTS_REPLACE);
		$node->field_video_image['und'][0] = (array)$file;
		
		
		$name = $data['video_name'];
		
		$video_name = $data['video_name'];
		$video_name = str_replace(' ', '',preg_replace("/[^A-Za-z0-9 ]/", '', $name)).'-'.$uid.'-'.$video_name;
		$video_name = str_replace(' ', '',$video_name);
		$videoData = base64_decode($data['video_data']);
		$video = file_save_data($videoData, 'public://'.$video_name, FILE_EXISTS_REPLACE);
		$video->display = TRUE;
		$video->title = $data['name'];
		$node->field_custom_video['und'][0] = (array)$video;

         
		
		 
		 
		$node->field_video_description['und'][0] = $data['comments'];
	  
   	  $node = node_submit($node); // Prepare node for saving

   	  node_save($node); 
	  
	  
   	  if($node){
   		  $data = array(
   		  'success' => 1,
   		  'message' => "Posture video was saved",
   		  );
   	  }
  
    }else{
 
      
   	  $data = array(
   	  'success' => 0,
   	  'message' => "Posture Video was not saved",
   	  );
	  
    }
 
  
  
  
  
     //TO DO
 
    //let PT know there is a report ready to generate
        drupal_mail('geia_services', 'posture_data_received',  $therapist->mail, user_preferred_language($therapist), array(
            'firstname' => $profile->field_first_name['und'][0]['value'],
            'lastname' => $profile->field_last_name['und'][0]['value'],
        ));
		
		
		return $data;
	
	
}

function _posture_image($ptuid,$uid,$data){
    $user = user_load($uid);
    $profile = profile2_load_by_user($user,'main');
    if(isset($ptuid) && (count($data) > 0)){
       //create posture node with images
        $node = new stdClass();
        $node->title = 'Posture for: '.$profile->field_first_name['und'][0]['value'].' '.$profile->field_last_name['und'][0]['value'];
        $node->type = 'posture';
        $node->uid =  $ptuid; 
        $node->status = 0; //(1 or 0): published or not
   	 $node->field_patient['und'][0]['uid'] = $uid;

	 
	
	
   	  //get the images and seve them to the node;
   	  $i = 0;
   	  foreach($data['images'] as $image){
		  
   	  	$image_data = base64_decode($image['image_data']);   
   		$image_name = $image['image_name'];
	
   	
   	  	 $file = file_save_data($image_data, 'public://'.$image_name, FILE_EXISTS_REPLACE);
        
   			switch ($i) {
   			    case 0:
   			        $node->field_front_image['und'][0] = (array)$file;
   			        break;
   			    case 1:
   			        $node->field_left_image['und'][0] = (array)$file;
   			        break;
   			    case 2:
   			        $node->field_right_image['und'][0] = (array)$file;
   			        break;
   			    case 3:
   			        $node->field_back_image['und'][0] = (array)$file;
   			        break;
   			    case 4:
   			        $node->field_other_image['und'][0] = (array)$file;
   			        break;
   			}
		 
		 
		 
   		 $i++;
	  
   	  }
	  
   	  $node = node_submit($node); // Prepare node for saving
   	  node_save($node);
	  
   	  if($i > 0){
   		  $data = array(
   		  'success' => 1,
   		  'message' => "Posture Data was saved: ".$i." images",
   		  );
   	  }
  
    }else{
 
      
   	  $data = array(
   	  'success' => 0,
   	  'message' => "Posture Data was not saved",
   	  );
	  
    }
 
  
  
  
  
     //TO DO
 
    //let PT know there is a report ready to generate
        drupal_mail('geia_services', 'posture_data_received',  $therapist->mail, user_preferred_language($therapist), array(
            'firstname' => $profile->field_first_name['und'][0]['value'],
            'lastname' => $profile->field_last_name['und'][0]['value'],
        ));
		
		
		return $data;
	
	
}






function geia_services_posture_create_bad($uid, $data){

 global $user;
 $user = user_load($uid);
 
$user = user_load($uid);
if(!$user){
    $data = array(
    	'success' => 0,
	'message' => 'user: '.$uid.' not found'
    );		
	return $data;

}
 
 $profile = profile2_load_by_user($user,'main');
 
 //get patients PT 
 $ptuid = geia_get_patients_pt($uid);
 
 
 
 if(isset($ptuid) && (count($data) > 0)){
    //create posture node with images
     $node = new stdClass();
     $node->title = 'Posture for: '.$profile->field_first_name['und'][0]['value'].' '.$profile->field_last_name['und'][0]['value'];
     $node->type = 'test';
     $node->uid =  $ptuid; 
     $node->status = 0; //(1 or 0): published or not
	 $node->field_patient['und'][0]['uid'] = $uid;
	 $node = node_submit($node); // Prepare node for saving
	 node_save($node);
	 
	 $node = node_load($node->nid);
	
	  //get the images and seve them to the node;
	  
	  foreach($data['images'] as $image){
		  
	  	$image_data = base64_decode($image['image_data']);   
		$image_name = $image['image_name'];
	
   	
	  	$file = file_save_data($image_data, 'public://drawingfield/'.$image_name, FILE_EXISTS_REPLACE);
		
		$url = file_create_url($file->uri);
		 
		$image_path = 'public://drawingfield/'.$image_name;
		$json_base64 = 'JSONdata:image/png;base64,'.$image['image_data'];
		$json = '{"shapes":[],"colors":{"primary":"#000","secondary":"#fff","background":"'.$url.'"}}';

		
		$data =  serialize(
		           array(
				     'json' => $json,
		             'json_base64' => $json_base64,
		             'image_path' => $image_path
					)
				  );
		 
		 $node->field_testimage['und'][0]['data'] = $data;
         
		 node_save($node);
	  }
	  
	  $node = node_load($node->nid);
	  
	  if( 1 == 0 ){
		  $data = array(
		  'success' => 1,
		  'message' => "Posture Data was saved:  1 images",
		  );
	  }
  
 }else{
 
      
	  $data = array(
	  'success' => 0,
	  'message' => "Posture Data was not saved",
	  );
	  
 }
 
  
  
  
  
  //TO DO
 
 //let PT know there is a report ready to generate

     return $node;


}