#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <IRremote.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <WebSerial.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

// set all relay pin
const int relay_1 = 18;
const int relay_2 = 5;
const int relay_3 = 13;
const int relay_4 = 2;

// Set wifi
const char* ssid = "DTR - Dream To Real";          // Your WiFi SSID
const char* password = "#8426#DoNoT";  // Your WiFi Password
AsyncWebServer server(80);

//set toggle state
int togglestate_1 = 0;
int togglestate_2 = 0;
int togglestate_3 = 0;
int togglestate_4 = 0;

//set ir remote
const int RECV_PIN = 15;
IRsend irsend;
IRrecv irrecv(RECV_PIN);
decode_results results;

// set lcd display off
void lcdOff(int delayValue){
  delay(delayValue);
  lcd.noBacklight();
}

//reciver data from webserial
void recvMsg(uint8_t *data, size_t len){
  WebSerial.println("Received Data...");
  String d = "";
  for(int i=0; i < len; i++){
    d += char(data[i]);
  }
  if(d == "relay 1"){
    if(togglestate_1 == 0){
      digitalWrite(relay_1, HIGH);
      delay(10);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Relay 1 ON");
      delay(10);
      WebSerial.println("Relay 1 ON");
      togglestate_1 = 1;
    }else{
      digitalWrite(relay_1, LOW);
      delay(10);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Relay 1 OFF");
      delay(10);
      WebSerial.println("Relay 1 OFF");
      togglestate_1 = 0;
    }
  }
  if(d == "relay 2"){
    if(togglestate_2 == 0){
      digitalWrite(relay_2, HIGH);
      delay(10);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Relay 2 ON");
      delay(10);
      WebSerial.println("Relay 2 ON");
      togglestate_2 = 1;
    }else{
      digitalWrite(relay_2, LOW);
      delay(10);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Relay 2 OFF");
      delay(10);
      WebSerial.println("Relay 2 OFF");
      togglestate_2 = 0;
    }
  }
  if(d == "relay 3"){
    if(togglestate_3 == 0){
      digitalWrite(relay_3, HIGH);
      delay(10);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Relay 3 ON");
      delay(10);
      WebSerial.println("Relay 3 ON");
      togglestate_3 = 1;
    }else{
      digitalWrite(relay_3, LOW);
      delay(10);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Relay 3 OFF");
      delay(10);
      WebSerial.println("Relay 3 OFF");
      togglestate_3 = 0;
    }
  }
  if(d == "relay 4"){
    if(togglestate_4 == 0){
      digitalWrite(relay_4, HIGH);
      delay(10);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Relay 4 ON");
      delay(10);
      WebSerial.println("Relay 4 ON");
      togglestate_4 = 1;
    }else{
      digitalWrite(relay_4, LOW);
      delay(10);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Relay 4 OFF");
      delay(10);
      WebSerial.println("Relay 1 OFF");
      togglestate_4 = 0;
    }
  }
}

void setup(){
  Serial.begin(115200);
  pinMode(relay_1, OUTPUT);
  pinMode(relay_2, OUTPUT);
  pinMode(relay_3, OUTPUT);
  pinMode(relay_4, OUTPUT);
  lcd.begin();
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  if (WiFi.waitForConnectResult() != WL_CONNECTED) {
    Serial.printf("WiFi Failed!\n");
    return;
  }
  Serial.print("IP Address: ");
  Serial.print(WiFi.localIP());
  Serial.println("/webserial");
  // WebSerial is accessible at "<IP Address>/webserial" in browser
  WebSerial.begin(&server);
  server.begin();
  WebSerial.msgCallback(recvMsg);
  irrecv.enableIRIn();
}
void loop(){
  lcd.setCursor(0,1);
  lcd.print(WiFi.localIP());
  if (irrecv.decode(&results)){
    lcd.backlight();
     switch(results.value){
      case 0xFFA25D:
        if(togglestate_1 == 1){
          digitalWrite(relay_1, LOW);
          delay(10);
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("Relay 1 OFF");
          delay(10);
          WebSerial.println("Relay 1 OFF");
          togglestate_1 = 0;
        }
        if(togglestate_2 == 1){
          digitalWrite(relay_2, LOW);
          delay(10);
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("Relay 2 OFF");
          delay(10);
          WebSerial.println("Relay 2 OFF");
          togglestate_2 = 0;
        }
        if(togglestate_3 == 1){
          digitalWrite(relay_3, LOW);
          delay(10);
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("Relay 3 OFF");
          delay(10);
          WebSerial.println("Relay 3 OFF");
          togglestate_3 = 0;
        }
        if(togglestate_4 == 1){
          digitalWrite(relay_4, LOW);
            delay(10);
            lcd.clear();
            lcd.setCursor(0,0);
            lcd.print("Relay 4 OFF");
            delay(10);
            WebSerial.println("Relay 4 OFF");
            togglestate_4 = 0;
        }
        break;
      case 0xFF30CF:
        if(togglestate_1 == 0){
          digitalWrite(relay_1, HIGH);
          delay(10);
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("Relay 1 ON");
          delay(10);
          WebSerial.println("Relay 1 ON");
          togglestate_1 = 1;
        }else{
          digitalWrite(relay_1, LOW);
          delay(10);
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("Relay 1 OFF");
          delay(10);
          WebSerial.println("Relay 1 OFF");
          togglestate_1 = 0;
        }
        break;
      case 0xFF18E7:
        if(togglestate_2 == 0){
          digitalWrite(relay_2, HIGH);
          delay(10);
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("Relay 2 ON");
          delay(10);
          WebSerial.println("Relay 2 ON");
          togglestate_2 = 1;
        }else{
          digitalWrite(relay_2, LOW);
          delay(10);
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("Relay 2 OFF");
          delay(10);
          WebSerial.println("Relay 2 OFF");
          togglestate_2 = 0;
        }
        break;
      case 0xFF7A85:
      if(togglestate_3 == 0){
          digitalWrite(relay_3, HIGH);
          delay(10);
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("Relay 3 ON");
          delay(10);
          WebSerial.println("Relay 3 ON");
          togglestate_3 = 1;
        }else{
          digitalWrite(relay_3, LOW);
          delay(10);
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("Relay 3 OFF");
          delay(10);
          WebSerial.println("Relay 3 OFF");
          togglestate_3 = 0;
        }
        break;
      case 0xFF10EF:
        if(togglestate_4 == 0){
            digitalWrite(relay_4, HIGH);
            delay(10);
            lcd.clear();
            lcd.setCursor(0,0);
            lcd.print("Relay 4 ON");
            delay(10);
            WebSerial.println("Relay 4 ON");
            togglestate_4 = 1;
          }else{
            digitalWrite(relay_4, LOW);
            delay(10);
            lcd.clear();
            lcd.setCursor(0,0);
            lcd.print("Relay 4 OFF");
            delay(10);
            WebSerial.println("Relay 4 OFF");
            togglestate_4 = 0;
          }
        break;
     }
     irrecv.resume();
  }
  lcdOff(2000);
}
