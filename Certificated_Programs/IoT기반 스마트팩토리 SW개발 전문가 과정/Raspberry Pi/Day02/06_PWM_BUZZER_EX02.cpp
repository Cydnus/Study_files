#include <stdio.h>
#include <wiringPi.h>

int main (void)
{
	const int iPin1_buzzer = 1;
	
	const int melody[] = {262,294,330,349,392,440,494,523};
	
	wiringPiSetup();
	
	pinMode(iPin1_buzzer,PWM_OUTPUT);
	pwmSetClock(19);
	pwmSetMode(PWM_MODE_MS);
	
	for( int note = 0; note < 8; note++ )
	{
		pwmSetRange(1000000/melody[note]);
		pwmWrite(iPin1_buzzer,1000000/melody[note] /2);
		delay(500);		
	}
	pwmWrite(iPin1_buzzer, 0);
}
