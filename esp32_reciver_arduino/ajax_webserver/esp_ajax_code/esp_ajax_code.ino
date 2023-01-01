//========================================================
//ESP32 Web Server: Reading Potentiometer Value using AJAX
//========================================================
#include <WiFi.h>
#include <WiFiClient.h>
#include <WebServer.h>
#include "webpage.h"
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
//---------------------------------------------------
WebServer server(80);
const char* ssid = "DTR - Dream To Real";
const char* password = "#8426#DoNoT";
//---------------------------------------------------
#include "handleFunctions.h"
//===================================================
void setup()
{
  lcd.begin();
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
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print(WiFi.localIP());
  server.handleClient(); delay(1);
  lcd.noBacklight();
}
