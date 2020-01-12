void login() {
  webserver.send(200, "text/html", "<!doctype html><html><head><meta charset='utf-8'><meta name='viewport' content='width=device-width, initial-scale=1, shrink-to-fit=no'><title>Login - Webserver</title><link rel='stylesheet' href='https://stackpath.bootstrapcdn.com/bootstrap/4.2.1/css/bootstrap.min.css'><link rel='stylesheet' href='https://www.epndata.com/iot18/demo/css/style.css'></head><body class='text-center'><form action='/login' method='post' class='form-signin'><h1 class='h3 mb-3 font-weight-normal'>Please sign in</h1><label for='inputEmail' class='sr-only'>Email address</label> <input type='email' name='inputEmail' id='inputEmail' class='form-control' placeholder='Email address' required autofocus> <label for='inputPassword' class='sr-only'>Password</label> <input type='password' name='inputPassword' id='inputPassword' class='form-control' placeholder='Password' required> <button class='btn btn-lg btn-primary btn-block' type='submit'>Sign in</button><p class='mt-5 mb-3 text-muted'>&copy; 2019 IoT18 Nackademin.</p></form></body></html>");
}

void validateLogin() {
  if(webserver.args() > 0) {
    for(uint8_t i = 0; i < webserver.args(); i++) {
      
      if(webserver.argName(i) == "inputEmail") {
        if(webserver.arg(i) == user_email) {
          Serial.println("E-postadressen stämmer");
          emailCheck = true;
        }
      }
      
      if(webserver.argName(i) == "inputPassword") {
        if(webserver.arg(i) == user_password) {
          Serial.println("Lösenordet stämmer");
          passwordCheck = true;
        }
      }
    }
  }
  if(emailCheck && passwordCheck) {
    webserver.sendHeader("Location", "/overview");
    webserver.send(303);
  } else {
    webserver.sendHeader("Location", "/");
    webserver.send(303);   
  }
}

void overview() {
  webserver.send(200, "text/html", "<h1>Overview</h1>");
}
