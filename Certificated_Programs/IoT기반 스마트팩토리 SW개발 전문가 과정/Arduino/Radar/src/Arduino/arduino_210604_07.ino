
#include <Servo.h>


#define PIN_TRIG 5
#define PIN_ECHO 6

#define PIN_SERVO 11

Servo servo;

#define START_ANGLE 30
#define END_ANGLE 150



uint8_t angle = START_ANGLE;
int sw = 1;


void setup() {
    // put your setup code here, to run once:

    Serial.begin(9600);
    pinMode(PIN_TRIG, OUTPUT);
    pinMode(PIN_ECHO, INPUT);

    servo.attach(PIN_SERVO);

}


void loop() {
    // put your main code here, to run repeatedly:
    servo.write(angle);

    Serial.print(angle);
    Serial.print(",");
    Serial.print(distance());
    Serial.print(".");
    
    angle += sw;
    if( angle <= START_ANGLE || angle >= END_ANGLE)
    {
        sw *= -1;
    }

    
    delay(30);

}

unsigned long distance()
{
    
    digitalWrite(PIN_TRIG,LOW);
    delayMicroseconds(2);
    digitalWrite(PIN_TRIG,HIGH);
    delayMicroseconds(10);
    digitalWrite(PIN_TRIG,LOW);

    unsigned long returnTIme = pulseIn(PIN_ECHO, HIGH);
    

    return (returnTIme);

      
}
