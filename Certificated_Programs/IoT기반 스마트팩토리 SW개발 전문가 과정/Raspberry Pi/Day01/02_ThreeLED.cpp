#include <stdio.h>
#include <wiringPi.h>


int main()
{
	wiringPiSetup();
	const int pin_led[] = {0,2,3};

	
	for(int i = 0 ;  i < 3; i ++)
	{
		pinMode(pin_led[i],OUTPUT);		
		digitalWrite(pin_led[i],0);
	}
	
	int led = 0;
	int count = 0;
	
	while( true )
	{
		count ++ ;
		if( count == 5)
		{
			digitalWrite(pin_led[led],1);
			digitalWrite(pin_led[(2+led)%3],0);
			led = (led +1) % 3;		
			count = 0;
		}
		
		delay(100);
	}
	return 0;
}