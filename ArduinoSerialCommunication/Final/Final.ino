#include "Arduino.h"
#include <Servo.h> 
#include <string.h>

String serialInput = "";
String readString;
int range = 30.0;
int base = 90.0;
char* x_val, y_val;

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
//  String inputString = Serial.readStringUntil('\n');
//  int val = Serial.parseInt();

   String inputStr = Serial.readStringUntil('\n');

   x_val = strtok(inputStr, ",")
   while(x_val != NULL)
   {
    if (x_val[x_val.length()-1] == 'a') //move left
    {
      
    }
    else if (x_val[x_val.length()-1] == 'c') //move right
    {
      
    }
   }


   y_val = strtok(inputStr, ",")
   while(y_val != NULL)
   {
    if (y_val[y_val.length()-1] == 'b') //move up
    {
      
    }
    else if (y_val[y_val.length()-1] == 'd') //move down
    {
      
    }
   }
  
  xServo.write(base);
  yServo.write(base);
  }
}  
