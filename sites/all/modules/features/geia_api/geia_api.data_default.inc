<?php
/**
 * @file
 * geia_api.data_default.inc
 */

/**
 * Implements hook_data_default().
 */
function geia_api_data_default() {
  $export = array();

  $data_table = new stdClass();
  $data_table->disabled = FALSE; /* Edit this to true to make a default data_table disabled initially */
  $data_table->api_version = 1;
  $data_table->title = 'Activity';
  $data_table->name = 'activity';
  $data_table->table_schema = array(
    'description' => '',
    'fields' => array(
      'id' => array(
        'type' => 'serial',
        'size' => 'normal',
        'not null' => TRUE,
        'description' => '',
      ),
      'uid' => array(
        'type' => 'int',
        'size' => 'normal',
        'not null' => FALSE,
        'description' => '',
      ),
      'goal_id' => array(
        'type' => 'int',
        'size' => 'normal',
        'not null' => FALSE,
        'description' => '',
      ),
      'date' => array(
        'type' => 'int',
        'size' => 'normal',
        'not null' => FALSE,
        'description' => '',
      ),
      'created' => array(
        'type' => 'int',
        'size' => 'normal',
        'not null' => FALSE,
        'description' => '',
      ),
      'updated' => array(
        'type' => 'int',
        'size' => 'normal',
        'not null' => FALSE,
        'description' => '',
      ),
      'total_steps' => array(
        'type' => 'int',
        'size' => 'normal',
        'unsigned' => FALSE,
      ),
      'steps_miles' => array(
        'type' => 'float',
        'size' => 'normal',
      ),
      'steps_calories' => array(
        'type' => 'float',
        'size' => 'normal',
      ),
      'activity_low' => array(
        'type' => 'int',
        'size' => 'normal',
        'unsigned' => FALSE,
      ),
      'activity_low_miles' => array(
        'type' => 'float',
        'size' => 'normal',
      ),
      'activity_low_calories' => array(
        'type' => 'int',
        'size' => 'normal',
        'unsigned' => FALSE,
      ),
      'activity_medium' => array(
        'type' => 'int',
        'size' => 'normal',
        'unsigned' => FALSE,
      ),
      'activity_medium_miles' => array(
        'type' => 'float',
        'size' => 'normal',
      ),
      'activity_medium_calories' => array(
        'type' => 'int',
        'size' => 'normal',
        'unsigned' => FALSE,
      ),
      'activity_high' => array(
        'type' => 'int',
        'size' => 'normal',
        'unsigned' => FALSE,
      ),
      'activity_high_miles' => array(
        'type' => 'float',
        'size' => 'normal',
      ),
      'activity_high_calories' => array(
        'type' => 'int',
        'size' => 'normal',
        'unsigned' => FALSE,
      ),
    ),
    'name' => 'activity',
    'indexes' => array(
      'activity_type' => array(
        0 => 'activity_type',
      ),
      'date' => array(
        0 => 'date',
      ),
      'goal_id' => array(
        0 => 'goal_id',
      ),
      'id' => array(
        0 => 'id',
      ),
      'uid' => array(
        0 => 'uid',
      ),
    ),
    'primary key' => array(
      0 => 'id',
    ),
  );
  $data_table->meta = array(
    'fields' => array(
      'id' => array(
        'label' => '',
      ),
      'uid' => array(
        'label' => '',
      ),
      'activity_type' => array(
        'label' => '',
      ),
      'activity' => array(
        'label' => '',
      ),
      'goal_id' => array(
        'label' => '',
      ),
      'calories' => array(
        'label' => '',
      ),
      'date' => array(
        'label' => '',
      ),
      'created' => array(
        'label' => '',
      ),
      'updated' => array(
        'label' => '',
      ),
      'xx' => array(
        'label' => '',
      ),
      'x' => array(
        'label' => '',
      ),
      'total_steps' => array(
        'label' => 'Total Steps',
      ),
      'steps_miles' => array(
        'label' => 'Steps Miles',
      ),
      'steps_calories' => array(
        'label' => 'Steps Calories',
      ),
      'activity_low' => array(
        'label' => 'Low Activity Mins',
      ),
      'activity_low_miles' => array(
        'label' => 'Low Activity Miles',
      ),
      'activity_low_calories' => array(
        'label' => 'Low Activity Calories',
      ),
      'activity_medium' => array(
        'label' => 'Medium Activity Mins',
      ),
      'activity_medium_miles' => array(
        'label' => 'Medium Activity Miles',
      ),
      'activity_medium_calories' => array(
        'label' => 'Medium Activity Calories',
      ),
      'activity_high' => array(
        'label' => 'High Activity Mins',
      ),
      'activity_high_miles' => array(
        'label' => 'High Activity Miles',
      ),
      'activity_high_calories' => array(
        'label' => 'High Activity Calories',
      ),
    ),
  );
  $export['activity'] = $data_table;

  $data_table = new stdClass();
  $data_table->disabled = FALSE; /* Edit this to true to make a default data_table disabled initially */
  $data_table->api_version = 1;
  $data_table->title = 'Activity Goals';
  $data_table->name = 'activity_goals';
  $data_table->table_schema = array(
    'description' => '',
    'fields' => array(
      'id' => array(
        'type' => 'serial',
        'size' => 'normal',
        'not null' => TRUE,
        'description' => '',
      ),
      'uid' => array(
        'type' => 'int',
        'size' => 'normal',
        'not null' => FALSE,
        'description' => '',
      ),
      'date' => array(
        'type' => 'int',
        'size' => 'normal',
        'not null' => FALSE,
        'description' => '',
      ),
      'updated' => array(
        'type' => 'int',
        'size' => 'normal',
        'not null' => FALSE,
        'description' => '',
      ),
      'created' => array(
        'type' => 'int',
        'size' => 'normal',
        'not null' => FALSE,
        'description' => '',
      ),
      'total_steps' => array(
        'type' => 'int',
        'size' => 'normal',
        'unsigned' => FALSE,
      ),
      'time_active_high' => array(
        'type' => 'int',
        'size' => 'normal',
        'unsigned' => FALSE,
      ),
      'time_active_medium' => array(
        'type' => 'int',
        'size' => 'normal',
        'unsigned' => FALSE,
      ),
      'time_active_low' => array(
        'type' => 'int',
        'size' => 'normal',
        'unsigned' => FALSE,
      ),
      'instructions' => array(
        'type' => 'text',
        'size' => 'big',
      ),
    ),
    'name' => 'activity_goals',
    'indexes' => array(
      'date' => array(
        0 => 'date',
      ),
      'id' => array(
        0 => 'id',
      ),
      'uid' => array(
        0 => 'uid',
      ),
    ),
    'primary key' => array(
      0 => 'id',
    ),
  );
  $data_table->meta = array(
    'fields' => array(
      'id' => array(
        'label' => '',
      ),
      'uid' => array(
        'label' => '',
      ),
      'date' => array(
        'label' => '',
      ),
      'goal' => array(
        'label' => '',
      ),
      'goal_type' => array(
        'label' => '',
      ),
      'updated' => array(
        'label' => '',
      ),
      'created' => array(
        'label' => '',
      ),
      'dete1' => array(
        'label' => '',
      ),
      'deed' => array(
        'label' => '',
      ),
      'total_steps' => array(
        'label' => 'Total Steps',
      ),
      'time_active_high' => array(
        'label' => 'High Activity Mins',
      ),
      'time_active_medium' => array(
        'label' => 'Medium Activity Mins',
      ),
      'time_active_low' => array(
        'label' => 'Low Activity Mins',
      ),
      'instructions' => array(
        'label' => 'Instructions',
      ),
    ),
  );
  $export['activity_goals'] = $data_table;

  $data_table = new stdClass();
  $data_table->disabled = FALSE; /* Edit this to true to make a default data_table disabled initially */
  $data_table->api_version = 1;
  $data_table->title = 'Activity Logs';
  $data_table->name = 'activity_logs';
  $data_table->table_schema = array(
    'description' => '',
    'fields' => array(
      'id' => array(
        'type' => 'serial',
        'size' => 'normal',
        'not null' => TRUE,
        'description' => '',
      ),
      'uid' => array(
        'type' => 'int',
        'size' => 'normal',
        'not null' => FALSE,
        'description' => '',
      ),
      'date' => array(
        'type' => 'int',
        'size' => 'normal',
        'not null' => FALSE,
        'description' => '',
      ),
      'updated' => array(
        'type' => 'int',
        'size' => 'normal',
        'not null' => FALSE,
        'description' => '',
      ),
      'created' => array(
        'type' => 'int',
        'size' => 'normal',
        'not null' => FALSE,
        'description' => '',
      ),
      'total_steps_goal' => array(
        'type' => 'int',
        'size' => 'normal',
        'not null' => FALSE,
        'description' => '',
      ),
      'total_steps' => array(
        'type' => 'int',
        'size' => 'normal',
        'not null' => FALSE,
        'description' => '',
      ),
      'time_active_high_goal' => array(
        'type' => 'int',
        'size' => 'normal',
        'not null' => FALSE,
        'description' => '',
      ),
      'time_active_high' => array(
        'type' => 'int',
        'size' => 'normal',
        'not null' => FALSE,
        'description' => '',
      ),
      'time_active_medium_goal' => array(
        'type' => 'int',
        'size' => 'normal',
        'not null' => FALSE,
        'description' => '',
      ),
      'time_active_medium' => array(
        'type' => 'int',
        'size' => 'normal',
        'not null' => FALSE,
        'description' => '',
      ),
      'time_active_low_goal' => array(
        'type' => 'int',
        'size' => 'normal',
        'not null' => FALSE,
        'description' => '',
      ),
      'time_active_low' => array(
        'type' => 'int',
        'size' => 'normal',
        'not null' => FALSE,
        'description' => '',
      ),
      'calories' => array(
        'type' => 'int',
        'size' => 'normal',
        'unsigned' => FALSE,
      ),
    ),
    'name' => 'activity_logs',
    'indexes' => array(
      'id' => array(
        0 => 'id',
      ),
      'uid' => array(
        0 => 'uid',
      ),
    ),
  );
  $data_table->meta = array(
    'fields' => array(
      'id' => array(
        'label' => '',
      ),
      'uid' => array(
        'label' => '',
      ),
      'date' => array(
        'label' => '',
      ),
      'updated' => array(
        'label' => '',
      ),
      'created' => array(
        'label' => '',
      ),
      'total_steps_goal' => array(
        'label' => '',
      ),
      'total_steps' => array(
        'label' => '',
      ),
      'time_active_high_goal' => array(
        'label' => '',
      ),
      'time_active_high' => array(
        'label' => '',
      ),
      'time_active_medium_goal' => array(
        'label' => '',
      ),
      'time_active_medium' => array(
        'label' => '',
      ),
      'time_active_low_goal' => array(
        'label' => '',
      ),
      'time_active_low' => array(
        'label' => '',
      ),
      'calories' => array(
        'label' => '',
      ),
    ),
  );
  $export['activity_logs'] = $data_table;

  $data_table = new stdClass();
  $data_table->disabled = FALSE; /* Edit this to true to make a default data_table disabled initially */
  $data_table->api_version = 1;
  $data_table->title = 'Activity Type';
  $data_table->name = 'activity_type';
  $data_table->table_schema = array(
    'description' => '',
    'fields' => array(
      'id' => array(
        'type' => 'serial',
        'size' => 'normal',
        'not null' => TRUE,
        'description' => '',
      ),
      'type' => array(
        'type' => 'text',
        'size' => 'normal',
        'not null' => FALSE,
        'description' => '',
      ),
      'created' => array(
        'type' => 'int',
        'size' => 'normal',
        'not null' => FALSE,
        'description' => '',
      ),
    ),
    'name' => 'activity_type',
    'indexes' => array(
      'id' => array(
        0 => 'id',
      ),
    ),
    'primary key' => array(
      0 => 'id',
    ),
  );
  $data_table->meta = array(
    'fields' => array(
      'id' => array(
        'label' => '',
      ),
      'type' => array(
        'label' => '',
      ),
      'created' => array(
        'label' => '',
      ),
    ),
  );
  $export['activity_type'] = $data_table;

  $data_table = new stdClass();
  $data_table->disabled = FALSE; /* Edit this to true to make a default data_table disabled initially */
  $data_table->api_version = 1;
  $data_table->title = 'Characteristics';
  $data_table->name = 'characteristics';
  $data_table->table_schema = array(
    'description' => '',
    'fields' => array(
      'id' => array(
        'type' => 'serial',
        'size' => 'normal',
        'not null' => TRUE,
        'description' => '',
      ),
      'uid' => array(
        'type' => 'int',
        'size' => 'normal',
        'not null' => FALSE,
        'description' => '',
      ),
      'weight' => array(
        'type' => 'float',
        'size' => 'normal',
        'not null' => FALSE,
        'description' => '',
        'unsigned' => FALSE,
      ),
      'height' => array(
        'type' => 'float',
        'size' => 'normal',
        'not null' => FALSE,
        'description' => '',
        'unsigned' => FALSE,
      ),
      'body_fat' => array(
        'type' => 'float',
        'size' => 'normal',
        'not null' => FALSE,
        'description' => '',
        'unsigned' => FALSE,
      ),
      'bmi' => array(
        'type' => 'float',
        'size' => 'normal',
        'not null' => FALSE,
        'description' => '',
        'unsigned' => FALSE,
      ),
      'resting_heart_rate' => array(
        'type' => 'int',
        'size' => 'normal',
        'not null' => FALSE,
        'description' => '',
      ),
      'blood_pressure_sys' => array(
        'type' => 'int',
        'size' => 'normal',
        'not null' => FALSE,
        'description' => '',
      ),
      'blood_pressure_dia' => array(
        'type' => 'int',
        'size' => 'normal',
        'not null' => FALSE,
        'description' => '',
      ),
      'record_date' => array(
        'type' => 'int',
        'size' => 'normal',
        'not null' => FALSE,
        'description' => '',
      ),
      'date_created' => array(
        'type' => 'int',
        'size' => 'normal',
        'not null' => FALSE,
        'description' => '',
      ),
      'emotion' => array(
        'type' => 'float',
        'size' => 'normal',
      ),
      'max_heart_rate' => array(
        'type' => 'int',
        'size' => 'normal',
        'unsigned' => FALSE,
      ),
    ),
    'name' => 'characteristics',
    'indexes' => array(
      'id' => array(
        0 => 'id',
      ),
      'record_date' => array(
        0 => 'record_date',
      ),
    ),
    'primary key' => array(
      0 => 'id',
    ),
  );
  $data_table->meta = array(
    'fields' => array(
      'id' => array(
        'label' => 'id',
        'locked' => FALSE,
        'required' => FALSE,
        'date' => array(
          'sql_type' => '',
          'granularity' => '',
        ),
      ),
      'uid' => array(
        'label' => 'uid',
        'locked' => FALSE,
        'required' => FALSE,
        'date' => array(
          'sql_type' => '',
          'granularity' => '',
        ),
      ),
      'weight' => array(
        'label' => 'weight',
        'locked' => FALSE,
        'required' => FALSE,
        'date' => array(
          'sql_type' => '',
          'granularity' => '',
        ),
      ),
      'height' => array(
        'label' => 'height',
        'locked' => FALSE,
        'required' => FALSE,
        'date' => array(
          'sql_type' => '',
          'granularity' => '',
        ),
      ),
      'body_fat' => array(
        'label' => 'body fat',
        'locked' => FALSE,
        'required' => FALSE,
        'date' => array(
          'sql_type' => '',
          'granularity' => '',
        ),
      ),
      'bmi' => array(
        'label' => 'bmi',
        'locked' => FALSE,
        'required' => FALSE,
        'date' => array(
          'sql_type' => '',
          'granularity' => '',
        ),
      ),
      'resting_heart_rate' => array(
        'label' => 'Resting Heart Rate',
        'locked' => FALSE,
        'required' => FALSE,
        'date' => array(
          'sql_type' => '',
          'granularity' => '',
        ),
      ),
      'blood_pressure_sys' => array(
        'label' => 'BP Sys',
        'locked' => FALSE,
        'required' => FALSE,
        'date' => array(
          'sql_type' => '',
          'granularity' => '',
        ),
      ),
      'blood_pressure_dia' => array(
        'label' => 'BP Dia',
        'locked' => FALSE,
        'required' => FALSE,
        'date' => array(
          'sql_type' => '',
          'granularity' => '',
        ),
      ),
      'record_date' => array(
        'label' => 'Date',
        'locked' => FALSE,
        'required' => FALSE,
        'date' => array(
          'sql_type' => 'datestamp',
          'granularity' => 'day',
        ),
      ),
      'date_created' => array(
        'label' => 'Created',
        'locked' => FALSE,
        'required' => FALSE,
        'date' => array(
          'sql_type' => 'datestamp',
          'granularity' => '',
        ),
      ),
      'emotion' => array(
        'label' => 'Emotion',
      ),
      'max_heart_rate' => array(
        'label' => 'Max Heart Rate',
      ),
    ),
    'label_field' => '',
    'is_entity_type' => 1,
    'entity_id' => 'id',
    'join' => array(),
  );
  $export['characteristics'] = $data_table;

  $data_table = new stdClass();
  $data_table->disabled = FALSE; /* Edit this to true to make a default data_table disabled initially */
  $data_table->api_version = 1;
  $data_table->title = 'Exercise images';
  $data_table->name = 'exercise_images';
  $data_table->table_schema = array(
    'description' => '',
    'fields' => array(
      'id' => array(
        'type' => 'serial',
        'size' => 'normal',
        'not null' => TRUE,
        'description' => '',
      ),
      'exid' => array(
        'type' => 'int',
        'size' => 'normal',
        'not null' => FALSE,
        'description' => '',
      ),
      'image1' => array(
        'type' => 'text',
        'size' => 'normal',
        'not null' => FALSE,
        'description' => '',
      ),
      'image2' => array(
        'type' => 'text',
        'size' => 'normal',
        'not null' => FALSE,
        'description' => '',
      ),
      'created' => array(
        'type' => 'int',
        'size' => 'normal',
        'not null' => FALSE,
        'description' => '',
      ),
      'updated' => array(
        'type' => 'int',
        'size' => 'normal',
        'not null' => FALSE,
        'description' => '',
      ),
    ),
    'name' => 'exercise_images',
    'indexes' => array(
      'id' => array(
        0 => 'id',
      ),
    ),
    'primary key' => array(
      0 => 'id',
    ),
  );
  $data_table->meta = array(
    'fields' => array(
      'id' => array(),
      'exid' => array(),
      'image1' => array(),
      'image2' => array(),
      'created' => array(),
      'updated' => array(),
    ),
  );
  $export['exercise_images'] = $data_table;

  $data_table = new stdClass();
  $data_table->disabled = FALSE; /* Edit this to true to make a default data_table disabled initially */
  $data_table->api_version = 1;
  $data_table->title = 'Exercise tracking';
  $data_table->name = 'exercise_tracking';
  $data_table->table_schema = array(
    'description' => '',
    'fields' => array(
      'id' => array(
        'type' => 'serial',
        'size' => 'normal',
        'not null' => TRUE,
        'description' => '',
      ),
      'uid' => array(
        'type' => 'int',
        'size' => 'normal',
        'not null' => FALSE,
        'description' => '',
      ),
      'peid' => array(
        'type' => 'int',
        'size' => 'normal',
        'not null' => FALSE,
        'description' => '',
      ),
      'date' => array(
        'type' => 'int',
        'size' => 'normal',
        'not null' => FALSE,
        'description' => '',
      ),
      'created' => array(
        'type' => 'int',
        'size' => 'normal',
        'not null' => FALSE,
        'description' => '',
      ),
    ),
    'name' => 'exercise_tracking',
    'primary key' => array(
      0 => 'id',
    ),
  );
  $data_table->meta = array(
    'fields' => array(
      'id' => array(),
      'uid' => array(),
      'peid' => array(),
      'date' => array(),
      'created' => array(),
    ),
  );
  $export['exercise_tracking'] = $data_table;

  $data_table = new stdClass();
  $data_table->disabled = FALSE; /* Edit this to true to make a default data_table disabled initially */
  $data_table->api_version = 1;
  $data_table->title = 'Exercise videos';
  $data_table->name = 'exercise_videos';
  $data_table->table_schema = array(
    'description' => '',
    'fields' => array(
      'id' => array(
        'type' => 'serial',
        'size' => 'normal',
        'not null' => TRUE,
        'description' => '',
      ),
      'exid' => array(
        'type' => 'int',
        'size' => 'normal',
        'not null' => FALSE,
        'description' => '',
      ),
      'mov' => array(
        'type' => 'text',
        'size' => 'normal',
        'not null' => FALSE,
        'description' => '',
      ),
      'mp4' => array(
        'type' => 'text',
        'size' => 'normal',
        'not null' => FALSE,
        'description' => '',
      ),
      'webm' => array(
        'type' => 'text',
        'size' => 'normal',
        'not null' => FALSE,
        'description' => '',
      ),
      'created' => array(
        'type' => 'int',
        'size' => 'normal',
        'not null' => FALSE,
        'description' => '',
      ),
      'updated' => array(
        'type' => 'int',
        'size' => 'normal',
        'not null' => FALSE,
        'description' => '',
      ),
    ),
    'name' => 'exercise_videos',
    'indexes' => array(
      'exid' => array(
        0 => 'exid',
      ),
      'id' => array(
        0 => 'id',
      ),
    ),
    'primary key' => array(
      0 => 'id',
    ),
  );
  $data_table->meta = array(
    'fields' => array(
      'id' => array(),
      'exid' => array(),
      'mov' => array(),
      'mp4' => array(),
      'webm' => array(),
      'created' => array(),
      'updated' => array(),
    ),
  );
  $export['exercise_videos'] = $data_table;

  $data_table = new stdClass();
  $data_table->disabled = FALSE; /* Edit this to true to make a default data_table disabled initially */
  $data_table->api_version = 1;
  $data_table->title = 'Exercises';
  $data_table->name = 'exercises';
  $data_table->table_schema = array(
    'description' => '',
    'fields' => array(
      'id' => array(
        'type' => 'serial',
        'size' => 'normal',
        'not null' => TRUE,
        'description' => '',
      ),
      'webexcode' => array(
        'type' => 'text',
        'size' => 'normal',
        'not null' => FALSE,
        'description' => '',
      ),
      'owner' => array(
        'type' => 'int',
        'size' => 'normal',
        'not null' => FALSE,
        'description' => '',
      ),
      'title' => array(
        'type' => 'text',
        'size' => 'normal',
        'not null' => FALSE,
        'description' => '',
      ),
      'created' => array(
        'type' => 'int',
        'size' => 'normal',
        'not null' => FALSE,
        'description' => '',
      ),
      'updated' => array(
        'type' => 'int',
        'size' => 'normal',
        'not null' => FALSE,
        'description' => '',
      ),
    ),
    'name' => 'exercises',
    'indexes' => array(
      'id' => array(
        0 => 'id',
      ),
      'webexcode' => array(
        0 => array(
          0 => 'webexcode',
          1 => 255,
        ),
      ),
    ),
    'primary key' => array(
      0 => 'id',
    ),
  );
  $data_table->meta = array(
    'fields' => array(
      'id' => array(),
      'webexcode' => array(),
      'owner' => array(),
      'title' => array(),
      'created' => array(),
      'updated' => array(),
    ),
  );
  $export['exercises'] = $data_table;

  $data_table = new stdClass();
  $data_table->disabled = FALSE; /* Edit this to true to make a default data_table disabled initially */
  $data_table->api_version = 1;
  $data_table->title = 'Nutrition Goals';
  $data_table->name = 'nutrition_goals';
  $data_table->table_schema = array(
    'description' => '',
    'fields' => array(
      'id' => array(
        'type' => 'serial',
        'size' => 'normal',
        'not null' => TRUE,
        'description' => '',
      ),
      'uid' => array(
        'type' => 'int',
        'size' => 'normal',
        'not null' => FALSE,
        'description' => '',
      ),
      'date' => array(
        'type' => 'int',
        'size' => 'normal',
        'not null' => FALSE,
        'description' => '',
      ),
      'created' => array(
        'type' => 'int',
        'size' => 'normal',
        'not null' => FALSE,
        'description' => '',
      ),
      'updated' => array(
        'type' => 'int',
        'size' => 'normal',
        'not null' => FALSE,
        'description' => '',
      ),
      'calories' => array(
        'type' => 'int',
        'size' => 'normal',
        'unsigned' => FALSE,
      ),
      'fat' => array(
        'type' => 'float',
        'size' => 'normal',
      ),
      'protein' => array(
        'type' => 'float',
        'size' => 'normal',
      ),
      'carbohydrates' => array(
        'type' => 'float',
        'size' => 'normal',
      ),
      'instructions' => array(
        'type' => 'text',
        'size' => 'big',
      ),
    ),
    'name' => 'nutrition_goals',
    'indexes' => array(
      'date' => array(
        0 => 'date',
      ),
      'id' => array(
        0 => 'id',
      ),
      'uid' => array(
        0 => 'uid',
      ),
    ),
    'primary key' => array(
      0 => 'id',
    ),
  );
  $data_table->meta = array(
    'fields' => array(
      'id' => array(
        'label' => '',
      ),
      'uid' => array(
        'label' => '',
      ),
      'goal' => array(
        'label' => '',
      ),
      'goal_type' => array(
        'label' => '',
      ),
      'date' => array(
        'label' => '',
      ),
      'created' => array(
        'label' => '',
      ),
      'updated' => array(
        'label' => '',
      ),
      'calories' => array(
        'label' => 'calories',
      ),
      'fat' => array(
        'label' => 'fat',
      ),
      'protein' => array(
        'label' => 'protein',
      ),
      'carbohydrates' => array(
        'label' => 'carbohydrates',
      ),
      'instructions' => array(
        'label' => 'instructions',
      ),
    ),
  );
  $export['nutrition_goals'] = $data_table;

  $data_table = new stdClass();
  $data_table->disabled = FALSE; /* Edit this to true to make a default data_table disabled initially */
  $data_table->api_version = 1;
  $data_table->title = 'Nutrition logs';
  $data_table->name = 'nutrition_logs';
  $data_table->table_schema = array(
    'description' => '',
    'fields' => array(
      'id' => array(
        'type' => 'serial',
        'size' => 'normal',
        'not null' => TRUE,
        'description' => '',
      ),
      'uid' => array(
        'type' => 'int',
        'size' => 'normal',
        'not null' => FALSE,
        'description' => '',
      ),
      'date' => array(
        'type' => 'int',
        'size' => 'normal',
        'not null' => FALSE,
        'description' => '',
      ),
      'created' => array(
        'type' => 'int',
        'size' => 'normal',
        'not null' => FALSE,
        'description' => '',
      ),
      'updated' => array(
        'type' => 'int',
        'size' => 'normal',
        'not null' => FALSE,
        'description' => '',
      ),
      'calories_goal' => array(
        'type' => 'numeric',
        'size' => 'normal',
        'precision' => '11',
        'scale' => '0',
        'not null' => FALSE,
        'description' => '',
      ),
      'calories' => array(
        'type' => 'numeric',
        'size' => 'normal',
        'precision' => '11',
        'scale' => '0',
        'not null' => FALSE,
        'description' => '',
      ),
      'fat_goal' => array(
        'type' => 'numeric',
        'size' => 'normal',
        'precision' => '11',
        'scale' => '0',
        'not null' => FALSE,
        'description' => '',
      ),
      'fat' => array(
        'type' => 'numeric',
        'size' => 'normal',
        'precision' => '11',
        'scale' => '0',
        'not null' => FALSE,
        'description' => '',
      ),
      'protein_goal' => array(
        'type' => 'numeric',
        'size' => 'normal',
        'precision' => '11',
        'scale' => '0',
        'not null' => FALSE,
        'description' => '',
      ),
      'protein' => array(
        'type' => 'numeric',
        'size' => 'normal',
        'precision' => '11',
        'scale' => '0',
        'not null' => FALSE,
        'description' => '',
      ),
      'carbohydrates_goal' => array(
        'type' => 'numeric',
        'size' => 'normal',
        'precision' => '11',
        'scale' => '0',
        'not null' => FALSE,
        'description' => '',
      ),
      'carbohydrates' => array(
        'type' => 'numeric',
        'size' => 'normal',
        'precision' => '11',
        'scale' => '0',
        'not null' => FALSE,
        'description' => '',
      ),
    ),
    'name' => 'nutrition_logs',
    'primary key' => array(
      0 => 'id',
    ),
  );
  $data_table->meta = array(
    'fields' => array(
      'id' => array(),
      'uid' => array(),
      'date' => array(),
      'created' => array(),
      'updated' => array(),
      'calories_goal' => array(),
      'calories' => array(),
      'fat_goal' => array(),
      'fat' => array(),
      'protein_goal' => array(),
      'protein' => array(),
      'carbohydrates_goal' => array(),
      'carbohydrates' => array(),
    ),
  );
  $export['nutrition_logs'] = $data_table;

  $data_table = new stdClass();
  $data_table->disabled = FALSE; /* Edit this to true to make a default data_table disabled initially */
  $data_table->api_version = 1;
  $data_table->title = 'Patient exercises';
  $data_table->name = 'patient_exercises';
  $data_table->table_schema = array(
    'description' => '',
    'fields' => array(
      'id' => array(
        'type' => 'serial',
        'size' => 'normal',
        'not null' => TRUE,
        'description' => '',
      ),
      'exid' => array(
        'type' => 'int',
        'size' => 'normal',
        'not null' => FALSE,
        'description' => '',
      ),
      'uid' => array(
        'type' => 'int',
        'size' => 'normal',
        'not null' => FALSE,
        'description' => '',
      ),
      'active' => array(
        'type' => 'int',
        'size' => 'normal',
        'not null' => FALSE,
        'description' => '',
      ),
      'reps' => array(
        'type' => 'int',
        'size' => 'normal',
        'not null' => FALSE,
        'description' => '',
      ),
      'sets' => array(
        'type' => 'int',
        'size' => 'normal',
        'not null' => FALSE,
        'description' => '',
      ),
      'rest' => array(
        'type' => 'int',
        'size' => 'normal',
        'not null' => FALSE,
        'description' => '',
      ),
      'daily' => array(
        'type' => 'int',
        'size' => 'normal',
        'not null' => FALSE,
        'description' => '',
      ),
      'weekly' => array(
        'type' => 'text',
        'size' => 'normal',
        'not null' => FALSE,
        'description' => '',
      ),
      'webexcode' => array(
        'type' => 'text',
        'size' => 'normal',
        'not null' => FALSE,
        'description' => '',
      ),
      'created' => array(
        'type' => 'int',
        'size' => 'normal',
        'not null' => FALSE,
        'description' => '',
      ),
      'updated' => array(
        'type' => 'int',
        'size' => 'normal',
        'not null' => FALSE,
        'description' => '',
      ),
      'comments' => array(
        'type' => 'text',
        'size' => 'big',
        'not null' => FALSE,
        'description' => '',
      ),
    ),
    'name' => 'patient_exercises',
    'primary key' => array(
      0 => 'id',
    ),
  );
  $data_table->meta = array(
    'fields' => array(
      'id' => array(),
      'exid' => array(),
      'uid' => array(),
      'active' => array(),
      'reps' => array(),
      'sets' => array(),
      'rest' => array(),
      'daily' => array(),
      'weekly' => array(),
      'webexcode' => array(),
      'created' => array(),
      'updated' => array(),
      'comments' => array(),
    ),
  );
  $export['patient_exercises'] = $data_table;

  $data_table = new stdClass();
  $data_table->disabled = FALSE; /* Edit this to true to make a default data_table disabled initially */
  $data_table->api_version = 1;
  $data_table->title = 'Step Data';
  $data_table->name = 'step_data';
  $data_table->table_schema = array(
    'description' => '',
    'fields' => array(
      'id' => array(
        'type' => 'serial',
        'size' => 'normal',
        'not null' => TRUE,
        'description' => '',
      ),
      'uid' => array(
        'type' => 'int',
        'size' => 'normal',
        'not null' => FALSE,
        'description' => '',
      ),
      'created' => array(
        'type' => 'int',
        'size' => 'normal',
        'not null' => FALSE,
        'description' => '',
      ),
      'start_date' => array(
        'type' => 'int',
        'size' => 'normal',
        'not null' => FALSE,
        'description' => '',
      ),
      'end_date' => array(
        'type' => 'int',
        'size' => 'normal',
        'not null' => FALSE,
        'description' => '',
      ),
      'step_count' => array(
        'type' => 'int',
        'size' => 'normal',
        'not null' => FALSE,
        'description' => '',
      ),
      'step_min' => array(
        'type' => 'int',
        'size' => 'normal',
        'unsigned' => FALSE,
      ),
    ),
    'name' => 'step_data',
    'indexes' => array(
      'created' => array(
        0 => 'created',
      ),
      'id' => array(
        0 => 'id',
      ),
      'uid' => array(
        0 => 'uid',
      ),
      'end_date' => array(
        0 => 'end_date',
      ),
      'step_min' => array(
        0 => 'step_min',
      ),
    ),
    'primary key' => array(
      0 => 'id',
    ),
  );
  $data_table->meta = array(
    'fields' => array(
      'id' => array(
        'label' => '',
      ),
      'uid' => array(
        'label' => 'UID',
      ),
      'created' => array(
        'label' => 'Created Date',
      ),
      'start_date' => array(
        'label' => '',
      ),
      'end_date' => array(
        'label' => '',
      ),
      'step_count' => array(
        'label' => '',
      ),
      'step_min' => array(
        'label' => '',
      ),
    ),
  );
  $export['step_data'] = $data_table;

  $data_table = new stdClass();
  $data_table->disabled = FALSE; /* Edit this to true to make a default data_table disabled initially */
  $data_table->api_version = 1;
  $data_table->title = 'Survey Data';
  $data_table->name = 'survey_data';
  $data_table->table_schema = array(
    'description' => '',
    'fields' => array(
      'id' => array(
        'type' => 'serial',
        'size' => 'normal',
        'not null' => TRUE,
        'description' => '',
      ),
      'uid' => array(
        'type' => 'int',
        'size' => 'normal',
        'not null' => FALSE,
        'description' => '',
      ),
      'created' => array(
        'type' => 'int',
        'size' => 'normal',
        'not null' => FALSE,
        'description' => '',
      ),
      'answers' => array(
        'type' => 'text',
        'size' => 'big',
        'not null' => FALSE,
        'description' => '',
      ),
      'score' => array(
        'type' => 'float',
        'size' => 'normal',
        'not null' => FALSE,
        'description' => '',
      ),
    ),
    'name' => 'survey_data',
    'indexes' => array(
      'created' => array(
        0 => 'created',
      ),
      'id' => array(
        0 => 'id',
      ),
      'uid' => array(
        0 => 'uid',
      ),
    ),
    'primary key' => array(
      0 => 'id',
    ),
  );
  $data_table->meta = array(
    'fields' => array(
      'id' => array(
        'label' => '',
      ),
      'uid' => array(
        'label' => '',
      ),
      'created' => array(
        'label' => '',
      ),
      'answers' => array(
        'label' => '',
      ),
      'score' => array(
        'label' => '',
      ),
    ),
  );
  $export['survey_data'] = $data_table;

  $data_table = new stdClass();
  $data_table->disabled = FALSE; /* Edit this to true to make a default data_table disabled initially */
  $data_table->api_version = 1;
  $data_table->title = 'Treshhold levels';
  $data_table->name = 'treshhold_levels';
  $data_table->table_schema = array(
    'description' => '',
    'fields' => array(
      'id' => array(
        'type' => 'serial',
        'size' => 'normal',
        'not null' => TRUE,
        'description' => '',
        'unsigned' => FALSE,
      ),
      'uid' => array(
        'type' => 'int',
        'size' => 'normal',
        'not null' => FALSE,
        'description' => '',
      ),
      'steps_low' => array(
        'type' => 'int',
        'size' => 'normal',
        'not null' => FALSE,
        'description' => '',
      ),
      'steps_high' => array(
        'type' => 'int',
        'size' => 'normal',
        'not null' => FALSE,
        'description' => '',
      ),
      'hr_low' => array(
        'type' => 'int',
        'size' => 'normal',
        'not null' => FALSE,
        'description' => '',
      ),
      'hr_high' => array(
        'type' => 'int',
        'size' => 'normal',
        'not null' => FALSE,
        'description' => '',
      ),
    ),
    'name' => 'treshhold_levels',
    'primary key' => array(
      0 => 'id',
    ),
    'indexes' => array(
      'uid' => array(
        0 => 'uid',
      ),
    ),
  );
  $data_table->meta = array(
    'fields' => array(
      'id' => array(
        'label' => '',
      ),
      'uid' => array(
        'label' => '',
      ),
      'steps_low' => array(
        'label' => '',
      ),
      'steps_high' => array(
        'label' => '',
      ),
      'hr_low' => array(
        'label' => '',
      ),
      'hr_high' => array(
        'label' => '',
      ),
    ),
  );
  $export['treshhold_levels'] = $data_table;

  return $export;
}
