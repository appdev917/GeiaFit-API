<?php

function geia_services_characteristics_index_access() {
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
function geia_services_characteristics_index($uid) {
	
	$user = user_load($uid);
	if(!$user){
       $data = array(
       	'success' => 0,
		'message' => 'user: '.$uid.' not found'
       );		
		return $data;
	
	}
	
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
 
  
  return $data;
}

function geia_services_characteristics_update($uid,$data) {
	
	$user = user_load($uid);
	if(!$user){
       $data = array(
       	'success' => 0,
		'message' => 'user: '.$uid.' not found'
       );		
		return $data;
	
	}
	
	
   if(isset($data['record_date'])){
   
   //single record
   
   
   
	$record_date = "'".gmdate("Y-m-d", $data["record_date"])."'";

	$query = db_select('characteristics', 'c');
	$query->fields('c');
	$query->condition('c.uid',$uid,'=');
	$query->condition('record_date',$data["record_date"],'=');
	$result = $query->execute();

	while($rdata = $result->fetchAssoc()) {
		$id = $rdata['id'];
    }

    if ($id == 0){
	$data['uid'] = $uid;
	$id = db_insert('characteristics')
	      ->fields($data)
	      ->execute();
	  watchdog('characteristics', "ID  = " . $id);
    }else{

		$id = db_update('characteristics')
		      ->fields($data)
		      ->condition('id',$id,'=')
		      ->execute();
    }
   
   
   return "OK Updated Single";
   
   
   
   
   }else{
	   
	 	$i = 1;
	   foreach($data as $record){
	 
	 	$id = 0; 
	
	 	$record_date = "'".gmdate("Y-m-d", $record["record_date"])."'";
	
	 	$query = db_select('characteristics', 'c');
	 	$query->fields('c');
	 	$query->condition('c.uid',$uid,'=');
	 	$query->condition('record_date',$record["record_date"],'=');
	 	$result = $query->execute();
    
	 	while($rdata = $result->fetchAssoc()) {
	 		$id = $rdata['id'];
	     }
	
	     if ($id == 0){
	 	$record['uid'] = $uid;
	 	$id = db_insert('characteristics')
	 	      ->fields($record)
	 	      ->execute();
	 	  watchdog('characteristics', "ID  = " . $id);
	     }else{
    	
	 		$id = db_update('characteristics')
	 		      ->fields($record)
	 		      ->condition('id',$id,'=')
	 		      ->execute();
	     }
	
	
	   }	
	     return "OK Updated multiple";
   
   }
  
  
	
	
}