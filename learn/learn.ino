#include <LiquidCrystal_I2C.h>
#include <IRremote.h>

const int RECV_PIN = 15;

IRrecv irrecv(RECV_PIN);
decode_results results;

LiquidCrystal_I2C lcd(0x27,16,2);

void setup() {
  Serial.begin(115200);
  lcd.begin();
  lcd.backlight();
  irrecv.enableIRIn();
}

void loop() {
  if(irrecv.decode(&results)){
    Serial.print("DEC: ");
    Serial.print(results.value, DEC);
    Serial.print("");
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
  delay(1000);
}
