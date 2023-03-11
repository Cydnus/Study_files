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

      while(1)
      {
            char cInput = getchar();

            int iNote = 8;
            switch( cInput)
            {
                  case 'a':
                  case 'A':
                        iNote = 0;
                        break;
                  case 's':
                  case 'S':
                        iNote = 1;
                        break;
                  case 'd':
                  case 'D':
                        iNote = 2;
                        break;
                  case 'f':
                  case 'F':
                        iNote = 3;
                        break;
                  case 'g':
                  case 'G':
                        iNote = 4;
                        break;
                  case 'r':
                  case 'R':
                        iNote = 5;
                        break;
                  case 'i':
                  case 'I':
                        iNote = 6;
                        break;
                  case 'k':
                  case 'K':
                        iNote = 7;
                        break;
            }

            if(iNote!=8)
            {
                  pwmSetRange(1000000/melody[iNote]);
                  pwmWrite(PIN24_BUZZER,1000000/melody[iNote]/2);
                  delay(500);
                  pwmWrite(PIN24_BUZZER,0);
                  iNote = 8;
            }


      }


      return 0;
}