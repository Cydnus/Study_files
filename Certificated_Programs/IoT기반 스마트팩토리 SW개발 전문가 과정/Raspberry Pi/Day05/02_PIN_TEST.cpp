#include <stdio.h>
#include <wiringPi.h>
#include <wiringPiI2C.h>
#include "I2C_LCD.h"

int main()
{
      wiringPiSetup();

//       int iPin_Strike[] = {4,5};
//       int iPin_Ball[] = {0,2,3};

//       int iPin_Col[] = {25,24,23,22};
//       int iPin_Row[] = {26,27,28,29};

//       for(int i = 0 ; i < 2; i++)
//       {
//             pinMode(iPin_Strike[i], OUTPUT);
//             digitalWrite(iPin_Strike[i], HIGH);
//       }
//       for(int i = 0 ; i < 3; i++)
//       {
//             pinMode(iPin_Ball[i], OUTPUT);
//             digitalWrite(iPin_Ball[i], HIGH);
//       }
//       for(int i = 0 ; i < 4; i++)
//       {
//             pinMode(iPin_Col[i], OUTPUT);
//             pinMode(iPin_Row[i], INPUT);
//             digitalWrite(iPin_Col[i], LOW);
//       }

//       int iColSelect = 0;

//       while(1)
//       {

//             digitalWrite(iPin_Col[iColSelect], HIGH);
//             int iKeyMap[4]={0,};
//             for(int i = 0; i<4; i++)
//             {
//                   iKeyMap[i] =  digitalRead (iPin_Row[i]);
//                   int iTemp =  i+(iColSelect*4);
//                   if(iKeyMap[i] == HIGH)
//                         printf("%d\n", iTemp);
//             }

//             delay(10);
//             digitalWrite(iPin_Col[iColSelect], LOW);
//             iColSelect ++;
//             iColSelect %= 4;
//      }
      I2C_LCD lcd;
      lcd.init(0x27);
      lcd.clear();
      lcd.print("hello world");
      lcd.setXY(0,1);
      lcd.print("Welcome to Rsap");




}