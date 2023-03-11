#include <stdio.h>
#include <wiringPi.h>

PI_THREAD(t1)
{
      while(1)
      {
            printf("\tT1\n");
            delay(500);
      }
}

int main()
{
      wiringPiSetup();
      piThreadCreate(t1);

      while(1)
      {
            printf("main\n");
            delay(1000);
      }

}