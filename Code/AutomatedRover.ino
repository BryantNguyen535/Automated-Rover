/*
Team: ZotGPT
Ben Vu, Bryant Ngo Nguyen, Cole Tateyama, Maddox Anthony Reyes, Rafael Julian Cortes
Last Edit: 2/21/24
This code allows for a rover to follow a line, then switch to a camera to track a object of a specific color and grab it.
*/

#include "CytronMotorDriver.h"
#include <Pixy2.h>
#include <Servo.h>

//Initialize Variables
//General Control
bool Active=true;
//PixyCam Tracking Constants
int trackingRange=10;
int trackingObjSize=150;
int object_x;
int object_width;
//Initialize Sensor Pin #'s
int sensor1=2; //Leftmost Sensor
int sensor2=4;
int sensor3=5; //Rightmost Sensor
int sensor1OUT;
int sensor2OUT;
int sensor3OUT;
//Initialize Servo Pin #'s
int S1=9;
//Motor Setup
CytronMD motor1(PWM_DIR, 3, 8); //LEFT MOTOR
CytronMD motor2(PWM_DIR, 6, 7); //RIGHT MOTOR
//Servo Setup
Servo servo;
//PIXYCAM Setup
Pixy2 pixy;

void setup()
{
Serial.begin(19200);
pinMode(sensor1, INPUT);
pinMode(sensor2, INPUT);
pinMode(sensor3, INPUT);
servo.attach(9);
pixy.init();
pixy.changeProg("color_connected_components");
servo.write(0);
}

void loop() //Read, Calc, Move
{
  while(Active==true) //code loops the linetrack code until it reaches the end of the track, then switches to the PixyCam code
  {
    lineTrack();
  } 
  PixyCamTrack(); 
}

void lineTrack() //Line tracking code for rover to follow line
{
  sensor1OUT=digitalRead(sensor1);
  sensor2OUT=digitalRead(sensor2);
  sensor3OUT=digitalRead(sensor3);
  //Sensor Read: *HIGH=Detects line  Negative = Left  Positive = Right
  if(sensor1OUT==LOW &&  sensor3OUT==LOW) //Detects no line on left/right sensors
  {
    motor1.setSpeed(120);
    motor2.setSpeed(120);
  }

  if(sensor1OUT==LOW &&  sensor3OUT==HIGH) //Detects when veering right
  {
    motor1.setSpeed(-200); //turn left
    motor2.setSpeed(150);
  }

  if(sensor1OUT==HIGH &&  sensor3OUT==LOW) //Detects when veering left
  {
    motor1.setSpeed(150); //turn right
    motor2.setSpeed(-200);
  }

  if(sensor1OUT==HIGH && sensor2OUT==HIGH && sensor3OUT==HIGH) //Detects line at end of track
  {
    motor1.setSpeed(0);
    motor2.setSpeed(0);
    Active=false; //disable line tracking code
  }
}

void PixyCamTrack() //Handles PixyCam code to track object + move toward it
{
  pixy.ccc.getBlocks(); //All blocks within frame

  object_x=pixy.ccc.blocks[0].m_x; //Track x value of largest block
  object_width=pixy.ccc.blocks[0].m_width; //Track width of largest block

  if(object_x<(157-trackingRange)) //If object is left of midline + theshold value
  {
    motor1.setSpeed(75); //turn Right
    motor2.setSpeed(-75); 
    servo.write(0);
  }
  else if(object_x>(157+trackingRange)) //If object is right of midline + threshold value
  {
    motor1.setSpeed(-75); //turn Left
    motor2.setSpeed(75); 
    servo.write(0);
  }
  else if(object_width<trackingObjSize) //If object is smaller than threshold size
  {
    motor1.setSpeed(100); //Straight
    motor2.setSpeed(100);
    servo.write(0);
  }
  if(object_width>trackingObjSize) //If object is greater than threshold size
  {
    motor1.setSpeed(0); //Stop
    motor2.setSpeed(0);
    servo.write(180); //Servo Motor close
    delay(500);
  }
}
