<?php

/**
 * @file
 * Holds alterations for forms related to ulf_theater_refund module.
 */

/**
 * Implements hook_form_FORMID_alter().
 */
function ulf_theater_refund_form_user_profile_form_alter(&$form, $form_state) {
  // If on a 'teaterkontaktlærer' profile.
  if (in_array('teaterkontakt', $form['#user']->roles)) {
    $form['picture']['#access'] = FALSE;
    // Hide all fields
    foreach ($form as $key => $value) {
      if (strpos($key, 'field_') !== FALSE) {
        $form[$key]['#access'] = FALSE;
      }
    }

    // But show name.
    $form['field_profile_name']['#access'] = TRUE;
    $form['field_allocated_budget']['#access'] = TRUE;
    $form['#validate'][] = '_tr_user_profile_form_validate';
  }
}

/**
 * Implements hook_form_FORMID_alter().
 */
function ulf_theater_refund_form_theater_refund_entityform_edit_form_alter(&$form, $form_state) {
  global $user;
  drupal_set_title(variable_get('tr_title'));

  $form['field_tr_follow_up_mail_sent']['#access'] = FALSE;

  $form['#logged_in_user'] = $user;
  // Set layout of page.
  $intro_text = variable_get(
    'tr_intro', [
    'value' => '',
    'format' => NULL,
  ]
  )['value'];
  $form['#prefix']
    = '<div class="tr-form"><div class="user-message--wrapper"><div class="user-message">'
    . $intro_text . '</div></div>';
  $form['#suffix'] = '</div>';

  // Add js and css to form.
  $form['#attached']['css'][]
    = drupal_get_path('module', 'ulf_theater_refund') . '/css/styling.css';
  $form['#attached']['library'] = [
    ['system', 'ui.datepicker'],
  ];

  // Hide editorial fields for non editors.
  if (!in_array('editor', $user->roles)) {
    $form['field_tr_status']['#access'] = FALSE;
    $form['field_tr_granted_amount']['#access'] = FALSE;
    $form['field_tr_remarks']['#access'] = FALSE;
    $form['field_tr_send_mail']['#access'] = FALSE;
  }
  // Always hide mails sent field. Set in code, and only used for display.
  $form['field_tr_mails_sent']['#access'] = FALSE;
  $form['field_tr_latest_editor']['#access'] = FALSE;


  if (!empty($form['field_tr_requested_amount'][LANGUAGE_NONE][0]['value']['#default_value']) && user_access('administer ulf theater refund settings', $user)) {
    $form['field_tr_granted_amount'][LANGUAGE_NONE]['0']['#suffix'] = t('Requested amount ex. vat: <strong>!amount</strong>', ['!amount' => number_format(((int) $form['field_tr_requested_amount'][LANGUAGE_NONE][0]['value']['#default_value'] * 0.8), 2, ',', '.')]);
  }

  // Auto fill send mail checkbox when editing an application.
  if ($form_state['entityform_form_mode'] == 'edit') {
    $form['field_tr_send_mail'][LANGUAGE_NONE]['#default_value'] = 1;
  }

  // Hide format options from description field.
  $form['field_tr_remarks']['#after_build'][] = '_tr_after';

  // Fill input fields for school users.
  if (in_array('teaterkontakt', $user->roles)) {
    // Add user email if user is logged in.
    $form['field_tr_mail'][LANGUAGE_NONE]['0']['value']['#default_value'] = $user->mail;
    $form['field_tr_school'][LANGUAGE_NONE]['#default_value'][0] = $user->uid;
  }

  $entity = $form_state['entityform'];

  if (property_exists($entity, 'is_new') && $entity->is_new == TRUE) {
    $status = 'new';
  }
  else {
    $status = $entity->field_tr_status[LANGUAGE_NONE][0]['value'];
    array_unshift($form['actions']['save']['#submit'], '_tr_request_form_submit_handle_status_change');
  }


  if (in_array('editor', $user->roles)) {
    //felter skjules aldrig for redaktører
    unset($form['actions']['captcha']);

    // Show an confirmation popup of the user is an editor
    $requested_amount = $form['field_tr_requested_amount'][LANGUAGE_NONE][0]['value']['#default_value'];
    $date = date('Y', $form['field_tr_date'][LANGUAGE_NONE][0]['#default_value']['value']);
    $form['actions']['save']['#attributes'] = array('onclick' => 'if(jQuery("#edit-field-tr-status select").val() == "accepted" && !confirm("Teaterkontaktlærer har '. _tr_get_remaining_budget($entity->uid, $date, $entity->entityform_id ) .' kr. i restbudget, vil du godkende denne ansøgning på " + jQuery("#edit-field-tr-granted-amount-und-0-value").val() + " kr.?")){return false;}');
  }
  else {
    if (in_array('teaterkontakt', $user->roles) && ($status == 'accepted' || $status == 'awaiting_payment')) {
      //hvis bruger har rollen "skole" og hvis ansøgningen har status "Godkendt" eller "Afventer udbetaling"
      //vises payment felter og alle andre felter deaktiveres
      $form['field_tr_conditions'][LANGUAGE_NONE]['#disabled'] = TRUE;
      $form['field_tr_course'][LANGUAGE_NONE]['#disabled'] = TRUE;
      $form['field_tr_course_not_found'][LANGUAGE_NONE]['#disabled'] = TRUE;
      $form['field_tr_date'][LANGUAGE_NONE]['#disabled'] = TRUE;
      $form['field_tr_gdpr'][LANGUAGE_NONE]['#disabled'] = TRUE;
      $form['field_tr_grade'][LANGUAGE_NONE]['#disabled'] = TRUE;
      $form['field_tr_mail'][LANGUAGE_NONE]['#disabled'] = TRUE;
      $form['field_tr_name'][LANGUAGE_NONE]['#disabled'] = TRUE;
      $form['field_tr_new_course_description'][LANGUAGE_NONE]['#disabled']
        = TRUE;
      $form['field_tr_new_course_name'][LANGUAGE_NONE]['#disabled'] = TRUE;
      $form['field_tr_phone'][LANGUAGE_NONE]['#disabled'] = TRUE;
      $form['field_tr_provider'][LANGUAGE_NONE]['#disabled'] = TRUE;
      $form['field_tr_requested_amount'][LANGUAGE_NONE]['#disabled'] = TRUE;
      $form['field_tr_school'][LANGUAGE_NONE]['#disabled'] = TRUE;
      $form['field_tr_subject'][LANGUAGE_NONE]['#disabled'] = TRUE;

      $form['field_tr_spent_amount'][LANGUAGE_NONE][0]['value']['#required']
        = TRUE;
      $form['field_tr_attachment'][LANGUAGE_NONE][0]['#required'] = TRUE;
      $form['field_tr_payment_date']['#access'] = FALSE;

      $form['field_tr_granted_amount']['#access'] = TRUE;
      $form['field_tr_granted_amount'][LANGUAGE_NONE]['#disabled'] = TRUE;
      $form['#group_children']['field_tr_granted_amount'] = 'group_tr_payment';

      array_unshift($form['actions']['save']['#submit'], '_tr_request_form_submit_payment_details');
      unset($form['actions']['captcha']);
    }
    else {
      //ellers skjules payment felter
      $form['field_tr_spent_amount']['#access'] = FALSE;
      $form['field_tr_attachment']['#access'] = FALSE;
      $form['field_tr_payment_date']['#access'] = FALSE;
    }
  }


  $form['#attached']['js'] = [
    drupal_get_path('module', 'ulf_theater_refund') . '/js/change-course-value.js',
    drupal_get_path('module', 'ulf_theater_refund') . '/js/calendar-popup.js',
    drupal_get_path('module', 'ulf_theater_refund') . '/js/change-subject.js',
    [
      'type' => 'setting',
      'data' => [
        'fcr' => [
          'from' => explode('-', variable_get('tr_from')),
          'to' => explode('-', variable_get('tr_to')),
          'subjects' => _tr_get_subjects(),
          'create_mode' => $form_state['entityform_form_mode'] == 'submit' ? 1
            : 0,
        ],
      ],
    ],
  ];

  // Auto fill send mail checkbox when editing an application.
  if ($form_state['entityform_form_mode'] == 'edit') {
    $form['field_tr_send_mail'][LANGUAGE_NONE]['#default_value'] = 1;
  }


  // Add ajax to provider field.
  $form['field_tr_provider'][LANGUAGE_NONE]['#ajax'] = [
    'event' => 'change',
    'callback' => '_tr_change_course_dropdown',
    'wrapper' => 'course-dropdown-wrapper',
  ];

  // Add ajax to course field.
  $form['field_tr_course'][LANGUAGE_NONE]['#ajax'] = [
    'event' => 'change',
    'callback' => '_tr_show_price_info',
    'wrapper' => 'course-price-wrapper',
  ];

  // Add ID wrapper to course dropdown for ajax use.
  $form['field_tr_course']['#prefix'] = '<div id="course-dropdown-wrapper">';
  $form['field_tr_course']['#suffix'] = '</div>';

  // Add ID wrapper to price dropdown for ajax use.
  $form['field_tr_requested_amount']['#prefix']
    = '<div id="course-price-wrapper">';
  $form['field_tr_requested_amount']['#suffix'] = '</div>';

  if ($form_state['entityform_form_mode'] == 'submit') {
    // Add no select options on create mode.
    $form['field_tr_provider_name'][LANGUAGE_NONE]['#options']['_none'] = t('- Select a theater -');

    $form['field_tr_subject'][LANGUAGE_NONE]['#options']['_none'] = t('- Select a subject -');
    $form['field_tr_school'][LANGUAGE_NONE]['#options']['_none'] = t('- Select a school -');
  }

  // Add custom validation handler.
  $form['#validate'][] = '_tr_request_form_validate';

  // Get price info if course is selected.
  if (isset($form_state['values']['field_tr_course'][LANGUAGE_NONE]['0']['target_id'])) {
    $price_info = _tr_get_course_price_info($form_state['values']['field_tr_course'][LANGUAGE_NONE]['0']['target_id']);
    $form['field_tr_requested_amount']['#prefix'] = '<div id="course-price-wrapper">' . $price_info;
  }

  // Set GDPR and Cancellation texts.
  $form['field_tr_conditions']['#prefix']
    = variable_get(
    'tr_cancellation', [
    'value' => '',
    'format' => NULL,
  ]
  )['value'];
  $form['field_tr_gdpr']['#prefix'] = variable_get(
    'tr_gdpr', [
    'value' => '',
    'format' => NULL,
  ]
  )['value'];


  if ($form_state['entityform_form_mode'] == 'submit' || $form_state['entityform_form_mode'] == 'edit') {

    $actions = $form['actions']['submit']['#submit'] ?? [];

    if(isset($form['actions']['save'])) {
      $actions = $form['actions']['save']['#submit'] ?? [];
    }

    if (!empty($actions)) {
      array_unshift($actions, '_tr_request_form_submit');
    }
  }

  if (isset($_GET['course']) && is_numeric($_GET['course'])) {
    $course = node_load($_GET['course']);
    if ($course !== NULL) {
      $form['field_tr_provider'][LANGUAGE_NONE]['#default_value'] = $course->uid;
      $form['field_tr_course'][LANGUAGE_NONE]['#default_value'] = $course->nid;
    }
  }

}

