#include <stdio.h>
#include <wiringPi.h>



volatile int iToggle = 1;

void BtnPressed()
{
      iToggle *= -1;
      delay(100);
}


int main()
{
      wiringPiSetup();

      int iPin0_led = 0;
      int iPin3_btn = 3;

      pinMode(iPin0_led, OUTPUT);
      wiringPiISR(iPin3_btn, INT_EDGE_FALLING, BtnPressed);

      

      while(1)
      {
            if(iToggle > 0)
            {
                  digitalWrite(iPin0_led,HIGH);
            } 
            else if(iToggle < 0)
            {
                  digitalWrite(iPin0_led,LOW);
            }
            delay(100);
      }
      
}