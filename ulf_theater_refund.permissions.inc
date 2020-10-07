<?php

/**
 * @file
 * Permission settings for the loop_documents module.
 */

/**
 * Implements hook_permissions_secure_permissions_roles().
 */
function ulf_theater_refund_secure_permissions_roles() {
  return array(
    'teaterkontakt',
  );
}

/**
 * Implements hook_permissions().
 *
 * Add permission to restrict access to certain admin paths.
 */
function ulf_theater_refund_permission() {
  $permissions = array(
    'administer ulf theater refund settings' => array(
      'title' => t('Administer theater refund settings'),
      'description' => t('Administer theater refund settings'),
    ),
  );

  return $permissions;
}

/**
 * Implements hook_secure_permissions().
 */
function ulf_theater_refund_secure_permissions($role) {
  $permissions = array(
    'teaterkontakt' => array(
      'view own entityform',
      'view the administration theme',
      'access toolbar',
    ),
    'editor' => array(
      'view any entityform',
      'edit any entityform',
      'delete any entityform',
      'assign teaterkontakt role',
      'administer ulf theater refund settings',
    ),
  );

  return isset($permissions[$role]) ? $permissions[$role] : NULL;
}
