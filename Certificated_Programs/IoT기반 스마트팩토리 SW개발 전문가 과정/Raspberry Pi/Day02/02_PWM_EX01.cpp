#include <stdio.h>
#include <wiringPi.h>
#include <stdlib.h>

int main(int argv, char** args)
{
	if( argv != 2)
	{
		printf("Useage : %s num (num : 0~1024)\n", args[0]);
		return 0;
	}
	
	wiringPiSetup();
	
	const int iPin1_pwm_led = 1;
	
	pinMode(iPin1_pwm_led, PWM_OUTPUT) ;
	pwmWrite(iPin1_pwm_led, atoi(args[1]));
	
}