#include <stdio.h>
#include <wiringPi.h>

int main(void)
{
      const int iPin1_led = 1;
      const int iPin2_btn = 2;

      wiringPiSetup();

      pinMode(iPin1_led, OUTPUT);
      pinMode(iPin2_btn, INPUT);

      while(1)
      {
            int iBtn_read = digitalRead(iPin2_btn);
            if( iBtn_read > 0 )
            {
                  digitalWrite(iPin1_led, HIGH);
            }
            else
            {
                  digitalWrite(iPin1_led, LOW);
            }
            delay(100);
      }

      return 0;
}