#include <stdio.h>
#include <wiringPi.h>

#define     PIN0_LED_RED            0
#define     PIN2_LED_GRN            2
#define     PIN1_LED_BLU            1

#define     PIN24_SERVO             24

PI_THREAD(tLED_GRN)
{      
      pinMode(PIN2_LED_GRN, OUTPUT);
      int iState_Green = 0;
      while(1)
      {
            digitalWrite(PIN2_LED_GRN, (iState_Green++)%2 );
            delay(600);
      }
}
PI_THREAD(tLED_BLU)
{
      pinMode(PIN1_LED_BLU, PWM_OUTPUT);
      
      int iState_Blue = 0;
      int iDirect_LED = 1;
      while(1)
      {
            
            // pwmSetMode(PWM_MODE_BAL);
            // pwmSetClock(32);
            // pwmSetRange(1024);
            pwmWrite(PIN1_LED_BLU,iState_Blue);
            iState_Blue += iDirect_LED;
            if( iState_Blue == 0|| iState_Blue == 1023)
            {
                  iDirect_LED *= -1;
            }
            
            delay(1);
      }

}
PI_THREAD(tServo)
{
      pinMode(PIN24_SERVO, PWM_OUTPUT);

      pwmSetMode(PWM_MODE_MS);
      pwmSetClock(19);
      pwmSetRange(1000000/50);

      int iState_Servo = 600;
      int iDirect_Servo = 1900/180;
      while(1)
      {

            // pwmSetMode(PWM_MODE_MS);
            // pwmSetClock(19);
            // pwmSetRange(1000000/50);
            pwmWrite(PIN24_SERVO, iState_Servo );
            iState_Servo+=iDirect_Servo;
            if(iState_Servo == 600 || iState_Servo == 2400 )
                  iDirect_Servo *= -1;
            delay(10);
      }
}
      
      

int main()
{
      wiringPiSetup();

     piThreadCreate(tLED_GRN);
      piThreadCreate(tLED_BLU);
      piThreadCreate(tServo);

      pinMode(PIN0_LED_RED, OUTPUT);
      int iState_Red = 0;
      while(1)
      {
            digitalWrite(PIN0_LED_RED, (iState_Red++)%2 );
            delay(300);
      }

}