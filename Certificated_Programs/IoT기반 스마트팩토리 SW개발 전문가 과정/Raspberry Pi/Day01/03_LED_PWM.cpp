#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>

#define PIN_LED0	0


int main(int argv, char** args)
{
	if(argv != 3)
	{
		printf("useage : %s High_delay_milis Low_delay_milis\n", args[0]);
		return 0 ;
	}
	wiringPiSetup();
	
	pinMode(PIN_LED0,OUTPUT);
	
	if( atoi(args[1]) <= 0 || atoi(args[2]) <= 0)
	{
		printf("Can't use Zero or Under Zero\n");		
		return 0;
	}
	
	while(true)
	{
		digitalWrite(PIN_LED0,HIGH);
		delay(atoi(args[1]));
		digitalWrite(PIN_LED0,LOW);
		delay(atoi(args[2]));
	}	


	return 0;
}
