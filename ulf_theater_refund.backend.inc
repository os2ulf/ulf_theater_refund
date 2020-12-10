<?php

/**
 * @file
 *
 * Code for the backend form.
 */

/**
 * Create custom backend form.
 *
 * @param array $form
 *   Custom backend form.
 * @param array $form_state
 *   Form state of the backend form.
 *
 * @return mixed
 *   The form displayed in the backend.
 */
function ulf_theater_refund_form_backend(array $form, array &$form_state) {
  $form['groups'] = array(
    '#type' => 'vertical_tabs',
  );

  $form['email_texts'] = array(
    '#type' => 'fieldset',
    '#title' => t('Email texts'),
    '#group' => 'groups',
    '#collapsible' => FALSE,
    '#collapsed' => 0,
  );

  $form['email_texts']['tr_notify_admin_email'] = array(
    '#type' => 'text_format',
    '#title' => t('Notification to adm. function when request is sent'),
    '#default_value' => variable_get('tr_notify_admin_email', array('value' => '', 'format' => NULL))['value'],
    '#format' => 'editor',
    '#weight' => 0,
  );

  $form['email_texts']['tr_confirmation_email'] = array(
    '#type' => 'text_format',
    '#title' => t('Copy of confirmation for user'),
    '#default_value' => variable_get('tr_confirmation_email', array('value' => '', 'format' => NULL))['value'],
    '#format' => 'editor',
    '#weight' => 1,
  );

  $form['email_texts']['tr_request_accepted_email'] = array(
    '#type' => 'text_format',
    '#title' => t('Request accepted'),
    '#default_value' => variable_get('tr_request_accepted_email', array('value' => '', 'format' => NULL))['value'],
    '#format' => 'editor',
    '#weight' => 2,
  );

  $form['email_texts']['tr_request_refused_email'] = array(
    '#type' => 'text_format',
    '#title' => t('Request refused'),
    '#default_value' => variable_get('tr_request_refused_email', array('value' => '', 'format' => NULL))['value'],
    '#format' => 'editor',
    '#weight' => 3,
  );

  $form['frontend_texts'] = array(
    '#type' => 'fieldset',
    '#title' => t('Frontend texts'),
    '#group' => 'groups',
    '#collapsible' => FALSE,
    '#collapsed' => 0,
  );

  $form['frontend_texts']['tr_title'] = array(
    '#type' => 'textfield',
    '#title' => t('Title for the form'),
    '#default_value' => variable_get('tr_title'),
    '#description' => t('Sit the title for the form page'),
    '#weight' => 0,
    '#size' => 30,
  );

  $form['frontend_texts']['tr_intro'] = array(
    '#type' => 'text_format',
    '#title' => t('Intro text'),
    '#default_value' => variable_get('tr_intro', array('value' => '', 'format' => NULL))['value'],
    '#format' => 'editor',
    '#weight' => 0,
  );

  $form['frontend_texts']['tr_cancellation'] = array(
    '#type' => 'text_format',
    '#title' => t('Cancellation text'),
    '#default_value' => variable_get('tr_cancellation', array('value' => '', 'format' => NULL))['value'],
    '#format' => 'editor',
    '#weight' => 0,
  );

  $form['frontend_texts']['tr_gdpr'] = array(
    '#type' => 'text_format',
    '#title' => t('GDPR text'),
    '#default_value' => variable_get('tr_gdpr', array('value' => '', 'format' => NULL))['value'],
    '#format' => 'editor',
    '#weight' => 0,
  );

  $form['frontend_texts']['tr_receipt'] = array(
    '#type' => 'text_format',
    '#title' => t('Receipt text'),
    '#default_value' => variable_get('tr_receipt', array('value' => '', 'format' => NULL))['value'],
    '#format' => 'editor',
    '#weight' => 0,
  );

  $form['settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('Other settings'),
    '#group' => 'groups',
    '#collapsible' => FALSE,
    '#collapsed' => 0,
  );

  $form['settings']['tr_admin_email'] = array(
    '#type' => 'textfield',
    '#title' => t('Email for Ulf administration'),
    '#default_value' => variable_get('tr_admin_email'),
    '#description' => t('Admin emails related to financing applications will be sent here. This must be an email address within the site domain. I.e info@ulfiaarhus.dk'),
    '#weight' => 1,
    '#size' => 30,
  );

  $form['settings']['dates'] = array(
    '#type' => 'fieldset',
    '#title' => t('Arrangement period'),
    '#description' => t('Set the date range of the arrangement date field in frontend'),
    '#weight' => 2,
  );

  $form['settings']['dates']['tr_from'] = array(
    '#type' => 'date_popup',
    '#title' => t('From'),
    '#default_value' => variable_get('tr_from'),
    '#date_type' => DATE_DATETIME,
    '#date_timezone' => date_default_timezone(),
    '#date_format' => 'd-m-Y',
    '#date_increment' => 1,
    '#date_year_range' => '-3:+3',
  );

  $form['settings']['dates']['tr_to'] = array(
    '#type' => 'date_popup',
    '#title' => t('To'),
    '#default_value' => variable_get('tr_to'),
    '#date_type' => DATE_DATETIME,
    '#date_timezone' => date_default_timezone(),
    '#date_format' => 'd-m-Y',
    '#date_increment' => 1,
    '#date_year_range' => '-3:+3',
  );

  return system_settings_form($form);
}

