#include <stdio.h>
#include <wiringPi.h>

#define PIN0_LED  0

int main()
{
      wiringPiSetup();

      pinMode(PIN0_LED , OUTPUT);

      while(1)
      {
            char cInput = getchar();
            if( cInput == 'N' ||cInput == 'n' )
                  digitalWrite(PIN0_LED, LOW);
            else if  (cInput == 'F' ||cInput == 'f' )
                  digitalWrite(PIN0_LED, HIGH);
            else if  (cInput == 'q' ||cInput == 'Q' )
                  break;
      }
      return 0;
}