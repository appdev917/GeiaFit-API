<?php /*require_once("includes/braintree_init.php"); */?>

<html>
<?php require_once("includes/head.php"); ?>



<body>

   <style>
     .hosted-field {
       height: 50px !important;
     }
     input {
         font-size: 18px;
     }
  </style>


    <?php require_once("includes/header.php"); ?>

    <div class="wrapper">
        <div class="checkout container">

            <header style="margin-top: 30px;">
                <h1>Hi, <span class="client_name"></span><br>Let's test a transaction</h1>
                <p>
                    Make a test payment with Braintree using PayPal or a card
                </p>
            </header>

            <h4 class="message">...</h4>
            <h4 class="brief_payment_info"></h4>
            <h4 class="block" style="color: red;"></h4>

            <form id="payment-form" style="display: none;">
                <section>

                    <div class="payment-info" style="display: none;">
                        <div id="error-message"></div>

                        <label for="card-number">Card Number</label>
                        <div class="hosted-field" id="card-number"></div>

                        <label for="cvv">CVV</label>
                        <div class="hosted-field" id="cvv"></div>

                        <label for="expiration-date">Expiration Date</label>
                        <div class="hosted-field" id="expiration-date"></div>
                    </div>

<!--                    <label class="input-label">Amount $</label>
                    <label for="amount">
                        <div class="input-wrapper amount-wrapper">
                           <input id="amount" name="amount" type="number" step="any" min="1" placeholder="$" value="10">
                        </div>
                    </label>
