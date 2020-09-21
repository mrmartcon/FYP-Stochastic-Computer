int a = 35;
int b = 36;
int sel = 37;

void setup() {
  pinMode(a,OUTPUT);
  pinMode(b,OUTPUT);
  pinMode(sel,OUTPUT);

  digitalWrite(a,HIGH);
  digitalWrite(b,LOW);
}

void loop() {
  digitalWrite(sel,HIGH);
  delay(1000);
  digitalWrite(sel,LOW);
  delay(1000);
}
