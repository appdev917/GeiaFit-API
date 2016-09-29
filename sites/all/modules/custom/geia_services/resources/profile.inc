<?php

/**
 * @file
 * Contains the resource callbacks for profile.
 */


/**
 * Returns a collection of profile.
 *
 * @see geia_services_index_entities()
 */
function geia_services_profile_index($uid) {
	global $base_url;
	$user = user_load($uid);
	
	if(!$user){
        $data = array(
        	'success' => 0,
			'message' => 'user: '.$uid.' not found'
        );		
		return $data;
		
	}
	
	$account = profile2_load_by_user($user,'main');

    
  foreach($account->field_goals['und'] as $goal){
	  $goals[] = $goal['value'];
  }
  if(isset($account->field_profile_image['und'])){
	  $image = $base_url."/sites/default/files/".$account->field_profile_image['und'][0]['filename'];
  }else{
      $image = "";
  }
  
  
  if(isset($account->field_total_gems['und'][0]['value'])){
     $gems = $account->field_total_gems['und'][0]['value'];
  }else{
     $gems = 0;
  }
  
  $profile = array(
  "success" => 1,
  "email" => $user->mail,
  "phone" => $account->field_phone['und'][0]['value'],
  "first_name" => $account->field_first_name['und'][0]['value'],
  "last_name" => $account->field_last_name['und'][0]['value'],
  "dob" => strtotime($account->field_date_of_birth['und'][0]['value']),
  "gender" => $account->field_gender['und'][0]['value'],
  "image" => $image,
  "goals" => $goals,
  "gems" => $gems,
  );
 
  
  return $profile;
}

/**
 * Determines an API user's access to index address.
 */
function geia_services_profile_index_access() {
    return TRUE;
}



function geia_services_profile_update($uid,$data){
	global $base_url;
   require_once DRUPAL_ROOT . '/' . variable_get('password_inc', 'includes/password.inc');
   $user = user_load($uid);
   
	if(!$user){
       $data = array(
       	'success' => 0,
		'message' => 'user: '.$uid.' not found'
       );		
		return $data;
	
	}
	
	$profile = profile2_load_by_user($user,'main');
	
	
	
	
	if(isset($data['last_name'])):
	 $profile->field_last_name['und'][0]['value'] = $data['last_name'];
	endif;
	if(isset($data['first_name'])):
	  $profile->field_first_name['und'][0]['value'] = $data['first_name'];
	endif;
	if(isset($data['gender'])):
	  $profile->field_gender['und'][0]['value'] = $data['gender'];
	endif;
	if(isset($data['dob'])):
      $profile->field_date_of_birth['und'][0]['value'] = gmdate("Y-m-d", $data['dob']);
	endif;
	if(isset($data['phone'])):
      $profile->field_phone['und'][0]['value'] = $data['phone'];
	endif;
	
	if(isset($data['goals'])){
	  unset($profile->field_goals);
	  $i = 0;
	  foreach($data['goals'] as $goal){
		
		$profile->field_goals['und'][$i]['value'] = $goal;
		$i++;
	 }
	}
	
	if(isset($data['password'])){
	  $user->pass = user_hash_password($data['password']);
	  $user = user_save($user);
	//update password
	}
	
	if(isset($data['field_onboarded'])){
	  $user->field_onboarded['und'][0]['value'] = $data['field_onboarded'];
	  $user = user_save($user);
	//update onboarded
	}
	
	
	if(isset($profile->field_total_gems['und'][0]['value'])){

	   $gems =  $profile->field_total_gems['und'][0]['value'];
	}else{
	   $gems = 0;
	}
	if(isset($data['gems'])){
	  $profile->field_total_gems['und'][0]['value'] = $gems + $data['gems'];
	}
	
	
    profile2_save($profile);
	$profile = profile2_load_by_user($user,'main');
    
	$goals = array();
	
    foreach($profile->field_goals['und'] as $goal){
  	  $goals[] = $goal['value'];
    }
    if(isset($profile->field_profile_image['und'])){
  	    $image = $base_url."/sites/default/files/".$profile->field_profile_image['und'][0]['filename'];
    }else{
        $image = "";
    }
	
    $account = array(
	"success" => 1,
    "email" => $user->mail,
    "first_name" => $profile->field_first_name['und'][0]['value'],
    "last_name" => $profile->field_last_name['und'][0]['value'],
    "dob" => strtotime($profile->field_date_of_birth['und'][0]['value']),
    "gender" => $profile->field_gender['und'][0]['value'],
    "image" => $image,
    "goals" => $goals,
    "gems" => $gems,
  
    );
 
  
    return $account;
}

