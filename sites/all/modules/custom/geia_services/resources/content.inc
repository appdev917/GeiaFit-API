<?php

/**
 * @file
 * Contains the resource callbacks for webex.
 */

function geia_services_content($type){
	
	switch ($type) {
	    case "health_points":
	        return _health_points();
	        break;
	    case "prescription":
	        return _prescription();
	        break;
	    case "outcome_meassures":
	        return _outcome_meassures();
	        break;
			default:
			$data = array(
				'success' => 0,
				'message' => 'something went wrong',
			);
			return $data;
			break;
	}
	
	
	
}

function _health_points(){
	
	$html = '<p>Health points are caclculated by</p>';
	$html .='<ul><li>activity</li><li>exercise</li><li>goals</li></ul>';
	
	$data = array(
		'success' => 1,
		'content' => $html,
	);
	
	return $data;
}

function _prescription(){
	
	$html = '<p>your activuty is based on thresholds set by your therapis</p>';
	
	$data = array(
		'success' => 1,
		'content' => $html,
	);
	
	return $data;
}


function _outcome_meassures(){
	
	$html = '<p>It is important for you to fill out these goal questions so we can provice best service possible</p>';
	
	$data = array(
		'success' => 1,
		'content' => $html,
	);
	
	return $data;
}