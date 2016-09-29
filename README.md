# geia_api

Environment:
    - Drupal 7
        services
        views
        rest
        
    - MySQL
    
    
    
#API
https://api.geiafit.com/api

##USER:
   Login POST: /user/login
      formdata: username and password
      
   returns user oject and : session_id , session_name and token
   
   All subsequent requests need to be made with Cokkie and Token in the header
   Cooke = session_name+'='+session_id
   Token = token
   
   Example:
    "sessid": "lMaG__9q3BRep76TfR1jDYWiGHPtZEmQxygqPZ7AOGU",
    "session_name": "SESS5dc4399c78481c1276416448d9e45919",
    "token": "tY35Ns_7TU6ktjz6pmF4R7oKwxGS3V6Hv9Ig7cG-r6M",
    
    get user profile GET: profile/1
	```sh
    header: Cookie: SESS5dc4399c78481c1276416448d9e45919=lMaG__9q3BRep76TfR1jDYWiGHPtZEmQxygqPZ7AOGU
            Token: tY35Ns_7TU6ktjz6pmF4R7oKwxGS3V6Hv9Ig7cG-r6M
	```
			
			
	Logout POST: user/logout
            
##Profile:
   Show GET: profile/1 :returns user profile: 
          1.Firstname
          2.Lastname
          3.DOB
          4.Address
          5.Goals
		  
```json
 {
   "email": "xxx@email.com",
   "first_name": "Fname",
   "last_name": "Lname",
   "dob": 1463986800,
   "gender": "2",
   "image": "http://local.geia.com/sites/default/files/Jiri_Plsek.png",
   "goals": [
     "Lose Weight",
     "Relieve Pain",
     "Improve Posture",
     "Manage Recovery"
   ],
   "gems": "48"
 }
```

  Update Put:  profile/37
  
  Data: 
  ```json
  {
    "email": "xxx@email.com",
    "first_name": "Sam",
    "last_name": "Plsek",
    "dob": 163580400,
    "gender": "2",
	"password": "123456",
    "goals": [
      "Eat Healthy",
      "Improve Posture",
      "Improve Overall Health"
    ],
    "gems": "2",
	"field_onboarded": 1
  }
  ```
  Reponse:
  ```json
  {
    "email": "xxx@email.com",
    "first_name": "Sam",
    "last_name": "Plsek",
    "dob": 163580400,
    "gender": "2",
    "image": "http://local.geia.com/sites/default/files/Jiri_Plsek.png",
    "goals": [
      "Eat Healthy",
      "Improve Posture",
      "Improve Overall Health"
    ],
    "gems": "342"
  }
  ```
  
###Update Profile Image:
  image data is base64encoded
  
  Post: profile/profileimage/1
  
  Data:
  
  ```json
	 {"image_name":"Carlos_Villarreal.png",
	    "image":"iVBORw0KGgoAAAANSUhEUgAAANAAAADQCAYAAAB2pO90AAAAAXNSR0IArs4c6QAAABxpRE9UAAAAAgAAAAAAAABoAAAAKAAAAGgAAABoAADCzmUR6s4AAEAASURBVHgBVL33m19Zdadb\/8B9POP73KHpnHM3ndRqqRVaOatyzjlXqUollapKKuWW1Eqt3JEcbWwaTDYDxoAxYOMABodxNhh7zIzDzDhgs+d91z5H3feH\/Zx8vmm957PW2mvvb8Wrrx9Jr7xyML3y8mJ66dpCXr58IF2+Op8uXplPL17cky5c2pfOX5hNFy+xfWkunT0\/k86f30tzSXtxluPu35teOD2dzpzdzb596dyLe9M5r7u8n2Oz6eQL0+nQ4ZG0\/8BA2jfbm\/bM9KTpXV1pbKgx9XZVp97uOlpt6umoSr2dVamH1t9bS6tLgwONaWigKQ32NabR4eY0MdaaJsda0u7pzjS7r597DqUDh0bS\/MJAOnBgMM3tH0yz831p33xvWtg\/kPbO9qSZmS5aZ5rZ051mdnel3bu7066pDvbxPti\/a7oj9s3O9nG8k\/WOtGdPV9qzj\/P39rDkHvvY5l5Te9rzOvv2zfk6fWl2rjft3tvJ8a40vYf77u1Oe2x7OtP07vY0NdXOso3XaUtTvNYutien3GY\/25OTrezjc9HGx5vS2HhLGuMzjo02p\/GxpjTK0n3DI41pZKQpDQ3yvfXw\/fTU01zWpYE+1\/keu2pTdzvfaWdt6mrj+4ztytTdyT7W+\/muu9p3pk6OdXfUxHfvsY62nVxXlTpat6eerhp+A+7D79HDsa62Sq6t45rK1NlK47yezhrOr0ldHRynua\/bdfZ38fp9vI73jfuwr63d9+AxzvNaWn9fQ\/zufX6O3oa43s80wG\/d30vraUhDfU1pgPU+7KPPz9nP56cND7SkwX....."
		}
  ```
###Request Password Reset:

  Post: profile/profile/pwdreset
  
  Data:
  
  ```json
  {
      "email":"george@plsek.us"
  }
  ```
  
###Create new (Selft PT) patient:

  Post: profile/createpatient/1
  
  Data:
  
  ```json
  {
	      "email":"blah@email.com",
	      "firstname":"firstname",
	      "lastname":"lastname"
  }
  ```
  
  Response:
   - Error
  
  ```json
  {
   "success": 0,
   "message": "User with this email already exists",
   "email": "blah@email.com"
  }
  ```
  
   -Success
   
   ```json
   {
     "success": 1,
     "email": "blah@plccccsek.us",
     "first_name": "bal",
     "last_name": "lastname"
   }
   
   ```

  
  
    

    
    
    
