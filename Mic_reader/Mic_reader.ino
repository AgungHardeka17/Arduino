void setup() {
  pinMode(0, INPUT);
  pinMode(9, OUTPUT);
  Serial.begin(9600);
}

int audioVal = 0;

void loop() {
  int dAudio = 0;
  int audioIn = analogRead(0);
  if(audioIn > audioVal) {
    dAudio = audioIn - audioVal;
  } else {
    dAudio = audioVal - audioIn;
  }
  int ledVal =map(audioIn, 650, 1023, 0, 255);
  analogWrite(9, ledVal);
  Serial.println(ledVal);
  audioVal = audioIn;
  delay(1);
}
