#ifndef FUNCTIONS_H
#define FUNCITONS_H

//Setup variables for the speed pins
int leftSpeedPin = 10;    //ENA
int rightSpeedPin = 5;    //ENB

//Setup variables for the direction
int leftCwPin = 9;        //IN1
int leftCcwPin = 8;       //IN2
int rightCwPin = 7;       //IN3
int rightCcwPin = 6;      //IN4

//Setup variables for Ultrasonic Sensor Pins
int trigPin = 3;            // Trigger pin
int echoPin = 4;            // Echo pin

void forwards(int speed){
    //Left Clockwise
    digitalWrite(leftCwPin, HIGH);
    digitalWrite(leftCcwPin, LOW);

    //Right Clockwise
    digitalWrite(rightCwPin, HIGH);
    digitalWrite(rightCcwPin, LOW);

    //Output Speed
    analogWrite(leftSpeedPin, speed);
    analogWrite(rightSpeedPin, speed);
}

void backwards(int speed){
    //Left Counter-Clockwise
    digitalWrite(leftCwPin, LOW);
    digitalWrite(leftCcwPin, HIGH);

    //Right Counter-Clockwise
    digitalWrite(rightCwPin, LOW);
    digitalWrite(rightCcwPin, HIGH);

    //Output Speed
    analogWrite(leftSpeedPin, speed);
    analogWrite(rightSpeedPin, speed);
}

void left(int speed){
    //Left Counter-Clockwise
    digitalWrite(leftCwPin, LOW);
    digitalWrite(leftCcwPin, HIGH);

    //Right Clockwise
    digitalWrite(rightCwPin, HIGH);
    digitalWrite(rightCcwPin, LOW);

    //Output Speed
    analogWrite(leftSpeedPin, speed);
    analogWrite(rightSpeedPin, speed);
}

void right(int speed){
    //Left Clockwise
    digitalWrite(leftCwPin, HIGH);
    digitalWrite(leftCcwPin, LOW);

    //Right Counter-Clockwise
    digitalWrite(rightCwPin, LOW);
    digitalWrite(rightCcwPin, HIGH);

    //Output Speed
    analogWrite(leftSpeedPin, speed);
    analogWrite(rightSpeedPin, speed);
}

void stop(){
    analogWrite(leftSpeedPin, 0);
    analogWrite(rightSpeedPin, 0);
}

#endif