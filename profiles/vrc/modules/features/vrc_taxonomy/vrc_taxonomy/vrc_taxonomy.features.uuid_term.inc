<?php
/**
 * @file
 * vrc_taxonomy.features.uuid_term.inc
 */

/**
 * Implements hook_uuid_features_default_terms().
 */
function vrc_taxonomy_uuid_features_default_terms() {
  $terms = array();

  $terms[] = array(
    'name' => 'Server based',
    'description' => '',
    'format' => NULL,
    'weight' => 0,
    'uuid' => '1b9a29cc-94ae-c574-0513-8b72df129efb',
    'vocabulary_machine_name' => 'compatibilities',
  );
  $terms[] = array(
    'name' => 'Desktop Software',
    'description' => '',
    'format' => NULL,
    'weight' => 0,
    'uuid' => '3a58d5db-7ba3-8584-21ee-a50a0947d33b',
    'vocabulary_machine_name' => 'compatibilities',
  );
  $terms[] = array(
    'name' => 'iOS',
    'description' => 'iOS (previously iPhone OS) is a mobile operating system developed and distributed by Apple Inc.',
    'format' => NULL,
    'weight' => 0,
    'uuid' => '4b3fb6b8-d4c5-5b74-2dd5-55374ef967ab',
    'vocabulary_machine_name' => 'compatibilities',
  );
  $terms[] = array(
    'name' => 'Online',
    'description' => '',
    'format' => NULL,
    'weight' => 0,
    'uuid' => '58d1e719-a249-1b24-c9b3-7c3790115695',
    'vocabulary_machine_name' => 'compatibilities',
  );
  $terms[] = array(
    'name' => 'LAMP (Linux Apache MySQL Php)',
    'description' => 'The standard web server stack',
    'format' => NULL,
    'weight' => 0,
    'uuid' => '8a048a28-534c-3e84-815c-ceadc839c267',
    'vocabulary_machine_name' => 'compatibilities',
  );
  $terms[] = array(
    'name' => '',
    'description' => NULL,
    'format' => NULL,
    'weight' => 0,
    'uuid' => 'b23fb3db-75a7-8864-6900-ea04af0d9bec',
    'vocabulary_machine_name' => 'compatibilities',
  );
  $terms[] = array(
    'name' => 'Mac/OS',
    'description' => 'OS X ( /oʊ ˌɛs ˈtɛn/),[7] formerly Mac OS X,[8] is a series of Unix-based graphical interface operating systems developed, marketed, and sold by Apple Inc. OS X is designed to run exclusively on Macintosh computers, having been pre-loaded on all Macs since 2002.',
    'format' => NULL,
    'weight' => 0,
    'uuid' => 'b4b1cea5-eb27-3554-5908-26cff166c0f2',
    'vocabulary_machine_name' => 'compatibilities',
  );
  $terms[] = array(
    'name' => 'Others',
    'description' => '',
    'format' => NULL,
    'weight' => 0,
    'uuid' => 'd7e55180-c637-c304-390d-3a74bc44df00',
    'vocabulary_machine_name' => 'compatibilities',
  );
  $terms[] = array(
    'name' => 'Android',
    'description' => 'Android is a Linux-based operating system for mobile devices such as smartphones and tablet computers.',
    'format' => NULL,
    'weight' => 0,
    'uuid' => 'e5f4550a-376f-3f94-312e-df1ef3acbfe1',
    'vocabulary_machine_name' => 'compatibilities',
  );
  $terms[] = array(
    'name' => 'Mobile',
    'description' => '',
    'format' => NULL,
    'weight' => 0,
    'uuid' => 'e99bca09-ef10-26b4-155c-e17dae97b347',
    'vocabulary_machine_name' => 'compatibilities',
  );
  $terms[] = array(
    'name' => 'Microsoft Windows',
    'description' => 'Microsoft Windows is a series of graphical interface operating systems developed, marketed, and sold by Microsoft.',
    'format' => NULL,
    'weight' => 0,
    'uuid' => 'e9cc0441-4ad4-7d44-596c-efc12d75aab0',
    'vocabulary_machine_name' => 'compatibilities',
  );
  $terms[] = array(
    'name' => 'GNU Linux',
    'description' => 'Linux is a Unix-like computer operating system assembled under the model of free and open source software development and distribution. ',
    'format' => NULL,
    'weight' => 0,
    'uuid' => 'f7368fa4-99bf-9154-c542-c29944a3c172',
    'vocabulary_machine_name' => 'compatibilities',
  );
  $terms[] = array(
    'name' => 'Other Mobiles',
    'description' => 'Other mobiles technologies such as Sybian, Mozilla OS, etc...',
    'format' => NULL,
    'weight' => 0,
    'uuid' => 'f971c863-e420-75a4-a956-151efcfdd1a5',
    'vocabulary_machine_name' => 'compatibilities',
  );
  return $terms;
}
