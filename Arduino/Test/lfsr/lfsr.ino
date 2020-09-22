int sel = 35;
int cp = 36;
int rstn = 37;
int count = 0;
int values[256];
int values2[256];

void setup() {
  pinMode(cp,OUTPUT);
  pinMode(sel,OUTPUT);
  pinMode(rstn,OUTPUT);

  for(int i=0;i<16;i++){
    pinMode(38+i,INPUT);
  }
  
  digitalWrite(cp,LOW);
  digitalWrite(sel,LOW); /*Set input to shift register as high for seed*/

  /*Turn all outputs to low*/
  digitalWrite(rstn,LOW);
  delay(10);
  digitalWrite(rstn,HIGH);

  /*Read in high to shift register*/
  digitalWrite(cp,HIGH);
  delay(10);
  digitalWrite(cp,LOW);
  delay(10);

  /*Now set input to shift register as output from XOR gates*/
  digitalWrite(sel,HIGH);

  for(int n=0;n<256;n++){
    values[n] = 0;
    values2[n] = 0;
  }
  
  Serial.begin(9600);
}

void loop() {
  count++;
  
  byte x = 0b00000000;
  byte x2 = 0b00000000;
  digitalWrite(cp,HIGH);
  delay(10);
  digitalWrite(cp,LOW);
  delay(10);
  
  for(int j=0;j<8;j++){
    bitWrite(x,j,digitalRead(38+j));
    bitWrite(x2,j,digitalRead(46+j));
  }

  values[x]++;
  values2[x2]++;

  if(count==255){
    bool noDups = true;
    bool noDups2 = true;
    for(int n=1;n<256;n++){
      if(values[n]!=1) noDups = false;
      if(values2[n]!=1) noDups2 = false;
    }
    Serial.println(noDups ? "Success 1" : "Failure 1");
    Serial.println(noDups2 ? "Success 2" : "Failure 2");
    count = 0;
    for(int n=0;n<256;n++){
      values[n] = 0;
      values2[n] = 0;
    }
  }
}
