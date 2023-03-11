#include <Wire.h> 
#include <LiquidCrystal_I2C.h>


LiquidCrystal_I2C lcd(0x27,16, 2);

void lcdInit()
{
  lcd.init();
  lcd.backlight(); 
}
void printIdle()
{
 // lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("tagging card");
}

void printOK()
{
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("ACCESS GRANTED");
  lcd.setCursor(0,1);
  lcd.print("Welcome, user!");
}

void printFail()
{
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("ACCESS DENIED");
  lcd.setCursor(0,1);
  lcd.print("TRY ONCE AGAIN");
}

void LCD_Clear()
{
  lcd.clear();
    
}
