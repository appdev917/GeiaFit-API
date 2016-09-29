<?php
/**
 * @file
 * geia_api.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function geia_api_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'addclient';
  $context->description = '';
  $context->tag = 'user';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'newpatient' => 'newpatient',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'geia_blocks-geia_user_register' => array(
          'module' => 'geia_blocks',
          'delta' => 'geia_user_register',
          'region' => 'content',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('user');
  $export['addclient'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'user';
  $context->description = '';
  $context->tag = 'user';
  $context->conditions = array(
    'user' => array(
      'values' => array(
        'administrator' => 'administrator',
        'therapist' => 'therapist',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-og_members-block_1' => array(
          'module' => 'views',
          'delta' => 'og_members-block_1',
          'region' => 'content',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('user');
  $export['user'] = $context;

  return $export;
}