/**
 * Implements hook_form_FORMID_alter().
 */
function ulf_theater_refund_form_views_exposed_form_alter(&$form, $form_state) {
  if ($form['#id'] == 'views-exposed-form-ulf-theater-refunds-theater-refunds-table' ||
    $form['#id'] == 'views-exposed-form-ulf-theater-refunds-theater-refunds-user') {
    $form['#attached']['css'][] = drupal_get_path('module', 'ulf_theater_refund') . '/css/styling.css';
  }
}


/**
 * Change the course dropdown.
 *
 * @param $form
 * @param $form_state
 *
 * @return mixed
 */
function _tr_change_course_dropdown($form, $form_state) {
  return $form['field_tr_course'];
}

/**
 * Show price information.
 *
 * @param $form
 * @param $form_state
 *
 * @return mixed
 */
function _tr_show_price_info($form, $form_state) {
  return $form['field_tr_requested_amount'];
}

/**
 * Get info about course prices.
 *
 * @param $nid
 *
 * @return string
 */
function _tr_get_course_price_info($nid) {
  // If _none is selected.
  if (!is_numeric($nid)) {
    return '';
  }

  // Get node values.
  $wrapper = entity_metadata_wrapper('node', $nid);
  $price_description = $wrapper->field_price_description->value();
  $price_ref = $wrapper->field_collection_price->value();
  $free = $wrapper->field_free->value();

  // Get allowed values list for units and vat.
  $field_unit_info = list_allowed_values(field_info_field('field_unit_price'));
  $field_vat_info = list_allowed_values(field_info_field('field_moms'));

  $text = '';

  // Start wrapping tag.
  if (!empty($price_description) || !empty($price_ref) || $free) {
    $text .= '<div class="price-info">';
  }
  else {
    $text .= '<div>';
  }

  // Add header
  $text .= '<strong>' . t('Price') . '</strong>';

  // Add free notification.
  if ($free) {
    $text .= '<div>' . t('This course is free.') . '</div>';
  }

  // Add price lines.
  if (!empty($price_ref)) {
    $text .= '<ul class="price-list">';

    foreach ($price_ref as $price_line) {
      $text .= '<li>';
      if (!empty($price_line->field_price)) {
        $text .= '<span>'
          . str_replace('.', ',', $price_line->field_price[LANGUAGE_NONE]['0']['value'])
          . '</span>';
      }
      if (!empty($price_line->field_unit_price)) {
        $text .= '<span>'
          . $field_unit_info[$price_line->field_unit_price[LANGUAGE_NONE]['0']['value']]
          . '</span>';
      }
      if (!empty($price_line->field_moms)) {
        $text .= '<span>('
          . $field_vat_info[$price_line->field_moms[LANGUAGE_NONE]['0']['value']]
          . ')</span>';
      }
      $text .= '</li>';
    }

    $text .= '</ul>';
  }

  // Add price description.
  if (!empty($price_description['safe_value'])) {
    $text .= $price_description['safe_value'];
  }

  // Close wrapping tag.
  $text .= '<div><a target="_blank" href="/node/' . $nid . '">' . t('Read more')
    . '</a></div>';
  $text .= '</div>';

  // Add subject selected information as well.
  $subject_ids = [];
  $subjects = $wrapper->field_subject->value();
  foreach ($subjects as $subject) {
    $subject_ids[] = $subject->tid;
  }
  $text .= '<div class="data-selected-subject" data-course-subject="'
    . implode(':', $subject_ids) . '"></div>';

  return $text;
}

