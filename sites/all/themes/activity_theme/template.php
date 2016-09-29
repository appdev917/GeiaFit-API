<?php

/*
 * Implements hook_html_head_alter
 */
function activity_theme_html_head_alter(&$head_elements) {
  // Force the latest IE rendering engine and Google Chrome Frame.
  $head_elements['character_set'] = array(
    '#type' => 'html_tag',
    '#tag' => 'meta',
    '#attributes' => array('charset' => 'utf-8'),
  );
  $head_elements['viewport'] = array(
    '#type' => 'html_tag',
    '#tag' => 'meta',
    '#attributes' => array('name' => 'viewport', 'content' => 'width=device-width, initial-scale=1'),
  );
    
}

function activity_theme_field__field_subtitle($variables){
  //dsm($variables);
  return '<p class="lead">'.$variables['items'][0]['#markup'].'</p>';
}

function activity_theme_field__field_big_image($variables){
  //dsm($variables);
  $attributes = ''; 
  $attributes ['src'] = file_create_url($variables['items'][0]['#item']['uri']);

  foreach (array('alt', 'title') as $key) {

    if (isset($variables['items'][0]['#item'][$key])) {
      $attributes [$key] = $variables['items'][0]['#item'][$key];
    }
  }

  return '<img' . drupal_attributes($attributes) . ' />';
}
function activity_theme_field__field_blog_image($variables){
  //dsm($variables);
  $attributes = ''; 
  $attributes ['src'] = file_create_url($variables['items'][0]['#item']['uri']);
  $attributes ['class'] = 'img-responsive';
  foreach (array('alt', 'title') as $key) {

    if (isset($variables['items'][0]['#item'][$key])) {
      $attributes [$key] = $variables['items'][0]['#item'][$key];
    }
  }

  return '<img' . drupal_attributes($attributes) . ' />';
}
function activity_theme_field__field_image_gallery($variables){

    foreach ($variables['items'] as $key => $value) {

      $attributes = '';
      $attributes['href'] = file_create_url($variables['items'][$key]['#item']['uri']);
      foreach (array('alt','title') as $attr) {

        if (isset($variables['items'][$key]['#item'][$attr])) {

          $attributes [$attr] = $variables['items'][$key]['#item'][$attr];

        }
      }
      if($key == 0) {

        $output = '<a '.drupal_attributes($attributes).' class="fancybox gal-bt" data-fancybox-group="group1"><i class="icon-camera-1"></i> Gallery</a>';

      }else{

        $output .= '<a '.drupal_attributes($attributes).' class="fancybox" data-fancybox-group="group1"></a>';

      }
    }
    return '<div class="gallery"> '.$output.'</div><!-- End gallery --> ';
}

function activity_theme_field__field_class_image($variables){
  //dsm($variables);
  $attributes = ''; 
  $attributes ['src'] = file_create_url($variables['items'][0]['#item']['uri']);
  $attributes ['class'] = 'img-rounded styled';
  foreach (array('alt', 'title') as $key) {

    if (isset($variables['items'][0]['#item'][$key])) {
      $attributes [$key] = $variables['items'][0]['#item'][$key];
    }
  }

  return '<img' . drupal_attributes($attributes) . ' />';
}

function activity_theme_field__field_trainer_image($variables){
  //dsm($variables);
  $attributes = ''; 
  $attributes ['src'] = file_create_url($variables['items'][0]['#item']['uri']);
  $attributes ['class'] = 'img-circle styled';
  foreach (array('alt', 'title') as $key) {

    if (isset($variables['items'][0]['#item'][$key])) {
      $attributes [$key] = $variables['items'][0]['#item'][$key];
    }
  }

  return '<p><img' . drupal_attributes($attributes) . ' /></p>';
}

function activity_theme_field__field_avatar($variables){
  //dsm($variables);
  $attributes = ''; 
  $attributes ['src'] = file_create_url($variables['items'][0]['#item']['uri']);
  $attributes ['class'] = 'img-circle';
  foreach (array('alt', 'title') as $key) {

    if (isset($variables['items'][0]['#item'][$key])) {
      $attributes [$key] = $variables['items'][0]['#item'][$key];
    }
  }

  return '<img' . drupal_attributes($attributes) . ' />';
}

