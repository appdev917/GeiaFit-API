<?php

function geia_services_outcome_measures_index_access() {
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
function geia_services_outcome_measures_index($uid) {
	
	$user = user_load($uid);
	if(!$user){
       $data = array(
       	'success' => 0,
		'message' => 'user: '.$uid.' not found'
       );		
		return $data;
	
	}
	
	
	$account = profile2_load_by_user($user,'main');
	$data = array();
	if(isset($account->field_outcome_goals['und'])){
		foreach($account->field_outcome_goals['und'] as $term){
			$ugoal = array();
			$tid = $term['tid'];
			
			
			$query = db_select('field_data_field_goal', 'g');
			$query->fields('g');
			$query->condition('field_goal_tid',$tid,'=');
			$query->condition('bundle','outcome_meassure','=');
			$result = $query->execute();
	
			while($goal = $result->fetchAssoc()) {
		
				$oc_goal = node_load($goal['entity_id']);
				//print_r($oc_goal);
				
				$ugoal['title'] = $oc_goal->title;
				$ugoal['nid'] = $oc_goal->nid;
				$questions = array();
				//get questions
				foreach($oc_goal->field_goal_question['und'] as $question_id){
					
					    $question_obj = entity_load('field_collection_item', array($question_id['value']));
						$question['question'] = $question_obj[$question_id['value']]->field_oc_question['und'][0]['value'];
						$question['item_id'] = $question_id['value'];
						$question['type'] = $question_obj[$question_id['value']]->field_question_type['und'][0]['value'];
						$question['unit'] = $question_obj[$question_id['value']]->field_unit['und'][0]['value'];
						$question['min'] = $question_obj[$question_id['value']]->field_min['und'][0]['value'];
						$question['max'] = $question_obj[$question_id['value']]->field_max['und'][0]['value'];
						$question['callback'] = $question_obj[$question_id['value']]->field_callback['und'][0]['value'];
						
						$questions[] = $question;
				}

				$ugoal['questions'] = $questions;
				$data['goals'][] = $ugoal;
			}
			
			
			
			
		}
		
        $data['success'] = 1;
    	$data['message'] = 'Users Questions';
		
	}else{
        $data['success'] = 0;
    	$data['message'] = 'OOPS something went wrong, or current user does not have any goals selected';

	}
	

  return $data;
}

function geia_services_outcome_measures_update($uid,$data) {
	
	$user = user_load($uid);
	if(!$user){
       $data = array(
       	'success' => 0,
		'message' => 'user: '.$uid.' not found'
       );		
		return $data;
	
	}
	
	
   if(isset($data['outcome_date'])){
   
   //single record
  

	$query = db_select('outcome_measures_log', 'omc');
	$query->fields('omc');
	$query->condition('omc.uid',$uid,'=');
	$query->where("from_unixtime(outcome_date, '%Y-%M-%D') = from_unixtime(:adate, '%Y-%M-%D')", array(':adate' => $data['outcome_date']));
	$result = $query->execute();

	while($rdata = $result->fetchAssoc()) {
		$id = $rdata['id'];
    }

    if ($id == 0){
	$data['uid'] = $uid;
	$data['updated'] = time();
	$data['created'] = time();
	$id = db_insert('outcome_measures_log')
	      ->fields($data)
	      ->execute();
	  watchdog('outcome_measures_log', "ID  = " . $id);
    }else{
        $data['updated'] = time();
		$id = db_update('outcome_measures_log')
		      ->fields($data)
		      ->condition('id',$id,'=')
		      ->execute();
    }
   
   
   return "OK Updated Single";
   
   
   
   
   }else{
	   
	 	$i = 1;
	   foreach($data as $record){
	 
	 	$id = 0; 
	
		$query = db_select('outcome_measures_log', 'omc');
		$query->fields('omc');
		$query->condition('omc.uid',$uid,'=');
		$query->where("from_unixtime(outcome_date, '%Y-%M-%D') = from_unixtime(:adate, '%Y-%M-%D')", array(':adate' => $record['outcome_date']));
		$result = $query->execute();
	 	
    
	 	while($rdata = $result->fetchAssoc()) {
	 		$id = $rdata['id'];
	     }
	
	     if ($id == 0){
	 	$record['uid'] = $uid;
		$record['updated'] = time();
		$record['created'] = time();
	 	$id = db_insert('outcome_measures_log')
	 	      ->fields($record)
	 	      ->execute();
	 	  watchdog('outcome_measures_log', "ID  = " . $id);
	     }else{
    	    $record['updated'] = time();
	 		$id = db_update('outcome_measures_log')
	 		      ->fields($record)
	 		      ->condition('id',$id,'=')
	 		      ->execute();
	     }
	
	
	   }	
	     return "OK Updated multiple";
   
   }
  
  
	
	
}