<?php

/*function xlog($tag, $msg) {
    $msg = print_r($msg, true);
    $today = date("d.m.Y");
    $filename = "{$tag}_{$today}.txt";
    if (!file_exists($filename)) {
        //chmod($filename, 0777);
    }
    $fd = fopen($filename, "a+");
    $str = "[" . date("d/m/Y h:i:s", time()) . "] " . $msg;
    fwrite($fd, $str . PHP_EOL);
    fclose($fd);
    //chmod($filename, 0644);
}*/

// Init BrainTree API
/*function init_bt() {
    include_once __DIR__.'/../../../../libraries/braintree/lib/Braintree.php';
    Braintree_Configuration::environment('sandbox');
    Braintree_Configuration::merchantId('3p9tjcbyfw3qvprq');
    Braintree_Configuration::publicKey('gywz9t33m798mz55');
    Braintree_Configuration::privateKey('22d2a72ebca156982ae0775731b6cb91');
}*/

function getCurrentUserSubscription () {
    global $user;
    $sql = "select * from `geia_subscriptions` where user_id = ".($GLOBALS['user']->uid)." ORDER BY `create_date` DESC limit 0,1";
    // xlog('subscribe', $sql);
    $r = db_query($sql);
    $subscription = $r->fetchAssoc();
    // xlog('subscribe', $subscription);
    /*if (!empty($subscription)) {
        $user_profile = profile2_load_by_user($user, 'main');
        $amount = field_get_items('profile2', $user_profile, 'field_amount');
        $amount = ((!empty($amount))?$user_profile->field_amount['und'][0]['value']:0);
        //xlog('subscribe', $amount);
        db_update('geia_subscriptions')->fields([
          'amount'               => $amount,
        ])->condition('id', $subscription['id'], '=')->execute();
    }*/
    return $subscription;
}

function getCurrentUserTherapist () {
    $sql = "
      select `users`.*
      from `field_data_field_therapist`
      left join `users` on `users`.`uid` = `field_data_field_therapist`.`field_therapist_uid`
      where `field_data_field_therapist`.`entity_id` = ".($GLOBALS['user']->uid)."
      limit 0,1";
    // xlog('subscribe', $sql);
    $r = db_query($sql);
    $r = $r->fetchAssoc();
    // xlog('subscribe', $subscription);
    return $r;
}

// Try create new subscription
function createNewSubscription () {
   global $user;
  // $user_profile = profile2_load_by_user($user, 'main');
   $therapist = getCurrentUserTherapist();
   if (!empty($therapist)) {
    /*    $amount = field_get_items('profile2', $user_profile, 'field_amount');
        $amount = ((!empty($amount))?$user_profile->field_amount['und'][0]['value']:0);*/
        db_insert('geia_subscriptions')
            ->fields(array(
                'user_id'              => $GLOBALS['user']->uid,
                'trainer_id'           => $therapist['uid'],
                'amount'               => 0,
            ))->execute();
        $subscription = getCurrentUserSubscription();
        return $subscription;
   } else {
     return 'Not found therapist. Please add therapist for patient '.$user->mail;
   }
}

