#include <stdio.h>
#include <wiringPi.h>

#define PIN0_LED_RED          0
#define PIN2_LED_GRN          2
#define PIN4_LED_BLU          4

PI_THREAD(tLed_Grn)
{
      pinMode(PIN2_LED_GRN, OUTPUT);
      int iStateGreen = 0; 
      while(1)
      {
            digitalWrite(PIN2_LED_GRN, (iStateGreen++)%2 );
            delay(650);
      }
}

PI_THREAD(tLed_Blu)
{
      pinMode(PIN4_LED_BLU, OUTPUT);
      int iStateBlue = 0; 
      while(1)
      {
            digitalWrite(PIN4_LED_BLU, (iStateBlue++)%2 );
            delay(850);
      }      
}


int main()
{
      wiringPiSetup();

      piThreadCreate(tLed_Grn);
      piThreadCreate(tLed_Blu);

      pinMode(PIN0_LED_RED, OUTPUT);
      int iStateRed = 0; 
      while(1)
      {
            digitalWrite(PIN0_LED_RED,(iStateRed++)%2);
            delay(350);
      }     
}