; CORE & API VERSION
; ==================
core = 7.x
api  = 2

; DRUPAL CORE
; ===========
projects[drupal][type] = core
projects[drupal][version] = 7.18
projects[drupal][patch][] = http://drupal.org/files/126197-ip-mask-default-on.patch
projects[drupal][patch][] = https://gist.github.com/raw/4274844/d64c41a32c91c9722f304fb50dd510d1a7317de4/126197-ip-mask-enable-real-vrc.patch
projects[drupal][patch][] = http://drupal.org/files/drupal-1453984-49-combined.patch
; Use vocabulary machine name for permissions
; http://drupal.org/node/995156
projects[drupal][patch][] = http://drupal.org/files/995156-31_portable_taxonomy_permissions-D7-15.patch

; MODULES
; =======

; CONTRIB MODULES
; ---------------
projects[service_links][subdir] = contrib
projects[service_links][version] = 2.1

projects[facebook_comments][subdir] = contrib
projects[facebook_comments][version] = 1.0-beta2

projects[linkchecker][subdir] = contrib
projects[linkchecker][version] = 1.0-beta1

; Wed Sep 14 18:00:21 2011 +1000
projects[admin][subdir] = contrib
projects[admin][download][type] = git
projects[admin][download][url] = http://git.drupal.org/project/admin.git
projects[admin][download][revision] = ad9aed4

projects[admin_menu][subdir] = contrib
projects[admin_menu][version] = 3.0-rc3

projects[auto_nodetitle][subdir] = contrib
projects[auto_nodetitle][version] = 1.0

projects[auto_indexer][subdir] = contrib
projects[auto_indexer][version] = 1.1

projects[backup_migrate][subdir] = contrib
projects[backup_migrate][version] = 2.4

projects[boxes][subdir] = contrib
projects[boxes][version] = 1.0

projects[chart][subdir] = contrib
projects[chart][version] = 1.1

projects[coder][subdir] = contrib
projects[coder][version] = 2.x-dev

projects[coder_tough_love][subdir] = contrib
projects[coder_tough_love][version] = 1.x-dev

projects[computed_field][subdir] = contrib
projects[computed_field][version] = 1.0-beta1

; Mon Nov 12 03:21:47 2012 +0100
projects[conditional_fields][subdir] = contrib
projects[conditional_fields][download][type] = git
projects[conditional_fields][download][url] = http://git.drupal.org/project/conditional_fields.git
projects[conditional_fields][download][revision] = cd29b00

; Tue Oct 9 15:59:04 2012 -0400
projects[context][subdir] = contrib
projects[context][download][type] = git
projects[context][download][url] = http://git.drupal.org/project/context.git
projects[context][download][revision] = 9539d09
projects[context][patch][] = http://drupal.org/files/context-array_to_string_error-1727794-9.patch

projects[ctools][subdir] = contrib
projects[ctools][version] = 1.2

; Sat Sep 29 08:01:24 2012 -0500
projects[date][subdir] = contrib
projects[date][download][type] = git
projects[date][download][url] = http://git.drupal.org/project/date.git
projects[date][download][revision] = 6f396c2

projects[decorator][subdir] = contrib
projects[decorator][version] = 1.x-dev

projects[defaultcontent][subdir] = contrib
projects[defaultcontent][version] = 1.x-dev

; Thu Nov 1 19:12:05 2012 -0400
projects[devel][subdir] = contrib
projects[devel][download][type] = git
projects[devel][download][url] = http://git.drupal.org/project/devel.git
projects[devel][download][revision] = 94881c9

projects[diff][subdir] = contrib
projects[diff][version] = 3.2

projects[disable_messages][subdir] = contrib
projects[disable_messages][version] = 1.1

projects[ds][subdir] = contrib
projects[ds][version] = 2.0

projects[entity][subdir] = contrib
projects[entity][version] = 1.0

projects[entityreference][subdir] = contrib
projects[entityreference][version] = 1.0

projects[eva][subdir] = contrib
projects[eva][version] = 1.2

projects[examples][subdir] = contrib
projects[examples][version] = 1.x-dev

