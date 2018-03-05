//zoomkat 11-22-12 simple delimited ',' string parse 
//from serial port input (via serial monitor)
//and print result out serial port
//multi servos added 

String readString;
#include <Servo.h> 
Servo xServo, yServo;  // create servo object to control a servo 

void setup() {
  Serial.begin(9600);

  //xServo.writeMicroseconds(1500); //set initial servo position if desired

  xServo.attach(6);  //the pin for the servoa control
  yServo.attach(7);  //the pin for the servob control // so I can keep track of what is loaded
}

void loop() {

  //expect single strings like 700a, or 1500c, or 2000d,
  //or like 30c, or 90a, or 180d,
  //or combined like 30c,180b,70a,120d,

  if (Serial.available())  {
    char c = Serial.read();  //gets one byte from serial buffer
    if (c == ',') {
      if (readString.length() >1) {
        Serial.println(readString); //prints string to serial port out

        int n = readString.toInt();  //convert readString into a number

        // auto select appropriate value, copied from someone elses code.
        if(n >= 500)
        {
          Serial.print("writing Microseconds: ");
          Serial.println(n);
          if(readString.indexOf('a') >0) xServo.writeMicroseconds(n);
          if(readString.indexOf('b') >0) yServo.writeMicroseconds(n);
        }
        else
        {   
          Serial.print("writing Angle: ");
          Serial.println(n);
          if(readString.indexOf('a') >0) xServo.write(n);
          if(readString.indexOf('b') >0) yServo.write(n);
        }
         readString=""; //clears variable for new input
      }
    }  
    else {     
      readString += c; //makes the string readString
    }
  }
}