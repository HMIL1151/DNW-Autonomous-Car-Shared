//Autonomous Car Project
//Autonomous Control Script
//Harrison I. L. Milburn
//07.04.2024
//Arduino Uno Rev3

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
        left(220);
        delay(300);

        stop();
        delay(200);
    }

    else{
        forwards(200);
    }
}



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