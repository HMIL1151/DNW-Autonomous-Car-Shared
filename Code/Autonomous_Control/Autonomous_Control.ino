//Autonomous Car Project
//Autonomous Control Script
//Harrison I. L. Milburn
//05.02.2025
//Arduino Uno Rev3

#include "Arduino.h"
#include "Functions.h"

int trigPin = 3;            // Trigger pin
int echoPin = 4;            // Echo pin

void setup() {
    //Set Pin Modes to Output or Input
    pinMode(leftSpeedPin, OUTPUT);
    pinMode(rightSpeedPin, OUTPUT);
    pinMode(leftCwPin, OUTPUT);
    pinMode(leftCcwPin, OUTPUT);
    pinMode(rightCwPin, OUTPUT);
    pinMode(rightCcwPin, OUTPUT);

    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
}

void loop() {

    long duration, distance; // Variables to store the duration of sound wave travel and calculated distance
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH); // Send a 10us pulse to trigger the sensor
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    duration = pulseIn(echoPin, HIGH); // Measure the time it takes for the echo to return
    distance = (duration * 0.0343) / 2; // Calculate distance in centimeters (speed of sound in air is approximately 343 m/s)

    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");

    delay(50); // Delay for stability

    if (distance < 17){
        stop();
        delay(200);

        left(220);
        delay(300);

        stop();
        delay(200);
    }

    else{
        forwards(200);
    }
}