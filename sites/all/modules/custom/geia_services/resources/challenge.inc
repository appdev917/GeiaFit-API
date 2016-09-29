<?php

/**
 * @file
 * Contains the resource callbacks for challenge.
 */


/**
 * Returns a collection of exercisses.
 *
 * @see geia_services_index_entities()
 */
 
 function geia_services_challenge($uid){
    
	
	
	$t=getdate();
	$randseed = mktime(0, 0, 0, $t['mday'], $t['mon'], $t['year']);
	
	$query = db_select('node', 'a');
	$query->fields('a');
	$query->condition('type','daily_challenge','=');
	//$query->orderby('', "rand($randseed)", "ASC", 'random_sort');
	$result = $query->execute();
    $data = array();
	while($rdata = $result->fetchAssoc()) {
		$data[] = $rdata['nid'];
    }
	$max = count($data) - 1;
	$min = 0;
	mt_srand($randseed);
	$random = mt_rand($min, $max);

	$node = node_load($data[$random]);
	
 
    if(isset($node)){
		return $node->body['und'][0]['value'];
	}else{
	    $data = array(
		'success' => 0,
		'message' => "The is no challenge",
		);
		
		return $data;
	
	}
 
    
 }