<?php

function subscription_api($action, $param1 = null, $param2 = null, $param3 = null) {
    $res = [
        "success" => true,
        "action"  => $action,
        "param1"  => $param1,
        "param2"  => $param2,
        "param3"  => $param3,
    ];
    if (!empty($action)) {
      switch ($action) {
          // Get subscription status for user
          case 'status': {


            break;
          }
          default: {
            $res["success"] = false;
            $res["message"] = 'Unknown api action';
            break;
          }
      }
    } else {
      $res["success"] = false;
      $res["message"] = 'Empty api action';
    }
    return $res;
}



