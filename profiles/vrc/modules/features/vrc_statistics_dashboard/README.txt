Setting up the cron
===================

This module requires a daily cron run properly to collect various statistics
summaries, the mail drush command being used for now is the:

  drush process_daily_statistics

An new entry should be added to the crontab to do the daily data processing.
Here is an example:

  0 0 * * * * drush --root=/Users/Kurt/Projects/Drupal\ Projects/vrc.local/html --uri=http://vrc.local --quite process_daily_statistics

For more information on how to set up the cron, run `drush docs-cron`

How to test
===========
There is a module called `vsdg` and have some drush commands that can generate
some various kinds of dummy content.
