*/15 * * * * wget -O - -q -t 1 http://geiafit.dev.cpcs.ws/cron.php?cron_key=buRDQ3mx08mDqCog2TtQr6lcmaX3BmyGv5_vW3ab-8E

Алгорит работы с API:
--------------------
1) Все запросы должны быть авторизированы в системе Drupal:
   Цитата из: (https://github.com/gplsek/geia_api)

   Login POST: /user/login formdata: username and password
   returns user oject and : session_id , session_name and token
   All subsequent requests need to be made with Cokkie and Token in the header Cooke = session_name+'='+session_id Token = token
   Example: "sessid": "lMaG__9q3BRep76TfR1jDYWiGHPtZEmQxygqPZ7AOGU", "session_name": "SESS5dc4399c78481c1276416448d9e45919", "token": "tY35Ns_7TU6ktjz6pmF4R7oKwxGS3V6Hv9Ig7cG-r6M",
   get user profile GET: profile/1
   ```sh
   header: Cookie: SESS5dc4399c78481c1276416448d9e45919=lMaG__9q3BRep76TfR1jDYWiGHPtZEmQxygqPZ7AOGU
           Token: tY35Ns_7TU6ktjz6pmF4R7oKwxGS3V6Hv9Ig7cG-r6M
   ```
   Logout POST: user/logout


2) При загрузке приложения делаем вызов API:
   http://geiafit.dev.cpcs.ws/api/bt/subscription

   Данный метод возвращает текущее состояние подписки.
   Пример результата и основные действия по интерпритированию результата:
   {
     "success": true,
     "logged": true,
     "action": "subscription",
     "param1": null,
     "param2": null,
     "param3": null,
     "client_name": "Jiri Plsek",
     "created_date": "2016-09-16 12:31:55",
     "last_payment_date": null,
     "geia_subscriptions_number_free_days": "0",
     "free": false,
     "expired": true,
     "need_input_payment_info": false,
     "block": true,
     "plans": [
       {
         id: 1,
         price: 150,
         period: 1
       },
       {
         id: 2,
         price: 130,
         period: 3
       }
     ],
     "status": "submitted_for_settlement",
     "brief_payment_info": {
       "bin": "411111",
       "last_4": null,
       "expiration_date": "10/2019"
     }
   }

   Основные поля результата которые нужно обробатывать в клиентском приложении:

   free     - показывает действует беслатный период пользования приложением или нет, если true - позволяем приложению работать
   expired  - показывает что текущая подписка истекла
   need_input_payment_info - показывает что нужно запросить платежную информацию у клиента через BrainTree API for IOS
                             (https://developers.braintreepayments.com/guides/client-sdk/setup/ios/v4)
   (так же возвращается поле token которое нужно для выполнения данной процелуры) в результате отправки платежной информации
   в BrainTree получаете токен nonceFromTheClient, который используется при вызове метода http://geiafit.dev.cpcs.ws/api/bt/payment/
   block    - если данное поле установлено в true - это показывает что подписка просрочена, но существует ранее созданная платежная транзакция,
              которая обробатывается банком. В данном случа показать сообщение клиенту что платеж обробатывается и блокировать дальнейшую работы приложения.
   plans   - список доступных тарифных планов - нужно пользователю предложить выбор из них:
            (price - цена за месяц на периоде period в месяцах, чем больше период тем дешевле обходится цена за 1 месяц, принцип оптовой покупки)

3) http://geiafit.dev.cpcs.ws/api/bt/payment/<plan_id>/<nonceFromTheClient>/?discount=<discount_code>
   Данный метод API вызывается в случаи значении true поля need_input_payment_info, в дальнейшем списание будет происходить автоматически на стороне сервера.
   Поле need_input_payment_info может опять принять значение true в случаи, если ранее введенная карта перестала быть актуальна (заблокирована, кончились деньги, перестали проходить транзакции и т.д.)

   <plan_id> - id тарифного плана выбранного клиентом на предыдущем этапе
   nonceFromTheClient     - клиенткский токен который получали при значении true поля need_input_payment_info


