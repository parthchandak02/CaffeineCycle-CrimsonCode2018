#include <Servo.h>

Servo xServo;
int xVal = 0;

Servo yServo;
int yVal = 0;

void setup()
{
  xServo.attach(9);
  yServo.attach(10);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    
    xVal = Serial.parseInt();
    xVal = map(xVal, 0, 1023, 0, 179);
    xServo.write(xVal);
    Serial.println(xVal);
    
    yVal = Serial.parseInt();
    yVal = map(yVal, 0, 1023, 0, 179);
    yServo.write(yVal);
    Serial.println(yVal);

    delay (1000);
  }
}
