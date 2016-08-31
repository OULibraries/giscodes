<?php

/**
 * @file
 * action for the gis code from submission
 */

/**
 * Implements hook_rules_action_info().
 */
function gisentity_rules_action_info() {
  $actions = array(
    'gisentity_action_form_submit' => array(
      'label' => t('Get Code From Submission'),
      'group' => t('GIS Actions'),
      'parameter' => array(
        'user' => array(
          'type' => 'user',
          'label' => t('User to get code'),
        ),
      ),
    ),

//    'gisentity_get_user' => array(
//      'label' => t('Get user info'),
//      'group' => t('GIS Actions'),
//      'parameter' => array(
//        'user' => array(
//          'type' => 'user',
//          'label' => t('User to get code'),
//        ),
//      ),
//    ),
  );
  
  return $actions;
}

/**
 * Implements hook_form_alter().
 */
//function gisentity_form_alter(&$form, &$form_state, $form_id) {
//  if (strpos($form_id, 'webform_client_form_5482') !== FALSE) {
//    $form['submit'][] = 'gisentity_action_form_submit';
//  }
//}


/**
 * the action function for the gis form submission
 */
function gisentity_action_form_submit($user, $node) {
  display_giscode($user);
}


/**
 * @param $user
 * action function to get user info on gis form submission
 * I moved this into the module file...will remove it here once I'm sure
 * it's working over there
 */
//function gisentity_get_user($user) {
//  $params['account'] = $user;
//  drupal_set_message(t('hello @username', array('@username' => $user->mail)));
//  $from = variable_get('site_mail', 'admin@example.com');
//  $result = drupal_mail('codeEmail', 'sendCode', 'timsemail@cox.net', user_preferred_language($user), $params, $from, TRUE);
//  dpm($result);
//  if ($result['result'] == TRUE) {
//    drupal_set_message(t('Your message has been sent'));
//  }
//  else {
//    drupal_set_message(t('something went wrong'), 'error');
//  }
//}

function codeEmail_mail($key, &$message, $params) {
  $data['user'] = $params['account'];
  $data['code'] = $params['codeInfo'];
  $options['language'] = $message['language'];
//  user_mail_tokens($variables, $data, $options);
  switch($key) {
    case 'sendCode':
      $langcode = $message['language']->language;
      $message['subject'] = t('GIS Code');
      $message['body'][] = t("Dear @user\n\nYour GIS code is @code .", array('@user' => $data['user']->name, '@code' => $data['code']['code']));
      $message['Return-Path'] = t('timsmith@ou.edu');
      $message['From'] = t('admin@gis1.com');
      break;
  }
}


