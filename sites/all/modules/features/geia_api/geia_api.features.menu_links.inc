<?php
/**
 * @file
 * geia_api.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function geia_api_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: user-menu_dashboard:pt/dashboard.
  $menu_links['user-menu_dashboard:pt/dashboard'] = array(
    'menu_name' => 'user-menu',
    'link_path' => 'pt/dashboard',
    'router_path' => 'pt/dashboard',
    'link_title' => 'Dashboard',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'user-menu_dashboard:pt/dashboard',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
  );
  // Exported menu link: user-menu_log-out:user/logout.
  $menu_links['user-menu_log-out:user/logout'] = array(
    'menu_name' => 'user-menu',
    'link_path' => 'user/logout',
    'router_path' => 'user/logout',
    'link_title' => 'Log out',
    'options' => array(
      'identifier' => 'user-menu_log-out:user/logout',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
    'customized' => 1,
  );
  // Exported menu link: user-menu_manage-profile:pt/profile.
  $menu_links['user-menu_manage-profile:pt/profile'] = array(
    'menu_name' => 'user-menu',
    'link_path' => 'pt/profile',
    'router_path' => 'pt/profile',
    'link_title' => 'Manage profile',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'user-menu_manage-profile:pt/profile',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Dashboard');
  t('Log out');
  t('Manage profile');

  return $menu_links;
}
