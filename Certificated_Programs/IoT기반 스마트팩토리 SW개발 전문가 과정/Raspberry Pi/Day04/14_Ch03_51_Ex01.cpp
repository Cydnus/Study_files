#include <stdio.h>
#include <wiringPi.h>
#include <mqueue.h>


#define PIN0_LED_RED          0
#define PIN2_LED_GRN          2
#define PIN3_LED_BLU          4

#define PIN1_LED_YLW          1
#define PIN5_LED_TRA          5

#define PIN24_SERVO          24

#define PIN3_BTN                    3




mqd_t mfd;

struct mq_attr attr = {
      .mq_maxmsg = 10,
      .mq_msgsize = 4
};

PI_THREAD(tLedYellow)
{
      int iState_Yellow = 0;
      int iDirect_yellow = 1;
      while(1)
      {
            pwmSetMode(PWM_MODE_BAL);
            pwmSetClock(32);
            pwmSetRange(1024);
            pwmWrite(PIN1_LED_YLW, iState_Yellow);
            iState_Yellow +=iDirect_yellow;
            if( iState_Yellow == 0 || iState_Yellow == 1023)
                  iDirect_yellow*=-1;
            delay(1);
      }

}
PI_THREAD(tLedTransp)
{
      int iState_Transp = 0;
      while(1)
      {
            digitalWrite(PIN5_LED_TRA,(iState_Transp++)%2 );
            delay(600);
      }

}
PI_THREAD(tServo)
{

      while(1)
      {
            char cInput = getchar();

            pwmSetMode(PWM_MODE_MS);
            pwmSetClock(19);
            pwmSetRange(1000000/50);
            
            if(cInput == 'q' || cInput== 'Q' )
                  pwmWrite(PIN24_SERVO, 600);
            if(cInput == 'w' || cInput== 'W' )
                  pwmWrite(PIN24_SERVO, 1550);
            if(cInput == 'E' || cInput== 'e' )
                  pwmWrite(PIN24_SERVO, 2500);
      }

}


void BtnPressed()
{
      static int iValue = 0;

      iValue = (iValue +1) %4;

      mq_send(mfd, (char*) &iValue, attr.mq_msgsize,1);

}

void init()
{
      pinMode(PIN0_LED_RED, OUTPUT );
      pinMode(PIN2_LED_GRN, OUTPUT) ;
      pinMode(PIN3_LED_BLU, OUTPUT) ;
      pinMode(PIN1_LED_YLW, PWM_OUTPUT) ;
      pinMode(PIN5_LED_TRA, OUTPUT) ;
      pinMode(PIN24_SERVO , PWM_OUTPUT) ;

}

int main()
{
      wiringPiSetup();
      

      mq_unlink("/msg_q");
      mfd = mq_open("/msg_q", O_RDWR | O_CREAT, 666, &attr) ;

      if( mfd == 1)
      {
            perror("open error") ;
            return -1;
      }

      init();
      wiringPiISR(PIN3_BTN, INT_EDGE_FALLING, BtnPressed);
      piThreadCreate(tLedYellow);
      piThreadCreate(tLedTransp);
      piThreadCreate(tServo);
      
      while(1)
      {
            int iValue = 3;
            mq_receive(mfd, (char*) &iValue, attr.mq_msgsize, NULL );
            if ( iValue == 0 )
            {
                  digitalWrite(PIN0_LED_RED, HIGH);
                  digitalWrite(PIN2_LED_GRN, LOW);
                  digitalWrite(PIN3_LED_BLU, LOW);
            }
            else if ( iValue == 1 )
            {
                  digitalWrite(PIN0_LED_RED, LOW);
                  digitalWrite(PIN2_LED_GRN, HIGH);
                  digitalWrite(PIN3_LED_BLU, LOW);

            }
            else if ( iValue == 2 )
            {
                  digitalWrite(PIN0_LED_RED, LOW);
                  digitalWrite(PIN2_LED_GRN, LOW);
                  digitalWrite(PIN3_LED_BLU, HIGH);

            }
            else if ( iValue == 3 )
            {
                  digitalWrite(PIN0_LED_RED, LOW);
                  digitalWrite(PIN2_LED_GRN, LOW);
                  digitalWrite(PIN3_LED_BLU, LOW);
            }

      }


}
