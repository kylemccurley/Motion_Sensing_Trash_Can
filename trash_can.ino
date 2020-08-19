#include <Servo.h>
Servo myservo;

// defines pins numbers
const int trigPin = 3;
const int echoPin = 2;

// defines variables
long duration;
int distance;
int pos = 0;
void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600); // Starts the serial communication
  myservo.attach(8); // Initialize the servo motor to digital pin 8
}

void loop() {
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance= duration*0.034/2;
  // Prints the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.println(distance);
  if (distance < 75) {
    while (pos < 170) {
      myservo.write(pos);
      pos += 2;
    }
   
    delay(5000);
  } else if (distance > 75) {
    while (pos > 0) {
      myservo.write(pos);
      pos -= 1;
      delay(20);
    }
  }
}
