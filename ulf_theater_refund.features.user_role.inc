<?php

/**
 * @file
 * ulf_theater_refund.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function ulf_theater_refund_user_default_roles() {
  $roles = array();

  // Exported role: teaterkontakt.
  $roles['teaterkontakt'] = array(
    'name' => 'teaterkontakt',
    'weight' => 6,
  );

  return $roles;
}
