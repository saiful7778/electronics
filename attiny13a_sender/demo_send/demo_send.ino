//Remote Control Transmitter Original ATtiny13A 20191021 2000
#include <avr/io.h>
#define F_CPU 9600000UL
#include <util/delay.h>
#include <avr/interrupt.h>
#include <avr/sleep.h>

uint8_t custom=0x99;
uint8_t data;
int8_t i,t;

#define on OCR0A=85; //Duty Cycle 1/3
#define off OCR0A=0;

ISR(PCINT0_vect){}

void infrared(){

  GIMSK&=~(1<<5);
  on;_delay_us(9000);off;_delay_us(4500); //Leader  

  for(i=0;i<8;i++){ //Custom
    on;_delay_us(562);off;
    if((custom>>(7-i))&1){_delay_us(1686);}else{_delay_us(562);}
  }

  if(~PINB & 0x02){data=0x01;} //PB1 Turn on
  if(~PINB & 0x04){data=0x02;} //PB2 Turn on
  if(~PINB & 0x08){data=0x03;} //PB3 Turn on
  if(~PINB & 0x10){data=0x04;} //PB4 Turn on

  for(i=0;i<8;i++){ //Data
    on;_delay_us(562);off;
    if((data>>(7-i))&1){_delay_us(1686);}else{_delay_us(562);}
  }

  on;_delay_us(562);off;_delay_ms(42); //Stop+Blank

  while(~PINB & 0x1E){ //Repeat
    on;_delay_us(1000);off;_delay_ms(50);
  }
  data=0;
  GIMSK|=(1<<5);
}

int main( void ){

  CLKPR =0b10000000; //Prescaler Change Enable
  CLKPR =0b00000000; //Div1(9.6MHz)

  DDRB  =0b00000001; //PB0:Infrared LED
  PORTB =0b00011110; //PB4-1:Switch

  TCCR0A=0b10000011; //Subcarrier
  TCCR0B=0b00000001;

  GIMSK =0b00100000; //PCINT Enable
  PCMSK =0b00011110; //PCINT4-1
  MCUCR =0b00110000; //Sleep Enable, Power Down Mode
  sei();

  while(1){

    if(~PINB & 0x1E){infrared();}

    sleep_mode(); //Power Down

  }
}//int main
