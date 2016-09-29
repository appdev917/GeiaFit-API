<?php

/**
 * @file
 * Contains the resource callbacks for notifications.
 */


/**
 * Returns a collection of profile.
 *
 * @see geia_services_index_entities()
 */
function geia_services_notifications_index($uid) {
	
	$user = user_load($uid);
	if(!$user){
       $data = array(
       	'success' => 0,
		'message' => 'user: '.$uid.' not found'
       );		
		return $data;
	
	}

	$query = db_select('geia_notifications', 'c');
	$query->fields('c');
	$query->condition('c.uid',$uid,'=');
	$query->orderBy("created", "DESC");
	
	$result = $query->execute();
	$ch = array();
	$i = 1;
	while($record = $result->fetchAssoc()) {
		$data[] = $record;
    }
	
    $rows = array();
    if($data){
      $rows['success'] = 1;
  	  $rows['notifications'] = $data;
    }else{
      $rows['success'] = 0;
  	 $rows['message'] = 'Something went wrong';
    }
  
    return $rows;

}

function geia_services_notifications_read($id){
	
	
	$data['updated'] = time();
	$data['`read`'] = '1';
	$nid = db_update('geia_notifications')
	      ->fields($data)
	      ->condition('id',$id,'=')
	      ->execute();

    if($nid == 1){
      $rows['success'] = 1;
  	  $rows['message'] = 'notification was updated';
    }else{
      $rows['success'] = 0;
  	 $rows['message'] = 'Something went wrong';
    }
  
    return $rows;
}