projects[exclude_node_title][subdir] = contrib
projects[exclude_node_title][version] = 1.5

; Thu Sep 27 07:10:03 2012 +0200
projects[fbconnect][subdir] = contrib
projects[fbconnect][download][type] = git
projects[fbconnect][download][url] = http://git.drupal.org/project/fbconnect.git
projects[fbconnect][download][revision] = 1d5f944
projects[fbconnect][patch][] = https://gist.github.com/kurtzhong/a23b9ebc4fad67194c8a/raw/9284ad3deff0be5977713794c481e525c473c703/fbconnect_no_make_file.patch

projects[features][subdir] = contrib
projects[features][download][type] = git
projects[features][download][url] = http://git.drupal.org/project/features.git
projects[features][download][revision] = c0b054d
; http://drupal.org/node/1063204
projects[features][patch][] = http://drupal.org/files/features_static_caches-1063204-32.patch

projects[feeds][subdir] = contrib
projects[feeds][version] = 2.0-alpha7

projects[feeds_comment_processor][version] = 1.x-dev
projects[feeds_comment_processor][subdir] = contrib

projects[feeds_tamper][subdir] = contrib
projects[feeds_tamper][version] = 1.0-beta4

projects[flag][subdir] = contrib
projects[flag][version] = 2.0

projects[flag_abuse][subdir] = contrib
projects[flag_abuse][version] = 2.0-alpha1

projects[grammar_parser_lib][subdir] = contrib
projects[grammar_parser_lib][download][type] = git
projects[grammar_parser_lib][download][url] = git@github.com:kurtzhong/grammar_parser_lib.git
projects[grammar_parser_lib][download][branch] = 7.x-1.x

projects[grammar_parser_ui][subdir] = contrib
projects[grammar_parser_ui][version] = 1.x-dev

projects[highcharts][subdir] = contrib
projects[highcharts][version] = 2.x-dev

projects[homebox][subdir] = contrib
projects[homebox][version] = 2.0-beta6

projects[imce][subdir] = contrib
projects[imce][version] = 1.6

projects[imce_wysiwyg][subdir] = contrib
projects[imce_wysiwyg][version] = 1.0

projects[job_scheduler][subdir] = contrib
projects[job_scheduler][version] = 2.0-alpha3

projects[link][subdir] = contrib
projects[link][version] = 1.0

;Wed Nov 9 12:42:18 2011 -0800
projects[logintoboggan][subdir] = contrib
projects[logintoboggan][download][type] = git
projects[logintoboggan][download][url] = http://git.drupal.org/project/logintoboggan.git
projects[logintoboggan][download][revision] = df2d73c
; http://drupal.org/node/1365764
projects[logintoboggan][patch][] = http://drupal.org/files/logintoboggan-js-settings-1365764-3.patch

projects[mailhandler][subdir] = contrib
projects[mailhandler][version] = 2.5

projects[mailcomment][subdir] = contrib
projects[mailcomment][version] = 2.2

projects[message][subdir] = contrib
projects[message][version] = 1.7

; Mon Jun 11 11:32:51 2012 -0500
projects[messaging][subdir] = contrib
projects[messaging][download][type] = git
projects[messaging][download][url] = http://git.drupal.org/project/messaging.git
projects[messaging][download][revision] = 32e414b
projects[messaging][patch][] = http://drupal.org/files/messaging_1659228_fixing-conflict-with-message-module_11.patch

; Mon Jun 11 11:38:34 2012 -0500
projects[notifications][subdir] = contrib
projects[notifications][download][type] = git
projects[notifications][download][url] = http://git.drupal.org/project/notifications.git
projects[notifications][download][revision] = 4f7914d
projects[notifications][patch][] = http://drupal.org/files/notifications_tags-use_vocabulary_machine_name-1870148-2.patch

projects[node_export][subdir] = contrib
projects[node_export][version] = 3.0

projects[nodereference_count][subdir] = contrib
projects[nodereference_count][version] = 1.0

projects[nodereference_url][subdir] = contrib
projects[nodereference_url][version] = 1.12

