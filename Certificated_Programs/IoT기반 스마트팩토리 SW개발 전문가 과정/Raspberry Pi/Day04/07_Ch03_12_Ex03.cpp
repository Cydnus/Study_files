#include <stdio.h>
#include <wiringPi.h>



volatile int iToggle = 1;

void BtnPressed()
{
      iToggle = (iToggle +1) % 8;
}


int main()
{
      wiringPiSetup();

      int iPin24_buzzer = 24;
      int iPin3_btn = 3;

	const int melody[] = {262,294,330,349,392,440,494,523};

      pinMode(iPin24_buzzer, PWM_OUTPUT);
      wiringPiISR(iPin3_btn, INT_EDGE_FALLING, BtnPressed);
      
	pwmSetClock(19);
	pwmSetMode(PWM_MODE_MS);
      int iOld_toggle = 0;
      while(1)
      {
            if(iOld_toggle !=  iToggle)
            {
                  pwmSetRange(1000000/melody[iToggle]);
                  pwmWrite(iPin24_buzzer,1000000/melody[iToggle]/2);
                  delay(500);
                  pwmWrite(iPin24_buzzer,0);
            iOld_toggle = iToggle;
            }
      }
      
}