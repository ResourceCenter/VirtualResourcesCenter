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

== Drush Preparations ==
During site installation, drush will use standard defaults for e.g. the uid1 username,
password and email.  These defaults are easily modified via a `~/.drushrc.php file.

Also, Drush uses 'site aliases' to identify local or remote Drupal installations.

=== Set Global Drush site-install Defaults  ===
Put the following in a `~/.drushrc.php` file, editing the values to your liking.
{{{
<?php
// These are the defaults if you don't create this file
$command_specific['site-install'] = array(
  'account-name' => 'admin',               // uid1 user name
  // 'account-pass' => '8qwedijhds',       // uid1 random generated pw
  'account-mail' => 'admin@example.com',   // uid1 email address
  'site-mail'    => 'admin@example.com',   // site from email address
);
}}}

=== Create Drush Site Alias ===
The following creates a site alias '`@vrc`'...
 * with an Apache document root of `/var/www/vrc`
 * using a mysql database named 'vrc_drupal'
 * with a mysql username of 'root' and password of '7faiuvcan'
 * and addressed by the URL `http://vrc.localhost/`
If you don't have a site yet, copy this into `~/.drush/aliases.drushrc.php`
and edit it with your local values.
{{{
<?php
# Example ~/.drush/aliases.drushrc.php sets alias for a VRC site
$aliases['vrc'] = array(
  'root' => '/var/www/vrc',
  'uri' => 'http://vrc.localhost/',
  'databases' =>
  array (
    'default' =>
    array (
      'default' =>
      array (
        'database' => 'vrc_drupal',
        'username' => 'root',
        'password' => '7faiuvcan',
        'host' => 'localhost',
        'port' => '',
        'driver' => 'mysql',
        'prefix' => '',
      ),
    ),
  ),
);
}}}

== Creating a VRC Site Instance ==
The commands below can - in many cases - be simply cut-and-pasted from this README
into a command line (terminal) window.

=== Instance Creation ===
The following assumes the variable DBNAME has been set and the drush alias file installed, e.g.,
{{{
DBNAME='vrc_drupal'
DOCROOT=`drush dd @vrc`
}}}

''If you already have an instance running, see Instance Removal (below).''
{{{
# Create a database
mysql -e "CREATE DATABASE $DBNAME"

# Pull the drush make file and install profile into your Apache DOCROOT:
svn co https://svn.civicactions.net/repos/ieu/trunk $DOCROOT

# Change to the Apache DOCROOT directory (created above):
cd $DOCROOT

# Ensure that DOCROOT is writable (needed by l10n translations):
chmod 755 .

# Run 'drush make' to pull Drupal core and required modules into
# the VRC Document Root (don't forget the trailing dot ('.')):
drush make --contrib-destination=profiles/vrc profiles/vrc/vrc.make .

# Now ensure that the user that your webserver is running as has
#   read access to all files
#   write access to all directories
# Often this is 'APACHE_RUN_USER=www-data', which is used below:
chown -R www-data .
chmod -R u+rwx .
}}}
Now:
 * Visit the site and choose the "VRC" install profile
 * Choose your installation/operation language

==== Troubleshooting ====
 * drush make errors
If "[error]" appears at the end of one or more lines of the drush make
process, ensure that DOCROOT is writable by Apache and re-run drush make.
Sometimes drush make just fails and simply re-running it fixes things.

 * Theme issues
If the theme still doesn't appear correctly, check that the installed
directories and files under sites/default/files/ are readable by Apache.
Or as the admin user, go to 'Appearances >> vrc' and Save configuration.

=== Instance Removal ===
Warning: this will remove all code and data from listings
but does not securely wipe all data from the disk
{{{
# If DOCROOT exists, then:
if [-d ${DOCROOT}]; then

    # (Optional) Backup the database:
    drush @vrc sql-dump --gzip --result-file

    # Drop database:
    mysql -e "DROP DATABASE ${DBNAME}"

    # (Optional) Save (rename) the existing DOCROOT directory:
    VERSION_CONTROL=numbered mv -b -f ${DOCROOT} ${DOCROOT}.save

    # Remove DOCROOT directory:
    cd ${DOCROOT}
    chmod -R +w sites/default/
    cd ..
    rm -rf ${DOCROOT}
fi
}}}

== Apache sites-available/vrc ==
Apache template for creating a VRC instance.
{{{
## Copy this to /etc/apache2/sites-available/vrc
## Change 'VRC.LOCALDOMAIN.NET' to your site name
## Run: a2ensite vrc
<VirtualHost *:80>
    ServerName VRC.LOCALDOMAIN.NET
    ServerAdmin webmaster@VRC.LOCALDOMAIN.NET
    DocumentRoot "/var/www/vrc"

    <Directory "/var/www/vrc">
        # prevent access to files that can leak site information
        # optionally deny read access to LICENSE\.txt|README\.txt
        <FilesMatch "\.(engine|inc|info|install|make|module|profile|test|po|sh|.*sql|theme|tpl(\.php)?|xtmpl)$|^(\..*|Entries.*|Repository|Root|Tag|Template|CHANGELOG\.txt|COPYRIGHT\.txt|INSTALL.*\.txt|MAINTAINERS\.txt|UPGRADE\.txt)$">
            Satisfy All
            Order allow,deny
        </FilesMatch>

        # Basic Auth for development sites (optional)
        # AuthType Basic
        # AuthUserFile PATH_TO_HTPASSWD_FILE
        # AuthName "VRC In Development"
        # Deny From All
        # Require valid-user
        # Allow from LOCAL.IP.DOTTED.QUAD
        # Satisfy Any

        allow from all
    </Directory>

    # Possible values include:
    # debug, info, notice, warn, error, crit, alert, emerg
    LogLevel warn
    ErrorLog /var/log/apache2/vrc.error.log
    CustomLog /var/log/apache2/vrc.access.log combined
</VirtualHost>
}}}
