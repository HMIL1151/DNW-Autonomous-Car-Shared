//Autonomous Car Project
//Motor Control Script
//Harrison I. L. Milburn
//29.05.2024
//Arduino Uno Rev3

//Setup variables for the speed pins
int leftSpeedPin = 10;    //ENA
int rightSpeedPin = 5;    //ENB

//Setup variables for the direction
int leftCwPin = 9;        //IN1
int leftCcwPin = 8;       //IN2
int rightCwPin = 7;       //IN3
int rightCcwPin = 6;      //IN4

void setup() {
  //Set Pin Modes to Output or Input
  pinMode(leftSpeedPin, OUTPUT);
  pinMode(rightSpeedPin, OUTPUT);
  pinMode(leftCwPin, OUTPUT);
  pinMode(leftCcwPin, OUTPUT);
  pinMode(rightCwPin, OUTPUT);
  pinMode(rightCcwPin, OUTPUT);
}

void loop() {
  forwards(200);
  delay(100);

  left(150);
  delay(100);

  forwards(200);
  delay(100);

  right(150);
  delay(100);
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
