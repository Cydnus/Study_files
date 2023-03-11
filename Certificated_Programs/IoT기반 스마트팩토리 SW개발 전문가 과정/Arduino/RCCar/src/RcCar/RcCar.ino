
#define PIN_LED_LEFT    2
#define PIN_LED_RIGHT    3

#define LED_FREQ     5

void setup() 
{
      // put your setup code here, to run once:
      
      Serial.begin(9600);
      
      Motor_init();

      pinMode(PIN_LED_LEFT, OUTPUT);
      pinMode(PIN_LED_RIGHT, OUTPUT);


}


uint8_t SerialRead()
{
            char temp = Serial.read();

            uint8_t MoterStatus = 0;
            if( temp == 'W' ||  temp == 'w')
            {
                   MoterStatus = 1;
            }
            else if( temp == 'a' ||  temp == 'A')
            {
                   MoterStatus = 3;
            }
            else if( temp == 's' ||  temp == 'S')
            {
                   MoterStatus = 2;
            }
            else if( temp == 'd' ||  temp == 'D')
            {
                   MoterStatus = 4;
            }
            else if( temp == 'x' ||  temp == 'X')
            {
                   MoterStatus = 0;
            }
            else if( temp == 'j' ||  temp == 'J')
            {
                  MoterStatus = 6; 
            }
            else if( temp == 'l' ||  temp == 'L')
            {
                  MoterStatus = 5;                   
            }            
            else if( temp == 'K' ||  temp == 'k')
            {
                  MoterStatus = 7;                   
            }            

            
      return MoterStatus;
}

uint8_t led_status = 0;
bool LED_SW_LEFT = LOW;
bool LED_SW_RIGHT = LOW;
uint8_t cnt = 0;

void loop() {
      // put your main code here, to run repeatedly:
     // MoterStatus = 0;
     uint8_t MoterStatus = 0;
     
      if( Serial.available() > 0)
      {
            MoterStatus = SerialRead();
      }

      if( MoterStatus ==1 )
      {
            Motor_Forward()  ;            
      }
      else if( MoterStatus == 2 )
      {
            Motor_Backward();   
      }
      else if( MoterStatus==3 )
      {
            Motor_GoLeft();
      }
      else if( MoterStatus ==4 )
      {
            Motor_GoRight();      
      }
      else if ( MoterStatus == 0 )
      {
            Motor_Stop();            
      }
       if( MoterStatus== 5  && led_status != 3)
      {
        if( led_status != 1)
        {
            LED_SW_LEFT = !LED_SW_LEFT;
            led_status = 1;
            cnt = 0;
        }    
        else
        {
            led_status =0;
          }
      }
      else if( MoterStatus == 6 && led_status != 3 )
      {
        if( led_status != 2)
        {
            LED_SW_RIGHT = !LED_SW_RIGHT;
            
            led_status = 2;
            cnt = 0;   
        }    
        else
        {
            led_status =0;
          }
      }
      else if( MoterStatus == 7 )
      {
        if( led_status != 3)
        {
            LED_SW_LEFT = !LED_SW_LEFT;            
            LED_SW_RIGHT = !LED_SW_RIGHT;            
            led_status = 3;
            cnt = 0;       
        }
        else
        {
            led_status = 0;
            
        }
             
      }

      
      
      if(led_status!=0 )
      {    
            cnt = (cnt +1)%LED_FREQ;       
      }

       if(cnt==0 &&led_status == 3)
       {
            digitalWrite(PIN_LED_LEFT,LED_SW_LEFT);
            digitalWrite(PIN_LED_RIGHT,LED_SW_RIGHT);
            
            LED_SW_LEFT = ! LED_SW_LEFT;
            LED_SW_RIGHT = ! LED_SW_RIGHT;
        
       }
      else if(cnt==0 && led_status == 1)
      {            
            digitalWrite(PIN_LED_LEFT,LED_SW_LEFT);
            LED_SW_LEFT = ! LED_SW_LEFT;
      }      
      
      if(cnt==0 && led_status == 2)
      {
            digitalWrite(PIN_LED_RIGHT,LED_SW_RIGHT);
            LED_SW_RIGHT = ! LED_SW_RIGHT;;
      }
     
           
    delay(100);

}
