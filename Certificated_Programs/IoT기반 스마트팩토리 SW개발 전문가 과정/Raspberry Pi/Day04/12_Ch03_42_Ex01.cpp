#include <stdio.h>
#include <wiringPi.h>


#define PIN1_LED_RED                1
#define PIN24_LED_GRN          24


PI_THREAD(tGreen)
{
      pinMode(PIN24_LED_GRN, PWM_OUTPUT);
      
      pwmSetClock(19);
      pwmSetMode(PWM_MODE_MS);
      pwmSetRange(1000);

      int iStateGreen = 0;
      int iDirect = 1;

      while(1)
      {
            pwmWrite(PIN24_LED_GRN, iStateGreen);
            iStateGreen += iDirect;
            if( iStateGreen ==0 || iStateGreen == 650 )
                  iDirect *= -1;
            delay(1);
      }
      

}

int main()
{
      wiringPiSetup();

      piThreadCreate(tGreen);

      pinMode(PIN1_LED_RED, PWM_OUTPUT);

      pwmSetClock(19);
      pwmSetMode(PWM_MODE_MS);
      pwmSetRange(1000);

      int iStateRed = 0;
      int iDirect = 1;
      
      while(1)
      {
            
            pwmWrite(PIN1_LED_RED, iStateRed);
            iStateRed += iDirect;
            if( iStateRed == 0 || iStateRed == 350)
                  iDirect *= -1;
            delay(1);
      }

}