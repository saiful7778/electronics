#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <IRremote.h>
#include <BluetoothSerial.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

#if !defined(CONFIG_BT_SPP_ENABLED)
#error Serial Bluetooth not available or not enabled. It is only available for the ESP32 chip.
#endif

BluetoothSerial SerialBT;

const int recv_pin = 13;

IRrecv irrecv(recv_pin);
decode_results results;

void setup() {
  Serial.begin(115200);
  lcd.begin();
  SerialBT.begin("ESP32test"); //Bluetooth device name
  Serial.println("The device started, now you can pair it with bluetooth!");
  irrecv.enableIRIn();  
}

void loop() {
  if(irrecv.decode(&results)){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(results.value, HEX);
    irrecv.resume();
  }
  
  if (Serial.available()) {
    SerialBT.write(Serial.read());
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.write(Serial.read());
  }
  if (SerialBT.available()) {
    Serial.write(SerialBT.read());
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(SerialBT.read());
  }
  delay(20);
}