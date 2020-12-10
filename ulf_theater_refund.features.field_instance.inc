<?php

/**
 * @file
 * ulf_theater_refund.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function ulf_theater_refund_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'entityform-theater_refund-field_tr_attachment'.
  $field_instances['entityform-theater_refund-field_tr_attachment'] = array(
    'bundle' => 'theater_refund',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'file',
        'settings' => array(),
        'type' => 'file_default',
        'weight' => 26,
      ),
    ),
    'entity_type' => 'entityform',
    'field_name' => 'field_tr_attachment',
    'label' => 'Bilag',
    'required' => 0,
    'settings' => array(
      'description_field' => 0,
      'file_directory' => 'bilag',
      'file_extensions' => 'pdf png jpg jpeg',
      'max_filesize' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'file',
      'settings' => array(
        'insert' => 0,
        'insert_absolute' => 0,
        'insert_class' => '',
        'insert_default' => 'icon_link',
        'insert_styles' => array(
          'auto' => 0,
          'icon_link' => 'icon_link',
          'image' => 0,
          'image_facebook_open_graph' => 0,
          'image_large' => 0,
          'image_logo' => 0,
          'image_medium' => 0,
          'image_node_display' => 0,
          'image_teaser_display' => 0,
          'image_thumbnail' => 0,
          'link' => 0,
        ),
        'insert_width' => '',
        'progress_indicator' => 'throbber',
      ),
      'type' => 'file_generic',
      'weight' => 26,
    ),
  );

  // Exported field_instance: 'entityform-theater_refund-field_tr_conditions'.
  $field_instances['entityform-theater_refund-field_tr_conditions'] = array(
    'bundle' => 'theater_refund',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 12,
      ),
    ),
    'entity_type' => 'entityform',
    'field_name' => 'field_tr_conditions',
    'label' => 'Ja, det er forstået',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'display_label' => 1,
      ),
      'type' => 'options_onoff',
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'entityform-theater_refund-field_tr_date'.
  $field_instances['entityform-theater_refund-field_tr_date'] = array(
    'bundle' => 'theater_refund',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'date',
        'settings' => array(
          'custom_date_format' => '',
          'format_type' => 'short',
          'fromto' => 'both',
          'multiple_from' => '',
          'multiple_number' => '',
          'multiple_to' => '',
          'show_remaining_days' => 0,
        ),
        'type' => 'date_default',
        'weight' => 17,
      ),
    ),
    'entity_type' => 'entityform',
    'field_name' => 'field_tr_date',
    'label' => 'Afviklingsdato',
    'required' => 1,
    'settings' => array(
      'default_value' => 'blank',
      'default_value2' => 'same',
      'default_value_code' => '',
      'default_value_code2' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'date',
      'settings' => array(
        'increment' => 15,
        'input_format' => 'd/m/Y - H:i:s',
        'input_format_custom' => '',
        'label_position' => 'above',
        'no_fieldset' => 1,
        'text_parts' => array(),
        'year_range' => '-3:+3',
      ),
      'type' => 'date_popup',
      'weight' => 42,
    ),
  );

  // Exported field_instance:
  // 'entityform-theater_refund-field_tr_follow_up_mail_sent'.
  $field_instances['entityform-theater_refund-field_tr_follow_up_mail_sent'] = array(
    'bundle' => 'theater_refund',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'date',
        'settings' => array(
          'custom_date_format' => '',
          'format_type' => 'long',
          'fromto' => 'both',
          'multiple_from' => '',
          'multiple_number' => '',
          'multiple_to' => '',
          'show_remaining_days' => FALSE,
        ),
        'type' => 'date_default',
        'weight' => 25,
      ),
    ),
    'entity_type' => 'entityform',
    'field_name' => 'field_tr_follow_up_mail_sent',
    'label' => 'Opfølgningsmail sendt',
    'required' => FALSE,
    'settings' => array(
      'default_value' => 'now',
      'default_value2' => 'same',
      'default_value_code' => '',
      'default_value_code2' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'module' => 'date',
      'settings' => array(
        'increment' => 1,
        'input_format' => 'd/m/Y - H:i:s',
        'input_format_custom' => '',
        'label_position' => 'above',
        'text_parts' => array(),
        'year_range' => '-3:+3',
      ),
      'type' => 'date_text',
      'weight' => 37,
    ),
  );

  // Exported field_instance: 'entityform-theater_refund-field_tr_gdpr'.
  $field_instances['entityform-theater_refund-field_tr_gdpr'] = array(
    'bundle' => 'theater_refund',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 16,
      ),
    ),
    'entity_type' => 'entityform',
    'field_name' => 'field_tr_gdpr',
    'label' => 'Jeg giver samtykke',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'display_label' => 1,
      ),
      'type' => 'options_onoff',
      'weight' => 15,
    ),
  );

  // Exported field_instance: 'entityform-theater_refund-field_tr_grade'.
  $field_instances['entityform-theater_refund-field_tr_grade'] = array(
    'bundle' => 'theater_refund',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Skriv hvilken klasse, der skal se forestillingen.',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 5,
      ),
    ),
    'entity_type' => 'entityform',
    'field_name' => 'field_tr_grade',
    'label' => 'Klasse',
    'required' => 1,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'maxlength_js' => 0,
        'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 18,
    ),
  );

  // Exported field_instance:
  // 'entityform-theater_refund-field_tr_granted_amount'.
  $field_instances['entityform-theater_refund-field_tr_granted_amount'] = array(
    'bundle' => 'theater_refund',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => ',',
          'prefix_suffix' => 1,
          'scale' => 2,
          'thousand_separator' => '',
        ),
        'type' => 'number_decimal',
        'weight' => 14,
      ),
    ),
    'entity_type' => 'entityform',
    'field_name' => 'field_tr_granted_amount',
    'label' => 'Bevilget beløb',
    'required' => 0,
    'settings' => array(
      'max' => '',
      'min' => '',
      'prefix' => '',
      'suffix' => ' kr.',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 8,
    ),
  );

  // Exported field_instance:
  // 'entityform-theater_refund-field_tr_latest_editor'.
  $field_instances['entityform-theater_refund-field_tr_latest_editor'] = array(
    'bundle' => 'theater_refund',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'bypass_access' => FALSE,
          'link' => FALSE,
        ),
        'type' => 'entityreference_label',
        'weight' => 24,
      ),
    ),
    'entity_type' => 'entityform',
    'field_name' => 'field_tr_latest_editor',
    'label' => 'Senest ændret af',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'entityreference',
      'settings' => array(
        'match_operator' => 'CONTAINS',
        'path' => '',
        'size' => 60,
      ),
      'type' => 'entityreference_autocomplete',
      'weight' => 12,
    ),
  );

  // Exported field_instance: 'entityform-theater_refund-field_tr_mail'.
  $field_instances['entityform-theater_refund-field_tr_mail'] = array(
    'bundle' => 'theater_refund',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 4,
      ),
    ),
    'entity_type' => 'entityform',
    'field_name' => 'field_tr_mail',
    'label' => 'Mailadresse',
    'required' => 1,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'html5_tools',
      'settings' => array(),
      'type' => 'emailwidget',
      'weight' => 22,
    ),
  );

  // Exported field_instance: 'entityform-theater_refund-field_tr_mails_sent'.
  $field_instances['entityform-theater_refund-field_tr_mails_sent'] = array(
    'bundle' => 'theater_refund',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 23,
      ),
    ),
    'entity_type' => 'entityform',
    'field_name' => 'field_tr_mails_sent',
    'label' => 'Sendte mails',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'maxlength_js' => 0,
        'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 11,
    ),
  );

  // Exported field_instance: 'entityform-theater_refund-field_tr_name'.
  $field_instances['entityform-theater_refund-field_tr_name'] = array(
    'bundle' => 'theater_refund',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'entityform',
    'field_name' => 'field_tr_name',
    'label' => 'Navn',
    'required' => 1,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'maxlength_js' => 0,
        'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 20,
    ),
  );

  // Exported field_instance:
  // 'entityform-theater_refund-field_tr_new_course_name'.
  $field_instances['entityform-theater_refund-field_tr_new_course_name'] = array(
    'bundle' => 'theater_refund',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 19,
      ),
    ),
    'entity_type' => 'entityform',
    'field_name' => 'field_tr_new_course_name',
    'label' => 'Forestilling',
    'required' => 1,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'maxlength_js' => 0,
        'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 39,
    ),
  );

  // Exported field_instance: 'entityform-theater_refund-field_tr_payment_date'.
  $field_instances['entityform-theater_refund-field_tr_payment_date'] = array(
    'bundle' => 'theater_refund',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'date',
        'settings' => array(
          'custom_date_format' => '',
          'format_type' => 'long',
          'fromto' => 'both',
          'multiple_from' => '',
          'multiple_number' => '',
          'multiple_to' => '',
          'show_remaining_days' => FALSE,
        ),
        'type' => 'date_default',
        'weight' => 25,
      ),
    ),
    'entity_type' => 'entityform',
    'field_name' => 'field_tr_payment_date',
    'label' => 'Udbetalingsdato',
    'required' => 0,
    'settings' => array(
      'default_value' => 'blank',
      'default_value2' => 'same',
      'default_value_code' => '',
      'default_value_code2' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'date',
      'settings' => array(
        'increment' => 15,
        'input_format' => 'd/m/Y - H:i:s',
        'input_format_custom' => '',
        'label_position' => 'above',
        'no_fieldset' => 1,
        'text_parts' => array(),
        'year_range' => '-3:+3',
      ),
      'type' => 'date_popup',
      'weight' => 27,
    ),
  );

  // Exported field_instance: 'entityform-theater_refund-field_tr_phone'.
  $field_instances['entityform-theater_refund-field_tr_phone'] = array(
    'bundle' => 'theater_refund',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 3,
      ),
    ),
    'entity_type' => 'entityform',
    'field_name' => 'field_tr_phone',
    'label' => 'Telefonnr',
    'required' => 1,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'html5_tools',
      'settings' => array(),
      'type' => 'telwidget',
      'weight' => 21,
    ),
  );

  // Exported field_instance:
  // 'entityform-theater_refund-field_tr_provider_name'.
  $field_instances['entityform-theater_refund-field_tr_provider_name'] = array(
    'bundle' => 'theater_refund',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_plain',
        'weight' => 30,
      ),
    ),
    'entity_type' => 'entityform',
    'field_name' => 'field_tr_provider_name',
    'label' => 'Teater',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => '',
      ),
      'type' => 'options_select',
      'weight' => 38,
    ),
  );

  // Exported field_instance: 'entityform-theater_refund-field_tr_quantity'.
  $field_instances['entityform-theater_refund-field_tr_quantity'] = array(
    'bundle' => 'theater_refund',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Skriv antal billetter eller forestillinger.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 0,
          'thousand_separator' => '',
        ),
        'type' => 'number_integer',
        'weight' => 29,
      ),
    ),
    'entity_type' => 'entityform',
    'field_name' => 'field_tr_quantity',
    'label' => 'Antal',
    'required' => 1,
    'settings' => array(
      'max' => '',
      'min' => '',
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'html5_tools',
      'settings' => array(),
      'type' => 'numberfield',
      'weight' => 40,
    ),
  );

  // Exported field_instance: 'entityform-theater_refund-field_tr_remarks'.
  $field_instances['entityform-theater_refund-field_tr_remarks'] = array(
    'bundle' => 'theater_refund',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 15,
      ),
    ),
    'entity_type' => 'entityform',
    'field_name' => 'field_tr_remarks',
    'label' => 'Bemærkninger',
    'required' => 0,
    'settings' => array(
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'maxlength_js' => '',
        'maxlength_js_enforce' => 0,
        'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
        'maxlength_js_truncate_html' => 0,
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 9,
    ),
  );

  // Exported field_instance:
  // 'entityform-theater_refund-field_tr_requested_amount'.
  $field_instances['entityform-theater_refund-field_tr_requested_amount'] = array(
    'bundle' => 'theater_refund',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Skriv forestillingens totale pris i hele tal inkl. moms - eks. \'8000\'.',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => ',',
          'prefix_suffix' => 1,
          'scale' => 2,
          'thousand_separator' => '',
        ),
        'type' => 'number_decimal',
        'weight' => 7,
      ),
    ),
    'entity_type' => 'entityform',
    'field_name' => 'field_tr_requested_amount',
    'label' => 'Ansøgt beløb',
    'required' => 1,
    'settings' => array(
      'max' => '',
      'min' => '',
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 41,
    ),
  );

  // Exported field_instance: 'entityform-theater_refund-field_tr_school'.
  $field_instances['entityform-theater_refund-field_tr_school'] = array(
    'bundle' => 'theater_refund',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'entityreference',
        'settings' => array(
          'bypass_access' => FALSE,
          'link' => FALSE,
        ),
        'type' => 'entityreference_label',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'entityform',
    'field_name' => 'field_tr_school',
    'label' => 'Skole',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => '',
      ),
      'type' => 'options_select',
      'weight' => 17,
    ),
  );

  // Exported field_instance: 'entityform-theater_refund-field_tr_send_mail'.
  $field_instances['entityform-theater_refund-field_tr_send_mail'] = array(
    'bundle' => 'theater_refund',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => 'Send mail til brugeren om status på ansøgningen når formularen gemmes.
Mail sendes dog kun hvis status er godkendt eller afvist.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 22,
      ),
    ),
    'entity_type' => 'entityform',
    'field_name' => 'field_tr_send_mail',
    'label' => 'Send mail ved gem',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'display_label' => 1,
      ),
      'type' => 'options_onoff',
      'weight' => 10,
    ),
  );

  // Exported field_instance: 'entityform-theater_refund-field_tr_spent_amount'.
  $field_instances['entityform-theater_refund-field_tr_spent_amount'] = array(
    'bundle' => 'theater_refund',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 2,
          'thousand_separator' => '',
        ),
        'type' => 'number_decimal',
        'weight' => 27,
      ),
    ),
    'entity_type' => 'entityform',
    'field_name' => 'field_tr_spent_amount',
    'label' => 'Forbrugt beløb (eks. moms)',
    'required' => 0,
    'settings' => array(
      'max' => '',
      'min' => '',
      'prefix' => '',
      'suffix' => ' kr.',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 25,
    ),
  );

  // Exported field_instance: 'entityform-theater_refund-field_tr_status'.
  $field_instances['entityform-theater_refund-field_tr_status'] = array(
    'bundle' => 'theater_refund',
    'default_value' => array(
      0 => array(
        'value' => 'awaiting',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 13,
      ),
    ),
    'entity_type' => 'entityform',
    'field_name' => 'field_tr_status',
    'label' => 'Status',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => 0,
      ),
      'type' => 'options_select',
      'weight' => 7,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_allocated_budget-field_budget'.
  $field_instances['field_collection_item-field_allocated_budget-field_budget'] = array(
    'bundle' => 'field_allocated_budget',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_budget',
    'label' => 'Allocated budget',
    'required' => 0,
    'settings' => array(
      'max' => '',
      'min' => '',
      'prefix' => 'Kr.',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'html5_tools',
      'settings' => array(),
      'type' => 'numberfield',
      'weight' => 1,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_allocated_budget-field_year'.
  $field_instances['field_collection_item-field_allocated_budget-field_year'] = array(
    'bundle' => 'field_allocated_budget',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_year',
    'label' => 'Year',
    'required' => 0,
    'settings' => array(
      'default_value' => 'now',
      'default_value2' => 'same',
      'default_value_code' => '',
      'default_value_code2' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'date',
      'settings' => array(
        'increment' => 15,
        'input_format' => 'd/m/Y - H:i:s',
        'input_format_custom' => '',
        'label_position' => 'above',
        'no_fieldset' => 0,
        'text_parts' => array(),
        'year_range' => '-3:+3',
      ),
      'type' => 'date_select',
      'weight' => 0,
    ),
  );

  // Exported field_instance: 'taxonomy_term-teater-field_government_subsidy'.
  $field_instances['taxonomy_term-teater-field_government_subsidy'] = array(
    'bundle' => 'teater',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_government_subsidy',
    'label' => 'Statstilskud',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'display_label' => 1,
      ),
      'type' => 'options_onoff',
      'weight' => 1,
    ),
  );

  // Exported field_instance: 'user-user-field_allocated_budget'.
  $field_instances['user-user-field_allocated_budget'] = array(
    'bundle' => 'user',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'field_collection',
        'settings' => array(
          'add' => 'Tilføj',
          'delete' => 'Slet',
          'description' => TRUE,
          'edit' => 'Redigér',
          'translate' => 'Oversæt',
        ),
        'type' => 'field_collection_list',
        'weight' => 14,
      ),
    ),
    'entity_type' => 'user',
    'field_name' => 'field_allocated_budget',
    'label' => 'Tildelt budget',
    'required' => 0,
    'settings' => array(
      'user_register_form' => 0,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'field_collection',
      'settings' => array(),
      'type' => 'field_collection_embed',
      'weight' => 20,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Afviklingsdato');
  t('Allocated budget');
  t('Ansøgt beløb');
  t('Antal');
  t('Bemærkninger');
  t('Bevilget beløb');
  t('Bilag');
  t('Forbrugt beløb (eks. moms)');
  t('Forestilling');
  t('Ja, det er forstået');
  t('Jeg giver samtykke');
  t('Klasse');
  t('Mailadresse');
  t('Navn');
  t('Opfølgningsmail sendt');
  t('Send mail til brugeren om status på ansøgningen når formularen gemmes.
Mail sendes dog kun hvis status er godkendt eller afvist.');
  t('Send mail ved gem');
  t('Sendte mails');
  t('Senest ændret af');
  t('Skole');
  t('Skriv antal billetter eller forestillinger.');
  t('Skriv forestillingens totale pris i hele tal inkl. moms - eks. \'8000\'.');
  t('Skriv hvilken klasse, der skal se forestillingen.');
  t('Statstilskud');
  t('Status');
  t('Teater');
  t('Telefonnr');
  t('Tildelt budget');
  t('Udbetalingsdato');
  t('Year');

  return $field_instances;
}
