//==================================
//ESP32 WebSocket Server: Toggle LED
//by: Ulas Dikme
//==================================
#include <WiFi.h>
#include <WiFiClient.h>
#include <WebServer.h>
//---------------------------------------------------
WebServer server(80);
//-----------------------------------------------
const char* ssid = "DTR - Dream To Real";
const char* password = "#8426#DoNoT";
//-----------------------------------------------
#define LED 2
//-----------------------------------------------
boolean LEDonoff=false; String JSONtxt;
//-----------------------------------------------
#include "html_page.h"
#include "functions.h"
//====================================================================
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
//====================================================================
void loop()
{
  webSocket.loop(); server.handleClient();
  //-----------------------------------------------
  if(LEDonoff == false) digitalWrite(LED, LOW);
  else digitalWrite(LED, HIGH);
  //-----------------------------------------------
  String LEDstatus = "OFF";
  if(LEDonoff == true) LEDstatus = "ON";
  JSONtxt = "{\"LEDonoff\":\""+LEDstatus+"\"}";
  webSocket.broadcastTXT(JSONtxt);
}
