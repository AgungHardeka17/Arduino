int leds[10] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
int baseLED = 0;
int upTime = 0;

void setup() {
  for(int i=0; i<10; i++) {
    pinMode(leds[i], OUTPUT);
  }
  
  fill(10);
  delay(500);
  fill(9);
  delay(500);
  fill(8);
  delay(500);
  fill(7);
  delay(500);
  fill(6);
  delay(500);
  fill(5);
  delay(500);
  fill(4);
  delay(500);
  fill(3);
  delay(500);
  fill(2);
  delay(500);
  fill(1);
  delay(500);
}

int inc = 1;

void loop() {
  
  setLEDRow(baseLED);
  if(inc == 1) {
    baseLED++;
  } else {
    baseLED--;
  }
  
  if(baseLED == 7) {
    inc = 0;
  } else if(baseLED == 0) {
    inc = 1;
  }
  
  delay(75);
}

void setLED(int LEDNumber) {
  digitalWrite(leds[LEDNumber], HIGH);
  for(int i = 0; i<10; i++) {
    if(i != LEDNumber) {
      digitalWrite(leds[i], LOW);
    }
  }
}

void setLEDRow(int LEDNumber) {
  digitalWrite(leds[LEDNumber], HIGH);
  digitalWrite(leds[LEDNumber+1], HIGH);
  digitalWrite(leds[LEDNumber+2], HIGH);
  for(int i = 0; i<10; i++) {
    if(i != LEDNumber && i != LEDNumber+1 && i != LEDNumber+2) {
      digitalWrite(leds[i], LOW);
    }
  }
}

void fill(int nLEDs) {
  for(int i = 0; i < 10; i++) {
    if(i < nLEDs) {
      digitalWrite(leds[i], HIGH);
    } else {
      digitalWrite(leds[i], LOW);
    }
  }
}

void playSound() {
  
  playSound();
}
