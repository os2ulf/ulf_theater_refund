<?php

/**
 * @file
 * ulf_theater_refund.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function ulf_theater_refund_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_gdpr|entityform|theater_refund|form';
  $field_group->group_name = 'group_gdpr';
  $field_group->entity_type = 'entityform';
  $field_group->bundle = 'theater_refund';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Databeskyttelse',
    'weight' => '5',
    'children' => array(
      0 => 'field_tr_gdpr',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Databeskyttelse',
      'instance_settings' => array(
        'required_fields' => 0,
        'id' => '',
        'classes' => 'group-gdpr field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_gdpr|entityform|theater_refund|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tr_course|entityform|theater_refund|form';
  $field_group->group_name = 'group_tr_course';
  $field_group->entity_type = 'entityform';
  $field_group->bundle = 'theater_refund';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Forestilling',
    'weight' => '2',
    'children' => array(
      0 => 'field_tr_date',
      1 => 'field_tr_new_course_name',
      2 => 'field_tr_requested_amount',
      3 => 'field_tr_quantity',
      4 => 'field_tr_provider_name',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Forestilling',
      'instance_settings' => array(
        'required_fields' => 0,
        'id' => '',
        'classes' => 'group-tr-course field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_tr_course|entityform|theater_refund|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tr_editors|entityform|theater_refund|form';
  $field_group->group_name = 'group_tr_editors';
  $field_group->entity_type = 'entityform';
  $field_group->bundle = 'theater_refund';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Redaktion',
    'weight' => '0',
    'children' => array(
      0 => 'field_tr_granted_amount',
      1 => 'field_tr_latest_editor',
      2 => 'field_tr_mails_sent',
      3 => 'field_tr_remarks',
      4 => 'field_tr_send_mail',
      5 => 'field_tr_status',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Redaktion',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-tr-editors field-group-fieldset',
        'description' => 'Kun synlig for redaktører.',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $field_groups['group_tr_editors|entityform|theater_refund|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tr_payment|entityform|theater_refund|form';
  $field_group->group_name = 'group_tr_payment';
  $field_group->entity_type = 'entityform';
  $field_group->bundle = 'theater_refund';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Udbetaling',
    'weight' => '3',
    'children' => array(
      0 => 'field_tr_attachment',
      1 => 'field_tr_payment_date',
      2 => 'field_tr_spent_amount',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Udbetaling',
      'instance_settings' => array(
        'required_fields' => 0,
        'id' => '',
        'classes' => 'group-tr-payment field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_tr_payment|entityform|theater_refund|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tr_school|entityform|theater_refund|form';
  $field_group->group_name = 'group_tr_school';
  $field_group->entity_type = 'entityform';
  $field_group->bundle = 'theater_refund';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Skole',
    'weight' => '1',
    'children' => array(
      0 => 'field_tr_grade',
      1 => 'field_tr_mail',
      2 => 'field_tr_name',
      3 => 'field_tr_phone',
      4 => 'field_tr_school',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Skole',
      'instance_settings' => array(
        'required_fields' => 0,
        'id' => '',
        'classes' => 'group-tr-school field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_tr_school|entityform|theater_refund|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tr_submission|entityform|theater_refund|form';
  $field_group->group_name = 'group_tr_submission';
  $field_group->entity_type = 'entityform';
  $field_group->bundle = 'theater_refund';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Det med småt',
    'weight' => '4',
    'children' => array(
      0 => 'field_tr_conditions',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Det med småt',
      'instance_settings' => array(
        'required_fields' => 0,
        'id' => '',
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_tr_submission|entityform|theater_refund|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Databeskyttelse');
  t('Det med småt');
  t('Forestilling');
  t('Redaktion');
  t('Skole');
  t('Udbetaling');

  return $field_groups;
}
