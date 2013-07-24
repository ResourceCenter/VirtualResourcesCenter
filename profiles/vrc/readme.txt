[[PageOutline]]
= Virtual Resources Center Site Creation =

== Overview ==
This file provides instructions for creating a Virtual Resources Center.

== Suggested System Requirements ==
''(based on those defined at http://openpublicapp.com/)''
 * Minimum of a dual-core processor with 2GB RAM (Linux) or 4GB RAM (Windows).
   Actual hardware requirements will vary depending on the amount of content and traffic.
 * 2 GB free disk space (more is better)
 * Web Server - NginX, Apache 1.3 or Apache 2.x. Drupal can also run on Microsoft IIS.
   Apache 2.x is the most tested platform.
 * PHP – Version 5.2.x or 5.3.x
 * Database – MySQL 4.1 or 5.x, though MySQL 5.1 is strongly recommended.
 * Drush 5.4+ (get from http://drupal.org/project/drush/)
 * Git (see http://drupal.org/node/1010894 for hints on installing)
 * Installing a PHP code optimizer like APC is highly recommended, especially for production use.
 * Your memory_limit variable, in php.ini needs to be at least 128M, but 190M is recommended.
 * If you are still having problems (seeing "white screens of death" or errors during installation)
   try setting:
  * max_execution_time to around 120 and
  * realpath_cache_size to 512K, 1M or even 2M.
  * max_input_time to around 120.

