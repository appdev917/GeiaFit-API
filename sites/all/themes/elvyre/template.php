<?php
global $theme_root ;
$theme_root = base_path() . drupal_get_path('theme', 'elvyre');

function elvyre_breadcrumb($variables) {

   $breadcrumb = $variables['breadcrumb'];
  if (!empty($breadcrumb)) {

    $output = '<h2 class="element-invisible">' . t('You are here') . '</h2>';

	$breadcrumb[] = drupal_get_title();
    $output .= '<ul class="crumbs"><li><span>You are here:</span></li> '  . implode('  /  ', $breadcrumb) . '</ul>';
    return $output;
  }
}


function elvyre_button($variables) {

  $element = $variables['element'];
  $element['#attributes']['type'] = 'submit';
  element_set_attributes($element, array('id', 'name', 'value'));

  $element['#attributes']['class'][] = 'wpcf7-submit default form-' . $element['#button_type'];
  if (!empty($element['#attributes']['disabled'])) {
    $element['#attributes']['class'][] = 'form-button-disabled';
  }

  return '<input' . drupal_attributes($element['#attributes']) . ' />';
}

function elvyre_preprocess_page(&$variables) {

  $main_menu = menu_tree_output(menu_tree_all_data(variable_get('menu_main_links_source', 'main-menu'), NULL, 3));

  // Custom wrapper for 1st menu level.
  $main_menu['#theme_wrappers'] = array('menu_tree__main_menu_primary');

  $variables['page']['main_menu'] = $main_menu;
}

/**
* Theme wrapper for 1st level of main menu
*/
function elvyre_menu_tree__main_menu_primary($variables) {
  return '<ul>' .  $variables['tree'] . '</ul>';
}

/**
* Theme wrapper for 2nd (and deeper) level of main menu
*/
function elvyre_menu_tree__main_menu($variables) {
  return  '<ul>' . $variables['tree'] . '</ul>';
}

function elvyre_menu_link(array $variables) {

  unset($variables['element']['#attributes']['class']);
  $element = $variables['element'];
  $sub_menu = '';
  
  if($variables['element']['#attributes']) {
    $sub_menu = '';
  }

  if ($element['#below']) {
    $sub_menu = drupal_render($element['#below']);
  }
  
  $output = l($element['#title'], $element['#href'], $element['#localized_options']);
  
  if(strpos($output,"active")>0){
    $element['#attributes']['class'][] = "current-menu-item";
  }
  
  return '<li' . drupal_attributes($element['#attributes']) . '>' . $output . $sub_menu . "</li>\n";
}



function elvyre_css_alter(&$css) { 

  // Sort CSS items, so that they appear in the correct order.
  // This is taken from drupal_get_css().
  uasort($css, 'drupal_sort_css_js');

  // The Print style sheets
  // I will populate this array with the print css (usually I have only one but just in case…)
  $print = array();

  // I will add some weight to the new $css array so every element keeps its position
  $weight = 0;

  foreach ($css as $name => $style) {

    // I leave untouched the conditional stylesheets
    // and put all the rest inside a 0 group
    if ($css[$name]['browsers']['!IE']) {
      $css[$name]['group'] = 0;
      $css[$name]['weight'] = ++$weight;
      $css[$name]['every_page'] = TRUE;
    }

    // I move all the print style sheets to a new array
    if ($css[$name]['media'] == 'print') {
      // remove and add to a new array
      $print[$name] = $css[$name];
      unset($css[$name]);
    }

  }

  // I merge the regular array and the print array
  $css = array_merge($css, $print);

}



function  elvyre_form_contact_site_form_alter(&$form, &$form_state) {
  drupal_set_title(' ');
}
function elvyre_theme() {
return array(
'contact_site_form' => array(
'render element' => 'form',
'template' => 'contact-site-form',
'path' => drupal_get_path('theme', 'elvyre').'/templates',
),
);
}
function elvyre_preprocess_contact_site_form(&$variables)
{
	//an example of setting up an extra variable, you can also put this directly in the template
	$variables['info'] = 'Please fill in the fields below to contact us';
	//this is the contents of the form
	$variables['contact'] = drupal_render_children($variables['form']);
 
}