#include <stdio.h>
#include <wiringPi.h>

#define NUMOFLED  4


void PushDown( int* iPin_leds, int* ishift, int* itimecount)
{      
      digitalWrite(iPin_leds[(*ishift)], LOW);
      digitalWrite(iPin_leds[ (NUMOFLED - 1 +(*ishift))%NUMOFLED], HIGH);
      if( *itimecount == 1000)
      {
            *ishift = (*ishift +1 ) % NUMOFLED ;
            *itimecount = 0;
      }
}

void PushUp( int* iPin_leds, int* icnt, int* idirect , int *itimecount)
{
          for ( int i = 0 ; i < NUMOFLED; i++)
                  {
                        if( ((*icnt) & (0x01 << i)) != 0 )
                              digitalWrite(iPin_leds[i], LOW);
                        else
                              digitalWrite(iPin_leds[i],HIGH);
                  }
                  
            if( *itimecount == 1000)
            {
                  (*icnt) += (*idirect);
                  if(*icnt == 0 || *icnt == 15)
                  {
                        (*idirect) *= -1;
                  }                  
                  *itimecount = 0;
            }
}


void init_state(int* iPin_leds , int* ishift, int* icnt,  int* idirect, int *itimecount)
{      
      *ishift = 0;
      *icnt = 0;
      *idirect = 1;
      *itimecount = 0;
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

      int icnt = 0;
      int idirect = 1;
      int iold_Btn = 0;
      int ishift = 0;

      int itime_cnt = 0;

      while( true )
      {
            int ibtn_input = digitalRead(iPin2_btn);

            if( iold_Btn == 0 && ibtn_input == 1)
                  init_state(iPin_leds, &ishift,&icnt,&idirect, &itime_cnt);                  // rising 
            else if (  iold_Btn == 1 && ibtn_input == 0 )
                  init_state(iPin_leds, &ishift,&icnt,&idirect , &itime_cnt);                   //falling

            if(ibtn_input == 1)
                  PushDown(iPin_leds, &ishift, &itime_cnt );
            else
               PushUp(iPin_leds , &icnt, &idirect, &itime_cnt);

            iold_Btn = ibtn_input;

            itime_cnt ++;
            delay(1);
      }
}