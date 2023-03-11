#include <stdio.h>
#include <wiringPi.h>

int main (void)
{
	const int iPin1_servo = 1;
	
	wiringPiSetup();
	
	pinMode(iPin1_servo,PWM_OUTPUT);
	pwmSetClock(19);
	pwmSetMode(PWM_MODE_MS);
	
    pwmSetRange(1000000/50);
    
    pwmWrite(iPin1_servo, 600); // 600 : 0  
                                //2500 : 180
    delay(1000);

    for( int i = 0; i< 3; i ++)
    {
        pwmWrite(iPin1_servo, 600);
        delay(1000);
        pwmWrite(iPin1_servo, 1500);
        delay(1000);
    }

	pwmWrite(iPin1_servo, 0);

    int angle = 600;
    int direct = 10;

    while( true )
    {
        pwmWrite(iPin1_servo, angle);
        delay(10);
        angle += direct;
        if( angle == 600 || angle == 2500)
            direct *= -1;
    }

	pwmWrite(iPin1_servo, 0);

    
}
