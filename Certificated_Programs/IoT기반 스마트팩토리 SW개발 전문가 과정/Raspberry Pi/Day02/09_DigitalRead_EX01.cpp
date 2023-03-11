#include <stdio.h>
#include <wiringPi.h>

int main(void)
{
      const int iPin2_btn = 2;

      wiringPiSetup();

      pinMode(iPin2_btn, INPUT) ;
      while(1)
      {
            int btnInput = digitalRead(iPin2_btn);
            printf("%d\n", btnInput);
            delay(100);
      }
      return 0;
}