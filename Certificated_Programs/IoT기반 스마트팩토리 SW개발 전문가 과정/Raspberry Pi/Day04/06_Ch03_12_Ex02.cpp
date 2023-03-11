#include <stdio.h>
#include <wiringPi.h>



volatile int iToggle = 1;

void BtnPressed()
{
      iToggle = (iToggle +1) % 3;
            delay(1000);
}


int main()
{
      wiringPiSetup();

      int iPin1_led = 1;
      int iPin3_btn = 3;

      pinMode(iPin1_led, PWM_OUTPUT);
      wiringPiISR(iPin3_btn, INT_EDGE_FALLING, BtnPressed);
      
      while(1)
      {
            pwmWrite(iPin1_led,50 * iToggle);
      }
      
}