#include <stdio.h>
#include <wiringPi.h>

#define NUMOFLED  4


void PushDown( int* iPin_leds, int* ishift, int itimecount)
{      
      digitalWrite(iPin_leds[(*ishift)], LOW);
      digitalWrite(iPin_leds[ (NUMOFLED - 1 +(*ishift))%NUMOFLED], HIGH);
      if( itimecount == 1000)
      {
            *ishift = (*ishift +1 ) % NUMOFLED ;
      }
}

void PushUp( int* iPin_leds, int* iHex , int itimecount)
{
          for ( int i = 0 ; i < NUMOFLED; i++)
                  {
                        if( (iHex[0] & (0x01 << i)) != 0 )
                              digitalWrite(iPin_leds[i], LOW);
                        else
                              digitalWrite(iPin_leds[i],HIGH);
                  }
                  
            if( itimecount == 1000)
            {
                  iHex[0] += iHex[1];
                  if(iHex[0] == 0 || iHex[0] == 15)
                  {
                        iHex[1] *= -1;
                  }                  
            }
}


void init_state(int* iPin_leds , int *itimecount)
{      
      *itimecount = 0;
      for (int j = 0; j < 2; j++ )
      {
            for ( int i = 0 ; i < NUMOFLED; i++)
            {
                  digitalWrite(iPin_leds[i],HIGH);
            }
            delay(250);
            for ( int i = 0 ; i < NUMOFLED; i++)
            {
                  digitalWrite(iPin_leds[i],LOW);
            }
            delay(250);
      }
      
      for ( int i = 0 ; i < NUMOFLED; i++)
      {
            digitalWrite(iPin_leds[i],HIGH);
      }
}


int main(void)
{
      int iPin_leds[] = {8,9,7,0} ;
      int iPin2_btn = 2; 

      wiringPiSetup();

      for ( int i = 0 ; i < NUMOFLED; i++)
      {
            pinMode(iPin_leds[i],OUTPUT);
            digitalWrite(iPin_leds[i],HIGH);
      }
      pinMode(iPin2_btn, INPUT);

      int iHex[] = {0,1};
      int iold_Btn = 0;
      int ishift = 0;
      int itime_cnt = 1;

      int iState = 0;

      while( true )
      {
            int ibtn_input = digitalRead(iPin2_btn);

            if( iold_Btn == 0 && ibtn_input == 1)
            {
                  init_state(iPin_leds, &itime_cnt);                  // rising 
                  iState = (iState + 1)%2;
            }

            if(iState == 1)
                  PushDown(iPin_leds, &ishift, itime_cnt );
            else
               PushUp(iPin_leds , iHex, itime_cnt);

            iold_Btn = ibtn_input;
            if( itime_cnt == 1000 )
            {
                  itime_cnt = 0;
            }
            itime_cnt ++;
            delay(1);
      }
}