int lightsensor = 0;
int initialLight = 0;

void setup() {
 Serial.begin(19200); 
 pinMode(lightsensor, INPUT);
 initialLight = analogRead(lightsensor);
}

int printNow = 1;
int sincePrint = 0;

void loop() {
  int lightVal = analogRead(lightsensor);
  
  if(lightVal > initialLight+100 && printNow == 1) {
    Serial.println("@donnywals It's dark in here man! lightVal: "+String(lightVal));
    printNow = 0;
  }
  sincePrint = sincePrint + 10;
  if(sincePrint >= 10000) {
    printNow = 1;
    sincePrint = 0;
  }

  delay(1);
}
