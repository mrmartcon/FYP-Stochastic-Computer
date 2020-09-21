void setup() {
  DDRA = B11111111;
  PORTA = B10101010;
  DDRC = B00000000;
  DDRL = B00000000;
  DDRF = B00111111;
  Serial.begin(9600);
}

void loop() {
  int xc = PINC;
  int xl = PINL;
  int xf = PINF;
  Serial.println(xc);
  Serial.println(xl);
  Serial.println(xf);
  xf = (xf<<2)+xl;
  Serial.println(xf);
  delay(1000);
}