-->

                    <label class="input-label">Price plan $</label>
                    <label for="plan">
                        <div class="input-wrapper amount-wrapper">
                            <select id="plan" name="plan" style="width: 100%;"></select>
                        </div>
                    </label>


                    <label class="input-label">Discount code</label>
                    <label for="discount">
                        <div class="input-wrapper amount-wrapper">
                            <input id="discount" name="discount"  placeholder="XXXXXXXXXXXX">
                        </div>
                    </label>

                </section>

                <div style="text-align: right;">
                    <button class="button send-transaction"><span>DO PAYMENT</span></button>
                </div>

            </form>
        </div>
    </div>

    <!-- Load the Client component. -->
    <script src="https://js.braintreegateway.com/web/3.1.0/js/client.min.js"></script>

    <!-- Load the Hosted Fields component. -->
    <script src="https://js.braintreegateway.com/web/3.1.0/js/hosted-fields.min.js"></script>


    <script type="text/javascript">

        var msg = function (m) {
          $('.message').html(m);
        }

        $(document).ready(function() {
            msg("Checking subscription status. Pl's wait a little bit ...");
            $.get("/api/bt/subscription", function( data ) {
                msg("");
                console.log(data);
                if (data.success) {
                  $('.client_name').html(data.client_name);
                  $('#amount').val(data.amount);

                  if (data.free) {
                    if (typeof(data.message) == 'string') {
                      msg('<span style="color: green;">' + data.message + '</span>');
                    } else {
                      msg('<span style="color: green;">' +"You have free period no payments need." + '</span>');
                    }
                  }

                  if (data.expired) {
                    $('#payment-form').show();

                    $(data.plans).each(function (index, plan) {
                      $('#plan').append('<option value="' + plan.id + '"> $' + plan.price + ' / month ' + ((plan.period > 1)?'with ' + plan.period + ' month subscription':'') + '</option>');
                    });


                    if (data.need_input_payment_info) {
                      $('.payment-info').show();

                      braintree.client.create({
                            authorization: data.token
                        }, function (clientErr, clientInstance) {
                            if (clientErr) {
                                // Handle error in client creation
                                return;
                            }
                            braintree.hostedFields.create({
                                client: clientInstance,
                                styles: {
                                    'input': {
                                        'font-size': '18px'
                                    },
                                    'input.invalid': {
                                        'color': 'red'
                                    },
                                    'input.valid': {
                                        'color': 'green'
                                    }
                                },
                                fields: {
                                    number: {
                                        selector: '#card-number',
                                        placeholder: '4111 1111 1111 1111'
                                    },
                                    cvv: {
                                        selector: '#cvv',
                                        placeholder: '123'
                                    },
                                    expirationDate: {
                                        selector: '#expiration-date',
                                        placeholder: '10 / 2019'
                                    }
                                }
                            }, function (hostedFieldsErr, hostedFieldsInstance) {
                                if (hostedFieldsErr) {
                                  // Handle error in Hosted Fields creation
                                  return;
                                }

                                $('.send-transaction').on('click', function (e) {
                                    e.preventDefault();
                                    // console.log('send-transaction');
                                    if (confirm('Are you sure?')) {
                                        hostedFieldsInstance.tokenize(function (tokenizeErr, payload) {
                                            console.log(tokenizeErr);
                                            if (tokenizeErr) {
                                                // Handle error in Hosted Fields tokenization
                                                alert(tokenizeErr.message);
                                                return;
                                            }

                                            /*var amount = $('#amount').val();
                                            if (amount == '' || typeof(amount) == 'undefined') {
                                                alert('Please input correct amount $');
                                                return;
                                            }

                                            amount = amount.toString().replace('.', ',');*/

                                           /* console.log(amount);
                                            console.log(payload);
                                            console.log(payload.nonce);*/

                                            var plan = $('#plan').val();
                                            var discount = $('#discount').val();

                                            $('#payment-form').hide();
                                            msg("Doing payment transaction. Pl's wait a little bit ...");
                                            $.get("/api/bt/payment/" + plan + "/" + payload.nonce + '/?discount=' + discount, function (data) {
                                                msg("");
                                                console.log(data);
                                                if (data.success) {
                                                    if (typeof(data.message) == 'string') {
                                                        $('.payment-info').hide();
                                                        alert(data.message);
                                                    } else {
                                                        msg("Successful transaction!");
                                                        alert('Successful transaction!');
                                                    }
                                                } else {
                                                    if (typeof(data.message) == 'string') {
                                                        alert(data.message);
                                                    } else {
                                                        alert('Failed transaction :(');
                                                    }
                                                }
                                            });
                                        });
                                        //*/
                                    }
                                });
                            });
                      });
                    } else {
                        $('.brief_payment_info').html('CARD: ' + data.brief_payment_info.type + '  ' + data.brief_payment_info.bin + ' ... ' + data.brief_payment_info.last_4 + ' ' + data.brief_payment_info.expiration_date);
                        if (data.block) {
                          $('.block').html('Found prev transaction in status ' + data.status);
                        }


                        $('.send-transaction').on('click', function (e) {
                            e.preventDefault();
                            if (confirm('Are you sure?')) {
                                $('#payment-form').hide();
                                msg("Doing payment transaction. Pl's wait a little bit ...");
                               /* var amount = $('#amount').val();
                                if (amount == '' || typeof(amount) == 'undefined') {
                                    alert('Please input correct amount $');
                                    return;
                                }
                                amount = amount.toString().replace('.', ',');*/

                                var plan = $('#plan').val();
                                var discount = $('#discount').val();

                                $.get("/api/bt/payment/" + plan + '/?discount=' + discount, function (data) {
                                    msg("");
                                    $('#payment-form').show();
                                    console.log(data);
                                    if (data.success) {
                                        if (typeof(data.message) == 'string') {
                                            $('.payment-info').hide();
                                            alert(data.message);
                                        } else {
                                            alert('Successful transaction!');
                                        }
                                    } else {
                                        if (typeof(data.message) == 'string') {
                                            alert(data.message);
                                        } else {
                                            alert('Failed transaction :(');
                                        }
                                    }
                                });
                            }
                        });
                    }
                    /*
                    //*/
                  } else {
                      if (typeof(data.msg) == 'string') {
                          msg('<span style="color: green;">' + data.msg + '</span>');
                      }
                  }
                } else {
                    if (typeof(data.msg) == 'string' && data.msg !== '') {
                      alert(data.msg);
                    } else {
                      alert('Error');
                    }
                }
            }).fail(function(res) {
                //console.log(res);
                alert("Error. " + res.statusText);
            });;

/*
            $.get("/api/bt/token", function( data ) {
                console.log(data);
                if (data.success) {

                    console.log(braintree);

                    braintree.client.create({
                        authorization: data.token
                    }, function (clientErr, clientInstance) {
                        if (clientErr) {
                            // Handle error in client creation
                            return;
                        }
                        braintree.hostedFields.create({
                            client: clientInstance,
                            styles: {
                                'input': {
                                    'font-size': '18px'
                                },
                                'input.invalid': {
                                    'color': 'red'
                                },
                                'input.valid': {
                                    'color': 'green'
                                }
                            },
                            fields: {
                                number: {
                                    selector: '#card-number',
                                    placeholder: '4111 1111 1111 1111'
                                },
                                cvv: {
                                    selector: '#cvv',
                                    placeholder: '123'
                                },
                                expirationDate: {
                                    selector: '#expiration-date',
                                    placeholder: '10 / 2019'
                                }
                            }
                        }, function (hostedFieldsErr, hostedFieldsInstance) {
                            if (hostedFieldsErr) {
                                // Handle error in Hosted Fields creation
                                return;
                            }
                            $('.send-transaction').on('click', function (e) {
                                e.preventDefault();
                                console.log('send-transaction');
                                hostedFieldsInstance.tokenize(function (tokenizeErr, payload) {
                                    console.log(tokenizeErr);
                                    if (tokenizeErr) {
                                        // Handle error in Hosted Fields tokenization
                                        alert(tokenizeErr.message);
                                        return;
                                    }

                                    var amount = $('#amount').val();
                                    if (amount == '' || typeof(amount) == 'undefined') {
                                        alert('Please input correct amount $');
                                        return;
                                    }

                                    amount = amount.toString().replace('.', ',');

                                    console.log(amount);
                                    console.log(payload);
                                    console.log(payload.nonce);

                                    $.get("/api/bt/transaction/" + amount + "/" + payload.nonce, function(data) {
                                      console.log(data);
                                      if (data.success) {
                                        if (typeof(data.message) == 'string') {
                                          alert(data.message);
                                        } else {
                                          alert('Successful transaction!');
                                        }
                                      } else {
                                        if (typeof(data.message) == 'string') {
                                          alert(data.message);
                                        } else {
                                          alert('Failed transaction :(');
                                        }
                                      }
                                    });

                                });

                            });
                        });
                    });




                } else {
                  if (typeof(data.msg) == 'string' && data.msg !== '') {
                    alert(data.msg);
                  } else {
                    alert('Error');
                  }
                }
            }).fail(function(res) {
                //console.log(res);
                alert("Error. " + res.statusText);
            });
            //*/



        });


    </script>
</body>
</html>