function ulf_theater_refund_teachers_overview() {
  $params = drupal_get_query_parameters(  );
  $year = $params['year'] ?? date('Y');

  $query = db_select('users', 'u');
  $query->fields('u', array('uid', 'name'));
  $query->innerJoin('users_roles', 'r', 'r.uid = u.uid');
  $query->innerJoin('field_data_field_profile_name', 'n', 'n.entity_id = u.uid');
  $query->leftJoin('field_data_field_allocated_budget', 'a', 'a.entity_id = u.uid');
  $query->leftJoin('field_data_field_budget', 'b', 'a.field_allocated_budget_value = b.entity_id && a.field_allocated_budget_revision_id = b.revision_id');
  $query->leftJoin('field_data_field_year', 'y', 'a.field_allocated_budget_value = y.entity_id && a.field_allocated_budget_revision_id = y.revision_id');
  $query->fields('n', array('field_profile_name_value'));

  $query->condition('r.rid', '31');
  $query->groupBy('u.uid');
  if (!empty($year)) {
    $query->where("DATE_FORMAT(y.field_year_value, '%Y') = :year", [':year' => $year]);
  }
  $query->addExpression('SUM(field_budget_value)', 'budget');
  $query->addExpression("DATE_FORMAT(y.field_year_value, '%Y')", 'year');
  $query->orderBy('u.name');

  $result = $query->execute();

  $headers = [
    'Name',
    'Allocated budget',
    'Spent budget',
    'Remaining budget',
    'Additional allocation',
    'Actions',
  ];

  $rows = [];
  foreach($result as $user) {
    $spent_budget = _tr_get_spent_budget($user->uid, $user->year);
    $remaining_budget = $user->budget - $spent_budget;

    $rows[] = [
      l($user->field_profile_name_value, '/admin/config/system/theater_refund/user/'. $user->uid, ['query' => ['field_tr_date_value_3' => ['value' => ['year' => $user->year]]],'field_tr_status_value' => ['accepted']]),
      $user->budget,
      $spent_budget,
      $remaining_budget < 0 ? 0 : $remaining_budget,
      $remaining_budget <= 0 ? $spent_budget - $user->budget: 0,
      l(t('Edit'), 'user/' . $user->uid . '/edit', ['query' => [drupal_get_destination()]])
    ];
  }

  $form = drupal_get_form('ulf_theater_refund_filter_form') ;
  return drupal_render($form) . theme_table([
    'header' => $headers,
    'rows' => $rows,
    'attributes' => [],
    'caption' => NULL,
    'colgroups' => NULL,
    'sticky' => FALSE,
    'empty' => NULL,
  ]);
}

function ulf_theater_refund_filter_form($form, &$form_state) {
  $params = drupal_get_query_parameters();

  $current_year = date('Y');

  $range = range($current_year - 3, $current_year + 3);
  $years = array_combine($range, $range);

  $form['#method'] = 'get';

  $form['year'] = array(
    '#type' => 'select',
    '#options' => $years,
    '#default_value' => $params['year'] ?? $current_year,
  );

  $form['submit_button'] = array(
    '#type' => 'submit',
    '#value' => t('Filter'),
  );

  return $form;
}
