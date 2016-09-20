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
  );
  
  return $actions;
}

/**
 * the action function for the gis form submission
 */
function gisentity_action_form_submit($user, $node) {
  display_giscode($user);
  return true;
}

function codeEmail_mail($key, &$message, $params) {
  $data['user'] = $params['account'];
  $data['code'] = $params['codeInfo'];
  $options['language'] = $message['language'];
//  user_mail_tokens($variables, $data, $options);
  switch($key) {
    case 'sendCode':
      $langcode = $message['language']->language;
      $message['subject'] = t('GIS Code');
      $message['body'][] = t("Dear @user\n\nYour GIS code is @code .", array('@user' => $data['user']->realname, '@code' => $data['code']['code']));
      $message['Return-Path'] = t('timsmith@ou.edu');
      $message['From'] = t('admin@gis1.com');
      break;
  }
}