function activity_theme_field__field_thumb_image($variables){
  //dsm($variables);
  $attributes = ''; 
  $attributes ['src'] = file_create_url($variables['items'][0]['#item']['uri']);
  foreach (array('alt', 'title') as $key) {

    if (isset($variables['items'][0]['#item'][$key])) {
      $attributes [$key] = $variables['items'][0]['#item'][$key];
    }
  }

  return '<img' . drupal_attributes($attributes) . ' />';
}

function activity_theme_field__field_facebook_link($variables){
  //dsm($variables);

  return '<li><a href="'.$variables['items'][0]['#href'].'"><i class="icon-facebook"></i></a></li>';
}

function activity_theme_field__field_twitter_link($variables){
  //dsm($variables);

  return '<li><a href="'.$variables['items'][0]['#href'].'"><i class="icon-twitter"></i></a></li>';
}

function activity_theme_field__field_google_plus_link($variables){
  //dsm($variables);

  return '<li><a href="'.$variables['items'][0]['#href'].'"><i class="icon-google"></i></a></li>';
}

function activity_theme_field__field_trainer_type($variables){
  //dsm($variables);
  $output = '';
  // Render the label, if it's not hidden.
  if (!$variables['label_hidden']) {
    $output .= '<div class="field-label">' . $variables['label'] . ': </div>';
  }
  // Render the items.
  foreach ($variables['items'] as $delta => $item) {
    $output .= drupal_render($item);
  }
  return $output;
}

function activity_theme_field__field_tags($variables){

  //dsm($variables);

  $output = '';

  // Render the label, if it's not hidden.
  if (!$variables['label_hidden']) {
    $output .= '<h3 class="field-label">' . $variables['label'] . ': </h3>';
  }

  // Render the items.
    foreach ($variables['items'] as $delta => $item) {
      $output .= ' '.drupal_render($item);
    }

  return $output;

}

function activity_theme_field__field_class_level($variables){
  //dsm($variables);

  $output = '';

  // Render the label, if it's not hidden.
  if (!$variables['label_hidden']) {
    $output .= '<h3 class="field-label">' . $variables['label'] . ': </h3>';
  }

  // Render the items.
  foreach ($variables['items'] as $delta => $item) {
    $output .= '<i class="icon-list-numbered"></i> Level: ' .$item['#title'];
  }


  return $output;

}

function activity_theme_field__field_duration_time($variables){
  //dsm($variables);
  return '<i class="icon-clock"></i>Duration: ' .$variables['items'][0]['#markup'];
}

function activity_theme_field__field_cardio($variables){
  //dsm($variables);
  $variables['attributes']['bar_color'] = 'progress-bar-danger';
  return activity_theme_theme_progress_bar($variables);
}

function activity_theme_field__field_toning($variables){
  //dsm($variables);
  $variables['attributes']['bar_color'] = 'progress-bar-info';
  return activity_theme_theme_progress_bar($variables);
}

function activity_theme_field__field_functionality($variables){
  //dsm($variables);
  $variables['attributes']['bar_color'] = 'progress-bar-warning';
  return activity_theme_theme_progress_bar($variables);
}

function activity_theme_field__field_body_and_mind($variables){
  //dsm($variables);
  $variables['attributes']['bar_color'] = 'progress-bar-success';
  return activity_theme_theme_progress_bar($variables);
}
function activity_theme_field__field_icon_class($variables){
  //dsm($variables);
  return $variables['items'][0]['#markup'];
}
function activity_theme_theme_progress_bar($variables) {
  
  $output = '<div class="progress">';
  $output .= '<div class="progress-bar '.$variables['attributes']['bar_color'].'" role="progressbar" data-percentage="'.$variables['items'][0]['#markup'].'">';
  $output .= '</div>';
  $output .= '</div>';
  $output .= '<p> '.$variables['label'].'</p>';
  return $output;
}

