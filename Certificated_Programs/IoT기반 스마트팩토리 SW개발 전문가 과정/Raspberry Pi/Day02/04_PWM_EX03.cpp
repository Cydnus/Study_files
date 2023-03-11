#include <stdio.h>
#include <wiringPi.h>

int main()
{	
	wiringPiSetup();
	
	const int iPin1_pwm_led = 1;
	
	pinMode(iPin1_pwm_led, PWM_OUTPUT) ;
	pwmSetClock(19);
	pwmSetMode(PWM_MODE_MS);
	pwmSetRange(1000000/100);
	
		pwmWrite(iPin1_pwm_led, 1000000/2/100);
	
	
}