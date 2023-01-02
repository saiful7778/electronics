#ifdef ESP8266
#include <ESP8266WiFi.h>
#include <ESP8266mDNS.h>
#elif defined(ESP32)
//#include <WiFi.h>
#include <ESPmDNS.h>
#else
#error "Board not found"
#endif


#include <ESPAsyncWebServer.h>

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
