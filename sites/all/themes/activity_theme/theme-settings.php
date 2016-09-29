<?php
/**
 * Implements hook_form_FORM_ID_alter().
 *
 * @param $form
 *   The form.
 * @param $form_state
 *   The form state.
 */
function activity_theme_form_system_theme_settings_alter(&$form, &$form_state) {

  $form['prof_settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('Professional Theme Settings'),
    '#collapsible' => FALSE,
    '#collapsed' => FALSE,
  );
  $form['prof_settings']['top_social_link'] = array(
    '#type' => 'fieldset',
    '#title' => t('Social links in footer'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );
  $form['prof_settings']['top_social_link']['social_links'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show social icons (Facebook, Twitter and RSS) in footer'),
    '#default_value' => theme_get_setting('social_links', 'activity_theme'),
    '#description'   => t("Check this option to show twitter, facebook, rss icons in footer. Uncheck to hide."),
  );
  $form['prof_settings']['top_social_link']['facebook_profile_url'] = array(
    '#type' => 'textfield',
    '#title' => t('Facebook URL'),
    '#default_value' => theme_get_setting('facebook_profile_url', 'activity_theme'),
    '#description' => t("Enter your Facebook profile URL."),
  );
  $form['prof_settings']['top_social_link']['twitter_profile_url'] = array(
    '#type' => 'textfield',
    '#title' => t('Twitter URL'),
    '#default_value' => theme_get_setting('twitter_profile_url', 'activity_theme'),
    '#description' => t("Enter your Twitter profile URL."),
  );
  $form['prof_settings']['top_social_link']['youtube_profile_url'] = array(
    '#type' => 'textfield',
    '#title' => t('Youtube URL'),
    '#default_value' => theme_get_setting('youtube_profile_url', 'activity_theme'),
    '#description' => t("Enter your Youtube profile URL."),
  );
  $form['prof_settings']['top_social_link']['gplus_profile_url'] = array(
    '#type' => 'textfield',
    '#title' => t('Gplus URL'),
    '#default_value' => theme_get_setting('gplus_profile_url', 'activity_theme'),
    '#description' => t("Enter your Gplus profile URL."),
  );
  $form['prof_settings']['top_social_link']['linkedin_profile_url'] = array(
    '#type' => 'textfield',
    '#title' => t('Linkedin URL'),
    '#default_value' => theme_get_setting('linkedin_profile_url', 'activity_theme'),
    '#description' => t("Enter your Linkedin profile URL."),
  );
  $form['prof_settings']['top_social_link']['instagram_profile_url'] = array(
    '#type' => 'textfield',
    '#title' => t('Instagram URL'),
    '#default_value' => theme_get_setting('instagram_profile_url', 'activity_theme'),
    '#description' => t("Enter your Instagram URL."),
  );
  $form['page_image'] = array(
    '#type' => 'fieldset',
    '#title' => t('Add image page'),
    '#collapsible' => FALSE,
    '#collapsed' => FALSE,
  );

  $form['page_image']['blog_page_image'] = array(
    '#title' => t('Blog page image'),
    '#description' => t('Image to display in left sidebar for blog page'),
    '#type' => 'managed_file',
    '#upload_location' => 'public://images/',
    '#upload_validators' => array(
      'file_validate_extensions' => array('gif png jpg jpeg'),
    ),
    '#default_value' => theme_get_setting('blog_page_image'),
  );

  $form['page_image']['contact_page_image'] = array(
    '#title' => t('Contact page image'),
    '#description' => t('Image to display in left sidebar for contact page'),
    '#type' => 'managed_file',
    '#upload_location' => 'public://images/',
    '#upload_validators' => array(
      'file_validate_extensions' => array('gif png jpg jpeg'),
    ),
    '#default_value' => theme_get_setting('contact_page_image'),
  );

  $form['#submit'][] = 'activity_theme_settings_form_submit';
  // Get all themes.
  $themes = list_themes();
  // Get the current theme
  $active_theme = $GLOBALS['theme_key'];
  $form_state['build_info']['files'][] = str_replace("/$active_theme.info", '', $themes[$active_theme]->filename) . '/theme-settings.php';

}

function activity_theme_settings_form_submit(&$form, $form_state) {
  $image_fid = $form_state['values']['blog_page_image'];
  $image = file_load($image_fid);
  if (is_object($image)) {
  // Check to make sure that the file is set to be permanent.
    if ($image->status == 0) {
    // Update the status.
      $image->status = FILE_STATUS_PERMANENT;
    // Save the update.
      file_save($image);
    // Add a reference to prevent warnings.
      file_usage_add($image, 'activity_theme', 'theme', 1);
    }
  }

  $image_fid = $form_state['values']['contact_page_image'];
  $image = file_load($image_fid);
  if (is_object($image)) {
  // Check to make sure that the file is set to be permanent.
    if ($image->status == 0) {
    // Update the status.
      $image->status = FILE_STATUS_PERMANENT;
    // Save the update.
      file_save($image);
    // Add a reference to prevent warnings.
      file_usage_add($image, 'activity_theme', 'theme', 1);
    }
  }

}