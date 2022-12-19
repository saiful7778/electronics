#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <IRremote.h>
#include <WiFi.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <WebSerial.h>

const char* ssid = "Galaxy A12E25";          // Your WiFi SSID
const char* password = "12345679";  // Your WiFi Password

LiquidCrystal_I2C lcd(0x27, 16, 2);

AsyncWebServer server(80);

const int RECV_PIN = 15;

IRrecv irrecv(RECV_PIN);
decode_results results;

void setup(){
  Serial.begin(115200);
  lcd.begin();
  lcd.backlight();
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  if (WiFi.waitForConnectResult() != WL_CONNECTED) {
    Serial.printf("WiFi Failed!\n");
    return;
  }
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());
  // WebSerial is accessible at "<IP Address>/webserial" in browser
  WebSerial.begin(&server);
  server.begin();
  irrecv.enableIRIn();
}
void loop(){
  if (irrecv.decode(&results)){
     WebSerial.print("DEC:  ")
     WebSerial.print((results.value));
     WebSerial.print("  ");
     WebSerial.print("HEX: ")
     WebSerial.println((String(results.value, HEX)));
     delay(10);
     Serial.print("DEC: ");
     Serial.print(results.value, DEC);
     Serial.print(" ");
     Serial.print("HEX: ");
     Serial.println(results.value, HEX);
     delay(10);
     lcd.clear();
     lcd.setCursor(0,0);
     lcd.print("DEC:");
     lcd.setCursor(5,0);
     lcd.print(results.value, DEC);
     lcd.setCursor(0,1);
     lcd.print("HEX: 0x");
     lcd.setCursor(7,1);
     lcd.print(results.value, HEX);
     delay(10);
     irrecv.resume();
  }
  delay(2000);
}
