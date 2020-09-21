#define toggleLED PORTE ^= _BV(PORTE4)

void setup() {
  pinMode(2, OUTPUT);
  PORTE &= ~_BV(PORTE4);
  delay(1000);
}

void loop() {
  toggleLED;
  delay(1000);
}
