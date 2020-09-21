void setup() {
  for(int i=0;i<16;i++){
    pinMode(38+i,OUTPUT);
  }

  //number P = 47
//  digitalWrite(38,HIGH);
//  digitalWrite(39,HIGH);
//  digitalWrite(40,HIGH);
//  digitalWrite(41,HIGH);
//  digitalWrite(42,LOW);
//  digitalWrite(43,HIGH);
//  digitalWrite(44,LOW);
//  digitalWrite(45,LOW);

  digitalWrite(38,HIGH);
  digitalWrite(39,HIGH);
  digitalWrite(40,HIGH);
  digitalWrite(41,HIGH);
  digitalWrite(42,HIGH);
  digitalWrite(43,HIGH);
  digitalWrite(44,HIGH);
  digitalWrite(45,HIGH);

  //numer Q = 165
//  digitalWrite(46,HIGH);
//  digitalWrite(47,LOW);
//  digitalWrite(48,HIGH);
//  digitalWrite(49,LOW);
//  digitalWrite(50,LOW);
//  digitalWrite(51,HIGH);
//  digitalWrite(52,LOW);
//  digitalWrite(53,HIGH);

  digitalWrite(46,HIGH);
  digitalWrite(47,HIGH);
  digitalWrite(48,HIGH);
  digitalWrite(49,HIGH);
  digitalWrite(50,LOW);
  digitalWrite(51,HIGH);
  digitalWrite(52,LOW);
  digitalWrite(53,LOW);

  //so P<Q
}

void loop() {
  // put your main code here, to run repeatedly:

}
