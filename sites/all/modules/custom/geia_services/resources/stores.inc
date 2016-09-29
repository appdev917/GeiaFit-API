<?php

/**
 * @file
 * Contains the resource callbacks for store.
 */


/**
 * Returns a collection of store.
 *
 * @see geia_services_index_entities()
 */
function geia_services_stores_index() {
    global $user;
	$type = "store_location"; 
	$stores = node_load_multiple(array(), array('type' => $type));
    return $stores;
}

/**
 * Determines an API user's access to index address.
 */
function geia_services_stores_index_access() {
    return TRUE;
}



function geia_services_store_update($location_id,$data){


    return $data;
}