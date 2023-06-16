#include <LiquidCrystal.h>

const int sensor1_pin = A0;
const int sensor2_pin = A1;

const int rs_pin = 12;
const int en_pin = 11;
const int d4_pin = 5;
const int d5_pin = 4;
const int d6_pin = 3;
const int d7_pin = 2;

LiquidCrystal lcd(rs_pin, en_pin, d4_pin, d5_pin, d6_pin, d7_pin);

long sensor1_time = 0;
long sensor2_time = 0;

long time_diff = 0;
float velocity = 0;
float distance = 15000;  //distance between two sensors in cm * 1000 to convert time from milisecond to second

void setup() {
  lcd.begin(16, 2);
  lcd.clear();
  lcd.print("IR Sensor Timer");

  pinMode(sensor1_pin, INPUT);
  pinMode(sensor2_pin, INPUT);

  Serial.begin(9600);
}

void loop() {
  if (analogRead(sensor1_pin) > 700 && sensor1_time == 0)  // sensor values after configuration.
  {
    sensor1_time = millis();
    Serial.println("Object detected at sensor 1");
  }
  if (analogRead(sensor2_pin) > 850 && sensor1_time > 0)  // sensor values after configuration.
  {
    sensor2_time = millis();
    time_diff = sensor2_time - sensor1_time;
    velocity = distance / time_diff;
    Serial.print("Object detected at sensor 2. Time difference: ");
    Serial.print(time_diff);
    Serial.print(" miliseconds. Velocity: ");
    Serial.print(velocity);
    Serial.println(" cm/s");
    if(time_diff>0)
    {
      lcd.clear();
      lcd.print("Time: ");
      lcd.print(time_diff);
      lcd.print(" ms");
      lcd.setCursor(0, 1);
      lcd.print("Speed: ");
      lcd.print(velocity);
      lcd.print(" cm/s");
    }

    sensor1_time = 0;
    sensor2_time = 0;
  }
}
