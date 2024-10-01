---

# Speed Measuring Device Using Arduino

This repository contains a project that demonstrates how to measure the speed of an object moving through a fluid using an Arduino Uno or Arduino Mini as the microcontroller. The project utilizes infrared (IR) sensors to detect the movement and displays the calculated speed on an LCD.

## Table of Contents
- [Hardware Requirements](#hardware-requirements)
- [Software Requirements](#software-requirements)
- [Project Overview](#project-overview)
- [Code Explanation](#code-explanation)
- [Setup Instructions](#setup-instructions)
- [Precautions](#precautions)
- [Contributions](#contributions)
- [License](#license)

## Hardware Requirements
- **Arduino Uno or Arduino Mini**
- **2 x IR Sensors**
- **16x2 LCD Display**
- **Breadboard and jumper wires**
- **Power source (USB or battery)**

## Software Requirements
- **Arduino IDE**

To install the Arduino IDE, visit the [Arduino Software page](https://www.arduino.cc/en/software).

## Project Overview
This speed-measuring device utilizes two IR sensors placed a fixed distance apart (15 cm) to determine the speed of an object moving through a fluid. When the object interrupts the infrared beams of the sensors, the Arduino records the time it takes for the object to travel between the two sensors, allowing it to calculate the speed in centimeters per second (cm/sec).

The calculated speed is displayed on a 16x2 LCD, providing a visual representation of the object's speed.

## Code Explanation
The main code for the project is as follows:

```cpp
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
  velocity = (15 / velocity); // distance in cm/sec (15 cm is distance between two sensors)

  lcd.setCursor(2, 1);
  lcd.print(velocity);
  lcd.print(" cm/sec");

  delay(500);
}
```

### Key Functions:
- **LiquidCrystal**: Initializes the LCD display.
- **IR Sensors**: Detect when the object passes through them to measure time intervals.
- **Velocity Calculation**: Calculates the speed based on the time difference between the two IR sensors being interrupted.

## Setup Instructions
1. **Wiring**: Connect the IR sensors and LCD display to the Arduino according to the specified pins in the code.
2. **Upload Code**: Open the Arduino IDE, copy the code provided above, and upload it to your Arduino.
3. **Power the Device**: Ensure the device is powered appropriately using USB or a battery.
4. **Calibration**: Before taking measurements, calibrate the IR sensors according to your environment.

## Precautions
- **Lighting Conditions**: Avoid performing this experiment in direct sunlight or well-lit environments, as IR sensors can be affected by ambient infrared radiation.
- **Sensor Placement**: Ensure the sensors are not placed too close together, as one sensor may receive infrared signals from the other.
- **One-Direction Measurement**: This setup measures speed in one direction only.

## Contributions
Contributions to improve the project are welcome! Feel free to fork the repository, make changes, and submit a pull request.

## License
This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for more information.

---