projects[pathauto][subdir] = contrib
projects[pathauto][version] = 1.2

projects[quicktabs][subdir] = contrib
projects[quicktabs][version] = 3.4

projects[quiz][subdir] = contrib
projects[quiz][version] = 4.0-alpha11

projects[rate][subdir] = contrib
projects[rate][version] = 1.6

; Sat Feb 11 03:25:53 2012 +0100
projects[references][type] = module
projects[references][subdir] = contrib
projects[references][download][type] = git
projects[references][download][url] = http://git.drupal.org/project/references.git
projects[references][download][revision] = a75aaab

; [Search Api] - Tue Nov 6 22:35:57 2012 +0100
projects[facetapi][version] = 1.2
projects[facetapi][subdir] = contrib

; [Search Api] - Tue Nov 6 22:35:57 2012 +0100
projects[search_api][subdir] = contrib
projects[search_api][download][type] = git
projects[search_api][download][url] = http://git.drupal.org/project/search_api.git
projects[search_api][download][revision] = e03ce20
projects[search_api][patch][] = https://gist.github.com/raw/972a4c2a85e322271d14/56406cef6715e70ce497edfc25cabce44f90ec22/vrc_let_blocks_opt_out_of_facet_filtering.patch

; [Search Api Solr] - Wed Nov 7 01:23:48 2012 +0100
projects[search_api_solr][subdir] = contrib
projects[search_api_solr][download][type] = git
projects[search_api_solr][download][url] = http://git.drupal.org/project/search_api_solr.git
projects[search_api_solr][download][revision] = a829b87

; [Search Api auto-complete] - Sun Oct 28 23:48:50 2012 +0100
projects[search_api_autocomplete][subdir] = contrib
projects[search_api_autocomplete][download][type] = git
projects[search_api_autocomplete][download][url] = http://git.drupal.org/project/search_api_autocomplete.git
projects[search_api_autocomplete][download][revision] = e320907
; Issue #1278042
projects[search_api_autocomplete][patch][] = http://drupal.org/files/search_api_autocomplete-auto_submit-1278042-26.patch
; Issue #1835108
projects[search_api_autocomplete][patch][] = http://drupal.org/files/search_api_autocomplete_access_argument_instance.patch

projects[custom_search][subdir] = contrib
projects[custom_search][version] = 1.x-dev
projects[custom_search][patch][] = http://drupal.org/files/notice.patch

projects[sharedemail][subdir] = contrib
projects[sharedemail][version] = 1.x-dev

projects[strongarm][subdir] = contrib
projects[strongarm][version] = 2.0

projects[subscriptions][subdir] = contrib
projects[subscriptions][version] = 1.1

projects[taxonomy_manager][subdir] = contrib
projects[taxonomy_manager][version] = 1.0-rc1

projects[taxonomy_xml][subdir] = contrib
projects[taxonomy_xml][version] = 1.x-dev

projects[term_permissions][subdir] = contrib
projects[term_permissions][version] = 1.0-beta2

projects[token][subdir] = contrib
projects[token][version] = 1.4

projects[tokenauth][subdir] = contrib
projects[tokenauth][version] = 1.0-alpha1

; Fri Nov 2 16:55:10 2012 -0700
projects[uuid][subdir] = contrib
projects[uuid][download][type] = git
projects[uuid][download][url] = http://git.drupal.org/project/uuid.git
projects[uuid][download][revision] = 2fde46e

; Thu Jul 12 10:02:19 2012 -0400
projects[uuid_features][subdir] = contrib
projects[uuid_features][download][type] = git
projects[uuid_features][download][url] = http://git.drupal.org/project/uuid_features.git
projects[uuid_features][download][revision] = 924559b

; Tue Jun 19 07:33:31 2012 +0200
projects[userpoints][subdir] = contrib
projects[userpoints][download][type] = git
projects[userpoints][download][url] = http://git.drupal.org/project/userpoints.git
projects[userpoints][download][revision] = d07618d

