#include <stdio.h>
#include <wiringPi.h>

#define PIN0_LED_RED   0
#define PIN1_LED_BLUE   1
#define PIN24_SERVO   24

void ShowMenu()
{
      printf("===<MENU>===\n");
      printf(" n : 빨강색 LED 켜기\n");
      printf(" f : 빨강색 LED 끄기\n");
      printf(" 0 : 파란색 LED 밝기 \t0%\n");
      printf(" 5 : 파란색 LED 밝기 \t50%\n");
      printf(" t : 파란색 LED 밝기 \t100%\n");
      printf(" q : Servo\t180도\n");
      printf(" w : Servo\t90도 \n");
      printf(" e : Servo\t0도 \n");
}

void PWM_LED(int iBright)
{
      pwmSetClock(32);
      pwmSetMode(PWM_MODE_BAL);
      pwmSetRange(1024);
      pwmWrite(PIN1_LED_BLUE,iBright);
}

void PWM_Servo(int iAngle)
{
      pwmSetClock(19);
      pwmSetMode(PWM_MODE_MS);
      pwmSetRange(1000000/50);
      pwmWrite(PIN24_SERVO,iAngle);
}


int main()
{
      ShowMenu();
      wiringPiSetup();

      pinMode(PIN0_LED_RED, OUTPUT);
      pinMode(PIN1_LED_BLUE, PWM_OUTPUT);
      pinMode(PIN24_SERVO, PWM_OUTPUT);


      while(1)
      {
            char cUserInput = getchar();

            if( cUserInput == 'n' ||cUserInput == 'N'  )
                  digitalWrite(PIN0_LED_RED, HIGH);
            else if( cUserInput == 'f' ||cUserInput == 'F'  )
                  digitalWrite(PIN0_LED_RED, LOW);

            else if( cUserInput == '0'  )
                  PWM_LED(0);
            else if( cUserInput == '5'  )
                  PWM_LED(50);
            else if( cUserInput == 't' ||cUserInput == 'T'  )
                  PWM_LED(100);

            else if( cUserInput == 'q' ||cUserInput == 'Q'  )
                  PWM_Servo(600);
            else if( cUserInput == 'w' ||cUserInput == 'W'  )
                  PWM_Servo(1550);
            else if( cUserInput == 'e' ||cUserInput == 'E'  )
                  PWM_Servo(2500);
      }
      return 0;
}