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
int cp = 18; // changed to pin 18, CMA 30/3/2020

byte number1s[5] = {B01100110,B10011001,B11000000,B00100000,B11100110}; //0.4, 0.6, 0.75, 0.125, 0.9
byte number2s[5] = {B10000000,B00110011,B00011010,B11001101,B01000000}; //0.5, 0.2, 0.1, 0.8, 0.25

void setup() {
  pinMode(sel,OUTPUT);
  pinMode(sel2,OUTPUT);
  pinMode(rstn,OUTPUT);
  pinMode(cp,OUTPUT);
  pinMode(rstcntr,OUTPUT);

  DDRA = B00000000; //read port A for counter value;
  DDRC = B11111111; //write to port C for number 1;
  DDRL = B11111111; //write to port L for number 2;

  initClk;  //set clock low
  
  initSel;  //Set sel low
  initSel2;   //Set sel2 high

  //clear shift registers
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

  Serial.begin(9600);
  initCounterClear;
  toggleCounterClear;

  setupClock();
}

//////////////////////////////////////////////////////////////////////////////////////////////

byte bitStreamPattern[51];

void setupClock() {
  for (int i=0; i<51; i++) bitStreamPattern[i] = 0x55;  
  Serial1.begin(2000000); // max baud is 2000000 (gives ~1MHz clock rate)
}

void runClockSequence() {
  // Run the clock for 255 cycles
  Serial1.write(bitStreamPattern, 51); // Output all 51 bytes for 255 clk cycles).
  while (!(UCSR1A & _BV(TXC1))); // Wait until serial buffer fully transmitted (need to do this because call to write is asynchronous)
}

void stocMulTest(int testIndex) {
  PORTC = number1s[testIndex];
  PORTL = number2s[testIndex];
  runClockSequence();
  float product = PINA/255.0;
  /* Uncomment to print result */
  Serial.print("Test Result #");
  Serial.print(testIndex);
  Serial.print(" = ");
  Serial.println(product);
  // faster strobe of rstcntr pin
  toggleCounterClear;
  toggleCounterClear;
}

int testIndx = 0;

void loop() {
  if (testIndx < 5)
    stocMulTest(testIndx++);
}
