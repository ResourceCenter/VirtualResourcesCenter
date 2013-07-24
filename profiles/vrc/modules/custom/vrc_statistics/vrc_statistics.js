/**
 * send click information
 */
(function($) {
	$(document).ready(function() {
		$('a[href^=http]').click(function(event) {
			event.preventDefault();

			var url = $(this).attr('href');
			$.post(
				Drupal.settings.basePath + 'vrc_statistics/ajax',
				{src_url: location.href, dst_url: url},
				function() {
					location = url;
				}
			);
		});
	});
})(jQuery);