/**
 * Custom validation to handle form states required fields.
 *
 * @param $element
 * @param $form_state
 */
function _tr_request_form_validate($element, $form_state) {
  if ($form_state['triggering_element']['#id'] == 'edit-submit'
    || $form_state['triggering_element']['#id'] == 'edit-save'
  ) {
    $granted_amount = $form_state['values']['field_tr_granted_amount'][LANGUAGE_NONE][0]['value']
      ??
      $element['#entity']->field_tr_granted_amount[LANGUAGE_NONE][0]['value'];
    if (!empty($form_state['values']['field_tr_spent_amount'][LANGUAGE_NONE][0]['value'])
      && $granted_amount
      < $form_state['values']['field_tr_spent_amount'][LANGUAGE_NONE][0]['value']
    ) {
      form_set_error(
        'field_tr_spent_amount', t(
        '%name: the value may be no greater than %max.', [
        '%name' => $element['field_tr_spent_amount'][LANGUAGE_NONE]['#title'],
        '%max' => $element['field_tr_granted_amount'][LANGUAGE_NONE]['#title'],
      ]
      )
      );
    }

    // Validate on no acceptance without amount.
    if (empty($form_state['values']['field_tr_granted_amount'][LANGUAGE_NONE][0]['value'])
      && $form_state['values']['field_tr_status'][LANGUAGE_NONE][0]['value'] == 'accepted'
    ) {
      form_set_error('field_tr_granted_amount', t('The field %field is required to accept an application.', ['%field' => $element['field_tr_granted_amount'][LANGUAGE_NONE]['#title']]));
    }
  }
}

