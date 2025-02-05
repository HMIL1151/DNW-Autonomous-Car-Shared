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
  
  Serial.print("Channel 1: ");
  Serial.print(channel1Value);
  Serial.print(", Channel 2: ");
  Serial.print(channel2Value);
  Serial.print(", Channel 3: ");
  Serial.print(channel3Value);
  Serial.print(", Channel 4: ");
  Serial.print(channel4Value);
  Serial.print(", Channel 5: ");
  Serial.println(channel5Value);
}