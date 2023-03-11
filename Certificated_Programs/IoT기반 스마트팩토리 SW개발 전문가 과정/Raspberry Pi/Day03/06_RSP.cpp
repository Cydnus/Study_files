#include <stdio.h>
#include <wiringPi.h>
#include <stdlib.h>
#include <time.h>
#include <wiringShift.h>

const int iPin_leds[]= {8,9,7};
const int iPin_btns[] = {0,2,3};

//8,0 : 보      9,2 : 바위    7,3 : 가위

const int iPin_dot_row[] = {29,28,27,25, 24,23,22,21};
const int iPin_dot_col[] = {14,13,12};    //ds(14) stcp(12), shcp(11)

volatile int iStatus = 3;
int print_once = 0;

uint8_t dot[8] = {
      0b00000000,
      0b00111100,
      0b00111100,
      0b00111100,
      0b00111100,
      0b00111100,
      0b00111100,
      0b00000000
}



void RockPressed()
{
      if( iStatus == 3)
            iStatus = 2;

}
void PaperPressed()
{
      if( iStatus == 3)
            iStatus = 0;

}
void ScissorsPressed()
{
      if( iStatus == 3)
            iStatus = 1;

}

void init()
{
      srand((unsigned) time (NULL) ) ;

      wiringPiSetup();

      for(int i = 0; i < 3; i ++)
      {
            pinMode(iPin_leds[i], OUTPUT);
            digitalWrite(iPin_leds[i], HIGH);
      }

      for(int i = 0; i < 8; i ++)
      {
            pinMode(iPin_dot_row[i], OUTPUT);
            digitalWrite(iPin_dot_row[i], HIGH);
      }
      for(int i = 0; i < 3; i ++)
      {
            pinMode(iPin_dot_col[i], OUTPUT);
            digitalWrite(iPin_dot_col[i], HIGH);
      }
      digitalWrite(iPin_dot_col[1], LOW);

      wiringPiISR(iPin_btns[0], INT_EDGE_RISING, PaperPressed) ;
      wiringPiISR(iPin_btns[1], INT_EDGE_RISING, ScissorsPressed) ;
      wiringPiISR(iPin_btns[2], INT_EDGE_RISING, RockPressed) ;

}

int iCreateNumber()
{
      return   rand() % 3 ;
}

void Moving()
{      
      static int iIndex = 0;
      
      digitalWrite(iPin_leds[iIndex], LOW);
      digitalWrite(iPin_leds[(2+iIndex)%3], HIGH);

      iIndex ++;
      iIndex %= 3;
}

int iCheck( int iRandNum)
{
      int iResult = 0;
      if( iRandNum == iStatus )
            iResult = 0;
      else if( iRandNum == 0)
      {//보
            if(iStatus == 1 ) //바위
                  iResult = 2;
            else
                  iResult = 1;
      }
      else if( iRandNum == 1)
      {//바위
            if(iStatus == 0 )//보
                  iResult = 1;
            else
                  iResult = 2;
      }
      else if( iRandNum == 2)
      {//가위
            if(iStatus == 1 )//바위
                  iResult = 1;
            else
                  iResult = 2;
      }
      

      return iResult;
}


int main()
{
      init();

      int iTime_Cnt = 0;
       int iNum = iCreateNumber();
      
      int total[3]  = {0,0,0};

      while(1)
      {
            for( int j = 0 ; j < 8; j++)
            {

                  
                   for(int i = 0 ; i< 8 ; i++)
                  {
                        digitalWrite(iPin_dot_row[i],((dot[j]>>i)&1)  )
                  }
                  delay(1);
                  shiftout();

            }
           
            

            if(iTime_Cnt == 0 && iStatus == 3)
            {
                  Moving();
            }
            if(print_once == 0 &&iStatus!= 3)
            {
                  total[0] ++;
                  print_once = 1;
                  for(int i = 0; i < 3; i ++)
                        digitalWrite(iPin_leds[i], HIGH);

                  if( iCheck(iNum) == 0 )
                  {
                        printf("Draw\n");
                        printf("total : %3d \t Win %3d  \t  Draw %3d\t Lose %3d \n", total[0], total[1], total[0]-(total[1]+total[2]),total[2]);
                  }                  
                  else if( iCheck(iNum) == 1  )
                  {
                        printf("Win\n");
                        total[1] ++;
                        printf("total : %3d \t Win %3d  \t  Draw %3d\t Lose %3d \n", total[0], total[1], total[0]-(total[1]+total[2]),total[2]);
                  }
                  else if( iCheck(iNum) == 2 )
                  {
                        printf("Lose\n");
                        total[2]++;
                        printf("total : %3d \t Win %3d  \t  Draw %3d\t Lose %3d \n", total[0], total[1], total[0]-(total[1]+total[2]),total[2]);
                  }


                  digitalWrite(iPin_leds[iNum], LOW);
                  delay(3000);
                  iStatus = 3;
                  print_once = 0;
            }
            if(iStatus == 3) {
                  iTime_Cnt = (iTime_Cnt + 1)% 500 ;
                   iNum = iCreateNumber();
            }
            delay(1);
      }


}