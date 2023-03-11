
#define LENGTH_USER     2


String Code[] = {
"13 63 EE 14",
"FC B9 2B 4A"
};

void setup() {
      Servo_init();
      lcdInit();
      RFID_init();
      buzzer_init();
      Serial.begin(9600);
      Serial.println("START");
      
      Servo_Close();
}

void loop() {
    
      String strRead = RFID_Read(true);
      
      if(strRead != " ")
            Serial.println(strRead);
   
      bool check = false;
      
      for( uint8_t i = 0; i<LENGTH_USER; i++)
      {
            if( strRead ==  Code[i])
            {
                  check = true;
            }
      }

      Serial.println(check);
      
      if( check )
      {
            buzzer_ok();
            printOK();
            Servo_Open();
            delay(5000);
            LCD_Clear();
      }
      else if ( !check && strRead != " " )
      {
            buzzer_denied();
            printFail();
            delay(5000);
            LCD_Clear();
      }
      else
      {
            printIdle();
            Servo_Close();            
      }
       delay(100);
}