/**
 * Validate if the user has submitted multiple budgets for the same year.
 *
 * @param $form
 *   The form.
 * @param $form_state
 *   The form state.
 */
function _tr_user_profile_form_validate($form, $form_state) {
    $submitted_budget_values = $form_state['values']['field_allocated_budget'][LANGUAGE_NONE];

    $budget_years = [];
    foreach($submitted_budget_values as $budget_value) {
      $budget_year = $budget_value['field_year'][LANGUAGE_NONE][0]['value'] ?? NULL;

      if(empty($budget_year)) {
        continue;
      }

      if (in_array($budget_year, $budget_years, false)) {
        form_set_error('field_allocated_budget', t('You cannot have multiple budgets for the same year'));
        break;
      }
      $budget_years[] = $budget_year;
    }
}





/**
 * Custom submit to alter submission values.
 *
 * @param $form
 * @param $form_state
 */
function _tr_request_form_submit($form, &$form_state) {
  // Add 3 hours to date timestamp to ensure correct date (Timezones and summertime)
  // We don't care about the exact time.
  $form_state['values']['field_tr_date'][LANGUAGE_NONE][0]['value'] = $form_state['values']['field_tr_date'][LANGUAGE_NONE][0]['value'] + 10800;


}

/**
 * Custom submit to alter submission values.
 *
 * @param $form
 * @param $form_state
 */
