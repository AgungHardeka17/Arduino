int leds[5] = {3, 4, 5, 6, 7};
int pot = 1;

void setup() {
  Serial.begin(9600);
  delay(100);
  for(int i=0; i<5; i++) {
    pinMode(leds[i], OUTPUT);
  }
  pinMode(pot, INPUT);
}

void loop() {
  int potVal = analogRead(pot);
  Serial.println(potVal);
  int numLEDs = map(potVal, 1023, 900, 0, 5);
  fill(numLEDs);
  delay(1);
}

void fill(int nLEDs) {
  for(int i = 0; i < 5; i++) {
    if(i < nLEDs) {
      digitalWrite(leds[i], HIGH);
    } else {
      digitalWrite(leds[i], LOW);
    }
  }
}
