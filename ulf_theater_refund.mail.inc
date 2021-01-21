<?php
/**
 * @file
 * Code for Ulf free course request mail handling.
 */

/**
 * Add the different cases in which to send mail.
 *
 * @param EntityMetadataWrapper $wrapper
 *   The wrapper of an entity.
 * @param string $action
 *   The action related to the mail.
 */
function _tr_notify(EntityMetadataWrapper $wrapper, $action) {
  $entity_form_id = $wrapper->entityform_id->value();
  $year = date('Y', $wrapper->field_tr_date->value());
  if (empty($entity_form_id)) {
    return;
  }

  global $language;

  // Set fallback email
  $to = variable_get('site_mail');
  $params = array();
  switch ($action) {
    case 'on_submit_user':
      $params['subject'] = t('Theater reimbursement', array(), array('langcode' => $language->language)) . ' ' . $year;
      $params['body'] .= variable_get('tr_confirmation_email', array(
        'value' => '',
        'format' => NULL,
      ))['value'];
      $params['body'] .= _tr_build_mail_confirmation($wrapper);

      // Log what mail was sent.
      $wrapper->field_tr_mails_sent[] =t('Theater reimbursement', array(), array('langcode' => $language->language)) . ' ' . $year;
      $wrapper->save();
      $to = $wrapper->field_tr_mail->value();
      break;

    case 'on_submit_admin':
      $params['subject'] = t('Theater reimbursement', array(), array('langcode' => $language->language)) . ' ' . $year;
      $params['body'] .= variable_get('tr_notify_admin_email', array(
        'value' => '',
        'format' => NULL,
      ))['value'];
      $params['body'] .= _tr_build_mail_confirmation($wrapper);

      $to = variable_get('_tr_admin_email');
      break;

    case 'on_change_accepted':
      $params['subject'] = t('Grant on reimbursement', array(), array('langcode' => $language->language)) . ' ' . $year;
      $params['body'] .= variable_get('tr_request_accepted_email', array(
        'value' => '',
        'format' => NULL,
      ))['value'];
      $params['body'] .= _tr_build_mail_followup($wrapper);

      // Log what mail was sent.
      $wrapper->field_tr_mails_sent[] = t('Theater refund accepted', array(), array('langcode' => $language->language));
      $wrapper->save();
      $to = $wrapper->field_tr_mail->value();
      break;

    case 'on_change_refused':
      $params['subject'] = t('Refusal of reimbursement', array(), array('langcode' => $language->language)) . ' ' . $year;
      $params['body'] .= variable_get('tr_request_refused_email', array(
        'value' => '',
        'format' => NULL,
      ))['value'];
      $params['body'] .= _tr_build_mail_followup($wrapper);

      $wrapper->field_tr_mails_sent[] = t('Theater refund refused', array(), array('langcode' => $language->language)) . ' ' . $year;
      $wrapper->save();
      $to = $wrapper->field_tr_mail->value();
      break;
  }

  drupal_mail('ulf_theater_refund', 'tr_notification', $to, $language->language, $params, 'Børnekulturhuset <info@ulfiaarhus.dk>');
}

/**
 * Implements hook_mail().
 *
 * Alter mail.
 */
function ulf_theater_refund_mail($key, &$message, $params) {
  switch ($key) {
    case 'tr_notification':
      $message['subject'] = $params['subject'];
      $message['body'] = $params['body'];
      break;
  }
}

/**
 * @file
 *
 * Handle the sending of mails.
 */

/**
 * Create mail template.
 *
 * @param EntityMetadataWrapper $wrapper
 *   The wrapper of an entity.
 *
 * @return string
 *   The values of the submitted form grouped into a string.
 */