// BrainTree API
function bt_api($action, $param1 = null, $param2 = null, $param3 = null) {
    global $user;
    global $base_url;

    $res = [
        "success" => true,
        "logged"  => user_is_logged_in(),
        "action"  => $action,
        "param1"  => $param1,
        "param2"  => $param2,
        "param3"  => $param3,
    ];

    if (!user_is_logged_in()) {
      $res["success"] = false;
      $res["message"] = 'Not authorized';
      return $res;
    }

    $user_profile = profile2_load_by_user($user, 'main');
    $res["client_name"] = $user_profile->field_first_name['und'][0]['value'].' '.$user_profile->field_last_name['und'][0]['value'];


    if (!empty($action)) {
      init_bt();
      $transactionSuccessStatuses = [
            Braintree\Transaction::AUTHORIZED,
            Braintree\Transaction::AUTHORIZING,
            Braintree\Transaction::SETTLED,               // final OK
            Braintree\Transaction::SETTLING,
            Braintree\Transaction::SETTLEMENT_CONFIRMED,
            Braintree\Transaction::SETTLEMENT_PENDING,
            Braintree\Transaction::SUBMITTED_FOR_SETTLEMENT
      ];
      switch ($action) {
          case 'test': {
             // $user_profile = profile2_load_by_user($user, 'main');
             // xlog('subscribe', $user);
             // xlog('subscribe', $user->mail);
             // xlog('subscribe', $user_profile->field_first_name['und'][0]['value']);
             // xlog('subscribe', $user_profile->field_last_name['und'][0]['value']);
             // getCurrentUserSubscription();

             // xlog('test', $_REQUEST);

             break;
          }

          // Check subscription
          case 'subscription': {

            $subscription = getCurrentUserSubscription();
            if (empty($subscription)) {
               $subscription = createNewSubscription();
               if (is_string($subscription)) {
                 $res["success"] = false;
                 $res["message"] = $subscription;
                 break;
               }
            }

            // Check free enterprise plane
            $therapist = getCurrentUserTherapist();
            if (!empty($therapist)) {
                $enterprise_plan = db_query("SELECT * FROM geia_enterprise WHERE geia_enterprise.trainer_id = ".$therapist['uid']." LIMIT 0, 1", [])->fetchAll();
                if (!empty($enterprise_plan)) {
                    $res["success"] = true;
                    $res["free"]    = true;
                    $res["message"] = "Free Enterprise Plan";
                    break;
                }
            }




            // 1 - Get date of user subscription creation
            $res["created_date"]      = $subscription['create_date'];
            $res["last_payment_date"] = $subscription['payment_date'];
            $res["next_payment_date"] = null;

            // 2 - Get number of free days
            $res["geia_subscriptions_number_free_days"] = variable_get('geia_subscriptions_number_free_days', 0);
            // 3 - Calc free mode if true continue work app, else continue logic check out
            $freeDate = strtotime("+".variable_get('geia_subscriptions_number_free_days', 0)." day", strtotime($subscription['create_date']));
            // $res["freeDate"] = date('Y-m-d H:i:s', $freeDate);
            // $res["time"] = date('Y-m-d H:i:s', time());
            // $res["freeDate1"] = $freeDate;
            // $res["time1"]     = time();
            $res["free"]                    = false;
            $res["expired"]                 = false;
            $res["need_input_payment_info"] = false;
            $res["block"]                   = false;
            $res["amount"]                  = $subscription['amount'];
            $res["plan_id"]                 = $subscription['plan_id'];
            $res["status"]                  = $subscription['status'];








            $period = 1;
            if (!empty($subscription['plan_id'])) {
                // Trying determine price plane
                $plan = db_query("
                SELECT *
                FROM geia_price_plan
                WHERE geia_price_plan.id = ".$subscription['plan_id']."
                LIMIT 0, 1
              ", [])->fetchAll();
               if (!empty($plan)) {
                  $period        = $plan[0]->period;
                  $res["amount"] = $plan[0]->price*$plan[0]->period;
               }
            }


            if ($freeDate > time() && $res["geia_subscriptions_number_free_days"] > 0) {
               $res["free"] = true;
               $res["message"] = 'You have free period to '.date('d M Y', $freeDate).' No payments need.';
            } else {
              // 4 - Check subscription status by date payment, if expired ask payment
              if (empty($subscription['plan_id']) || empty($subscription['payment_date']) || strtotime("+".(30*$period)." day", strtotime($subscription['payment_date'])) <= time()) {
                $res["expired"] = true;
                $res["plans"]   = [];
                // Get price plans
                $plans = db_query("
                  SELECT *
                  FROM geia_price_plan
                ", [])->fetchAll();
                foreach ($plans as $plan) {
                  $res["plans"][] = [
                    'id'     => $plan->id,
                    'price'  => $plan->price,
                    'period' => $plan->period,
                  ];
                }
                // We need create client or payment type on Braine Tree service. So, we try get client token for this reasons.
                if (empty($subscription['client_id']) || empty($subscription['client_payment_type'])) {
                   $clientToken  = Braintree_ClientToken::generate();
                   $res["token"] = $clientToken;
                   $res["need_input_payment_info"] = true;
                } else {
                   $res["brief_payment_info"] = [
                       'bin'                  => $subscription['bin'],
                       'last_4'               => $subscription['last_4'],
                       'expiration_date'      => $subscription['expiration_date'],
                   ];
                }
                if ($subscription['status'] !== Braintree\Transaction::SETTLED) {
                  $res["block"] = true;
                }
              } else {
                $res["expired"] = false;
                $res["brief_payment_info"] = [
                  'bin'                  => $subscription['bin'],
                  'last_4'               => $subscription['last_4'],
                  'expiration_date'      => $subscription['expiration_date'],
                ];
                $res["next_payment_date"] = date('Y-m-d', strtotime("+".(30*$period)." day", strtotime($subscription['payment_date'])));
                $res["msg"] = '
                  You have paid period to '.date('d M Y', strtotime("+".(30*$period)." day", strtotime($subscription['payment_date']))).'
                  <br/>
                  Last payment was '.date('d M Y', strtotime($subscription['payment_date'])).'
                  <br/>
                  CARD: '.$subscription['bin'].' ... '.$subscription['last_4'].' '.$subscription['expiration_date'].'
                ';
              }
            }
            break;
          }

          // Try do payment through BrainTree API
          case 'payment': {
            if (!empty($param1)) {
              $planId             = floatval($param1);
              $paymentMethodNonce = $param2;
              $subscription       = getCurrentUserSubscription();
              if (empty($subscription)) {
                $subscription = createNewSubscription();
                if (is_string($subscription)) {
                  $res["success"] = false;
                  $res["message"] = $subscription;
                  break;
                }
              }
              // Try create new client on BrainTreeAPI
              if (empty($subscription['client_id'])) {

                  $resultCustomer = Braintree_Customer::create([
                      'firstName'          => $user_profile->field_first_name['und'][0]['value'],
                      'lastName'           => $user_profile->field_last_name['und'][0]['value'],
                      'paymentMethodNonce' => $paymentMethodNonce
                  ]);
                  if ($resultCustomer->success) {
                     $subscription['client_id']           = $resultCustomer->customer->id;
                     $subscription['client_payment_type'] = $resultCustomer->customer->paymentMethods[0]->token;

                     //$res['s'] = $subscription;

                     db_update('geia_subscriptions')->fields([
                       'client_id'           => $subscription['client_id'],
                       'client_payment_type' => $subscription['client_payment_type'],
                     ])->condition('id', $subscription['id'], '=')->execute();
                  } else {
                      $res["success"] = false;
                      $res["message"] = 'Error while creating new customer entity: '."\n";
                      $i = 1;
                      foreach($resultCustomer->errors->deepAll() as $error) {
                          $res["errors"][] = $error->code . ": " . $error->message;
                          $res["message"] .= $i.') '.$error->code . ": " . $error->message."\n";
                          $i++;
                      }
                      return $res;
                  }
              } else {
                  // Try create new payment type on BraineTreeAPI
                  if (empty($subscription['client_payment_type'])) {
                      $resultPaymentMethod = Braintree_PaymentMethod::create([
                          'customerId'         => $subscription['client_id'],
                          'paymentMethodNonce' => $paymentMethodNonce
                      ]);
                      if ($resultPaymentMethod->success) {
                          $subscription['client_payment_type'] = $resultPaymentMethod->paymentMethod->token;
                          db_update('geia_subscriptions')->fields([
                              'client_payment_type' => $subscription['client_payment_type'],
                          ])->condition('id', $subscription['id'], '=')->execute();
                      } else {
                          $res["success"] = false;
                          $res["message"] = 'Error while creating new payment method: '."\n";
                          $i = 1;
                          foreach($resultPaymentMethod->errors->deepAll() as $error) {
                              $res["errors"][] = $error->code . ": " . $error->message;
                              $res["message"] .= $i.') '.$error->code . ": " . $error->message."\n";
                              $i++;
                          }
                          return $res;
                      }
                  }
              }

              if (empty($subscription['client_payment_type'])) {
                  $res["success"] = false;
                  $res["message"] = "Pl's determine payment method";
                  return $res;
              }

              // Trying determine price plane
              $plan = db_query("
                SELECT *
                FROM geia_price_plan
                WHERE geia_price_plan.id = ".$planId."
                LIMIT 0, 1
              ", [])->fetchAll();
              if (empty($plan)) {
                $res["success"] = false;
                $res["message"] = "Pl's determine price plan";
                return $res;
              }
              $amount = $plan[0]->price*$plan[0]->period;

              // Trying determine discount
              if (!empty($_REQUEST['discount'])) {
                $discount = db_query("
                  SELECT *
                  FROM geia_discounts
                  WHERE
                         geia_discounts.code = '".$_REQUEST['discount']."'
                    AND  geia_discounts.trainer_id = ".$subscription['trainer_id']."
                    AND  geia_discounts.used_date IS NULL
                  LIMIT 0, 1
                ", [])->fetchAll();
                if (empty($discount)) {
                   $res["success"] = false;
                   $res["message"] = "Wrong discount code";
                   return $res;
                } else {
                  $amount = $amount*(1 - $discount[0]->percent/100);

                  db_update('geia_subscriptions')->fields([
                    'discount_id' => $discount[0]->id,
                  ])->condition('id', $subscription['id'], '=')->execute();

                  db_update('geia_discounts')->fields([
                    'user_id'    => $GLOBALS['user']->uid,
                    'used_date'  => date("Y-m-d H:i:s"),
                  ])->condition('id', $discount[0]->id, '=')->execute();

                  /*
                  $res["success"] = false;
                  $res["message"] = "OK discount code";
                  return $res;
                  */
                }
              }


              // Transactions actions:
              // 1) Cancel a transaction before it is settled:
              // $result = Braintree_Transaction::void('the_transaction_id');
              // 2) If you want to refund a customer for a transaction that has already settled, use
              // $result = Braintree_Transaction::refund('the_transaction_id');
              // 3) Find
              // $transaction = Braintree_Transaction::find('the_transaction_id');

              $transaction = Braintree_Transaction::sale([
                    'amount'             => $amount,
                    'paymentMethodToken' => $subscription['client_payment_type'],
                    //'paymentMethodNonce' => 'fake-valid-nonce',
                    'options' => [
                        'submitForSettlement' => True
                    ],
                    'descriptor' => [
                        'name' => 'geiafit*subscription',
                        //'phone' => '3125551212',
                        'url' => 'geiafit.com'
                    ]
              ]);

              $res["success"] = $transaction->success;
              $res["status"]  = $transaction->transaction->status;
              if ($transaction->success == true) {
                    $res["transaction"] = [
                        'id'         => $transaction->transaction->id,
                        'type'       => $transaction->transaction->type,
                        'amount'     => $transaction->transaction->amount,
                        'status'     => $transaction->transaction->status,
                        'created_at' => $transaction->transaction->createdAt->format('Y-m-d H:i:s'),
                        'updated_at' => $transaction->transaction->updatedAt->format('Y-m-d H:i:s'),
                        'card'       => [
                            'token'              => $transaction->transaction->creditCardDetails->token,
                            'bin'                => $transaction->transaction->creditCardDetails->bin,
                            'last_4'             => $transaction->transaction->creditCardDetails->last_4,
                            'card_type'          => $transaction->transaction->creditCardDetails->card_type,
                            'expiration_date'    => $transaction->transaction->creditCardDetails->expirationDate,
                            'cardholder_name'    => $transaction->transaction->creditCardDetails->cardholderName,
                            'customer_location'  => $transaction->transaction->creditCardDetails->customerLocation,
                        ],
                        'customer'   => [

                        ],
                    ];
                    if (!is_null($transaction->transaction->customerDetails->id)) {
                        $res["transaction"]["customer"] = [
                            "id"           => $transaction->transaction->customerDetails->id,
                            "first_name"   => $transaction->transaction->customerDetails->firstName,
                            "last_name"    => $transaction->transaction->customerDetails->lastName,
                            "email"        => $transaction->transaction->customerDetails->email,
                            "company"      => $transaction->transaction->customerDetails->company,
                            "website"      => $transaction->transaction->customerDetails->website,
                            "phone"        => $transaction->transaction->customerDetails->phone,
                            "fax"          => $transaction->transaction->customerDetails->fax,
                        ];
                    }

                    $res["transaction_id"]  = $transaction->transaction->id;

                    // Write inner transaction record for historical purposes
                    db_update('geia_subscriptions')->fields([
                        'card_type'            => $transaction->transaction->creditCardDetails->card_type,
                        'bin'                  => $transaction->transaction->creditCardDetails->bin,
                        'last_4'               => $transaction->transaction->creditCardDetails->last_4,
                        'expiration_date'      => $transaction->transaction->creditCardDetails->expirationDate,
                        'amount'               => $amount,
                        'plan_id'              => $planId,
                        'status'               => $transaction->transaction->status,
                    ])->condition('id', $subscription['id'], '=')->execute();

                    db_insert('geia_transactions')
                      ->fields(array(
                          'subscription_id'      => $subscription['id'],
                          'transaction_id'       => $transaction->transaction->id,
                          'card_type'            => $transaction->transaction->creditCardDetails->card_type,
                          'bin'                  => $transaction->transaction->creditCardDetails->bin,
                          'last_4'               => $transaction->transaction->creditCardDetails->last_4,
                          'expiration_date'      => $transaction->transaction->creditCardDetails->expirationDate,
                          'amount'               => $amount,
                          'status'               => $transaction->transaction->status,
                      ))->execute();
                    //*/


                    // $t = Braintree_Test_Transaction::settle($transaction->transaction->id);
                    // $t = Braintree_Test_Transaction::settlementConfirm($transaction->transaction->id);
                    // $t = Braintree_Test_Transaction::settlementDecline($transaction->transaction->id);
                    // $res["status"]  = $t->status;

                    if (in_array($transaction->transaction->status, $transactionSuccessStatuses)) {
                      $res["message"] = "Success! Your transaction has been successfully processed.";
                    } else {
                      $res["message"] = "Transaction Failed. Your test transaction has a status of " . $transaction->transaction->status . ".";
                    }
              } else {
                  $res["message"] = 'Failed transaction :'."\n";
                  $i = 1;
                  foreach($transaction->errors->deepAll() as $error) {
                    $res["errors"][] = $error->code . ": " . $error->message;
                    $res["message"] .= $i.') '.$error->code . ": " . $error->message."\n";
                    $i++;
                  }
              }
            } else  {
              $res["success"] = false;
              $res["message"] = 'API action wrong params';
            }
            break;
          }

          /*
          // Get client token for BrainTree API
          case 'token': {
            $clientToken  = Braintree_ClientToken::generate();
            $res["token"] = $clientToken;
            $res["logged"] = user_is_logged_in();
            break;
          }
          //*/

          /*
          // Do client transaction for BrainTree API
          case 'transaction': {
            if (!empty($param1) && !empty($param2)) {
              $amount             = floatval($param1);
              $paymentMethodNonce = $param2;

              $subscription = getCurrentUserSubscription();
              if (empty($subscription)) {
                  // Try create client in BrainTree
                  $user_profile = profile2_load_by_user($user, 'main');
                  $resultCustomer = Braintree_Customer::create([
                      'firstName'          => $user_profile->field_first_name['und'][0]['value'],
                      'lastName'           => $user_profile->field_last_name['und'][0]['value'],
                      // 'company'            => 'Jones Co.',
                      'paymentMethodNonce' => $paymentMethodNonce
                   ]);
                   if ($resultCustomer->success) {
                     // Try create new subscription
                     db_insert('geia_subscriptions')
                           ->fields(array(
                               'user_id'              => $GLOBALS['user']->uid,
                               'trainer_id'           => 0,
                               'amount'               => 0,
                               'client_id'            => $resultCustomer->customer->id,
                               'client_payment_type'  => $resultCustomer->customer->paymentMethods[0]->token,
                               'client_cc'            => null,
                           ))->execute();
                     $subscription = getCurrentUserSubscription();
                   } else {
                     $res["success"] = false;
                     $res["message"] = 'Failed transaction :('."\n";
                     $i = 1;
                     foreach($resultCustomer->errors->deepAll() as $error) {
                        $res["errors"][] = $error->code . ": " . $error->message;
                        $res["message"] .= $i.') '.$error->code . ": " . $error->message."\n";
                        $i++;
                     }
                     return $res;
                   }

              }

              if (!empty($subscription) && !empty($subscription['client_payment_type'])) {
                $res["message"] = 'Found subscription';

              } else {
                $res["success"] = false;
                $res["message"] = 'Not found subscription';
              }



              $transaction = Braintree_Transaction::sale([
                 'amount'             => $amount,
                  'paymentMethodNonce' => $paymentMethodNonce,
                 //'paymentMethodNonce' => 'fake-valid-nonce',
                 'options' => [
                   'submitForSettlement' => True
                 ],
                 'descriptor' => [
                   'name' => 'geiafit*subscription',
                   //'phone' => '3125551212',
                   'url' => 'geiafit.com'
                 ]
              ]);

              // Transactions actions:
              // 1) Cancel a transaction before it is settled:
              // $result = Braintree_Transaction::void('the_transaction_id');
              // 2) If you want to refund a customer for a transaction that has already settled, use
              // $result = Braintree_Transaction::refund('the_transaction_id');
              // 3) Find
              // $transaction = Braintree_Transaction::find('the_transaction_id');


              $res["success"] = $transaction->success;
              $res["status"]  = $transaction->transaction->status;

              $res["logged"] = user_is_logged_in();

              if ($transaction->success == true) {
                 $res["transaction"] = [
                   'id'         => $transaction->transaction->id,
                   'type'       => $transaction->transaction->type,
                   'amount'     => $transaction->transaction->amount,
                   'status'     => $transaction->transaction->status,
                   'created_at' => $transaction->transaction->createdAt->format('Y-m-d H:i:s'),
                   'updated_at' => $transaction->transaction->updatedAt->format('Y-m-d H:i:s'),
                   'card'       => [
                      'token'              => $transaction->transaction->creditCardDetails->token,
                      'bin'                => $transaction->transaction->creditCardDetails->bin,
                      'last_4'             => $transaction->transaction->creditCardDetails->last_4,
                      'card_type'          => $transaction->transaction->creditCardDetails->card_type,
                      'expiration_date'    => $transaction->transaction->creditCardDetails->expirationDate,
                      'cardholder_name'    => $transaction->transaction->creditCardDetails->cardholderName,
                      'customer_location'  => $transaction->transaction->creditCardDetails->customerLocation,
                   ],
                   'customer'   => [

                   ],
                 ];
                 if (!is_null($transaction->transaction->customerDetails->id)) {
                     $res["transaction"]["customer"] = [
                        "id"           => $transaction->transaction->customerDetails->id,
                        "first_name"   => $transaction->transaction->customerDetails->firstName,
                        "last_name"    => $transaction->transaction->customerDetails->lastName,
                        "email"        => $transaction->transaction->customerDetails->email,
                        "company"      => $transaction->transaction->customerDetails->company,
                        "website"      => $transaction->transaction->customerDetails->website,
                        "phone"        => $transaction->transaction->customerDetails->phone,
                        "fax"          => $transaction->transaction->customerDetails->fax,
                     ];
                 }

                 $res["transaction_id"]  = $transaction->transaction->id;

                 // $t = Braintree_Test_Transaction::settle($transaction->transaction->id);
                 // $t = Braintree_Test_Transaction::settlementConfirm($transaction->transaction->id);
                 // $t = Braintree_Test_Transaction::settlementDecline($transaction->transaction->id);
                 // $res["status"]  = $t->status;

                 if (in_array($transaction->transaction->status, $transactionSuccessStatuses)) {
                   $message = "Success! Your test transaction has been successfully processed. See the Braintree API response and try again.";
                 } else {
                   $message = "Transaction Failed. Your test transaction has a status of " . $transaction->transaction->status . ". See the Braintree API response and try again.";
                 }
                 $res["message"] = $message;
              }
              if ($transaction->success == false) {
                 $res["message"] = 'Failed transaction :('."\n";
                 $i = 1;
                 foreach($transaction->errors->deepAll() as $error) {
                   $res["errors"][] = $error->code . ": " . $error->message;
                   $res["message"] .= $i.') '.$error->code . ": " . $error->message."\n";
                   $i++;
                 }
              }




            } else {
              $res["success"] = false;
              $res["message"] = 'API action wrong params';
            }
            break;
          }

          //*/

          default : {
            $res["success"] = false;
            $res["message"] = 'Empty api action';
            break;
          }
      }
    } else {
      $res["success"] = false;
    }
    return $res;
}


function bt_test() {
    return [
     'ok'  => true,
     'msg' => 'bt_test',
    ];
}

?>