function _tr_request_form_submit_handle_course($form, &$form_state) {
  $entity = $form['#entity'];
  if ((!property_exists($entity, 'is_new') || $entity->is_new != TRUE)
    && empty($form_state['values']['field_tr_course'][LANGUAGE_NONE][0]['target_id'])
  ) {
    form_set_value($form['field_tr_course'], $entity->field_tr_course, $form_state);
  }
}

/**
 * Custom submit to alter submission values.
 *
 * @param $form
 * @param $form_state
 */
function _tr_request_form_submit_handle_status_change($form, &$form_state) {
  if ($form['#entity']->wrapper()->field_tr_status->value()
    != 'ready_for_payment'
    && $form_state['values']['field_tr_status'][LANGUAGE_NONE][0]['value']
    == 'ready_for_payment'
  ) {
    //if status is being changed to "ready_for_payment" set payment date
    form_set_value($form['field_tr_payment_date'], [LANGUAGE_NONE => [['value' => NULL]]], $form_state);
  }
  if ($form['#entity']->wrapper()->field_tr_status->value()
    != 'payment_completed'
    && $form_state['values']['field_tr_status'][LANGUAGE_NONE][0]['value']
    == 'payment_completed'
  ) {
    //if status is being changed to "payment_completed" set payment date
    form_set_value($form['field_tr_payment_date'], [LANGUAGE_NONE => [['value' => time()]]], $form_state);
  }

}

/**
 * Custom submit to alter submission values.
 *
 * @param $form
 * @param $form_state
 */
function _tr_request_form_submit_payment_details($form, &$form_state) {
  form_set_value($form['field_tr_status'], [LANGUAGE_NONE => [['value' => 'awaiting_payment']]], $form_state);
}


/**
 * Get all middle school courses by user.
 *
 * @param $uid
 * @param $current_options
 *
 * @return mixed
 */
function _tr_get_courses($uid, $current_options) {

  if ($uid === '_none') {
    return $current_options;
  }

  // Set target group pre school and middle school.
  $term_ids = ['148'];

  // Get courses.
  $query = new EntityFieldQuery;
  $result = $query
    ->entityCondition('entity_type', 'node')
    ->propertyCondition('status', 1)
    ->propertyCondition('type', 'course')
    ->propertyCondition('uid', $uid)
    ->fieldCondition('field_target_group', 'tid', $term_ids, 'IN')
    ->execute();

  if (empty($result['node'])) {
    return ['_none' => t('Ingen kurser fundet')];
  }

  $nids = array_keys($result['node']);

  // Compare user courses to the original options.
  foreach ($current_options as $id => $title) {
    if (!empty($nids)) {
      if (!in_array($id, $nids) && $id != '_none') {
        // Remove options if not in query.
        unset($current_options[$id]);
      }
    }
  }

  return $current_options;
}

/**
 * Get all middle school courses by user.
 *
 * @return array
 */
function _tr_get_hacked_course_options($user, $target_id) {
  $options = [];
  $query = db_select('node', 'n');
  $query->condition('n.type', 'course', '=');
  if (!in_array('editor', $user->roles) && in_array('teaterkontakt', $user->roles)) {
    $query->condition('n.nid', $target_id, '=');
  }
  $query->fields('n', ['nid', 'title']);
  $result = $query->execute();
  foreach ($result as $record) {
    $options[$record->nid] = $record->title;
  }
  return $options;
}

/**
 * Remove format options from form element.
 *
 * @param $form
 *
 * @return mixed
 */
function _tr_after(&$form) {
  $form[LANGUAGE_NONE][0]['format']['guidelines']['#access'] = FALSE;
  $form[LANGUAGE_NONE][0]['format']['format']['#access'] = FALSE;
  $form[LANGUAGE_NONE][0]['format']['help']['#access'] = FALSE;
  $form[LANGUAGE_NONE][0]['format']['#theme_wrappers'] = NULL;
  return $form;
}

