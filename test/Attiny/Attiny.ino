//#include <IRremote.h>

int LED_PIN = 0;
int du_led_pin = 2;

bool high = false;

int togglestate = 0;

int RECV_PIN = 1;
//IRrecv irrecv(RECV_PIN);
//decode_results results;

void setup()
{
  pinMode(RECV_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  pinMode(du_led_pin, OUTPUT);
//  irrecv.enableIRIn();
}
void loop() {
  unsigned long duration = pulseIn(RECV_PIN, HIGH);
  if(duration == 2242){
    if(togglestate == 0){
      digitalWrite(LED_PIN, HIGH);
      togglestate=1;
      }else{
        digitalWrite(LED_PIN, LOW);
        togglestate=0;
      }
  }
//  if (irrecv.decode(&results))
//  {
//    if (results.value == 0xFF30CF)
//    {
//      high =! high;
//      digitalWrite(LED_PIN, high);
//      delay(10);
//    }
//    irrecv.resume();
//  }
}
