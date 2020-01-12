#include <ESP8266WiFi.h>

void initSerial(int baud) {
  Serial.begin(baud);
  delay(2000);
  Serial.println("Serial communication initiated.");
}

void initWifi() {
  Serial.println("Wifi communication initiated. Please wait...");
  
  while(WiFi.status() != WL_CONNECTED) { 
    WiFi.begin(WIFI_SSID, WIFI_PASS);
    delay(10000);
  }

  Serial.printf("Connected to Wifi Network %s \r\n", WIFI_SSID);
  Serial.print("IP-Address: ");
  Serial.println(WiFi.localIP());
}

void initWebServer() {
  webserver.on("/", login);
  webserver.on("/login", HTTP_POST, validateLogin);
  webserver.on("/overview", overview);
  webserver.begin();
  
  Serial.println("Webserver initiated and started.");
}
