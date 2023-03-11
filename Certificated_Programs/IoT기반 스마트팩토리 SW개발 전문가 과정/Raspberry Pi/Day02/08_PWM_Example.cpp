#include <stdio.h>
#include <wiringPi.h>

int main (void)
{
	const int iPin1_buzzer = 1;	
	
	wiringPiSetup();
	
	pinMode(iPin1_buzzer,PWM_OUTPUT);
	pwmSetClock(19);
	pwmSetMode(PWM_MODE_MS);
#if DEBUG == 1 
	const int melody[] = {262,294,330,349,392,440,494,523};
    int iRow = 0;
    while( iRow < 8 )
    {
        for( int note = 0; note < 8-iRow; note++ )
        {
            pwmSetRange(1000000/melody[note]);
            pwmWrite(iPin1_buzzer,1000000/melody[note]/5);
            delay(200);		
        }
        iRow ++;
    }
    
#elif DEBUG == 2
	const int melody[] = {1000000, 262,294,330,349, 392,440,494,523 };
	//96bpm
	int scale[] = { 5,5,6,6, 5,5,3, 5,5,3,3, 2,0,
				5,5,6,6, 5,5,3, 5,3,2,3, 1,0 }; 
	//4분음표 : 625
	int Rhythm[] = {
		1,1,1,1, 1,1,2, 1,1,1,1, 3,1,
		1,1,1,1, 1,1,2, 1,1,1,1, 3,1 };
	const int length = 26;

	pwmWrite(iPin1_buzzer, 0);
	// delay(10000);
	for( int i = 0; i < length; i++ )
	{
		int iCheck = scale[i];
		int iCal_melody = 1000000/melody[iCheck];
		pwmSetRange(int(iCal_melody));

		double rhy = iCal_melody*10 / (double)16/(double)Rhythm[i];
		
		pwmWrite(iPin1_buzzer, long(rhy) );
		delay(625*Rhythm[i]);
		pwmWrite(iPin1_buzzer, 0 );
		delay(10);
	}

#endif
	pwmWrite(iPin1_buzzer, 0);
}
