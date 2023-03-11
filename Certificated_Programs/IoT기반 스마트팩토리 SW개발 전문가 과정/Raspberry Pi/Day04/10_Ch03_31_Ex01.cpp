#include <stdio.h>
#include <wiringPi.h>

#define MAX_STATE                 4
#define PIN3_BTN                    3

#define PIN24_SERVO           24

volatile int iState = MAX_STATE-1;

PI_THREAD(THREAD_SERVO)
{

      pinMode(PIN24_SERVO, PWM_OUTPUT);

      pwmSetMode(PWM_MODE_MS);
      pwmSetClock(19);
      pwmSetRange(1000000/50);      
      while(1)
      {
      char cInput = getchar();
            if( cInput == 'q' || cInput == 'Q' )
                  pwmWrite(PIN24_SERVO, 600);
            else if( cInput == 'w' || cInput == 'W' )
                  pwmWrite(PIN24_SERVO, 1550);
            else if( cInput == 'e' || cInput == 'E' )
                  pwmWrite(PIN24_SERVO, 2500);
      }

}


void BtnPressed()
{
      iState ++;
      iState %= MAX_STATE;
}

int main()
{
      wiringPiSetup();
      
      const int PIN_LEDS[] ={0,2,4}; //r  g     b

      for (int i = 0; i < MAX_STATE-1 ; i++)
      {
            pinMode(PIN_LEDS[i],OUTPUT);
      }

      wiringPiISR(PIN3_BTN, INT_EDGE_RISING, BtnPressed);
      
      piThreadCreate(THREAD_SERVO);

      while(1)
      {
            if( iState != MAX_STATE-1)
            {
                  digitalWrite(PIN_LEDS[iState],HIGH);
                  digitalWrite(PIN_LEDS[(MAX_STATE-1-1+iState)% (MAX_STATE-1)],LOW);
                   delay(1);
            }
            else
            {
                  for (int i = 0; i < MAX_STATE-1 ; i++)
                  {
                        digitalWrite(PIN_LEDS[i],LOW);
                  }                  
                  delay(1);
            }
      }
      return 0;
}