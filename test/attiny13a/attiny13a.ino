int ir_led = 0;
int led = 2;

bool high = false;

void setup() {
  pinMode(ir_led, INPUT);
  pinMode(led, OUTPUT);
}

void loop() {
  unsigned long duration = pulseIn(ir_led, HIGH);
  if(duration == 2243){
    high =! high;
    digitalWrite(led, high);
    delay(100);
  }
}
