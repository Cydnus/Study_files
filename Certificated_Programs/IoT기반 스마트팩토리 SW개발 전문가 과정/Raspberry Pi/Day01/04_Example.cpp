#include <stdio.h>
#include <wiringPi.h>

int main()
{
	wiringPiSetup();
	
	int index = 0;
	
#if DEBUG > 1 
	const int pin_hex_led[] = {8,9,2,3};
#endif

#if DEBUG > 2
	int sw = 1;
#endif
	
#if DEBUG==1

	while( true )
	{
		printf("%d\n", index);
		index = (index +1)%16;
		
		delay(1000);
	}
	
#elif DEBUG == 2

	
	for(int i = 0 ; i < 4 ; i ++)
	{
		pinMode(pin_hex_led[i], OUTPUT);
		digitalWrite(pin_hex_led[i],HIGH);
	}
	
	
	while( true )
	{

		for(int i = 0 ; i < 4 ; i ++)
		{
			if( (index & ( 0x01 << i )) != 0)
				digitalWrite(pin_hex_led[i],LOW);
			else
				digitalWrite(pin_hex_led[i],HIGH);		
			delay(1);
		}		
		
		delay(960);
		index = (index +1)%16;
	}
	
#elif DEBUG == 3

	for(int i = 0 ; i < 4 ; i ++)
	{
		pinMode(pin_hex_led[i], OUTPUT);
		digitalWrite(pin_hex_led[i],HIGH);
	}
	
	while( true )
	{

		for(int i = 0 ; i < 4 ; i ++)
		{
			if( (index & ( 0x01 << i )) != 0)
				digitalWrite(pin_hex_led[i],LOW);
			else
				digitalWrite(pin_hex_led[i],HIGH);		
			delay(1);
		}		
		printf("%d\n", index) ;
		delay(960);
		
		index = (index +sw)%16;
		
		if(index == 0 || index == 15)
			sw *= -1;
	}
	
	
#elif DEBUG == 4

	int pin_three_led[] = { 4,5};	 // 4 : Red
	for(int i = 0 ; i < 4 ; i ++)
	{
		pinMode(pin_hex_led[i], OUTPUT);
		digitalWrite(pin_hex_led[i],HIGH);
	}
	
	for(int i = 0 ; i < 2 ; i ++)
	{
		pinMode(pin_three_led[i], OUTPUT);
		digitalWrite(pin_three_led[i],LOW);
	}
	
	
	while( true )
	{
		for(int i = 0 ; i < 4 ; i ++)
		{
			if( (index & ( 0x01 << i )) != 0)
				digitalWrite(pin_hex_led[i],LOW);
			else
				digitalWrite(pin_hex_led[i],HIGH);		
			delay(1);
		}		
		
		if( sw > 0 )
		{
			digitalWrite(pin_three_led[0], HIGH );
			digitalWrite(pin_three_led[1], LOW );
		}
		else
		{
			digitalWrite(pin_three_led[0], LOW );
			digitalWrite(pin_three_led[1], HIGH );
		}
		
		printf("%d\n", index) ;
		delay(960);
		
		index = (index +sw)%16;
		
		if(index == 0 || index == 15)
			sw *= -1;
		
	}
	
#endif
	return 0;
}