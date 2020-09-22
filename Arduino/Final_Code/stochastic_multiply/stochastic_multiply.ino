#define initClk PORTD &= ~_BV(PORTD3)
#define initSel PORTD &= ~_BV(PORTD7)
#define initSel2 PORTG |= _BV(PORTG2)
#define initCounterClear PORTG &= ~_BV(PORTG0)
#define toggleClk PORTD ^= _BV(PORTD3)
#define toggleSel PORTD ^= _BV(PORTD7)
#define toggleSel2 PORTG ^= _BV(PORTG2)
#define toggleCounterClear PORTG ^= _BV(PORTG0)

int sel = 38;
int sel2 = 39;
int rstn = 40;
int rstcntr = 41;
int cp = 18;

void setup() {
  pinMode(sel,OUTPUT);
  pinMode(sel2,OUTPUT);
  pinMode(rstn,OUTPUT);
  pinMode(cp,OUTPUT);
  pinMode(rstcntr,OUTPUT);

  DDRA = B00000000; //read port A for counter value;
  DDRC = B11111111; //write to port C for number 1;
  DDRL = B11111111; //write to port L for number 2;
  
  Serial.begin(9600);
}

float coordinates[2] = {0.0,0.0};
float result = 0.0;
int index = 0;

byte convertFloat(float f){
  int16_t shift=0;
  int32_t mantissa;
  byte val;
  while(f < 1.0){
    f *= 2.0;
    shift--;
  }
  f = f - 1.0;
  mantissa = f*(0x800000 + 0.5f);
  mantissa = (mantissa>>1) + 0x400000;
  val = mantissa>>(14-shift);
  return val;
}

float convertByte(byte bz){
  int32_t shift = 0;
  int32_t mantissa = 0;
  float result = 0;

  while((bz&0x80) != 0x80){
    bz = bz<<1;
    shift--;
  }
  
  bz = bz<<1;
  shift--;
  mantissa = bz;
  result = mantissa<<15;
  result /= 0x800000;
  result += 1.0f;
  while(shift<0){
    result /= 2.0;
    shift++;
  }
  Serial.println(result,BIN);
  return result;
}

void setupMultiply(){
  initClk;  //set clock low
  
  initSel;  //Set sel low
  initSel2;   //Set sel2 high
  
  /*Turn all outputs to low*/
  PORTG &= ~_BV(PORTG1);
  PORTG |= _BV(PORTG1);

  /*Read in high to shift register*/
  toggleClk;
  toggleClk;
  
  toggleSel2; //toggle sel2 low
  
  toggleClk;
  toggleClk;

   /*Now set input to shift register as output from XOR gates*/
  toggleSel; //toggle sel high
  toggleSel2; //toggle sel2 high

  initCounterClear;
  toggleCounterClear;
}

float stochasticMultiply(float f1, float f2){
  setupMultiply();
  
  PORTC = convertFloat(f1);
  PORTL = convertFloat(f2);

  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  toggleClk;
  float product = PINA/255.0;

  toggleCounterClear;
  toggleCounterClear;

  return product;
}

void loop() {
  if(Serial.available()>0){
    coordinates[index] = Serial.parseFloat();
    index++;
  }

  if(index==2){
    float ans = stochasticMultiply(coordinates[0],coordinates[1]);
    Serial.println(ans,6);
    Serial.println("end");
    index = 0;
  }
}