/**
 * Determines an API user's access to update profile.
 */
function geia_services_profile_update_access() {
    return TRUE;
}

function geia_services_usercreate($uid,$data){
	global $user;
	$pt = user_load($uid);
	
	
	if(!$pt){
       $data = array(
       	'success' => 0,
		'message' => 'Therapist: '.$uid.' not found'
       );		
		return $data;
	
	}
	
    $patient = user_load_by_mail($data['email']);
	if($patient){
		$data = array(
			'success' => 0,
			'message' => "User with this email already exists",
			'email' => $data['email']
		);
		return $data;
	}
	
	
    $fields = array(
        'name' => $data['email'],
        'mail' => $data['email'],
        'init' => $data['email'],
        'pass' => bin2hex(openssl_random_pseudo_bytes(6)),
        'status' => 1,
        'roles' => array(
            DRUPAL_AUTHENTICATED_RID => 'authenticated user',
			5 => 'patient'
        ),
    ); 
    $account = user_save(null, $fields);
    $account = user_load($account->uid);

    $account->field_therapist[LANGUAGE_NONE][0]['uid'] = $uid;
    $account = user_save($account);
	
	
	
	

    $profile = profile2_create(array('type' => 'main', 'uid' => $account->uid));
    $profile->field_first_name[LANGUAGE_NONE][0]['value'] = $data['firstname'];
    $profile->field_last_name[LANGUAGE_NONE][0]['value'] = $data['lastname'];

    $patient_id = generateRandomString();
    $profile->field_webex_patient_id['und']['0']['value'] = $patient_id;
    profile2_save($profile);

    $data['profile'] = $profile;
    $data['account'] = $account;
    $data['patient_id'] = $patient_id;
    $webex_url = create_webexercise_account($data);
    $profile->field_webex_url['und'][0]['value'] = $webex_url;
    profile2_save($profile);

    drupal_set_message(t('User: @firstname @lastname was added, email to the patient was sent', array(
        '@firstname' => $values['firstname'],
        '@lastname' => $values['lastname'],
    )));

    drupal_mail('geia_pt', 'account_created', $account->mail, user_preferred_language($account), array(
        'firstname' => $values['firstname'],
        'lastname' => $values['lastname'],
        'email' => $values['email'],
        'password' => $fields['pass'],
    ));


    drupal_mail('geia_pt', 'patient_account_created', $pt->mail, user_preferred_language($account), array(
        'firstname' => $values['firstname'],
        'lastname' => $values['lastname'],
        'email' => $values['email'],
        'password' => $fields['pass'],
    ));
	
	$profile = profile2_load_by_user($account,'main');
	
    $paccount = array(
	"success" => 1,
    "email" => $account->mail,
    "first_name" => $profile->field_first_name['und'][0]['value'],
    "last_name" => $profile->field_last_name['und'][0]['value']
  
    );
 
  
    return $paccount;
	
}

function geia_services_assign_therapist($uid,$tid){
	$user = user_load($uid);
	
	if(!$user){
       $data = array(
       	'success' => 0,
		'message' => 'user: '.$uid.' not found'
       );		
		return $data;
	
	}

	$user->field_therapist['und'][0]['uid'] = $tid;
	
	$user = user_save($user);
	
	return $user;
	
}


