<?php
/**
 * @file
 * geia_core.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function geia_core_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function geia_core_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function geia_core_image_default_styles() {
  $styles = array();

  // Exported image style: user_profile.
  $styles['user_profile'] = array(
    'label' => 'user_profile',
    'effects' => array(
      2 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 150,
          'height' => 150,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: video_image.
  $styles['video_image'] = array(
    'label' => 'video image',
    'effects' => array(
      1 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 250,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}