function activity_theme_preprocess_node(&$variables){
  //dsm($variables);
  if(isset($variables['field_image_gallery'])){
  
    drupal_add_css(
      drupal_get_path('theme', 'activity_theme') . "/js/fancybox/source/jquery.fancybox.css",
      array(
        'group' => CSS_THEME,
        'weight' => '9999',
      ));
    drupal_add_js(
      drupal_get_path('theme', 'activity_theme') . "/js/fancybox/source/jquery.fancybox.pack.js",
      array(
        'type' => 'file', 
        'scope' => 'footer'));
    drupal_add_js(
      drupal_get_path('theme', 'activity_theme') . "/js/fancybox/source/helpers/jquery.fancybox-media.js",
      array(
        'type' => 'file', 
        'scope' => 'footer'));
    drupal_add_js(drupal_get_path('theme', 'activity_theme') . "/js/fancy_func.js" ,
      array(
        'type' => 'file', 
        'scope' => 'footer'));

  }
  if($variables['type'] == 'program_goal') {
      drupal_add_js(drupal_get_path('theme', 'activity_theme') . '/js/progress-bar.js',
        array(
          'type' => 'file',
          'scope' => 'footer'));
  }
  if($variables['type'] == 'program'){
    if($variables['view_mode'] == 'teaser'){
      $variables['theme_hook_suggestions'][] = 'node__program__teaser';
    }
  }
  $nid = $variables['node']->nid;
  $variables['num_comments'] = db_query("SELECT COUNT(cid) AS count FROM {comment} WHERE nid =:nid",array(":nid"=>$variables['nid']))->fetchField();
}

function activity_theme_preprocess_page(&$variables) {
  
  // Primary nav.
  $variables['primary_nav'] = FALSE;
  $variables['date'] = FALSE;
  // $variables['date'] =  format_date($node->created, 'custom', 'D j M Y');
  if ($variables['main_menu']) {
    // Build links.
    $variables['primary_nav'] = menu_tree(variable_get('menu_main_links_source', 'main-menu'));
    // Provide default theme wrapper function.
    $variables['primary_nav']['#theme_wrappers'] = array('menu_tree__primary');

	
  }

  if(arg(0) == 'node' && is_numeric(arg(1))) {

    $nid=arg(1);
    if(isset($variables['page']['content']['system_main']['nodes'][$nid]['field_image_gallery'])){

      $images_gallery = $variables['page']['content']['system_main']['nodes'][$nid]['field_image_gallery'];
      array_unshift($variables['page']['sidebar_left'] , array('images_gallery' => $images_gallery));
      unset($variables['page']['content']['system_main']['nodes'][$nid]['field_image_gallery']);
    }
    if(isset($variables['page']['content']['system_main']['nodes'][$nid]['field_big_image'])){

      $big_image = $variables['page']['content']['system_main']['nodes'][$nid]['field_big_image'];
      array_unshift($variables['page']['sidebar_left'] , array('big_image' => $big_image));
      unset($variables['page']['content']['system_main']['nodes'][$nid]['field_big_image']);
    }
    
  }

  if($variables['is_front']){
    $output ='';
    $output ='<div class="flexslider">
                <ul class="slides">';
    foreach($variables['page']['content']['system_main']['nodes'] as $key => $value) {
      if(is_numeric($key)){
        $output.= '<li style="background: url('.file_create_url($value['field_big_image'][0]['#item']['uri']).') center"></li>';
      }
    }
    $output .='</ul>
            </div><!-- End slider -->';
    $output .='<div id="calculators_home">
                <div class="container" >
                  <div class="row">';
    foreach($variables['page']['content']['system_main']['nodes'] as $key => $value) {
      if(is_numeric($key)){
        //$output.= '<div class="col-md-3 col-sm-6 col-xs-6"><div class="box_calculator">';
        //$output.= '<a href="'.url('node/'.$key).'">';
        //$title = get_node_title($key);
        //$output.= '<img src="'.file_create_url($value['field_icon_image'][0]['#item']['uri']).'" alt="" data-retina="true">';
        //$output.='<h3>'. $title .'</h3></a>';
        //$output.='</div><!-- End box-calculator --></div><!-- End col-md-3 -->';
      }
    }
    $output .='   </div><!-- End row --> 
              </div><!-- End container -->
            </div><!--calculators_home -->';             
    $variables ['page']['content']= $output; 
  }
  // To add image for left sidebar in blog and contact page
  if($variables['theme_hook_suggestions'][0] == 'page__blog'){
    $big_image = file_load(theme_get_setting('blog_page_image'));
    $variables['page']['sidebar_left'] = '<img src="'.file_create_url($big_image->uri).'">';
  }
  // To add image for left sidebar in blog and contact page
  if($variables['theme_hook_suggestions'][0] == 'page__contact'){
    $big_image = file_load(theme_get_setting('contact_page_image'));
    if(isset($big_image)){
      $variables['page']['sidebar_left'] = '<img src="'.file_create_url($big_image->uri).'">';
    }
  }
}

