<?php
/**
 * @file
 * geia_api.services.inc
 */

/**
 * Implements hook_default_services_endpoint().
 */
function geia_api_default_services_endpoint() {
  $export = array();

  $endpoint = new stdClass();
  $endpoint->disabled = FALSE; /* Edit this to true to make a default endpoint disabled initially */
  $endpoint->api_version = 3;
  $endpoint->name = 'geia';
  $endpoint->server = 'rest_server';
  $endpoint->path = 'api';
  $endpoint->authentication = array(
    'services' => 'services',
  );
  $endpoint->server_settings = array(
    'formatters' => array(
      'json' => TRUE,
      'bencode' => FALSE,
      'jsonp' => FALSE,
      'php' => FALSE,
      'xml' => FALSE,
    ),
    'parsers' => array(
      'application/json' => TRUE,
      'application/x-www-form-urlencoded' => TRUE,
      'multipart/form-data' => TRUE,
      'application/vnd.php.serialized' => FALSE,
      'application/xml' => FALSE,
      'text/xml' => FALSE,
    ),
    'docs' => array(
      'notifications' => array(
        'operations' => array(
          'index' => array(
            'enable' => 1,
            'description' => 'List Users Notifications',
            'request_url' => 'https://api.geiafit.com/api/notifications/[uid]',
            'response' => '{
  "success": 1,
  "notifications": [
    {
      "id": "15",
      "created": "1472351621",
      "updated": "1472763434",
      "read": "1",
      "category": "prescription",
      "message": "Meeting at Renovate America about the new site next Thursday if you want to roll.",
      "uid": "37",
      "title": "Test Title",
      "image_url": ""
    },
    {
      "id": "7",
      "created": "1472264849",
      "updated": "1472264849",
      "read": "0",
      "category": "alert",
      "message": "Meeting at Renovate America about the new site next Thursday if you want to roll.",
      "uid": "37",
      "title": "Test Title",
      "image_url": ""
    },
    {',
            'auth' => 1,
          ),
        ),
      ),
    ),
  );
  $endpoint->resources = array(
    'challenge' => array(
      'operations' => array(
        'index' => array(
          'enabled' => '1',
        ),
      ),
    ),
    'characteristics' => array(
      'operations' => array(
        'index' => array(
          'enabled' => '1',
        ),
        'update' => array(
          'enabled' => '1',
        ),
      ),
    ),
    'goals' => array(
      'operations' => array(
        'index' => array(
          'enabled' => '1',
        ),
      ),
    ),
    'log' => array(
      'operations' => array(
        'index' => array(
          'enabled' => '1',
        ),
        'update' => array(
          'enabled' => '1',
        ),
      ),
    ),
    'messages' => array(
      'operations' => array(
        'index' => array(
          'enabled' => '1',
        ),
        'update' => array(
          'enabled' => '1',
        ),
      ),
    ),
    'notifications' => array(
      'operations' => array(
        'index' => array(
          'enabled' => '1',
        ),
        'update' => array(
          'enabled' => '1',
        ),
      ),
    ),
    'outcome_measures' => array(
      'operations' => array(
        'index' => array(
          'enabled' => '1',
        ),
        'update' => array(
          'enabled' => '1',
        ),
      ),
    ),
    'posture' => array(
      'operations' => array(
        'index' => array(
          'enabled' => '1',
        ),
        'create' => array(
          'enabled' => '1',
        ),
      ),
    ),
    'profile' => array(
      'operations' => array(
        'index' => array(
          'enabled' => '1',
        ),
        'update' => array(
          'enabled' => '1',
        ),
        'delete' => array(
          'enabled' => '1',
        ),
        'create' => array(
          'enabled' => '1',
        ),
      ),
      'actions' => array(
        'therapists' => array(
          'enabled' => '1',
        ),
        'logout' => array(
          'enabled' => '1',
        ),
        'pwdreset' => array(
          'enabled' => '1',
        ),
        'assigntherapists' => array(
          'enabled' => '1',
        ),
        'createpatient' => array(
          'enabled' => '1',
        ),
        'mypatients' => array(
          'enabled' => '1',
        ),
        'profileimage' => array(
          'enabled' => '1',
        ),
      ),
    ),
    'push_notifications' => array(
      'operations' => array(
        'create' => array(
          'enabled' => '1',
        ),
        'delete' => array(
          'enabled' => '1',
        ),
      ),
    ),
    'survey' => array(
      'operations' => array(
        'index' => array(
          'enabled' => '1',
        ),
        'update' => array(
          'enabled' => '1',
        ),
      ),
    ),
    'system' => array(
      'actions' => array(
        'connect' => array(
          'enabled' => '1',
        ),
        'get_variable' => array(
          'enabled' => '1',
        ),
        'set_variable' => array(
          'enabled' => '1',
        ),
        'del_variable' => array(
          'enabled' => '1',
        ),
      ),
    ),
    'user' => array(
      'operations' => array(
        'retrieve' => array(
          'enabled' => '1',
        ),
        'create' => array(
          'enabled' => '1',
        ),
        'update' => array(
          'enabled' => '1',
        ),
        'delete' => array(
          'enabled' => '1',
        ),
        'index' => array(
          'enabled' => '1',
        ),
      ),
      'actions' => array(
        'login' => array(
          'enabled' => '1',
          'settings' => array(
            'services' => array(
              'resource_api_version' => '1.0',
            ),
          ),
        ),
        'logout' => array(
          'enabled' => '1',
          'settings' => array(
            'services' => array(
              'resource_api_version' => '1.0',
            ),
          ),
        ),
        'token' => array(
          'enabled' => '1',
        ),
        'request_new_password' => array(
          'enabled' => '1',
        ),
        'register' => array(
          'enabled' => '1',
        ),
      ),
      'targeted_actions' => array(
        'cancel' => array(
          'enabled' => '1',
        ),
        'password_reset' => array(
          'enabled' => '1',
        ),
        'resend_welcome_email' => array(
          'enabled' => '1',
        ),
      ),
    ),
    'webex' => array(
      'operations' => array(
        'index' => array(
          'enabled' => '1',
        ),
        'create' => array(
          'enabled' => '1',
        ),
      ),
      'actions' => array(
        'record' => array(
          'enabled' => '1',
        ),
      ),
    ),
  );
  $endpoint->debug = 0;
  $export['geia'] = $endpoint;

  return $export;
}
