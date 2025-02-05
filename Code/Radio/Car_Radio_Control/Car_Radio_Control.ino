int channel1Pin = 11;
int channel2Pin = 10;
int channel3Pin = 8;
int channel4Pin = 7;
int channel5Pin = 4;

void setup() {
  // put your setup code here, to run once:
    Serial.begin(9600);
    pinMode(channel1Pin, INPUT);
    pinMode(channel2Pin, INPUT);
    pinMode(channel3Pin, INPUT);
    pinMode(channel4Pin, INPUT);
    pinMode(channel5Pin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int channel1Value = pulseIn(channel1Pin, HIGH); //Left/Right Thumbstick
  int channel2Value = pulseIn(channel2Pin, HIGH); //Up/Down Thumbstick
  int channel3Value = pulseIn(channel3Pin, HIGH); //Number 3 Button
  int channel4Value = pulseIn(channel4Pin, HIGH); //Number 4 Button
  int channel5Value = pulseIn(channel5Pin, HIGH); //Number 5 Button
  
  if (channel2Value > 1500){
    Serial.println("Forwards");
    forwards(220);
  }
  else if (channel2Value < 500){
    Serial.println("Backwards");
    backwards(220);
  }
  else if (channel1Value > 1500){
    Serial.println("Right");
    right(220);
  }
  else if (channel1Value < 500){
    Serial.println("Left");
    left(220);
  }
  else[
    Serial.println("Stop");
    stop();
  ]
}