#include <wiringPi.h>
#include <stdio.h>
#include <wiringSerial.h>

int main()
{
      int iSerial_port;
      char dat;
      char asc = 65;
      if( (iSerial_port = serialOpen("/dev/ttyAMA0",115200))<0)
            return 1;

      wiringPiSetup();
      while(1)
      {
            printf("T .. %d", asc);
            serialPutchar(iSerial_port,asc);
            delay(100);
            if( serialDataAvail(iSerial_port))
            {
                  dat = serialGetchar(iSerial_port);
                  printf(" ==> R : %d \n", dat);
                  serialFlush(iSerial_port);
            }
            delay(300);
            asc++;
      }

}