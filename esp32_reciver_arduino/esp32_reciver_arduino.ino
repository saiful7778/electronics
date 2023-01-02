#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <WebServer.h>
#include <IRremote.h>
#include <ESPmDNS.h>
#include <WebSocketsServer.h>
#include <ArduinoJson.h>
//#include <Ticker.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

// set all relay pin
const int relay_1 = 18;
const int relay_2 = 5;
const int relay_3 = 13;
const int relay_4 = 2;

void sendData();
//Ticker timer;

// Set wifi
const char* ssid = "DTR - Dream To Real";          // Your WiFi SSID
const char* password = "#8426#DoNoT";  // Your WiFi Password

WebServer server(80);
WebSocketsServer webSocket = WebSocketsServer(81);

#include "webpage.h"
#include "handlefunctions.h"

//set ir remote
const int RECV_PIN = 15;
//IRsend irsend;
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup(){
  Serial.begin(115200);
  pinMode(relay_1, OUTPUT);
  pinMode(relay_2, OUTPUT);
  pinMode(relay_3, OUTPUT);
  pinMode(relay_4, OUTPUT);
  WiFi.begin(ssid, password);
  while(WiFi.status() != WL_CONNECTED){Serial.print("."); delay(500);}
  WiFi.mode(WIFI_STA);
  Serial.println(WiFi.localIP());
  if (MDNS.begin("DTR_HOME")) { //esp.local/
    Serial.println("MDNS responder started");
  }
  //-----------------------------------------------
  server.on("/", webpage);
  server.onNotFound(notFound);
  //-----------------------------------------------
  server.begin(); webSocket.begin();
  webSocket.onEvent(webSocketEvent);
  lcd.begin();
  irrecv.enableIRIn();
}
void loop(){
  server.handleClient();
  webSocket.loop();
}
