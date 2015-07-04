// -*-mode: c++; indent-tabs-mode: nil; -*-

#include <Servo.h>

Servo myServo;

int const potPin = A0;
int potVal = 0;
int angle = 0;

void setup() {
  Serial.begin(9600); // open a serial port
  Serial.println("Setting up the pins ..."); // <-- not a part of the original starter kit project code!
  myServo.attach(9);
}

void loop() {
  potVal = analogRead(potPin);
  Serial.print("potVal: ");
  Serial.print(potVal);
  angle = map(potVal, 0, 1023, 0, 179);
  Serial.print(", angle: ");
  Serial.println(angle);
  myServo.write(angle);
  delay(15);
}
