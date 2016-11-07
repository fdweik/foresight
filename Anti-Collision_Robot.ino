//#include <Ultrasonic.h>

//defines ultrasonic pins
const int TP = 3;
const int EP = 2;
int spd = A0;
#include <Wire.h>
#include <rgb_lcd.h>

//declares lcd
rgb_lcd lcd;

//sets backlight color
int colorR = 255;
int colorG = 0;
int colorB = 0;

//defines ultrasonic variables
long duration;
double distance;

void setup() {
  pinMode(spd, INPUT); //sets potentiometer
  pinMode(A2, INPUT); //sets PVC
  pinMode(TP,OUTPUT); //sets trigger pin as output
  pinMode(EP,INPUT);  //sets echo pin as an input

  Serial.begin(9600); //sets up serial port for communication
}

void loop() {
  UltrasonicD();
  Serial.print("Distance: "); //prints Distance: 
  Serial.println(distance); //prints current ultrasonic distance
}

void UltrasonicD () { //reads distance from ultrasonic sensor
  //clears trigger pin
  digitalWrite(TP, LOW);
  delayMicroseconds(2);

  //sets trigger pin on high state for 10 microseconds
  digitalWrite(TP, HIGH);
  delayMicroseconds(10);
  digitalWrite(TP, LOW);

  //reads echo pin and returns sound wave in microseconds
  duration = pulseIn(EP, HIGH);

  //calculates distance
  distance = duration*.034/2;
}