/**
 * Helper function to get the node title without loading the whole node object.
 */
function get_node_title($nid) {
  return db_query('SELECT title FROM {node} WHERE nid = :nid', array(':nid' => $nid))->fetchField();
}

/**
 * Overrides theme_menu_link().
 */
function activity_theme_menu_link(array $variables) {
  $element = $variables['element'];
  $sub_menu = '';
  $output = '';
  //dsm($variables);
  if($element['#href'] == '<nolink>'){
      $element['#href'] = '#';
  }
  if (!empty($element['#below'])) {
    
    // Prevent dropdown functions from being added to management menu so it
    // does not affect the navbar module.
    if (($element['#original_link']['menu_name'] == 'management') && (module_exists('navbar'))) {
      $sub_menu = drupal_render($element['#below']);
    }
    elseif ((!empty($element['#original_link']['depth'])) && ($element['#original_link']['depth'] == 1)) {
      // Add our own wrapper.
      unset($element['#below']['#theme_wrappers']);
      $sub_menu = "<div class='drop-down-container normal'>\n <ul> \n" .drupal_render($element['#below']) . "</ul> \n </div><!-- End dropdown normal --> \n";
      // Generate as standard dropdown.
      $element['#attributes']['class'][] = 'drop-normal';
      $element['#localized_options']['html'] = TRUE;

      // Set dropdown trigger element to # to prevent inadvertant page loading
      // when a submenu link is clicked.
      $element['#localized_options']['attributes']['data-target'] = '#';
      $element['#localized_options']['attributes']['class'][] = 'dropdown-toggle';
      $element['#localized_options']['attributes']['data-toggle'] = 'dropdown';
      $output = '<a href = "#" class="drop-down"> '.$element['#title'].' </a>';

    }  
  }
  else{
    $output = '<a href = "'.url($element['#href']).'"> '.$element['#title'].' </a>'; 
    //dsm($output);
  }
  
  // On primary navigation menu, class 'active' is not set on active menu item.
  // @see https://drupal.org/node/1896674
  if (($element['#href'] == $_GET['q'] || ($element['#href'] == '<front>' && drupal_is_front_page())) && (empty($element['#localized_options']['language']))) {
    $element['#attributes']['class'][] = 'active';
  }
  return '<li' . drupal_attributes($element['#attributes']) . '>' . $output .$sub_menu ."\n</li>\n";
}

/**
 * Overrides theme_menu_tree().
 */
function activity_theme_menu_tree(&$variables) {
  return '<ul class="menu nav">' . $variables['tree'] . '</ul>';
}

/**
 *Theme wrapper function for the primary menu links.
 */
function activity_theme_menu_tree__primary(&$variables) {
  return '<ul class="menu">' . $variables['tree'] . '</ul>';
}


function activity_theme_menu_tree__local_task(&$variables) {
  return '<ul class="nav navbar-tabs">' . $variables['tree'] . '</ul>';
}



/**
 * Implements hook_theme().
 */
function activity_theme_theme($existing, $type, $theme, $path) {
  return array(
    'comment_form' =>array(
      'render element' => 'form',
      'template' =>'comment-form',
      'path' => drupal_get_path('theme', 'activity_theme').'/template/features',
      ),
    
    'contact_site_form' =>array(
      'render element' => 'form',
      'template' =>'contact-site-form',
      'path' => drupal_get_path('theme', 'activity_theme').'/template/features',
      ),
    );
}

