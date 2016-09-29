<?php
/**
 * @file
 * The primary PHP file for this theme.
 */
 
 function geiafitadmin_theme() {
   $items = array();
   // create custom user-login.tpl.php
   $items['user_login'] = array(
   'render element' => 'form',
   'path' => drupal_get_path('theme', 'geiafitadmin') . '/templates/system',
   'template' => 'user-login',
   'preprocess functions' => array(
   'geiafitadmin_preprocess_user_login'
   ),
  );
 return $items;
 }