; Wed Apr 11 10:40:15 2012 +0200
projects[userpoints_nc][subdir] = contrib
projects[userpoints_nc][download][type] = git
projects[userpoints_nc][download][url] = http://git.drupal.org/project/userpoints_nc.git
projects[userpoints_nc][download][revision] = 10c494f

projects[video_filter][subdir] = contrib
projects[video_filter][version] = 3.1

projects[views][subdir] = contrib
projects[views][version] = 3.5

projects[views_decorator][subdir] = contrib
projects[views_decorator][version] = 1.x-dev

projects[views_rss][subdir] = contrib
projects[views_rss][version] = 2.0-rc3

projects[views_bulk_operations][subdir] = contrib
projects[views_bulk_operations][version] = 3.0

; Tue Oct 23 23:20:02 2012 +0200
projects[votingapi][subdir] = contrib
projects[votingapi][download][type] = git
projects[votingapi][download][url] = http://git.drupal.org/project/votingapi.git
projects[votingapi][download][revision] = 6d54f05
projects[votingapi][patch][] = http://drupal.org/files/votingapi-fix_incorrect_handling_of_age_option-1932826-1.patch

projects[captcha][subdir] = contrib
projects[captcha][version] = 1.0-beta2

projects[field_permissions][subdir] = contrib
projects[field_permissions][version] = 1.0-beta2

projects[libraries][subdir] = contrib
projects[libraries][version] = 2.0

projects[term_reference_tree][subdir] = contrib
projects[term_reference_tree][version] = 1.9

projects[rules][subdir] = contrib
projects[rules][version] = 2.2

projects[underscore][subdir] = contrib
projects[underscore][version] = 1.2

projects[views_tree][subdir] = contrib
projects[views_tree][version] = 2.0

projects[wysiwyg][subdir] = contrib
projects[wysiwyg][version] = 2.2
projects[wysiwyg][patch][] = http://drupal.org/files/wysiwyg_height_per_field-507696-75.patch


; LIBRARIES
; =========

libraries[ckeditor][directory_name] = ckeditor
libraries[ckeditor][download][type] = get
libraries[ckeditor][download][url] = http://download.cksource.com/CKEditor/CKEditor/CKEditor%203.6.3/ckeditor_3.6.3.tar.gz

;libraries[arc2][directory_name] = arc
;libraries[arc2][download][type] = git
;libraries[arc2][download][url]=http://github.com/semsol/arc2.git

libraries[facebook-php-sdk][download][type] = get
libraries[facebook-php-sdk][download][url] = http://github.com/facebook/php-sdk/tarball/v3.1.1

libraries[grammar_parser][download][type] = git
libraries[grammar_parser][download][url] = http://git.drupal.org/project/grammar_parser.git
libraries[grammar_parser][download][branch] = 7.x-2.x

libraries[SolrPhpClient][download][type] = file
libraries[SolrPhpClient][download][url] = http://solr-php-client.googlecode.com/files/SolrPhpClient.r60.2011-05-04.zip

libraries[highcharts][download][type] = file
libraries[highcharts][download][url] = http://www.highcharts.com/downloads/zips/Highcharts-2.3.5.zip

; THEMES
; ======

; Tao
projects[tao][type] = theme
projects[tao][version] = 3.0-beta4

; Rubik
projects[rubik][type] = theme
projects[rubik][version] = 4.0-beta8

; AdaptiveTheme
projects[adaptivetheme][type] = theme
projects[adaptivetheme][version] = 2.3
projects[adaptivetheme][patch][] = http://drupal.org/files/adaptivetheme-rtl-1290386-7.patch

; Pixture Reloaded
projects[pixture_reloaded][type] = theme
projects[pixture_reloaded][version] = 3.0-rc1

; OM 2 HTML5
projects[om][type] = theme
projects[om][version] = 2.21

; OM Admin Theme
projects[om_admin][type] = theme
projects[om_admin][version] = 2.2


; TRANSLATIONS
; ============

; Arabic, Farsi, Burmese, Russian, Chinese, Tamil
translations[] = ar
translations[] = fa
translations[] = my
translations[] = ru
translations[] = zh-hans
translations[] = ta-lk
