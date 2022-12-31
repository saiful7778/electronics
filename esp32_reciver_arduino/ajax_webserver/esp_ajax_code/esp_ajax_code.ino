//========================================================
//ESP32 Web Server: Reading Potentiometer Value using AJAX
//========================================================
#include <WiFi.h>
#include <WiFiClient.h>
#include <WebServer.h>
#include "webpage.h"
//---------------------------------------------------
WebServer server(80);
const char* ssid = "DTR - Dream To Real";
const char* password = "#8426#DoNoT";
//---------------------------------------------------
#include "handleFunctions.h"
//===================================================
void setup()
{
  Serial.begin(115200);
  //-------------------------------------------------
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.println("Connecting to WiFi");
  while(WiFi.waitForConnectResult() != WL_CONNECTED)
  {
    delay(500); Serial.print(".");
  }
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  //-------------------------------------------------
  server.on("/", handleRoot);
  server.on("/readPOT", handlePOT);
  server.begin();
  Serial.println("HTTP server started");
}
//===================================================
void loop(void)
{
  server.handleClient(); delay(1);
}
