int incomingByte = 0;

void setup() {
  Serial.begin(9600);
  delay(500);
  Serial.println("hello python!");
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);
}

int ledTimeout = 2000;
int ledTimeon = 0;
int ledOn = 1;

void loop() {
  while(Serial.available() == 1) {
    blinkLed();
    Serial.flush();
  }
  
  if(ledOn == 1) {
    ledTimeon++;
    if(ledTimeon == ledTimeout) {
      ledOn = 0;
      digitalWrite(13, LOW);
      ledTimeon = 0;
    }
  }
  
 
  
  delay(1);
}
