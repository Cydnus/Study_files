#include <stdio.h>
#include <wiringPi.h>
#include <wiringPiI2C.h>

#define LCD_CHR  1 // Mode - Sending data
#define LCD_CMD  0 // Mode - Sending command

#define LINE1  0x80 // 1st line
#define LINE2  0xC0 // 2nd line

#define LCD_BACKLIGHT_ON   0x08  // On
#define LCD_BACKLIGHT_OFF  0x00  # Off

#define ENABLE  0b00000100 // Enable bit

class I2C_LCD
{
private :

      int fd;

      void lcd_byte(int bits, int mode);
      void lcd_toggle_enable(int bits);

      // added by Lewis
      void typeInt(int i);
      void typeFloat(float myFloat);

public:
      I2C_LCD();
      I2C_LCD(int fd);

      void init(int fd);

      void print( const char* str);
      void setXY(int x, int y);
      void clear();
      void putchar(char str);

};


