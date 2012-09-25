// Array met de pins die je gebruikt voor leds
int leds[5] = {3, 4, 5, 6, 7};
// Analog pin die je gebruikt voor je sensor
int sensor = 1;

void setup() {
  // Open seriele communicatie
  Serial.begin(9600);
  // Vertraging om de Aruino de seriele communicatie te laten openen
  delay(100);
  // Set alle pins in het leds array als OUTPUT
  for(int i=0; i<5; i++) {
    pinMode(leds[i], OUTPUT);
  }
  // Set de sensor als input
  pinMode(sensor, INPUT);
}

void loop() {
  // Lees de sensor uit
  int sensorVal = analogRead(sensor);
  // Schrijf de waarde van de sensor weg via seriele communicatie
  Serial.println(sensorVal);
  // Bepaal het aantal LEDs dat aanmoeten via de map() functie
  int numLEDs = map(sensorVal, 850, 1000, 0, 5);
  // roep de fill() functie aan om het gewenste aantal LEDs aan te zetten.
  fill(numLEDs);
  delay(1);
}

void fill(int nLEDs) {
  // voer de inhoud van deze loop 5 keer uit (het aantal leds dat er aangesloten zijn)
  for(int i = 0; i < 5; i++) {
    // als i kleiner is dan het aantal LEDs dat aanmoeten, zet hem dan aan
    if(i < nLEDs) {
      digitalWrite(leds[i], HIGH);
    } 
    // als i groter is dan het aantal LEDs dat aanmoeten, zet hem dan uit
    else {
      digitalWrite(leds[i], LOW);
    }
  }
}
