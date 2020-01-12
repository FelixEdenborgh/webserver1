/*
 *  Glöm inte andra WIFI_SSID och WIFI_PASS i config.h 
 *  Gå in och ändra e-postkontot och lösenordet i config.h
 *  eller använd e-postadressen user@domain.com och lösenordet BytMig123
 */

#include <ESP8266WebServer.h>
ESP8266WebServer webserver(80);

#include "config.h"             // innehåller inställningar som ssid etc.
#include "websites.h"           // innehåller alla hemsidor som används
#include "functions.h"          // innehåller alla init-funktioner


void setup() {
  initSerial(115200);           
  initWifi();                   
  initWebServer();              
}

void loop() {
  webserver.handleClient();
}
