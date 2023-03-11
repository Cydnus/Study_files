#include <stdio.h>
#include <wiringPi.h>

volatile int iState = 0;

void BtnPreesed()
{
      iState = ( iState + 1 ) % 3 ;
}

int main()
{
      int iPin3_btn = 3;
      int iPin24_servo = 24;

      wiringPiSetup();

      pinMode(iPin24_servo , PWM_OUTPUT);
      wiringPiISR(iPin3_btn, INT_EDGE_RISING, BtnPreesed);

      pwmSetClock(19);
      pwmSetMode(PWM_MODE_MS);

      pwmSetRange(1000000 / 50) ;
      while(1)
      {
            if(iState == 0)
            {
                  pwmWrite(iPin24_servo, 600);
            }
            else if (iState == 1)
            {
                  pwmWrite(iPin24_servo, 1550);
            }
            else
            {
                  pwmWrite(iPin24_servo, 2500);
            }
            delay(500);

      }



}