function _tr_build_mail_confirmation(EntityMetadataWrapper $wrapper) {

  $application = '';
  $entity_form_id = $wrapper->entityform_id->value();
  $year = date('Y', $wrapper->field_tr_date->value());
  $uid = $wrapper->uid->value();

  if (empty($entity_form_id )) {
    return $application;
  }

  global $language;
  $translation_lang = array('langcode' => $language->language);

  // School wrapper
  $school_id = $wrapper->field_tr_school->value();
  $school_wrapper = entity_metadata_wrapper('user', $school_id);

  // Provider wrapper
  $provider_id = $wrapper->field_tr_provider_name->value();
  $provider_wrapper = entity_metadata_wrapper('taxonomy_term', $provider_id);

  $application .= '<h3>';
  $application .= t('Your application', array(), $translation_lang);
  $application .= ':</h3>';

  $application .= '<strong>';
  $application .= t('Id', array(), $translation_lang);
  $application .= ':</strong> ';
  $application .= $wrapper->entityform_id->value();
  $application .= '<br/>';

  $application .= '<p>';
  $application .= '<strong>';
  $application .= t('School', array(), $translation_lang);
  $application .= ':</strong> ';
  $application .= $school_wrapper->field_profile_name->value();
  $application .= '<br/>';
  $application .= '<strong>';
  $application .= t('Grade', array(), $translation_lang);
  $application .= ':</strong> ';
  $application .= $wrapper->field_tr_grade->value();
  $application .= '<br/>';
  $application .= '<strong>';
  $application .= t('Name', array(), $translation_lang);
  $application .= ':</strong> ';
  $application .= $wrapper->field_tr_name->value();
  $application .= '<br/>';
  $application .= '<strong>';
  $application .= t('Phone', array(), $translation_lang);
  $application .= ':</strong> ';
  $application .= $wrapper->field_tr_phone->value();
  $application .= '<br/>';
  $application .= '<strong>';
  $application .= t('Email', array(), $translation_lang);
  $application .= ':</strong> ';
  $application .=  $wrapper->field_tr_mail->value();
  $application .= '</p>';

  $application .= '<p>';
  $application .= '<strong>';
  $application .= t('Theater', array(), $translation_lang);
  $application .= ':</strong> ';
  $application .= $provider_wrapper->label();
  $application .= '<br/>';
  $application .= '<strong>';
  $application .= t('Show', array(), array('langcode' => $language->language, 'context' => 'theater_refund'));
  $application .= ':</strong> ';
  $application .= $wrapper->field_tr_new_course_name->value();
  $application .= '<br/>';
  $application .= '<strong>';
  $application .= t('Quantity', array(), $translation_lang);
  $application .= ':</strong> ';
  $application .= $wrapper->field_tr_quantity->value();
  $application .= '<br/>';
  $application .= '<strong>';
  $application .= t('Requested amount', array(), $translation_lang);
  $application .= ':</strong> ';
  $application .= $wrapper->field_tr_requested_amount->value() . ' kr.';
  $application .= '<br/>';
  $application .= '<strong>';
  $application .= t('Date', array(), $translation_lang);
  $application .= ':</strong> ';
  $application .= date('d/m/Y', $wrapper->field_tr_date->value());
  $application .= '<br/>';
  $application .= '<br/>';

  $application .= '<h3>';
  $application .= t('Budget and spending for :year to date:', array(':year' => $year), $translation_lang);
  $application .= '</h3>';

  $application .= '<strong>'. t('Allocated budget', array(), $translation_lang) .'</strong>: ';
  $application .= number_format(_tr_get_allocated_budget($uid, $year), 2, ',', '.') . ' kr.';
  $application .= '<br/>';

  $application .= '<strong>'. t('Spent budget', array(), $translation_lang) .'</strong>: ';
  $application .= number_format(_tr_get_spent_budget($uid, $year), 2, ',', '.') . ' kr.';
  $application .= '<br/>';

  $application .= '<strong>'. t('Remaining budget', array(), $translation_lang) .'</strong>: ';
  $application .= number_format(_tr_get_remaining_budget($uid, $year), 2, ',', '.') . ' kr.';
  $application .= '</p>';

  return $application;
}

/**
 * Follow up mail template.
 *
 * @param EntityMetadataWrapper $wrapper
 *   The wrapper of an entity.
 *
 * @return string
 *   The values of the submitted form grouped into a string.
 */
