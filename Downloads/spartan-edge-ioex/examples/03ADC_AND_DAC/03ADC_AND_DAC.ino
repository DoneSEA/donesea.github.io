/*
  03DAC_AND_DAC
 
  read ADC information from FPGA and output by Serial
  write DAC value to FPGA

  The MIT License (MIT)
  Copyright (C) 2019  Seeed Technology Co.,Ltd.
 */

// include the ioex library
#include <spartan-edge-ioex.h>

// initialize the spartan_edge_ioex library
spartan_edge_ioex ioex;

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 115200 bits per second: 
  Serial.begin(115200);

  // enable ADC1173
  ioex.enableAdc();
}

// the loop routine runs over and over again forever:
void loop() {
  unsigned long voltVal;

  // read ADC value
  voltVal = ioex.readAdcData();
  
  /* output Voltage(ms) by Serial */
  Serial.print("ADC : ");
  Serial.print(voltVal);
  Serial.print(" mV ");

  // output DAC val
  // DAC-OUT = ADC-IN ,input DAC value ,which is what you read before 
  ioex.writeDacData(voltVal);
  
  // Change other line
  Serial.println();  
  // delay in between reads for stability
  delay(1500);
}
