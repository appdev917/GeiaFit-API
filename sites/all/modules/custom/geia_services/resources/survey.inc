<?php

/**
 * @file
 * Contains the resource callbacks for profile.
 */


/**
 * Returns a collection of questions.
 *
 * @see geia_services_index_entities()
 */
function geia_services_survey_index($type) {
	$nid = 4;
	if($type == 'risk_analysis'){
	 $nid = 4;
	}
	$node = node_load($nid);
	
	$survey = array();
	$survey['nid'] = $node->nid;
	$survey['title'] = $node->title;
	$survey['description'] = $node->body['und'][0]['value'];
	$survey['disclaimer'] = $node->field_disclaimer['und'][0]['value'];
	$i=1;
	foreach($node->field_question['und'] as $question){
		
		$question_item = field_collection_item_load($question['value']);
		$question_value = $question_item->field_question_item['und'][0]['value'];
		$answers_items = array();
		foreach($question_item->field_answers['und'] as $answers){
			$answer_item = field_collection_item_load($answers['value']);
			$answers_items[] = array(
			   'points' => $answer_item->field_points['und'][0]['value'],
			   'answer' => $answer_item->field_answer['und'][0]['value'],
			);

		}
		
		$survey['questions'][] = array(
		'question_id' => $i,
		'question' => $question_value,
		//$i => $question_value,
		'answers' => $answers_items
		
		);
		
		
		

		$i++;
	
	}
 
  
  return $survey;
}

function geia_services_survey_save_answers($uid, $data){
	
	$user = user_load($uid);
	if(!$user){
       $data = array(
       	'success' => 0,
		'message' => 'user: '.$uid.' not found'
       );		
		return $data;
	
	}
	

   $record = array(
   
        'uid' => $uid,
		'created' => time(),
		'answers' => array (serialize($data)),
   
   );
    
	$id = db_insert('survey_data')
			      ->fields($record)
			      ->execute();
		
   watchdog('survey', "ID  = " . $id);
   
 $data = array(
 'success' => 1,
 'message' => 'Survey Data Saved');
 
 
 return $data;

}