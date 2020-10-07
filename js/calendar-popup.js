/**
 * Add popup with range limit.
 **/
(function ($) {
  "use strict";
  Drupal.behaviors.theater_refund_form = {
    attach: function (context, settings) {
      var from = settings.tr.from;
      var to = settings.tr.to;
      $('.field-name-field-rfc-date input').datepicker({
        minDate: new Date(from[0], parseInt(from[1]) - 1, from[2]),
        maxDate: new Date(to[0], parseInt(to[1]) - 1, to[2]),
        dateFormat: 'dd/mm/yy'
      });
    }
  }
}(jQuery));
