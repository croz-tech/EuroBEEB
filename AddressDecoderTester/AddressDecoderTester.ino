// Address Decoder Mapper 
// Uses Arduino Mega | S.Crozier | Dec 2024
// ----------------------------------------
// 1. Runs through all addresses in turn (as outputs)
// 2. Reads in the decoded enable signals
// 3. Prints these over the serial port for address 0x0000
// and then each time an output state changes until 0xFFFF
// - Effectively display a memory map 

// Address lines
// A15=pin22 through A0=pin52 (even pins)
//
// Decoded enable lines
// E7=pin39 through E0=pin53 (odd pins)
// format = LSB ...... MSB below
// Address LSB = brown,  MSB = blue
// Enable  LSB = purple, MSB = yellow
const char ADDR[] = {22, 24, 26, 28, 30, 32, 34, 36, 38, 40, 42, 44, 46, 48, 50, 52};
const char ENABLE[] = {39, 41, 43, 45, 47, 49, 51, 53};
#define PERIOD 1    // Settling time from addressing to read (ms)

void setup() {
  // Setup port directions (Address lines as outputs, Enable lines as inputs)
  for (int n=0; n<=15; n++) {
    pinMode(ADDR[n], OUTPUT);
  }
   for (int n=0; n<=7; n++) {
    pinMode(ENABLE[n], INPUT);
  }
  Serial.begin(57600);
  Serial.println ("Address decoding / memory mapper - Steve C - Dec 2024");
  Serial.println ();
  Serial.println ("Address | E0 | E1 | E2 | E3 | E4 | E5 | E6 | E7 ");
  Serial.println ("------------------------------------------------");

  unsigned int LastWord=0x0000;
  // Loop through each of 16 bit addresses
  for (unsigned int Address=0x0000 ; Address<0xFFFF ; Address++) {
    // Set up the address output (not the most efficient way but bits aren't contiguous on one port)
    for (unsigned int BitIdx=0 ; BitIdx<=15 ; BitIdx++) {
      digitalWrite(ADDR[BitIdx],bitRead(Address,BitIdx));
    }
    delay (PERIOD);
    // Now read the decoded enable lines
    unsigned int ReadWord=0;
    for (int BitIdx=0; BitIdx<=7; BitIdx++) {
      int Bit = digitalRead(ENABLE[BitIdx]) ? 1:0;
      bitWrite (ReadWord,BitIdx,Bit);
    }
    if ((Address==0x0000) || (ReadWord!=LastWord) || (Address==0xFFFF)){
      char output[15];
      //String AddrStr = String(Address, HEX);
      //String EnStr = String(ReadWord, BIN);
      //String OutputStr = AddrStr+' '+EnStr;
      sprintf(output, " 0x%04X", Address);
      Serial.print (output);
      for (int BitIdx=0; BitIdx<=7; BitIdx++) {
        Serial.print (" |  ");
        Serial.print (bitRead(ReadWord,BitIdx));
      }
      Serial.println();
      LastWord=ReadWord;
    }
  }
  Serial.println ("------------------------------------------------");
  Serial.println ("--Done---");
}

void loop() {
}
