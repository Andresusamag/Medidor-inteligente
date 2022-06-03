#pragma once

/* ADEComm library by German Castro
 */

// This will load the definition for common Particle variable types
#include "Particle.h"
#include "Registros_7880.h"

const unsigned int READ = 0b00000001;  //This value tells the ADE7953 that data is to be read from the requested register.
const unsigned int WRITE = 0b00000000; //This value tells the ADE7953 that data is to be written to the requested register.
//const int SPI_freq = 1000000;//Communicate with the ADE7953 at 1 MHz frequency.

// This is your main class that users will import into their application
class ADE7880
{
public:
  /**
   * Constructor
   */
  ADE7880(int SS_, int SPI_freq);
  void initialize();
  void Test();
  void Split_Add(unsigned int Address);
  void SPI_Select();
  void SPI8_write(unsigned int Address, byte onemsb);
  void SPI16_write(unsigned int Address, byte onemsb, byte twolsb);
  void SPI24_write(byte MSB, byte LSB, byte onemsb, byte two, byte threelsb);
  void SPI32_write(unsigned int Address, byte onemsb, byte two, byte three, byte fourlsb); 
  void SPI8_Read(unsigned int Address);
  void SPI16_Read(unsigned int Address);
  void SPI32_Read(unsigned int Address);
  float Dec_Val_32(String Param);
  int32_t Dec_Val_24(String Param);
  float Read_Rms(unsigned int Address, String Param);
  
  byte AMSB = 0x00;
  byte ALSB = 0x00;
  byte Valor_32[4];
  float Ir1 = 0;
  float Irms[4] = {0,0,0,0};
  float *Irms_ptr = Irms;
  float Vrms[4] = {0,0,0,0};
  float *Vrms_ptr = Vrms;
  /**
   * Example method
   */
  void begin();

  /**
   * Example method
   */
  void process();

private:
  /**
   * Example private method
   */
  int _SS;
  int _SPI_freq;
  void doit();
};