function _tr_build_mail_followup(EntityMetadataWrapper $wrapper) {
  $application = '';
  $entity_form_id = $wrapper->entityform_id->value();
  $uid = $wrapper->uid->value();
  $year = date('Y', $wrapper->field_tr_date->value());

  if (empty($entity_form_id )) {
    return $application;
  }

  // Status values info.
  $field_status_info = list_allowed_values(field_info_field('field_tr_status'));

  global $language;
  $translation_lang = array('langcode' => $language->language);

  // School wrapper
  $school_id = $wrapper->field_tr_school->value();
  $school_wrapper = entity_metadata_wrapper('user', $school_id);

  // Provider wrapper
  $provider_id = $wrapper->field_tr_provider_name->value();
  $provider_wrapper = entity_metadata_wrapper('user', $provider_id);


  $application .= '<h3>';
  $application .= t('Your application', array(), $translation_lang);
  $application .= ':</h3>';

  $application .= '<p>';
  $application .= '<p>---</p>';
  $application .= '<strong>';
  $application .= t('Status', array(), $translation_lang);
  $application .= ':</strong> ';
  $application .=  $field_status_info[$wrapper->field_tr_status->value()];
  $application .= '<br/>';
  $application .= '<strong>';
  $application .= t('Granted amount', array(), $translation_lang);
  $application .= ':</strong> ';
  $application .= $wrapper->field_tr_granted_amount->value() . ' kr.';
  $application .= '<br/>';
  $application .= '<strong>';
  $application .= t('Remarks', array(), $translation_lang);
  $application .= ':</strong> ';
  $application .= $wrapper->field_tr_remarks->value()['value'];
  $application .= '<br/>';
  $application .= '<p>---</p>';
  $application .= '</p>';

  $application .= '<strong>';
  $application .= t('Id', array(), $translation_lang);
  $application .= ':</strong> ';
  $application .= $wrapper->entityform_id->value();
  $application .= '<br/>';

  $application .= '<p>';
  $application .= '<strong>';
  $application .= t('School', array(), $translation_lang);
  $application .= ':</strong> ';
  $application .= $school_wrapper->field_profile_name->value();
  $application .= '<br/>';
  $application .= '<strong>';
  $application .= t('Grade', array(), $translation_lang);
  $application .= ':</strong> ';
  $application .= $wrapper->field_tr_grade->value();
  $application .= '<br/>';
  $application .= '<strong>';
  $application .= t('Name', array(), $translation_lang);
  $application .= ':</strong> ';
  $application .= $wrapper->field_tr_name->value();
  $application .= '<br/>';
  $application .= '<strong>';
  $application .= t('Phone', array(), $translation_lang);
  $application .= ':</strong> ';
  $application .= $wrapper->field_tr_phone->value();
  $application .= '<br/>';
  $application .= '<strong>';
  $application .= t('Email', array(), $translation_lang);
  $application .= ':</strong> ';
  $application .=  $wrapper->field_tr_mail->value();
  $application .= '</p>';

  $application .= '<p>';
  $application .= '<strong>';
  $application .= t('Theater', array(), $translation_lang);
  $application .= ':</strong> ';
  $application .= $provider_wrapper->label();
  $application .= '<br/>';
  $application .= '<strong>';
  $application .= t('Show', array(), array('langcode' => $language->language, 'context' => 'theater_refund'));
  $application .= ':</strong> ';
  $application .= $wrapper->field_tr_new_course_name->value();
  $application .= '<br/>';
  $application .= '<strong>';
  $application .= t('Quantity', array(), $translation_lang);
  $application .= ':</strong> ';
  $application .= $wrapper->field_tr_quantity->value();
  $application .= '<br/>';
  $application .= '<strong>';
  $application .= t('Requested amount', array(), $translation_lang);
  $application .= ':</strong> ';
  $application .= $wrapper->field_tr_requested_amount->value() . ' kr.';
  $application .= '<br/>';
  $application .= '<strong>';
  $application .= t('Date', array(), $translation_lang);
  $application .= ':</strong> ';
  $application .= date('d/m/Y', $wrapper->field_tr_date->value());
  $application .= '<br/>';
  $application .= '<br/>';

  $application .= '<h3>';
  $application .= t('Budget and spending for :year to date:', array(':year' => $year), $translation_lang);
  $application .= '</h3>';

  $application .= '<strong>'. t('Allocated budget', array(), $translation_lang) .'</strong>: ';
  $application .= number_format(_tr_get_allocated_budget($uid, $year), 2, ',', '.') . ' kr.';
  $application .= '<br/>';

  $application .= '<strong>'. t('Spent budget', array(), $translation_lang) .'</strong>: ';
  $application .= number_format(_tr_get_spent_budget($uid, $year), 2, ',', '.') . ' kr.';
  $application .= '<br/>';

  $application .= '<strong>'. t('Remaining budget', array(), $translation_lang) .'</strong>: ';
  $application .= number_format(_tr_get_remaining_budget($uid, $year), 2, ',', '.') . ' kr.';
  $application .= '</p>';

  return $application;
}

