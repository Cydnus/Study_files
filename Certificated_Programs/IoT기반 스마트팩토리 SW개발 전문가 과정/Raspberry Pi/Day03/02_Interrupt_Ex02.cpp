#include <stdio.h>
#include <wiringPi.h>

#define NUMOFLED  4

const  int iPin_leds[] = {8,9,7,0} ;

volatile int iState = 0;
volatile int itimecount = 0;

void PushDown( int* ishift)
{      
      digitalWrite(iPin_leds[(*ishift)], LOW);
      digitalWrite(iPin_leds[ (NUMOFLED - 1 +(*ishift))%NUMOFLED], HIGH);
      if( itimecount == 1000)
      {
            *ishift = (*ishift +1 ) % NUMOFLED ;
      }
}

void PushUp(  int* iHex)
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


void init_state()
{      
      itimecount = 0;
      for ( int i = 0 ; i < NUMOFLED; i++)
      {
            digitalWrite(iPin_leds[i],HIGH);
      }
}


void ButtonPressed()
{
      init_state();
      iState = (iState +1) %2;
}


int main(void)
{
     
      int iPin2_btn = 2; 

      wiringPiSetup();

      for ( int i = 0 ; i < NUMOFLED; i++)
      {
            pinMode(iPin_leds[i],OUTPUT);
            digitalWrite(iPin_leds[i],HIGH);
      }
      wiringPiISR(iPin2_btn, INT_EDGE_RISING, ButtonPressed);

      int iHex[] = {0,1};
      int iold_Btn = 0;
      int ishift = 0;

      while( true )
      {
            if(iState == 1)
                  PushDown( &ishift );
            else
               PushUp(iHex);

            if( itimecount == 1000 )
            {
                  itimecount = 0;
            }

            itimecount ++;
            delay(1);
      }
}