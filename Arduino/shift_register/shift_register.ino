int cp = 35;
int ds2 = 36;
int rstn = 37;

void setup() {
  pinMode(cp,OUTPUT);
  pinMode(ds2,OUTPUT);
  pinMode(rstn,OUTPUT);
  digitalWrite(rstn,LOW);
  delay(10);
  digitalWrite(rstn,HIGH);
}

void loop() {
  digitalWrite(cp,LOW);
  digitalWrite(ds2,HIGH);
  delay(100);
  digitalWrite(cp,HIGH);
  delay(100);
  digitalWrite(ds2,LOW);
  for(int i=0; i<8; i++){
    delay(500);
    digitalWrite(cp,LOW);
    delay(500);
    digitalWrite(cp,HIGH);
  }
}