/**
 * Get all topics for dropdown.
 *
 * @return array
 */
function _tr_get_subjects() {
  $options = [];
  $vid = taxonomy_vocabulary_machine_name_load('topic')->vid;
  $options_source = taxonomy_get_tree($vid);
  foreach ($options_source as $item) {
    $key = $item->tid;
    $value = $item->name;
    $options[$key] = $value;
  }
  natsort($options);
  return $options;
}

/**
 * Get the allocated budget.
 *
 * @param $uid
 *   The user id
 * @param null $year
 *  The year to get the allocated budget for.
 *
 * @return mixed
 */
function _tr_get_allocated_budget($uid = NULL, $year = NULL) {
  $query = db_select('field_data_field_allocated_budget', 'a');
  $query->leftJoin('field_data_field_budget', 'b', 'a.field_allocated_budget_value = b.entity_id && a.field_allocated_budget_revision_id = b.revision_id');
  $query->leftJoin('field_data_field_year', 'y', 'a.field_allocated_budget_value = y.entity_id && a.field_allocated_budget_revision_id = y.revision_id');

  if (!empty($uid) && is_numeric($uid)) {
    $query->condition('a.entity_id', $uid);
  }

  if (!empty($year)) {
    $query->where("DATE_FORMAT(y.field_year_value, '%Y') = :year", [':year' => $year]);
  }

  $query->addExpression('SUM(field_budget_value)', 'requested_amount');
  $result = ($query->execute()->fetchCol());
  return reset($result);
}

/**
 * Get the remaining budget
 *
 * @param $uid
 *   The user id
 * @param null $year
 *  The year to get the allocated budget for.
 * @param null $request_id
 *  The application id to remove from result. Is useful if you dont want the
 *  current application to be calculated into the remaining budget.
 *
 * @return string
 */
function _tr_get_remaining_budget($uid = NULL, $year = NULL, $request_id = NULL) {
  $allocated_budget = _tr_get_allocated_budget($uid, $year);
  $spent_amount = _tr_get_spent_budget($uid, $year);

  $remaining_budget = $allocated_budget - $spent_amount;
  return number_format($remaining_budget < 0 ? 0 : $remaining_budget, 2, ',', '.');
}

/**
 * Get the spent budget.
 *
 * @param $uid
 *   The user id
 * @param null $year
 *  The year to get the allocated budget for.
 *
 * @return mixed
 */
function _tr_get_spent_budget($uid, $year) {
  $query = db_select('entityform', 'e');
  $query->leftJoin('field_data_field_tr_granted_amount', 'ga', 'e.entityform_id = ga.entity_id');
  $query->leftJoin('field_data_field_tr_provider_name', 'pn', 'e.entityform_id = pn.entity_id');
  $query->leftJoin('field_data_field_government_subsidy', 'gs', 'pn.field_tr_provider_name_tid = gs.entity_id');
  $query->leftJoin('field_data_field_tr_status', 's', 'e.entityform_id = s.entity_id');

  $query->condition('e.type', 'theater_refund');
  $query->condition('s.field_tr_status_value', ['awaiting', 'refused', 'cancelled'], 'NOT IN');

  if (!empty($uid) && is_numeric($uid)) {
    $query->condition('e.uid', $uid);
  }

  if($year) {
    $query->leftJoin('field_data_field_tr_date', 'd', 'e.entityform_id = d.entity_id');

    $start = strtotime($year . '0101');
    $end = strtotime($year . '1231T23:59:59');

    if ($start > 0 && $end > 0) {
      $query->condition('d.field_tr_date_value', $start, '>');
      $query->condition('d.field_tr_date_value', $end, '<');
    }
  }

  $query->addField('ga', 'field_tr_granted_amount_value', 'granted_amount');
  $query->addField('gs', 'field_government_subsidy_value', 'subsidy');
  $result = $query->execute()->fetchAll();

  $granted_amount = 0;
  foreach($result as $amount) {
    if ($amount->granted_amount !== NULL) {
      $multiplier = $amount->subsidy === '1' ? 2 : 1;
      $granted_amount += ($amount->granted_amount * $multiplier);
    }
  }
  return $granted_amount;
}
