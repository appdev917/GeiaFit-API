<?php
/**
 * @file
 * geia_core.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function geia_core_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'bmi';
  $context->description = '';
  $context->tag = 'calculator';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'calculator/body-mass-calculator' => 'calculator/body-mass-calculator',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'activity-block_bmi_body_mass' => array(
          'module' => 'activity',
          'delta' => 'block_bmi_body_mass',
          'region' => 'features',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('calculator');
  $export['bmi'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'calorie_burned';
  $context->description = '';
  $context->tag = 'calculator';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'calculator/calorie-burned-activities' => 'calculator/calorie-burned-activities',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'activity-block_cb_activity' => array(
          'module' => 'activity',
          'delta' => 'block_cb_activity',
          'region' => 'features',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('calculator');
  $export['calorie_burned'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'daily_calories';
  $context->description = '';
  $context->tag = 'calculator';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'calculator/daily-calories-calculator' => 'calculator/daily-calories-calculator',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'activity-block_daily_calories' => array(
          'module' => 'activity',
          'delta' => 'block_daily_calories',
          'region' => 'features',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('calculator');
  $export['daily_calories'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'heartrate';
  $context->description = '';
  $context->tag = 'calculator';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'calculator/calories-burned-heart-rate' => 'calculator/calories-burned-heart-rate',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'activity-block_cb_heart_rate' => array(
          'module' => 'activity',
          'delta' => 'block_cb_heart_rate',
          'region' => 'features',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('calculator');
  $export['heartrate'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'patient';
  $context->description = '';
  $context->tag = 'patient';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'pt/patient' => 'pt/patient',
        'pt/patient/*' => 'pt/patient/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'geia_blocks-geia_patient_info' => array(
          'module' => 'geia_blocks',
          'delta' => 'geia_patient_info',
          'region' => 'content',
          'weight' => '-10',
        ),
        'geia_pt-geia_pt_patient_nav' => array(
          'module' => 'geia_pt',
          'delta' => 'geia_pt_patient_nav',
          'region' => 'content',
          'weight' => '-9',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('patient');
  $export['patient'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'pt_dashboard';
  $context->description = '';
  $context->tag = 'PT';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'pt/dashboard' => 'pt/dashboard',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-pt_patients-block' => array(
          'module' => 'views',
          'delta' => 'pt_patients-block',
          'region' => 'content',
          'weight' => '10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('PT');
  $export['pt_dashboard'] = $context;

  return $export;
}
