#include <Servo.h>

Servo servos[2];
int servoPins[] = {5, 3}; 
const int servoCount = 2;

void setup() {
  Serial.begin(9600);

  for (int i = 0; i < servoCount; i++) {
    servos[i].attach(servoPins[i]);
  }

  Serial.println("Ready! Enter angles like 90,45");
}

void loop() {
  if (Serial.available()) {
    String input = Serial.readStringUntil('\n');
    input.trim(); 

    int commaIndex = input.indexOf(',');

    if (commaIndex != -1) {
      int angle1 = input.substring(0, commaIndex).toInt();
      int angle2 = input.substring(commaIndex + 1).toInt();

      servos[0].write(angle1);
      servos[1].write(angle2);

      Serial.print("Servo 0 -> ");
      Serial.print(angle1);
      Serial.print("   Servo 1 -> ");
      Serial.println(angle2);
    } else {
      Serial.println("Invalid input! Use format like: 90,45");
    }

    Serial.println("Enter next angles:");
  }
}