/**
 * Preprocessor for comment_form theme.
 */
function activity_theme_preprocess_comment_form(&$variables) {

  $variables['author_name']= drupal_render($variables['form']['author']['name']);
  $variables['author_email']= drupal_render($variables['form']['author']['mail']);
  hide($variables['form']['comment_body']['und'][0]['format']);
  $variables['comment_body']= drupal_render($variables['form']['comment_body']);
  $variables['everything_eles']= drupal_render_children($variables['form']);
}


function activity_theme_form_comment_form_alter(&$form, &$form_state, $form_id) {
  //debug($form);

  // To modefiy forms
  $form['author']['homepage']['#access'] = FALSE;
  unset($form['author']['name']['#title']);
  $form['author']['name']['#required'] = TRUE;
  $form['author']['name']['#attributes']['placeholder'] = t( 'Name' );
  $form['author']['name']['#attributes']['class'][] = t( 'form-control required' );

  unset($form['author']['mail']['#title']);
  $form['author']['mail']['#required'] = TRUE;
  $form['author']['mail']['#attributes']['placeholder'] = t( 'Email' );
  $form['author']['mail']['#attributes']['class'][] = t( 'form-control required' );

  unset($form['comment_body'][LANGUAGE_NONE][0]['#title']);
  $form['comment_body'][LANGUAGE_NONE][0]['#attributes']['placeholder'] = t( 'Message' );
  $form['comment_body'][LANGUAGE_NONE][0]['#attributes']['class'][] = t( 'form-control' );

  $form['actions']['submit']['#attributes']['class'][] = t('button_medium add_top');
  $form['actions']['preview']['#attributes']['class'][] = t('button_medium add_top');
  //dsm($form);
}

/**
 * Preprocessor for contact_form theme.
 */
function activity_theme_preprocess_contact_site_form(&$variables) {

  $variables['fname']= drupal_render($variables['form']['name']);
  $variables['lname']= drupal_render($variables['form']['lname']);
  $variables['phone']= drupal_render($variables['form']['phone']);
  $variables['email']= drupal_render($variables['form']['mail']);
  $variables['message']= drupal_render($variables['form']['message']);
  $variables['subject']= drupal_render($variables['form']['subject']);
  $variables['everything_eles']= drupal_render_children($variables['form']);
}

/**
* Implements hook_form_contact_site_form_alter().
* This function will add a phone number field to the site-wide contact form,
* by implementing hook_form_FORM_ID_alter().
*/
function activity_theme_form_contact_site_form_alter(&$form, &$form_state, $form_id) {
  //dsm($form);

  $form['lname'] = array(
    '#type' => 'textfield',
    '#maxlength' => 20,
    '#title' => t('Enter last Name'),
    );

  // Add a phone number field to the contact form.
  $form['phone'] = array(
    '#type' => 'textfield',
    '#maxlength' => 20,
    '#title' => t('Enter phone number'),
    );
  $form['lname']['#required'] = TRUE;

  unset($form['name']['#title']);
  $form['name']['#attributes']['class'][] = 'form-control';
  $form['name']['#attributes']['placeholder'] = t('Enter first Name');

  unset($form['lname']['#title']);
  $form['lname']['#attributes']['class'][] = 'form-control';
  $form['lname']['#attributes']['placeholder'] = t('Enter last Name');

  unset($form['mail']['#title']);
  $form['mail']['#attributes']['class'][] = 'form-control';
  $form['mail']['#attributes']['placeholder'] = t('Enter Email');

  unset($form['phone']['#title']);
  $form['phone']['#attributes']['class'][] = 'form-control';
  $form['phone']['#attributes']['placeholder'] = t('Enter phone number');

  unset($form['subject']['#title']);
  $form['subject']['#attributes']['class'][] = 'form-control';
  $form['subject']['#attributes']['placeholder'] = t('Enter subject');

  unset($form['message']['#title']);
  $form['message']['#attributes']['class'][] = 'form-control';
  $form['message']['#attributes']['placeholder'] = t('Write your message');
  $form['message']['#attributes']['rows'] = '5';

  $form['actions']['submit']['#attributes']['class'][] = t('button_medium');

  // Define the order of the top level elements on the form (include those from contact_site_form().
  $order = array('name', 'lname', 'mail', 'phone', 'subject', 'cid', 'message', 'copy', 'actions');

  // Order the elements by changing their #weight property.
  foreach($order as $key => $field) {
    $form[$field]['#weight'] = $key;
  }
}

