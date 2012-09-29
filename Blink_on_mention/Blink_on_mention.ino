int led = 9;

void setup() {
  Serial.begin(19200);
  pinMode(led, OUTPUT);
}

int timeSinceLedLightup = 0;
int ledIsOn = 0;

void loop() {  
  if(ledIsOn == 1) {
    timeSinceLedLightup++;
  }
  
  if(timeSinceLedLightup == 500) {
    digitalWrite(led, LOW);
    timeSinceLedLightup = 0;
    ledIsOn = 0;
  }
  
  delay(1);
}

void serialEvent() {
  digitalWrite(led, HIGH);
  delay(500);
  digitalWrite(led, LOW);
}
