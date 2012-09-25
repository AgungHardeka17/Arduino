int ledPin = 7;

void setup() {
  pinMode(7, OUTPUT);
  Serial.begin(9600);
  delay(500);
  Serial.println("hello python!");
}

int ledOn = 0;
int ledTimeout = 9600;
int ledTimeon = 0;

void loop() {
  int receivedData;
  
  while(Serial.available() == 0) {
    if(ledOn == 1) {
      ledTimeon++;
      if(ledTimeon == ledTimeout) {
        ledOn = 0;
        ledTimeon = 0;
        digitalWrite(ledPin, LOW);
      }
    }
  }
  
  receivedData = Serial.read() - '0';
  Serial.flush();
  
  if(receivedData == 0) {
    ledOn = 1;
    digitalWrite(ledPin, HIGH);
  }
  
  delay(1);
}
