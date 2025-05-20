#include <LX16Servo.h>
#include <SoftwareSerial.h>

SoftwareSerial servoSerial(10, 11);

const int servo1_ID = 1;
const int servo2_ID = 2;

void setup() {
  Serial.begin(9600);
  servoSerial.begin(115200);      
  LX16Servo::begin(servoSerial);   

  Serial.println("Ready! Enter angles in format: 90,45");
}

void loop() {
  if (Serial.available()) {
    String input = Serial.readStringUntil('\n');
    input.trim();

    if (input.length() == 0) {
      Serial.println("No input received. Try again.");
      return;
    }

    int commaIndex = input.indexOf(',');

    if (commaIndex != -1) {
      int angle1 = constrain(input.substring(0, commaIndex).toInt(), 0, 240);
      int angle2 = constrain(input.substring(commaIndex + 1).toInt(), 0, 240);

      LX16Servo::move(servo1_ID, angle1);
      LX16Servo::move(servo2_ID, angle2);

      Serial.print("Servo ");
      Serial.print(servo1_ID);
      Serial.print(" -> ");
      Serial.print(angle1);

      Serial.print("   Servo ");
      Serial.print(servo2_ID);
      Serial.print(" -> ");
      Serial.println(angle2);
    } else {
      Serial.println("Invalid input! Use format like: 90,45");
    }

    Serial.println("Enter next angles:");
  }
}
