#define BUZ 3

int tones_pass[] = {261, 293, 311};
int tones_denied[] = {311, 311, 311};
void buzzer_init()
{
  pinMode(BUZ, OUTPUT);
}
void buzzer_ok()
{
  for(int i = 0 ; i < 3 ; i++)
  {
    tone(BUZ, tones_pass[i]);
    delay(300);  
  }

  noTone(BUZ);
}

void buzzer_denied()
{
  for(int i = 0 ; i < 3 ; i++)
  {
    tone(BUZ, tones_denied[i]);
    delay(100);  
  }

  noTone(BUZ);
}
