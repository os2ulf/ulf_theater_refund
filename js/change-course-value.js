/**
 * Add Remove course selection and price info, course not found is selected.
 **/
(function ($) {
  "use strict";
  Drupal.behaviors.theater_refund_remove_course = {
    attach: function (context, settings) {
      $('#edit-field-tr-course-not-found-und').change(function() {
        $('#edit-field-tr-course-und').val('_none');
        $('#edit-field-tr-course-und').trigger("chosen:updated");
        $('.price-info').remove();
      });
    }
  }
}(jQuery));
