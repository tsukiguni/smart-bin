#include <Arduino.h>
#include <NewPing.h>
#include <Servo.h>

#define TRIG_PIN 8
#define ECHO_PIN 9
#define MAX_DISTANCE 400

// init the sonar and servo
NewPing sonar(TRIG_PIN, ECHO_PIN, MAX_DISTANCE);
Servo DoorServo;

// motion sensor pin
int pirPin = 5;

// variable that we will store the distance value from the sonar
float distance;
void setup()
{
  Serial.begin(9600);
  DoorServo.attach(3);
  pinMode(pirPin, INPUT);
}

void loop()
{
  motionDetection();
  delay(500);
}

// func to open the bin door when someone gets closer than 5cm
void doorDetection()
{
  distance = sonar.ping_cm();
  while (distance <= 5.00)
  {
    DoorServo.write(90);
    delay(1500);
    distance = sonar.ping_cm();
  }
  DoorServo.write(0);
}

// WIP
void motionDetection()
{
  int motion;
  motion = digitalRead(pirPin);
  Serial.println(motion);
}
