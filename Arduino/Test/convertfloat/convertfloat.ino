void setup() {
//  float f = 0.4;
//  float f1 = 0.5;
//  float f2 = 0.1;
//  float f3 = 0.1;
//  float f4 = 0.2;
//  float f5 = 0.8;
//  
//  byte x = convertFloat(f);
//  byte x1 = convertFloat(f1);
//  byte x2 = convertFloat(f2);
//  byte x3 = convertFloat(f3);
//  byte x4 = convertFloat(f4);
//  byte x5 = convertFloat(f5);
//
//  Serial.begin(9600);
//  Serial.println(x,HEX);
//  Serial.println(x1,HEX);
//  Serial.println(x2,HEX);
//  Serial.println(x3,HEX);
//  Serial.println(x4,HEX);
//  Serial.println(x5,HEX);

//=====================================================================
  byte b = 0b00011111;
  Serial.begin(9600);
  float f = convertByte(b);
  
}

byte convertFloat(float fz){
  //Serial.print("Received: ");
  //Serial.println(fz);
  int16_t shift = 0;
  int32_t mantissa;
  byte val;
  while(fz < 1.0){
    fz *= 2.0;
    shift--;
  }
  fz = fz - 1.0;
  mantissa = fz*(0x800000 + 0.5f);
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

void loop() {
  // put your main code here, to run repeatedly:

}
