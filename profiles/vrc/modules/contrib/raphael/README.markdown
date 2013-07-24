Raphaël module for Drupal
=========================

This module exposes [Raphaël][] as a JavaScript library for use with
other Drupal modules. To use this, you’ll need to download the Raphaël
library to your libraries folder, so `raphael.js` is located at
`sites/all/libraries/raphael/raphael.js` (or a similar location, as
supported by the [Libraries API][]).

If you use [drush make][] to build your site and download Raphaël, the
JavaScript library should be downloaded automatically, courtesy of the
`raphael.make` file in this folder.

This module depends on [Libraries API][].

Usage
-----

To use this library, first call `libraries_load('raphael', 'minified');`
somewhere in your PHP code to let Drupal know that you want to load
Raphaël on this page. After this, Raphaël will be available for use in
your JavaScript code.

[Raphaël]: http://raphaeljs.com/
[Libraries API]: http://drupal.org/project/libraries
[drush make]: http://drupal.org/project/drush_make