function geia_services_profile_image($uid,$data){
	
	
	$user = user_load($uid);
	
	if(!$user){
       $data = array(
       	'success' => 0,
		'message' => 'user: '.$uid.' not found'
       );		
		return $data;
	
	}
	
	
	global $base_url;
	$image_name = $data['image_name'];
	$imageData = base64_decode($data['image']);   
	
   	
	$file = file_save_data($imageData, 'public://'.$image_name, FILE_EXISTS_REPLACE);

	

	
	
	
    $profile = profile2_load_by_user($user,'main');
	
	$profile->field_profile_image['und'][0] = (array)$file;
	
	
	
	profile2_save($profile);
	
	$goals = array();
	
    foreach($profile->field_goals['und'] as $goal){
  	  $goals[] = $goal['value'];
    }
    if(isset($profile->field_profile_image['und'])){
  	   $image = $base_url."/sites/default/files/".$account->field_profile_image['und'][0]['filename'];
    }else{
        $image = "";
    }
	
    $account = array(
    "email" => $user->mail,
    "first_name" => $profile->field_first_name['und'][0]['value'],
    "last_name" => $profile->field_last_name['und'][0]['value'],
    "dob" => strtotime($profile->field_date_of_birth['und'][0]['value']),
    "gender" => $profile->field_gender['und'][0]['value'],
    "image" => $image,
    "goals" => $goals,
    "gems" => $gems,
  
    );
 
  
    return $account;
	
}

function geia_services_therapists(){

	$query = 'SELECT ur.uid
	    FROM {users_roles} AS ur
	    WHERE ur.rid = :rid';
	  $result = db_query($query, array(':rid' => 4));
	  $uids = $result->fetchCol();
	  return user_load_multiple($uids);

}

function geia_services_logout($uid){

	$query = 'DELETE 
	    FROM {sessions}
	    WHERE  uid = :uid';
	  $result = db_query($query, array(':uid' => $uid));


      return true;

}

function geia_services_pwdreset($email){
	
	
	
    require_once DRUPAL_ROOT . '/' . variable_get('password_inc', 'includes/password.inc');
	
	
	$user = user_load_by_mail($email);
	
	if(!$user){
       $data = array(
       	'success' => 0,
		'message' => 'user: '.$email.' not found'
       );		
		return $data;
	
	}
	
	
	if(!$user){
     $message = array(
 	   "Status" => 0,
 	   "Message" => "Count not find this user :".$email,
 	 );
	 return $message;
	
	}
	
	$pass = user_password(6);
    $user->pass = user_hash_password($pass);
    $user = user_save($user);
	
	

    //=========SELLER_MAIL
    $module = 'geia_services';
    $key = 'password';
    $language = language_default();
    $params = array();
    $send = TRUE;
    //$to_user = user_load($seller_uid);
    $from = 'noreply@plsekwerks.com';
    $to = $user->mail;

   
    $headers = array(
        'MIME-Version' => '1.0',
        'Content-Type' => 'text/html; charset=UTF-8; format=flowed',
        'Content-Transfer-Encoding' => '8Bit',
        'X-Mailer' => 'Drupal'
    );
    $params['headers'] = $headers;

    


    $message = drupal_mail($module, $key, $to, $language, $params, $from, FALSE);


    $message['subject'] = "Your new GeiaFit Password";

    $body = "Your report new password is: ".$pass." please use this password to login to the GeiaFit App on your phone, then you can update your password in your Profile";

    $message['body'] = array();
    $message['body'][] = $body;

    // Retrieve the responsible implementation for this message.
    $system = drupal_mail_system($module, $key);
    // Format the message body.
    $message = $system->format($message);
    // Send e-mail.
    $message['result'] = $system->mail($message);

    $message = array(
	   "Status" => 1,
	   "Message" => "You will receive email at ".$user->mail." with your new password",
	);

    return $message;
	
	

}


function geia_services_mypatients($uid){
	global $user;
	
	
	
	$therapist = user_load($uid);
	
	if(!$therapist){
       $data = array(
       	'success' => 0,
		'message' => 'user: '.$uid.' not found'
       );		
		return $data;
	
	}
	
	$data = _get_patient_data($therapist);
	
	
	return $data;
	
	
	
	
	
}


