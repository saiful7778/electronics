#include <LiquidCrystal_I2C.h>
#include <IRremote.h>
#include <WiFi.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <WebSerial.h>

const char* ssid = "Hatiya Express";
const char* password = "Hatiyamess1819@.";

AsyncWebServer server(80);

const int RECV_PIN = 15;

IRrecv irrecv(RECV_PIN);
decode_results results;

LiquidCrystal_I2C lcd(0x27,16,2);

void setup(){
  Serial.begin(115200);
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
  lcd.begin();
  irrecv.enableIRIn();
}

void loop(){
  if(irrecv.decode(&results)){
    WebSerial.print("DEC: ");
    WebSerial.print((String(reuslts.value)));
    WebSerial.print("   ");
    WebSerial.print("HEX: ");
    WebSerial.println((String(results.value, HEX)));
    delay(10);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("DEC: ");
    delay(10);
    irrecv.resume();
  }
  delay(1000);
}
