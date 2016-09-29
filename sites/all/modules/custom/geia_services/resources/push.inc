<?php

/**
 * @file
 * Contains the resource callbacks for push notifications.
 */


/**
 * Returns a collection of exercisses.
 *
 * @see geia_services_index_entities()
 */
 
 function geia_services_add_device($uid){
    
	
	
	$token = _push_notifications_service_create_device_token();
 
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

