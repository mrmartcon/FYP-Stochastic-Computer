int sel = 35;
int cp = 36;
int rstn = 37;
int stochastic_bits = 34;
int stochastic_bits2 = 33;

float count = 0;
float ones = 0;
float ones2 = 0;

void setup() {
  pinMode(cp,OUTPUT);
  pinMode(sel,OUTPUT);
  pinMode(rstn,OUTPUT);

  //number Q
  for(int i=0;i<8;i++){
    pinMode(38+i,OUTPUT);
  }
  digitalWrite(38,LOW);
  digitalWrite(39,LOW);
  digitalWrite(40,LOW);
  digitalWrite(41,LOW);
  digitalWrite(42,LOW);
  digitalWrite(43,LOW);
  digitalWrite(44,HIGH);
  digitalWrite(45,HIGH);
  
  //number Q2
  for(int i=0;i<8;i++){
    pinMode(46+i,OUTPUT);
  }
  digitalWrite(46,LOW);
  digitalWrite(47,LOW);
  digitalWrite(48,LOW);
  digitalWrite(49,LOW);
  digitalWrite(50,LOW);
  digitalWrite(51,HIGH);
  digitalWrite(52,LOW);
  digitalWrite(53,LOW);

  pinMode(stochastic_bits,INPUT);
  pinMode(stochastic_bits2,INPUT);

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

  Serial.begin(9600);
}

void loop() {
  count++;
  
  digitalWrite(cp,HIGH);
  delay(10);
  digitalWrite(cp,LOW);
  delay(10);
  
  if(digitalRead(stochastic_bits) == HIGH){
    ones++;
  }
  if(digitalRead(stochastic_bits2) == HIGH){
    ones2++;
  }

  if(count==255){
    float value = ones/count;
    float value2 = ones2/count;
    Serial.print("Value 1 is: ");
    Serial.println(value);
    Serial.print("Value 2 is: ");
    Serial.println(value2);
    count = 0;
    ones = 0;
    ones2 = 0;
  }
}
