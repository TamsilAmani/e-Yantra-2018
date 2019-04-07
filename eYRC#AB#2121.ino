/* 
 * Team Id : 2121
 * Author List : Tamsil Sajid Amani, Mohd Bilal Aziz, Mohammed Omar Siddiqui, Zaid Hasan
 * Filename: eYRC#AB#2121.ino
 * Theme: Ant Bot (AB)
 * Functions: setup(), servoMotion(), lineSenor(), loop(), setColor(int, int, int)
 * Global Variables: analogPin1 , analogPin2, analogPin3, value1, value2, value3, stservo, micservo, Buzzer, redPin, greenPin, bluePin
 */

#include <Servo.h>

int analogPin1 = 0;  
int analogPin2 = 2;
int analogPin3 = 4;
int value1 = 0;
int value2 = 0;
int value3 = 0;
int value = 0;
Servo stservo;
Servo micservo;
int Buzzer = 13;

int redPin = 9;
int greenPin = 10;
int bluePin = 11;

/*
 * Function Name: setup
 * Input: None
 * Output: Setup motors, led, buzzer
 * Logic: Setup procedures
 * Example Call: setup()
*/
void setup()
{
  Serial.begin(9600);
  stservo.attach(3);
  micservo.attach(6);
  stservo.write(12);
  micservo.write(25);
}

void servoMotion()
{
  stservo.write(12);
  delay(2000);
  micservo.write(25);
  delay(2000);
  micservo.write(47);
  delay(2000);
  stservo.write(25);
  delay(2000);
}

void lineSenor()
{
  value1 = analogRead(analogPin1);     // read the input pin
  value2 = analogRead(analogPin2);     // read the input pin
  value3 = analogRead(analogPin3);     // read the input pin
  Serial.print(value1);
  Serial.print(" ");
  Serial.print(value2);
  Serial.print(" ");
  Serial.println(value3);
  //servoMotion();
  //digitalWrite(Buzzer, LOW);
}

void loop()
{
  lineSenor();

  if(Serial.available()){

  }

  setColor(255, 0, 0);

  delay(10);
}


void setColor(int red, int green, int blue)
{
  red = 255 - red;
  green = 255 - green;
  blue = 255 - blue;
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);  
}