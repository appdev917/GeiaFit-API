<?php
/**
 * @file
 * geia_api.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function geia_api_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-therapist.
  $menus['menu-therapist'] = array(
    'menu_name' => 'menu-therapist',
    'title' => 'Therapist',
    'description' => '',
  );
  // Exported menu: user-menu.
  $menus['user-menu'] = array(
    'menu_name' => 'user-menu',
    'title' => 'User menu',
    'description' => 'The <em>User</em> menu contains links related to the user\'s account, as well as the \'Log out\' link.',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('The <em>User</em> menu contains links related to the user\'s account, as well as the \'Log out\' link.');
  t('Therapist');
  t('User menu');

  return $menus;
}
