<?php

function geia_services_logs_index_access() {
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
function geia_services_messages_index($uid,$timestamp = 0000000000) {
	
	$user = user_load($uid);
	if(!$user){
       $data = array(
       	'success' => 0,
		'message' => 'user: '.$uid.' not found'
       );		
		return $data;
	
	}
	
    $sql = "SELECT m.message_id, m.uid1, m.uid2, m.message, m.timestamp 
            FROM drupalchat_msg m 
            WHERE (m.uid2 = 1 OR m.uid1 = 1) AND m.timestamp > 1454005077 ORDER BY m.timestamp ASC";



	$query = db_select('drupalchat_msg','m');
	$query->fields('m');
	$query->condition('timestamp',$timestamp,'>');
	$query->where('m.uid2 = '.$uid.' OR m.uid1 = '.$uid);
	

	$result = $query->execute();

    $data = array();
	while($record = $result->fetchAssoc()) {
		$message = array(
		'message_id' => $record['message_id'],
		'uid1' => $record['uid1'],
		'uid2' => $record['uid2'],
		'message' => $record['message'],
		'timestamp' => $record['timestamp']
		);
		
		$data[] = $message;

    }
 
  
  return $data;
}

function geia_services_messages_update($uid,$data) {
   
	$user = user_load($uid);
	if(!$user){
       $data = array(
       	'success' => 0,
		'message' => 'user: '.$uid.' not found'
       );		
		return $data;
	
	}
  $rows = array();
  
  $user = user_load($uid);
  $profile = profile2_load_by_user($user,'main');
  
  $sender = $uid;
  
  if(!(isset($data['recipient']))){
	  if((!isset($user->field_therapist['und'][0]['uid']))){
	     $rows['success'] = 0;
		 $rows['message'] = 'You dont have a therapist assigned or you are a therapist sending to your self';
	     return $rows;
  
	  }
	  $recipient = $user->field_therapist['und'][0]['uid'];
	  $therapist = user_load($recipient);
	  
  }else{
  	
	  $recipient = $data['recipient'];
	
  }
  

  
  
  if($recipient == $sender){
     $rows['success'] = 0;
	 $rows['message'] = 'You are sending a message to your self, you must me a therapist';
     return $rows;
  }
   
  $message_time =  time();
  $milliseconds = round(microtime(true) * 1000);

  $message = $data['message'];
  
  $data = array(
      'message_id' => 'm_'.$sender.'_'.$recipient.'_'.$milliseconds,
	  'uid1' => $sender,
	  'uid2' => $recipient,
	  'message' => $message,
	  'timestamp' => $message_time
  );
  
  try{
	  
      db_insert('drupalchat_msg')
        ->fields($data)
        ->execute();
		
        $rows['success'] = 1;
    	$rows['message'] = 'message sent';
   	    $rows['timestamp'] = $message_time;
		$rows['message_id'] = 'm_'.$sender.'_'.$recipient.'_'.$milliseconds;
  }
  catch (PDOException $e) {
    drupal_set_message(t('Error: %message', array('%message' => $e->getMessage())), 'error');
	
     $rows['success'] = 0;
	 $rows['message'] = 'Something went wrong';
  }
  
  if($therapist){
	  
	  //let PT know there is a report ready to generate
	      drupal_mail('geia_services', 'pt_new_message',  $therapist->mail, user_preferred_language($therapist), array(
	          'firstname' => $profile->field_first_name['und'][0]['value'],
	          'lastname' => $profile->field_last_name['und'][0]['value'],
			  'message' =>  $message
	      ));
  	
  }
  
  $m_data = array(
   'uid' => $recipient,
   'category' => 'messages',
   'title' => $profile->field_first_name['und'][0]['value'].' '.$profile->field_last_name['und'][0]['value'].' sent you a message',
   'message' => $message,
   'image_url' =>'', 
   'created' => time(),
   'updated' => time(),
	
  );
 
   geia_services_create_notification($m_data);
  
   return $rows;
	
}






  function geia_create_message($recuid,$senduid,$body,$subject = 'app message'){


  		   $recipient = user_load($recuid);
		   $recipient->type = 'user';
		   $recipient->recipient = $recipient->uid;
			   
	           $author = user_load($senduid);
			   $author->type = 'user';
			   $author->recipient = $recipient->uid;
		 
           $message = new stdClass();
  		 $message->author = $author;
  		 $message->body = $body;
  		 $message->subject = $subject;
  		 $message->recipient = $recipient->name;
  		 $message->op = 'Send message';
  		 $message->mid = 0;
		 $message->timestamp = time();
  		 $message->recipients = array(
  		   'user_1' => $recipient
  		    );
		 
			//print_r($message);die();
  	    $message = _privatemsg_send($message);
  		_privatemsg_handle_recipients($message->mid, $message->recipients);
		
		return true;
  }
