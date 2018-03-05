#include "Arduino.h"
#include <Servo.h> 


String serialInput = "";
String readString;
int range = 45;
int base = 90;
int xVal, yVal, angle;

Servo xServo, yServo;  // create servo object to control a servo 

void setup() {

  Serial.begin(9600);
  xServo.attach(9);  //the pin for the xServo control
  xServo.write(base);
  yServo.attach(10);  //the pin for the yServob control
  yServo.write(base);
}

void loop() {

  //expect single strings like 700a, or 1500c, or 2000d,
  //or like 30c, or 90a, or 180d,
  //or combined like 180b,70a,

  //examples:
  //+x = 172a,
  //+y = 172b,
  //-x = 172c,
  //-y = 172d,

  if (Serial.available())  {
    String inputString = Serial.readStringUntil('\n');
    
    // Convert from String Object to String.
    char buf[20];
    inputString.toCharArray(buf, sizeof(buf));
    char *p = buf;
    char *str;
    while ((inputString = strtok_r(p, ",", &p)) != NULL) // delimiter is the comma
    {
      Serial.println("\nString is: ");
      Serial.print(inputString);
      int val = inputString.toInt();
      val = map(val, 0, 320, 0 , 40);
      
      if(inputString.indexOf('a') >0){
      angle = base-val;
      xServo.write(angle);
      }
      if(inputString.indexOf('b') >0)
      {
      angle = base-val;
      yServo.write(angle);
      }
      if(inputString.indexOf('c') >0)
      {
      angle = base+val;
      xServo.write(angle);

      }
      if(inputString.indexOf('d') >0)
      {
      angle = base+val;
      yServo.write(angle);

      }
      Serial.println("\nAngle is: ");
      Serial.print(angle);
    }

    inputString=""; //clears variable for new input
  }
}  
