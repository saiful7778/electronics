#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <IRremote.h>
#include <BluetoothSerial.h>
#include <WiFi.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <WebSerial.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

#if !defined(CONFIG_BT_SPP_ENABLED)
#error Serial Bluetooth not available or not enabled. It is only available for the ESP32 chip.
#endif

BluetoothSerial SerialBT;

AsyncWebServer server(80);

const int RECV_PIN = 13;

const char* ssid = "DTR - Dream To Real";          // Your WiFi SSID
const char* password = "#8426#DoNoT";  // Your WiFi Password


IRrecv irrecv(RECV_PIN);
decode_results results;

void setup() {
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
  lcd.backlight();
  SerialBT.begin("ESP32test"); //Bluetooth device name
  Serial.println("The device started, now you can pair it with bluetooth!");
  irrecv.enableIRIn();
}

void display_text(char text,int posi1, int posi2){
  lcd.clear();
  delay(20);
  lcd.setCursor(posi1, posi2);
  lcd.print(text);
  delay(500);
  }

void loop() {
  if (irrecv.decode(&results)){
    const recvData = (results.value, HEX);
    display_text(recvData,0,0);
    SerialBT.println(recvData);
    irrecv.enableIRIn();
    delay(1000);
    }
  
  if (Serial.available()) {
    SerialBT.write(Serial.read());
    WebSerial.println(Serial.read());
    delay(100);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(Serial.read(), DEC);
  }
  if (SerialBT.available()) {
    Serial.write(SerialBT.read());
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(SerialBT.read());
  }
  delay(20);
}
