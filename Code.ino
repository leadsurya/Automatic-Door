// C++ code
//
#include <Servo.h>

int distance = 0;

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}

Servo servo_10;

void setup()
{
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  servo_10.attach(10, 500, 2500);
}

void loop()
{
  distance = 0.01723 * readUltrasonicDistance(12, 11);
  Serial.println(distance);
  if (distance <= 25) {
    digitalWrite(13, HIGH);
    servo_10.write(90);
    delay(2000); // Wait for 2000 millisecond(s)
    digitalWrite(13, LOW);
    servo_10.write(0);
  } else {
    servo_10.write(0);
  }
}