/*

*/
function activity_theme_pager($variables) {
  $tags = $variables['tags'];
  $element = $variables['element'];
  $parameters = $variables['parameters'];
  $quantity = $variables['quantity'];
  global $pager_page_array, $pager_total;

  // Calculate various markers within this pager piece:
  // Middle is used to "center" pages around the current page.
  $pager_middle = ceil($quantity / 2);
  // current is the page we are currently paged to
  $pager_current = $pager_page_array[$element] + 1;
  // first is the first page listed by this pager piece (re quantity)
  $pager_first = $pager_current - $pager_middle + 1;
  // last is the last page listed by this pager piece (re quantity)
  $pager_last = $pager_current + $quantity - $pager_middle;
  // max is the maximum page number
  $pager_max = $pager_total[$element];
  // End of marker calculations.

  // Prepare for generation loop.
  $i = $pager_first;
  if ($pager_last > $pager_max) {
    // Adjust "center" if at end of query.
    $i = $i + ($pager_max - $pager_last);
    $pager_last = $pager_max;
  }
  if ($i <= 0) {
    // Adjust "center" if at start of query.
    $pager_last = $pager_last + (1 - $i);
    $i = 1;
  }
  // End of generation loop preparation.

  $li_first = theme('pager_first', array('text' => (isset($tags[0]) ? $tags[0] : t('« first')), 'element' => $element, 'parameters' => $parameters));
  $li_previous = theme('pager_previous', array('text' => (isset($tags[1]) ? $tags[1] : t('‹ previous')), 'element' => $element, 'interval' => 1, 'parameters' => $parameters));
  $li_next = theme('pager_next', array('text' => (isset($tags[3]) ? $tags[3] : t('next ›')), 'element' => $element, 'interval' => 1, 'parameters' => $parameters));
  $li_last = theme('pager_last', array('text' => (isset($tags[4]) ? $tags[4] : t('last »')), 'element' => $element, 'parameters' => $parameters));

  if ($pager_total[$element] > 1) {
    if ($li_first) {
      $items[] = array(
        'class' => array('pager-first'),
        'data' => $li_first,
      );
    }
    if ($li_previous) {
      $items[] = array(
        'class' => array('pager-previous'),
        'data' => $li_previous,
      );
    }

    // When there is more than one page, create the pager list.
    if ($i != $pager_max) {
      if ($i > 1) {
        $items[] = array(
          'class' => array('pager-ellipsis'),
          'data' => '…',
        );
      }
      // Now generate the actual pager piece.
      for (; $i <= $pager_last && $i <= $pager_max; $i++) {
        if ($i < $pager_current) {
          $items[] = array(
            'class' => array('pager-item'),
            'data' => theme('pager_previous', array('text' => $i, 'element' => $element, 'interval' => ($pager_current - $i), 'parameters' => $parameters)),
          );
        }
        if ($i == $pager_current) {
          $items[] = array(
            'class' => array('pager-current active'),
            'data' => l($i,'#'),
          );
        }
        if ($i > $pager_current) {
          $items[] = array(
            'class' => array('pager-item'),
            'data' => theme('pager_next', array('text' => $i, 'element' => $element, 'interval' => ($i - $pager_current), 'parameters' => $parameters)),
          );
        }
      }
      if ($i < $pager_max) {
        $items[] = array(
          'class' => array('pager-ellipsis'),
          'data' => '…',
        );
      }
    }
    // End generation.
    if ($li_next) {
      $items[] = array(
        'class' => array('pager-next'),
        'data' => $li_next,
      );
    }
    if ($li_last) {
      $items[] = array(
        'class' => array('pager-last'),
        'data' => $li_last,
      );
    }
    return theme('item_list', array(
      'items' => $items,
      'attributes' => array('class' => array('pagination pagination-lg')),
    ));
  }
}