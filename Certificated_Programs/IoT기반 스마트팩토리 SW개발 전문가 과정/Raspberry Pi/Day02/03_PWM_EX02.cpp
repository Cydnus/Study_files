#include <stdio.h>
#include <wiringPi.h>

int main()
{	
	wiringPiSetup();
	
	const int iPin1_pwm_led = 1;
	
	pinMode(iPin1_pwm_led, PWM_OUTPUT) ;
	pwmSetClock(19);
	pwmSetMode(PWM_MODE_MS);
	pwmSetRange(1000000);
	
	long temp = 0;
	int sw = 100000 ;
	while( true)
	{
		pwmWrite(iPin1_pwm_led, temp);
		temp += sw;
		if( temp  == 1000000 || temp == 0)
			sw *= -1;
		delay(1000);
	}
	
	
}