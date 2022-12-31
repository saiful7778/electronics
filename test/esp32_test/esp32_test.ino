#include <Wire.h>
#include <LiquidCrystal_I2C.h>
//#include <IRremote.h>
//
//const uint16_t kIrLed = 4;
//
//IRsend irsend(kIrLed);

LiquidCrystal_I2C lcd(0x27, 16, 2);

//const int RECV_PIN = 15;
//IRrecv irrecv(RECV_PIN);
//decode_results results;

void setup() {
  Serial.begin(115200);
}

void loop() {
  lcd.setCursor(0,0);
  lcd.print("Saiful Islam");
//irsend.sendSony(0xa8305E8, 24, 1);
//  if(irrecv.decode(&results)){
//    unsigned long onTime = pulseIn(RECV_PIN, HIGH);
//    Serial.print("DEC: ");
//    Serial.print(results.value, DEC);
//    Serial.print("  ");
//    Serial.print("HEX: ");
//    Serial.print(results.value, HEX);
//    Serial.print("  ");
//    Serial.print("on_time: ");
//    Serial.println(onTime);
//    lcd.clear();
//    lcd.setCursor(0,0);
//    lcd.print(results.value, DEC);
//    lcd.setCursor(0,1);
//    lcd.print(onTime);
//    delay(10);
//    irrecv.resume();
//  }
  
}
