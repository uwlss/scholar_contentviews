<?php

/**
 * Implementation of hook_views_default_views().
 */
function scholar_contentviews_views_default_views() {
  $views = array();

  // Exported view: vsite_content_by_user
  $view = new view;
  $view->name = 'vsite_content_by_user';
  $view->description = 'Lists of posts by site users';
  $view->tag = '';
  $view->view_php = '';
  $view->base_table = 'node';
  $view->is_cacheable = FALSE;
  $view->api_version = 2;
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->override_option('arguments', array(
    'name' => array(
      'default_action' => 'summary asc',
      'style_plugin' => 'default_summary',
      'style_options' => array(
        'count' => 1,
        'override' => 0,
        'items_per_page' => '25',
      ),
      'wildcard' => 'all',
      'wildcard_substitution' => 'All',
      'title' => '',
      'breadcrumb' => '',
      'default_argument_type' => 'fixed',
      'default_argument' => '',
      'validate_type' => 'none',
      'validate_fail' => 'not found',
      'glossary' => 0,
      'limit' => '0',
      'case' => 'none',
      'path_case' => 'none',
      'transform_dash' => 1,
      'id' => 'name',
      'table' => 'users',
      'field' => 'name',
      'validate_user_argument_type' => 'uid',
      'validate_user_roles' => array(
        '2' => 0,
        '5' => 0,
        '3' => 0,
        '4' => 0,
        '6' => 0,
      ),
      'relationship' => 'none',
      'default_options_div_prefix' => '',
      'default_argument_fixed' => '',
      'default_argument_user' => 0,
      'default_argument_php' => '',
      'validate_argument_node_type' => array(
        'announcement' => 0,
        'blog' => 0,
        'book' => 0,
        'class' => 0,
        'class_material' => 0,
        'event' => 0,
        'gallery' => 0,
        'image' => 0,
        'link' => 0,
        'page' => 0,
        'presentation' => 0,
        'feed' => 0,
        'sitewide_page' => 0,
        'vsite' => 0,
        'project' => 0,
        'vsite_users_profile' => 0,
        'biblio' => 0,
        'profile' => 0,
      ),
      'validate_argument_node_access' => 0,
      'validate_argument_nid_type' => 'nid',
      'validate_argument_vocabulary' => array(
        '49' => 0,
        '3' => 0,
        '1' => 0,
        '5' => 0,
        '2' => 0,
        '6' => 0,
        '7' => 0,
        '8' => 0,
        '9' => 0,
        '23' => 0,
        '14' => 0,
        '53' => 0,
        '24' => 0,
        '25' => 0,
        '26' => 0,
        '27' => 0,
        '28' => 0,
        '29' => 0,
        '30' => 0,
        '31' => 0,
        '32' => 0,
        '33' => 0,
        '34' => 0,
        '35' => 0,
        '36' => 0,
        '37' => 0,
        '38' => 0,
        '39' => 0,
        '45' => 0,
        '41' => 0,
        '42' => 0,
        '43' => 0,
        '44' => 0,
        '46' => 0,
        '47' => 0,
        '50' => 0,
        '51' => 0,
        '52' => 0,
      ),
      'validate_argument_type' => 'tid',
      'validate_argument_transform' => 0,
      'validate_user_restrict_roles' => 0,
      'validate_argument_node_flag_name' => '*relationship*',
      'validate_argument_node_flag_test' => 'flaggable',
      'validate_argument_node_flag_id_type' => 'id',
      'validate_argument_user_flag_name' => '*relationship*',
      'validate_argument_user_flag_test' => 'flaggable',
      'validate_argument_user_flag_id_type' => 'id',
      'validate_argument_is_member' => 'OG_VIEWS_DO_NOT_VALIDATE_MEMBERSHIP',
      'validate_argument_group_node_type' => array(
        'vsite' => 0,
        'project' => 0,
      ),
      'validate_argument_signup_status' => 'any',
      'validate_argument_signup_node_access' => 0,
      'validate_argument_php' => '',
    ),
  ));
  $handler->override_option('filters', array(
    'current' => array(
      'operator' => 'all',
      'value' => '',
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'current',
      'table' => 'spaces',
      'field' => 'current',
      'relationship' => 'none',
    ),
    'type' => array(
      'operator' => 'not in',
      'value' => array(
        'book' => 'book',
        'event' => 'event',
      ),
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'type',
      'table' => 'node',
      'field' => 'type',
      'relationship' => 'none',
      'override' => array(
        'button' => 'Override',
      ),
    ),
  ));
  $handler->override_option('access', array(
    'type' => 'none',
  ));
  $handler->override_option('cache', array(
    'type' => 'none',
  ));
  $handler->override_option('header', '<strong><p>Note: book posts are excluded, as they are collaboratively edited.<br/>
Posts are abbreviated - click to view a full post.</p></strong>');
  $handler->override_option('header_format', '1');
  $handler->override_option('header_empty', 1);
  $handler->override_option('items_per_page', 20);
  $handler->override_option('use_pager', '1');
  $handler->override_option('row_plugin', 'node');
  $handler->override_option('row_options', array(
    'relationship' => 'none',
    'build_mode' => 'teaser',
    'links' => 1,
    'comments' => 0,
  ));
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->override_option('path', 'cp/content/user/posts');
  $handler->override_option('menu', array(
    'type' => 'default tab',
    'title' => 'Posts',
    'description' => '',
    'weight' => '-2',
    'name' => 'navigation',
  ));
  $handler->override_option('tab_options', array(
    'type' => 'tab',
    'title' => 'By User',
    'description' => '',
    'weight' => '-1',
    'name' => 'navigation',
  ));

  $views[$view->name] = $view;

  return $views;
}
