int sel = 38;
int sel2 = 39;
int rstn = 40;
int rstcntr = 41;
int cp = 18;

int count = 0;

byte number1s[5] = {B01100110,B10011001,B11000000,B00100000,B11100110}; //0.4, 0.6, 0.75, 0.125, 0.9
byte number2s[5] = {B10000000,B00110011,B00011010,B11001101,B01000000}; //0.5, 0.2, 0.1, 0.8, 0.25

int index = 0;

void setup() {
  pinMode(sel,OUTPUT);
  pinMode(sel2,OUTPUT);
  pinMode(rstn,OUTPUT);
  pinMode(cp,OUTPUT);
  pinMode(rstcntr,OUTPUT);

  DDRA = B00000000; //read port A for counter value;
  DDRC = B11111111; //write to port C for number 1;
  DDRL = B11111111; //write to port L for number 2;

  digitalWrite(cp,LOW);
  digitalWrite(sel,LOW); /*Set input to shift register as high for seed*/
  digitalWrite(sel2,HIGH);

  /*Turn all outputs to low*/
  digitalWrite(rstn,LOW);
  delay(1);
  digitalWrite(rstn,HIGH);

  /*Read in high to shift register*/
  digitalWrite(cp,HIGH);
  delay(1);
  digitalWrite(cp,LOW);
  delay(1);
  digitalWrite(sel2,LOW);
  digitalWrite(cp,HIGH);
  delay(1);
  digitalWrite(cp,LOW);
  delay(1);

   /*Now set input to shift register as output from XOR gates*/
  digitalWrite(sel,HIGH);
  digitalWrite(sel2,HIGH);

  Serial.begin(9600);
  digitalWrite(rstcntr,LOW);
  delay(1);
  digitalWrite(rstcntr,HIGH);
  delay(1000);
}

void loop() {
  if(index<5&&count==0){
    PORTC = number1s[index];
    Serial.print("Value 1 is: ");
    Serial.println(((float)number1s[index])/256);
    PORTL = number2s[index];
    Serial.print("Value 2 is: ");
    Serial.println(((float)number2s[index])/256 );
  }
  count++;
  digitalWrite(cp,HIGH);
  delayMicroseconds(1);
  digitalWrite(cp,LOW);
  delayMicroseconds(1);
    
  if(index<5&&count==255){
    float x = PINA;
  
    float product = x/255;
    Serial.print("Product is: ");
    Serial.println(product);
    Serial.println();
    count = 0;
    product = 0;
    index++;
    digitalWrite(rstcntr,LOW);
    delay(1);
    digitalWrite(rstcntr,HIGH);
  }
}
