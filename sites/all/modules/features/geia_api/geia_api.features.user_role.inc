<?php
/**
 * @file
 * geia_api.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function geia_api_user_default_roles() {
  $roles = array();

  // Exported role: patient.
  $roles['patient'] = array(
    'name' => 'patient',
    'weight' => 4,
  );

  // Exported role: therapist.
  $roles['therapist'] = array(
    'name' => 'therapist',
    'weight' => 3,
  );

  return $roles;
}
