<?php

/**
 * @file
 * ulf_theater_refund.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ulf_theater_refund_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function ulf_theater_refund_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_default_entityform_type().
 */
function ulf_theater_refund_default_entityform_type() {
  $items = array();
  $items['theater_refund'] = entity_import('entityform_type', '{
    "type" : "theater_refund",
    "label" : "Ans\\u00f8g om teater refusion",
    "data" : {
      "draftable" : 0,
      "draft_redirect_path" : "",
      "draft_button_text" : "",
      "draft_save_text" : { "value" : "", "format" : "editor" },
      "submit_button_text" : "",
      "submit_confirm_msg" : "",
      "your_submissions" : "",
      "disallow_resubmit_msg" : "",
      "delete_confirm_msg" : "",
      "page_title_view" : "",
      "preview_page" : 0,
      "submission_page_title" : "Application received",
      "submission_text" : { "value" : "", "format" : "editor" },
      "submission_show_submitted" : 1,
      "submissions_view" : "default",
      "user_submissions_view" : "default",
      "form_status" : "ENTITYFORM_OPEN",
      "roles" : { "1" : "1", "2" : "2", "18" : 0, "19" : 0, "20" : 0, "21" : 0 },
      "resubmit_action" : "new",
      "redirect_path" : "",
      "instruction_pre" : { "value" : "", "format" : "editor" }
    },
    "weight" : "0",
    "paths" : {
      "submit" : {
        "source" : "eform\\/submit\\/theater-refund",
        "alias" : "ansoeg\\/teater-refusion",
        "language" : "und"
      },
      "confirm" : {
        "source" : "eform\\/theater-refund\\/confirm",
        "alias" : "ansoeg\\/teater-refusion\\/modtaget",
        "language" : "und"
      }
    }
  }');
  return $items;
}
