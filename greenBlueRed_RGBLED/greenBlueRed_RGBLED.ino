int r = 5;
int g = 6;
int b = 3;
void setup() {
  pinMode(r, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(b, OUTPUT);
}

int rVal = 0;
int gVal = 255;
int bVal = 0;

int rRising = 1;
int gRising = 0;
int bRising = 1;

int updateB = 0;

void loop() {
  analogWrite(r, rVal);
  analogWrite(g, gVal);
  analogWrite(b, bVal);
  
  rVal = updateColor(rVal, rRising, 0);
  gVal = updateColor(gVal, gRising, 0);
  
  rRising = isRising(rVal, rRising);
  gRising = isRising(gVal, gRising);
  
  bVal = updateColor(bVal, bRising, 1);
  bRising = isRising(bVal, bRising);
  
  delay(10);
}

int updateColor(int val, int rising, int doubleRise) {
  if(rising == 1) {
    val++;
    if(doubleRise == 1) val++;
  } else {
    val--;
    if(doubleRise == 1) val--;
  }
  return val;
}

int isRising(int val, int rising) {
  if(val > 253) {
    rising = 0;
  } else if(val < 2) {
    rising = 1;
  }
  return rising;
}
