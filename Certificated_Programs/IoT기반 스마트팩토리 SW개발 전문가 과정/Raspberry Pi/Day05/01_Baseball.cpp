#include <iostream>
#include <wiringPi.h>
#include <stdlib.h>
#include <time.h>

#include "Baseball.h"
#include "I2C_LCD.h"
#include <mqueue.h>


mqd_t mfd;

struct mq_attr attr = {
      .mq_maxmsg = 10,
      .mq_msgsize = 4,
};




PI_THREAD(BTN_MAP)
{
      int iPin_Col[] = {25,24,23,22};
      int iPin_Row[] = {26,27,28,29};

      int iMAPPING[] = 
      {
            1,2,3,12,
            4,5,6,12,
            7,8,9,12,
            12,0,20,30
      };

      for(int i = 0 ; i < 4; i++)
      {
            pinMode(iPin_Col[i], OUTPUT);
            pinMode(iPin_Row[i], INPUT);
            digitalWrite(iPin_Col[i], LOW);
      }

      int iColSelect = 0;

      while(1)
      {
            digitalWrite(iPin_Col[iColSelect], HIGH);
            int iKeyMap[4]={0,};
            for(int i = 0; i<4; i++)
            {
                  iKeyMap[i] =  digitalRead (iPin_Row[i]);
                  int iTemp =  i+(iColSelect*4);
                  if(iKeyMap[i] == HIGH)
                  {
                        //메시지큐에 입력
                        printf("%d\n", iMAPPING[iTemp]);
                         mq_send(mfd, (char*) &iMAPPING[iTemp], attr.mq_msgsize,1 );
                  }
            }

            delay(65);
            digitalWrite(iPin_Col[iColSelect], LOW);
            iColSelect ++;
            iColSelect %= 4;
     }
}



void init( int* iPin_Strike, int *iPin_Ball)
{
      wiringPiSetup();
      

      mq_unlink("/msg_q");
      mfd = mq_open("/msg_q", O_RDWR | O_CREAT, 666, &attr) ;
      
      if( mfd == 1)
      {
            perror("open error") ;
            exit(-1);
      }

      piThreadCreate(BTN_MAP);


      for(int i = 0 ; i < 2; i++)
      {
            pinMode(iPin_Strike[i], OUTPUT);
      }
      for(int i = 0 ; i < 3; i++)
      {
            pinMode(iPin_Ball[i], OUTPUT);
      }

      srand((unsigned) time(NULL)) ;
}

int inCheck(int num, int input)
{
      for (int i = 0 ; input != 0 ; i++ )
      {
            if((input%10) == num)
                  return 1;
            input /=10;
      }      
      return 0;
}


int InputNumber(I2C_LCD& lcd )
{
      int iInput = 0;

      int iMsg = 12;
      lcd.setXY(0,0);
      lcd.print("Input Num : ___");
      lcd.setXY(12,0);

      do
      {
            mq_receive(mfd, (char *) &iMsg, attr.mq_msgsize, NULL) ;
            if( iMsg < 10 && iInput < 100 && (inCheck(iMsg, iInput) == 0))
            {
                  lcd.putchar(iMsg + 48);
                  iInput *= 10;
                  iInput += iMsg;                        
            }
            else if(iMsg == 20)
            {
                  iInput /= 10;
                  lcd.setXY(12,0);
                  lcd.print("___ ");
                        lcd.setXY(12,0);

                  if(iInput!=0)
                  {
                        char * cNumberToString = new char[4] ;
                        sprintf(cNumberToString,"%d",iInput);
                        lcd.print(cNumberToString);                              
                  }                  
            }
      }while( iMsg != 30);


      if( iInput < 100 || iInput > 999)
            return InputNumber(lcd);

      return iInput;
}


void DisplaySnB(I2C_LCD& lcd, int iStrike, int iBall)
{
       lcd.clear();
      lcd.setXY(1,1);
      lcd.putchar(((char)iStrike)+48);
      lcd.print(" S");
      lcd.setXY(8,1);
      lcd.putchar(((char)iBall)+48);
      lcd.print(" B");
}

void LedSnB(int* iPin_Strike, int* iPin_Ball , int iStrike, int iBall)
{
      
      for(int i = 0; i< MAX_LENGTH-1; i++)
      {
            digitalWrite(iPin_Strike[i], LOW );
            if( i <= iStrike-1)
                  digitalWrite(iPin_Strike[i], HIGH );
      }

      for(int i = 0; i< MAX_LENGTH; i++)
      {
            digitalWrite(iPin_Ball[i], LOW );
            if( i < iBall)
                  digitalWrite(iPin_Ball[i], HIGH );
      }
}

void LED_OFF(int* iPin_Strike, int* iPin_Ball)
{
      for(int i = 0; i< MAX_LENGTH-1; i++)
                  digitalWrite(iPin_Strike[i], LOW );
      for(int i = 0; i< MAX_LENGTH; i++)
                  digitalWrite(iPin_Ball[i], LOW );

}

int EndCheck(I2C_LCD& lcd , ComNumber cnComputer )
{
       lcd.clear();
      int iDone = 1;
      char cEndCheck;
      do{
            lcd.setXY(0,0);
            lcd.print("Success");
            lcd.setXY(0,1);
            lcd.print("Continue?(1/2)");                  
            mq_receive(mfd, (char *) &cEndCheck, attr.mq_msgsize, NULL) ;
            
            if( cEndCheck == 1){
                  cnComputer.Reset();
                  iDone = 1;
            }
            else  if( cEndCheck == 2)
                  iDone = 0;
            lcd.clear();
      }while( !( cEndCheck ==1 || cEndCheck== 2) );

      return iDone;
}



int main()
{

      I2C_LCD lcd;
      lcd.init(0x27);
      lcd.clear();

      int iPin_Strike[] = {4,5};
      int iPin_Ball[] = {0,2,3};

      init(iPin_Strike, iPin_Ball);
      LED_OFF(iPin_Strike, iPin_Ball);
      
      ComNumber cnComputer = ComNumber() ;
      int iDone = 1;
      printf("%d\n", cnComputer.iGetNumber());
      lcd.print("Input Num : ___");
      while(iDone)
      {
            int iInput = InputNumber(lcd);  
            
            int iStrike =  cnComputer.iStrikeCount(iInput);
            int iBall = cnComputer.iBallCount(iInput);

            if( iStrike != 3)
            { 
                DisplaySnB(lcd, iStrike, iBall);
                LedSnB(iPin_Strike, iPin_Ball, iStrike, iBall);
            }
            else
            {
                  LED_OFF (iPin_Strike, iPin_Ball);
                 iDone = EndCheck(lcd, cnComputer);
            }
      }
}
