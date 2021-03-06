<?php
/**
 * @file
 * hr_contacts.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function hr_contacts_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function hr_contacts_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function hr_contacts_node_info() {
  $items = array(
    'hr_contact' => array(
      'name' => t('Contact'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}

/**
 * Implements hook_default_og_membership_type().
 */
function hr_contacts_default_og_membership_type() {
  $items = array();
  $items['hr_responder'] = entity_import('og_membership_type', '{ "name" : "hr_responder", "description" : "Responder", "language" : "" }');
  return $items;
}
