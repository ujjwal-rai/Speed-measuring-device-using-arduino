const int sensor1_pin = A0;
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  pinMode(sensor1_pin, INPUT);
}

void loop() {
  // read the input on analog pin 0:
  int sensorValue = analogRead(sensor1_pin);
  // print out the value you read:
  Serial.println(sensorValue);
  delay(1);        // delay in between reads for stability
}
