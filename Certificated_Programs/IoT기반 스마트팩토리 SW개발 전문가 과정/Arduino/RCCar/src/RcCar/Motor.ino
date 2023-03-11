

const uint8_t Pin_MOTOR[] = {11,10,5,6};

#define MOTOR_A_SPEED 231           //L
#define MOTOR_A_SPEED_LOW 154          //L
#define MOTOR_B_SPEED 219           //R
#define MOTOR_B_SPEED_LOW 146           //R

#define MOTOR_A_FORWORD   {analogWrite(Pin_MOTOR[0], MOTOR_A_SPEED); analogWrite(Pin_MOTOR[1], 0);}
#define MOTOR_A_BACKWORD  {analogWrite(Pin_MOTOR[0], 0); analogWrite(Pin_MOTOR[1], MOTOR_A_SPEED);}

#define MOTOR_B_FORWORD   {analogWrite(Pin_MOTOR[2], MOTOR_B_SPEED); analogWrite(Pin_MOTOR[3], 0);}
#define MOTOR_B_BACKWORD  {analogWrite(Pin_MOTOR[2], 0); analogWrite(Pin_MOTOR[3], MOTOR_B_SPEED);}


#define MOTOR_A_FORWORD_LOW   {analogWrite(Pin_MOTOR[0], MOTOR_A_SPEED_LOW); analogWrite(Pin_MOTOR[1], 0);}
#define MOTOR_A_BACKWORD_LOW  {analogWrite(Pin_MOTOR[0], 0); analogWrite(Pin_MOTOR[1], MOTOR_A_SPEED_LOW);}
#define MOTOR_B_FORWORD_LOW  {analogWrite(Pin_MOTOR[2], MOTOR_B_SPEED_LOW); analogWrite(Pin_MOTOR[3], 0);}
#define MOTOR_B_BACKWORD_LOW  {analogWrite(Pin_MOTOR[2], 0); analogWrite(Pin_MOTOR[3], MOTOR_B_SPEED_LOW);}

#define MOTOR_ALL_STOP { analogWrite(Pin_MOTOR[0], 0); analogWrite(Pin_MOTOR[1], 0);analogWrite(Pin_MOTOR[2], 0);analogWrite(Pin_MOTOR[3], 0);}


void Motor_init()
{
      for( int i  = 0 ; i < 4; i++)
      {
            pinMode(Pin_MOTOR[i], OUTPUT);
            digitalWrite(Pin_MOTOR[i], LOW);
      }
}

void Motor_Forward()
{
            MOTOR_A_FORWORD;
            MOTOR_B_FORWORD;
}

void Motor_Backward()
{
            MOTOR_A_BACKWORD;
            MOTOR_B_BACKWORD;
}

void Motor_GoLeft()
{
            MOTOR_A_BACKWORD_LOW;
            MOTOR_B_FORWORD_LOW;
}
void Motor_GoRight()
{
            MOTOR_A_FORWORD_LOW;
            MOTOR_B_BACKWORD_LOW;
}
void Motor_Stop()
{      
      MOTOR_ALL_STOP;
}
