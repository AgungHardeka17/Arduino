int r = 9;
int g = 6;
int b = 3;

void setup() {
 pinMode(r, OUTPUT);
 pinMode(g, OUTPUT);
 pinMode(b, OUTPUT);
}

void loop() {
 analogWrite(r, 255);
 analogWrite(g, 0);
 analogWrite(b, 0);
 delay(500);
 analogWrite(r, 0);
 analogWrite(g, 255);
 analogWrite(b, 0);
 delay(500);
 analogWrite(r, 0);
 analogWrite(g, 0);
 analogWrite(b, 255);
 delay(500);
}
