void setup() {
  Serial.begin(9600);
}

float inputs[6] = {0.0,0.0,0.0,0.0,0.0,0.0};
byte outputs[6] = {0,0,0,0,0,0};
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

void loop() {
  if(Serial.available()>0){
    inputs[index] = Serial.parseFloat();
    index++;
  }
  
  if(index==2){
    for(int i=0; i<2; i++){
      outputs[i]=convertFloat(inputs[i]);
      Serial.println(outputs[i]);
    }
    Serial.println("end");
    index = 0;
  }
}
