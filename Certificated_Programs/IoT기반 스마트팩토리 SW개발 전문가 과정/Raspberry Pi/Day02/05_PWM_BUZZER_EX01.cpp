#include <stdio.h>
#include <wiringPi.h>

int main (void)
{
	const int iPin1_buzzer = 1;
	
	wiringPiSetup();
	
	pinMode(iPin1_buzzer,PWM_OUTPUT);
	pwmSetClock(19);
	pwmSetMode(PWM_MODE_MS);
	pwmSetRange(1000000/262);
	pwmWrite(iPin1_buzzer,1000000/262 /2);
	delay(3000);
	pwmWrite(iPin1_buzzer, 0);
}
