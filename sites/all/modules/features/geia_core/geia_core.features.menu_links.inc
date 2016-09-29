<?php
/**
 * @file
 * geia_core.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function geia_core_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu_body-and-mind-program:node/8.
  $menu_links['main-menu_body-and-mind-program:node/8'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/8',
    'router_path' => 'node/%',
    'link_title' => 'Body and mind program',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'main-menu_body-and-mind-program:node/8',
    ),
    'module' => 'menu',
    'hidden' => 1,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
    'customized' => 1,
    'parent_identifier' => 'main-menu_exercise-programs:<front>',
  );
  // Exported menu link: main-menu_calculators:<nolink>.
  $menu_links['main-menu_calculators:<nolink>'] = array(
    'menu_name' => 'main-menu',
    'link_path' => '<nolink>',
    'router_path' => '<nolink>',
    'link_title' => 'Calculators',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_calculators:<nolink>',
    ),
    'module' => 'menu',
    'hidden' => 1,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 1,
    'weight' => -49,
    'customized' => 1,
  );
  // Exported menu link: main-menu_documentation:http://activity.drupal.gobtan.com/documentation/.
  $menu_links['main-menu_documentation:http://activity.drupal.gobtan.com/documentation/'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'http://activity.drupal.gobtan.com/documentation/',
    'router_path' => '',
    'link_title' => 'Documentation',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_documentation:http://activity.drupal.gobtan.com/documentation/',
    ),
    'module' => 'menu',
    'hidden' => 1,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -46,
    'customized' => 1,
  );
  // Exported menu link: main-menu_home:<front>.
  $menu_links['main-menu_home:<front>'] = array(
    'menu_name' => 'main-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Home',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_home:<front>',
    ),
    'module' => 'menu',
    'hidden' => 1,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
  );
  // Exported menu link: main-menu_pages:<nolink>.
  $menu_links['main-menu_pages:<nolink>'] = array(
    'menu_name' => 'main-menu',
    'link_path' => '<nolink>',
    'router_path' => '<nolink>',
    'link_title' => 'Pages',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_pages:<nolink>',
    ),
    'module' => 'menu',
    'hidden' => 1,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 1,
    'weight' => -47,
    'customized' => 1,
  );
  // Exported menu link: main-menu_pricing:node/12.
  $menu_links['main-menu_pricing:node/12'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/12',
    'router_path' => 'node/%',
    'link_title' => 'Pricing',
    'options' => array(
      'identifier' => 'main-menu_pricing:node/12',
    ),
    'module' => 'menu',
    'hidden' => 1,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
    'parent_identifier' => 'main-menu_pages:<nolink>',
  );
  // Exported menu link: main-menu_programs:node/11.
  $menu_links['main-menu_programs:node/11'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/11',
    'router_path' => 'node/%',
    'link_title' => 'Programs',
    'options' => array(
      'identifier' => 'main-menu_programs:node/11',
    ),
    'module' => 'menu',
    'hidden' => 1,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
    'parent_identifier' => 'main-menu_pages:<nolink>',
  );
  // Exported menu link: main-menu_purchase-this-template:http://themeforest.net/user/sowailem/portfolio?ref=sowailem.
  $menu_links['main-menu_purchase-this-template:http://themeforest.net/user/sowailem/portfolio?ref=sowailem'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'http://themeforest.net/user/sowailem/portfolio?ref=sowailem',
    'router_path' => '',
    'link_title' => 'Purchase this template',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_purchase-this-template:http://themeforest.net/user/sowailem/portfolio?ref=sowailem',
    ),
    'module' => 'menu',
    'hidden' => 1,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -45,
    'customized' => 1,
  );
  // Exported menu link: main-menu_shortcodes:node/13.
  $menu_links['main-menu_shortcodes:node/13'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/13',
    'router_path' => 'node/%',
    'link_title' => 'Shortcodes',
    'options' => array(
      'identifier' => 'main-menu_shortcodes:node/13',
    ),
    'module' => 'menu',
    'hidden' => 1,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -45,
    'customized' => 1,
    'parent_identifier' => 'main-menu_pages:<nolink>',
  );
  // Exported menu link: main-menu_toning-program:node/7.
  $menu_links['main-menu_toning-program:node/7'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/7',
    'router_path' => 'node/%',
    'link_title' => 'Toning program',
    'options' => array(
      'identifier' => 'main-menu_toning-program:node/7',
    ),
    'module' => 'menu',
    'hidden' => 1,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
    'parent_identifier' => 'main-menu_exercise-programs:<front>',
  );
  // Exported menu link: navigation_page:node/add/page.
  $menu_links['navigation_page:node/add/page'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'node/add/page',
    'router_path' => 'node/add/page',
    'link_title' => 'Page',
    'options' => array(
      'attributes' => array(
        'title' => 'Add set of pages ',
      ),
      'identifier' => 'navigation_page:node/add/page',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'navigation_add-content:node/add',
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Body and mind program');
  t('Calculators');
  t('Documentation');
  t('Home');
  t('Page');
  t('Pages');
  t('Pricing');
  t('Programs');
  t('Purchase this template');
  t('Shortcodes');
  t('Toning program');

  return $menu_links;
}
