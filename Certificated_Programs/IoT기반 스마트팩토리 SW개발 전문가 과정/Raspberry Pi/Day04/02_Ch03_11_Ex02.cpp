#include <stdio.h>
#include <wiringPi.h>

#define PIN1_LED  1

int main()
{
      wiringPiSetup();

      pinMode(PIN1_LED , PWM_OUTPUT);

      while(1)
      {
            char cInput = getchar();

            if( cInput == '0' )
                  pwmWrite(PIN1_LED, 0);
            else if  (cInput == '5' )
                  pwmWrite(PIN1_LED, 50);            
            else if  (cInput == 't'  ||cInput == 'T' )
                  pwmWrite(PIN1_LED, 100);            
            else if  (cInput == 'q' ||cInput == 'Q' )
                  break;
      }
      return 0;
}