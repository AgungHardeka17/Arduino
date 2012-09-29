#define DARK_MSG 0

// define pins
int led = 9;

/*
* sensor returns values between 500 and 1018
* 1018 = dark
* 500 = light
*/
int lightSensor = 0;

// other vars
boolean serialReceived = false;
String receivedString = "";

void setup() {
    Serial.begin(9600);
    
    pinMode(led, OUTPUT);

    pinMode(0, INPUT);
}

void loop() {
    int lightVal = analogRead(lightSensor);
    if(lightVal >= 950) {
        sendMessage(DARK_MSG);
    }
    
    if(serialReceived == true) {
        if(receivedString == "0") {
            digitalWrite(led, HIGH);
        } else if(receivedString == "1") {
            digitalWrite(led, LOW);
        }
        receivedString = "";
        serialReceived = false;
    }
}

void sendMessage(int message) {
    Serial.println(message);
    delay(500);
}

void serialEvent() {
    while(Serial.available()) {
        char incomingChar = (char)Serial.read();
        
        receivedString += incomingChar;
        
        serialReceived = true;
    }
}