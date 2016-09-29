<?php

function geia_subscriptions_options($form) {
    $options = [];
    for ($i = 0; $i <= 31; $i++) {
       $options[$i] = $i;
    }

    $form['geia_subscriptions_number_free_days'] = array(
        '#type' => 'select',
        '#options' => $options,
        '#title' => t('How many days after 1st login user can users can use the app before we prompt them to payment'),
        '#default_value' => variable_get('geia_subscriptions_number_free_days', 0),
        '#required' => TRUE,
    );

   /* $form['unisender'] = array(
        '#type' => 'fieldset',
        '#title' => t('Настройка подписки Unisender'),
        '#weight' => 1,
        '#collapsible' => TRUE,
        '#collapsed' => FALSE,
    );

    $form['unisender']['unisender_api_key'] = array(
        '#type' => 'textfield',
        '#title' => t('API ключ'),
        '#default_value' => variable_get('unisender_api_key', ''),
        '#size' => 60,
        '#maxlength' => 128,
        '#required' => TRUE,
    );*/

   /* if ($api_key = variable_get('unisender_api_key', '')) {
        module_load_include('php', 'takeda_misc', 'includes/unisender.api');
        $api = new UniSenderApi($api_key);
        $lists = $api->getLists();
        $unisender_lists = array();
        if (isset($lists->error) && $lists->error) {
            drupal_set_message($lists->code . ': ' . $lists->error, 'error');
        } elseif ($lists->result) {
            foreach ($lists->result as $list) {
                $unisender_lists[$list->id] = $list->title;
            }
            $form['unisender']['unisender_list_ids'] = array(
                '#type' => 'checkboxes',
                '#title' => t('Списки рассылки'),
                '#options' => $unisender_lists,
                '#default_value' => variable_get('unisender_list_ids', ''),
            );
        }
    }*/

    return system_settings_form($form);
}
