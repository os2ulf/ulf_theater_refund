<?php

/**
 * @file
 * ulf_theater_refund.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function ulf_theater_refund_taxonomy_default_vocabularies() {
  return array(
    'teater' => array(
      'name' => 'Teater',
      'machine_name' => 'teater',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
