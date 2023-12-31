#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int IR1 = A0;
int IR2 = A1;

unsigned long t1 = 0;
unsigned long t2 = 0;

float velocity;

void setup()
{
  lcd.begin(16, 2);
  pinMode(IR1, INPUT);
  pinMode(IR2, INPUT);
  Serial.begin(9600);
  
  lcd.clear();
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("Object Speed");
}

void loop()
{
  if (digitalRead(IR1) == 0)
  {
    t1 = millis();
  }

  if (digitalRead(IR2) == 0)
  {
    t2 = millis();
  }

  velocity = t2 - t1;
  velocity = velocity / 1000; // convert milliseconds to seconds
  velocity = (15 / velocity) // distance in cm/sec (15 cm is distance between two sensors)

  lcd.setCursor(2, 1);
  lcd.print(velocity);
  lcd.print(" cm/sec");

  delay(500);
}
