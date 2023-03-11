#include<stdio.h>
#include <wiringPi.h>

#define PIN24_BUZZER    24

int main()
{
      wiringPiSetup();

	const int melody[] = {262,294,330,349,392,440,494,523};

      pinMode(PIN24_BUZZER, PWM_OUTPUT);

	pwmSetClock(19);
	pwmSetMode(PWM_MODE_MS);

      pwmSetRange(1000000/50);
      while(1)
      {
            char cInput = getchar();

            int iNote = 8;
            switch( cInput)
            {
                  case 'q':
                  case 'Q':
                        pwmWrite(PIN24_BUZZER,600);
                        break;
                  case 'w':
                  case 'W':
                        pwmWrite(PIN24_BUZZER,1560);
                        break;
                  case 'e':
                  case 'E':
                        pwmWrite(PIN24_BUZZER,2500);
                        break;
            }

            if(iNote!=8)
            {
                  pwmWrite(PIN24_BUZZER,1000000/melody[iNote]/2);
                  delay(500);
                  iNote = 8;
            }


      }


      return 0;
}