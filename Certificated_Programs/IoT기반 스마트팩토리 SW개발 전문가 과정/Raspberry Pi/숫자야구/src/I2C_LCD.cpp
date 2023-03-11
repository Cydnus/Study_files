
#include "I2C_LCD.h"

I2C_LCD :: I2C_LCD()
{
                  fd = 0;
}

I2C_LCD :: I2C_LCD(int fd)
{
             init(fd);
}

void I2C_LCD::init(int fd)
{
      this->fd = wiringPiI2CSetup(fd); 
      // Initialise display
      lcd_byte(0x32, LCD_CMD); // Initialise
      lcd_byte(0x06, LCD_CMD); // Cursor move direction
      lcd_byte(0x0C, LCD_CMD); // 0x0F On, Blink Off
      lcd_byte(0x28, LCD_CMD); // Data length, number of lines, font size
      lcd_byte(0x01, LCD_CMD); // Clear display
      delayMicroseconds(500);
}

void I2C_LCD::print( const char* str)
{
      while ( *str ) lcd_byte(*(str++), LCD_CHR);
}

void I2C_LCD::putchar(char str)
{
      lcd_byte(str, LCD_CHR);
}


void I2C_LCD::setXY(int x, int y)
{
      //0,0
            lcd_byte((LINE1      | (0x40 * y) )      + x, LCD_CMD);
}
void I2C_LCD::clear()
{
      lcd_byte(0x01, LCD_CMD);
      lcd_byte(0x02, LCD_CMD);
}


// float to string
void      I2C_LCD::typeFloat(float myFloat)       {
      char buffer[20];
      sprintf(buffer, "%4.2f",      myFloat);
      print(buffer);
}

// int to string
void      I2C_LCD::typeInt(int i)       {
      char array1[20];
      sprintf(array1, "%d",      i);
      print(array1);
}

void      I2C_LCD::lcd_byte(int bits, int mode)       {

      //Send byte to data pins
      // bits = the data
      // mode = 1 for data, 0 for command
      int bits_high;
      int bits_low;
      // uses the two half byte writes to LCD
      bits_high = mode | (bits & 0xF0) | LCD_BACKLIGHT_ON ;
      bits_low = mode | ((bits << 4) & 0xF0) | LCD_BACKLIGHT_ON ;

      // High bits
      wiringPiI2CReadReg8(fd, bits_high);
      lcd_toggle_enable(bits_high);

      // Low bits
      wiringPiI2CReadReg8(fd, bits_low);
      lcd_toggle_enable(bits_low);
}

void      I2C_LCD::lcd_toggle_enable(int bits)       {
      // Toggle enable pin on LCD display
      delayMicroseconds(500);
      wiringPiI2CReadReg8(fd, (bits | ENABLE));
      delayMicroseconds(500);
      wiringPiI2CReadReg8(fd, (bits & ~ENABLE));
      delayMicroseconds(500);
}

