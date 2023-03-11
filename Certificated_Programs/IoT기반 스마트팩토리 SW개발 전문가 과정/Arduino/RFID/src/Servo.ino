#include <Servo.h>

#define PIN_SERVO 6


Servo servo;


void Servo_init()
{
      servo.attach(PIN_SERVO);
}

void Servo_Open(){
      servo.write(120);
}

void Servo_Close(){
      servo.write(30);
}
