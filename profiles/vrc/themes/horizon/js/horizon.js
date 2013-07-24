/**
 * Implementation of Drupal behavior.
 */
(function($) {
Drupal.behaviors.horizon = {};
Drupal.behaviors.horizon.attach = function(context) {
  // Remove the label of answer body
  var answerForm = $('#answer-node-form');
  answerForm.find('label[for^="edit-field-answer-body-und-0-value"]').remove();
};
})(jQuery);
