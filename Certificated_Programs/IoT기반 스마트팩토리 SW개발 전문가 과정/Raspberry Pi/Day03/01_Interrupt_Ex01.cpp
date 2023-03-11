#include <stdio.h>
#include <wiringPi.h>

volatile int iLed_state = LOW;
volatile int iLed_state_changed = 0;

void buttonPressed(void)
{
      iLed_state = (iLed_state == LOW) ? HIGH:LOW;
      iLed_state_changed = 1;
}

int main()
{
      const int iPin2_btn = 2;
      const int iPin3_led = 3;

      wiringPiSetup();

      pinMode(iPin3_led, OUTPUT);      
      wiringPiISR(iPin2_btn, INT_EDGE_RISING, buttonPressed) ;

      while(1)
      {
            if( iLed_state_changed == 1) 
            {
                  iLed_state_changed = 0;
                  digitalWrite(iPin3_led, iLed_state);
            }
      }

}