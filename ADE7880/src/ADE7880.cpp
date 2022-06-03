/* ADEComm library by German Castro
 */

#include "ADE7880.h"

/**
 * Constructor.
 */
ADE7880::ADE7880(int SS_, int SPI_freq)
{
  // be sure not to call anything that requires hardware be initialized here, put those in begin()
  _SS = SS_;
  _SPI_freq = SPI_freq;
}

/**
 * Example method.
 */
void ADE7880::Test(){
  Split_Add(Version_8);
}

void ADE7880::Split_Add(unsigned int Address){
  //byte AMSB = 0x00;
  //byte ALSB = 0x00;

  AMSB = (Address & 0xFF00)>>8;
  ALSB = (Address & 0x00FF);

  //Log.info("MSB: %02X", AMSB);
  //Log.info("LSB: %02X", ALSB); 
}

void ADE7880::SPI_Select(){
  //byte one;

  pinMode(_SS, OUTPUT); // FYI: SS is pin 10 by Arduino's SPI library on many boards (including the UNO), set SS pin as Output
  digitalWrite(_SS, HIGH); //Initialize pin as HIGH to bring communication inactive
  SPI.begin();
  delay(50);
  SPI.setBitOrder(MSBFIRST);  //Define MSB as first (explicitly)
  for(int i=1;i<=3;i++)
  {
    SPI8_write(SPI_SEL_8,0x11);
    delay(50);
  }
  //SPI8_write(CONFIG2_8, 0x00);
  //delay(100);
  //SPI8_Read(LAST_RWDATA8_8);
  //delay(100);
  //Log.info("Ultimo Valor: %02X", one); 
  SPI8_Read(Version_8);
  SPI16_Read(COMPMODE_16);
  SPI16_write(COMPMODE_16, 0X41, 0XFF);
  SPI32_Read(MASK1_32);
  //SPI32_write(MASK1_32, 0X00, 0X00, 0X02, 0X08);
  SPI32_write(MASK1_32, 0X00, 0X00, 0X10, 0X00);
  //SPI16_write(CONFIG_16, 0X00, 0X03);
  SPI16_Read(CONFIG_16);
  SPI32_Read(MASK1_32);
  SPI32_Read(STATUS1_32);
  SPI32_write(STATUS1_32, Valor_32[3], Valor_32[2], Valor_32[1], Valor_32[0]);
  //SPI32_Read(STATUS1_32);
  SPI8_write(0XE7FE, 0XAD);
  SPI8_write(0XE7E3, 0X80);
  SPI16_write(RUN_16, 0X00, 0X01);
  //SPI16_Read(COMPMODE_16);

  //SPI32_Read(STATUS1_32);
  //SPI32_write(STATUS1_32, 0X01, 0XA0, 0X81, 0XFF);
  //SPI32_Read(STATUS1_32);
  //SPI16_Read(CONFIG_16);
  //delay(100);
  //Log.info("Version: %02X", one);
}
void ADE7880::initialize(){

  /*  
  #ifdef ADE7953_VERBOSE_DEBUG
   Serial.print("ADE7953:initialize function started "); 
  #endif
  */

  /*
  pinMode(_SS, OUTPUT); // FYI: SS is pin 10 by Arduino's SPI library on many boards (including the UNO), set SS pin as Output
  digitalWrite(_SS, HIGH); //Initialize pin as HIGH to bring communication inactive
  SPI.begin();
  delay(50);
  SPI.setBitOrder(MSBFIRST);  //Define MSB as first (explicitly)
  SPI.beginTransaction(SPISettings(_SPI_freq, MSBFIRST, SPI_MODE3));  //Begin SPI transfer with most significant byte (MSB) first. Clock is high when inactive. Read at rising edge: SPIMODE3.
  delay(50);
  */
  
  //Write 0x00AD to Register Address 0x00FE. "This unlocks Register 0x120." per datasheet
  digitalWrite(_SS, LOW);//Enable data transfer by bringing SS line LOW.
  SPI.transfer(0x00); //Pass in MSB of register 0x00FE first.
  SPI.transfer(0xFE); //Pass in LSB of register 0x00FE next.
  SPI.transfer(WRITE); //This tells the ADE7953 that data is to be written to register 0x00FE, per datasheet
  SPI.transfer(0x00); //Pass in MSB of 0x00AD first to write to 0x00FE, per datasheet
  SPI.transfer(0xAD); //Pass in LSB of 0x00AD next to write to 0x00FE, per datasheet
  
  //Write 0x0030 to Register Address 0x0120. "This configures the optimum settings." per datasheet
  SPI.transfer(0x01); //Pass in MSB of register 0x0120 first, per datasheet
  SPI.transfer(0x20); //Pass in LSB of register 0x0120 next, per datasheet
  SPI.transfer(WRITE);//This tells the ADE7953 that data is to be written to register 0x0120, per datasheet
  SPI.transfer(0x00); //Pass in MSB of 0x0030 first to write to 0x0120, per datasheet
  SPI.transfer(0x30); //Pass in LSB of 0x0030 next to write to 0x0120, per datasheet
  SPI.endTransaction();
  digitalWrite(_SS, HIGH);//End data transfer by bringing SS line HIGH.
  delay(100);
  #ifdef ADE7953_VERBOSE_DEBUG
   Serial.print(" ADE7953:initialize function completed "); 
  #endif
  
  //Default Calibrations - Per Datasheet
  //spiAlgorithm16_write((functionBitVal(PHCALA_16,1)),(functionBitVal(PHCALA_16,0)),0x00,0x00);
  //delay(100);
  //spiAlgorithm32_write((functionBitVal(AP_NOLOAD_32,1)),(functionBitVal(AP_NOLOAD_32,0)),0x00,0x00,0x00,0x01); //Check for ensuring read and write operations are okay
  //delay(100);
  //spiAlgorithm8_write((functionBitVal(LCYCMODE_8,1)),(functionBitVal(LCYCMODE_8,0)),0b01111111); //Enable line cycle accumulation mode for all energies and channels
  //delay(100);
  //spiAlgorithm16_write((functionBitVal(LINECYC_16,1)),(functionBitVal(LINECYC_16,0)),0x00,0x78); //Sets number of half line cycle accumulations to 120
  //delay(100);

}
void ADE7880::SPI8_write(unsigned int Address, byte onemsb){
  
  Split_Add(Address);

  digitalWrite(_SS, LOW);//Enable data transfer by bringing SS line LOW.
  SPI.beginTransaction(SPISettings(_SPI_freq, MSBFIRST, SPI_MODE3)); 
  SPI.transfer(WRITE); //This tells the ADE7953 that data is to be written to register 0x00FE, per datasheet
  SPI.transfer(AMSB); //Pass in MSB of register 0x00FE first.
  SPI.transfer(ALSB); //Pass in LSB of register 0x00FE next.
  SPI.transfer(onemsb); 
  SPI.endTransaction();
  digitalWrite(_SS, HIGH);//End data transfer by bringing SS line HIGH.
}
void ADE7880::SPI16_write(unsigned int Address, byte onemsb, byte twolsb){
  Split_Add(Address);

  digitalWrite(_SS, LOW);//Enable data transfer by bringing SS line LOW.
  SPI.beginTransaction(SPISettings(_SPI_freq, MSBFIRST, SPI_MODE3)); 
  SPI.transfer(WRITE); //This tells the ADE7953 that data is to be written to register 0x00FE, per datasheet
  SPI.transfer(AMSB); //Pass in MSB of register 0x00FE first.
  SPI.transfer(ALSB); //Pass in LSB of register 0x00FE next.
  SPI.transfer(onemsb); 
  SPI.transfer(twolsb); 
  SPI.endTransaction();
  digitalWrite(_SS, HIGH);//End data transfer by bringing SS line HIGH.
}
void ADE7880::SPI24_write(byte MSB, byte LSB, byte onemsb, byte two, byte threelsb){
  digitalWrite(_SS, LOW);//Enable data transfer by bringing SS line LOW.
  SPI.beginTransaction(SPISettings(_SPI_freq, MSBFIRST, SPI_MODE3)); 
  SPI.transfer(WRITE); //This tells the ADE7953 that data is to be written to register 0x00FE, per datasheet
  SPI.transfer(MSB); //Pass in MSB of register 0x00FE first.
  SPI.transfer(LSB); //Pass in LSB of register 0x00FE next.
  SPI.transfer(onemsb); 
  SPI.transfer(two); 
  SPI.transfer(threelsb); 
  SPI.endTransaction();
  digitalWrite(_SS, HIGH);//End data transfer by bringing SS line HIGH.
}
void ADE7880::SPI32_write(unsigned int Address, byte onemsb, byte two, byte threelsb, byte fourlsb) {
  Split_Add(Address);

  digitalWrite(_SS, LOW);//Enable data transfer by bringing SS line LOW.
  SPI.beginTransaction(SPISettings(_SPI_freq, MSBFIRST, SPI_MODE3)); 
  SPI.transfer(WRITE); //This tells the ADE7953 that data is to be written to register 0x00FE, per datasheet
  SPI.transfer(AMSB); //Pass in MSB of register 0x00FE first.
  SPI.transfer(ALSB); //Pass in LSB of register 0x00FE next.
  SPI.transfer(onemsb); 
  SPI.transfer(two); 
  SPI.transfer(threelsb); 
  SPI.transfer(fourlsb); 
  SPI.endTransaction();
  digitalWrite(_SS, HIGH);//End data transfer by bringing SS line HIGH.
}
void ADE7880::SPI8_Read(unsigned int Address){
  byte value;
  
  Split_Add(Address);

  digitalWrite(_SS, LOW);//Enable data transfer by bringing SS line LOW.
  SPI.beginTransaction(SPISettings(_SPI_freq, MSBFIRST, SPI_MODE3)); 
  SPI.transfer(READ); //This tells the ADE7953 that data is to be written to register 0x00FE, per datasheet
  SPI.transfer(AMSB); //Pass in MSB of register 0x00FE first.
  SPI.transfer(ALSB); //Pass in LSB of register 0x00FE next.
  value = SPI.transfer(0x00); 
  SPI.endTransaction();
  digitalWrite(_SS, HIGH);//End data transfer by bringing SS line HIGH.

  Log.info("Leido: %02X", value);
}

void ADE7880::SPI16_Read(unsigned int Address){
  byte val_1;
  byte val_2;

  Split_Add(Address);

  digitalWrite(_SS, LOW);//Enable data transfer by bringing SS line LOW.
  SPI.beginTransaction(SPISettings(_SPI_freq, MSBFIRST, SPI_MODE3)); 
  SPI.transfer(READ); //This tells the ADE7953 that data is to be written to register 0x00FE, per datasheet
  SPI.transfer(AMSB); //Pass in MSB of register 0x00FE first.
  SPI.transfer(ALSB); //Pass in LSB of register 0x00FE next.
  val_1 = SPI.transfer(0x00); 
  val_2 = SPI.transfer(0x00); 
  SPI.endTransaction();
  digitalWrite(_SS, HIGH);//End data transfer by bringing SS line HIGH.

  Log.info("Leido: %02X, %02X", val_1, val_2);
}

void ADE7880::SPI32_Read(unsigned int Address){
  byte val_1;
  byte val_2;
  byte val_3;
  byte val_4;
  
  Split_Add(Address);

  digitalWrite(_SS, LOW);//Enable data transfer by bringing SS line LOW.
  SPI.beginTransaction(SPISettings(_SPI_freq, MSBFIRST, SPI_MODE3)); 
  SPI.transfer(READ); //This tells the ADE7953 that data is to be written to register 0x00FE, per datasheet
  SPI.transfer(AMSB); //Pass in MSB of register 0x00FE first.
  SPI.transfer(ALSB); //Pass in LSB of register 0x00FE next.
  val_1 = SPI.transfer(0x00); 
  val_2 = SPI.transfer(0x00); 
  val_3 = SPI.transfer(0x00); 
  val_4 = SPI.transfer(0x00); 
  SPI.endTransaction();
  digitalWrite(_SS, HIGH);//End data transfer by bringing SS line HIGH.

  //Log.info("Leido: %02X, %02X,  %02X,  %02X", val_1, val_2, val_3, val_4);

  Valor_32[0] = val_4;
  Valor_32[1] = val_3;
  Valor_32[2] = val_2;
  Valor_32[3] = val_1;
}

float ADE7880::Dec_Val_32(String Param){
  float Value;
  memcpy(&Value, &Valor_32, sizeof(Value));

  Log.info(Param + ": %f", Value);

  return Value;
}

int32_t ADE7880::Dec_Val_24(String Param){
  int32_t Value;
  memcpy(&Value, &Valor_32, sizeof(Value));

  //Log.info(Param + ": %f", Value);
  Log.info("Valor Int: %ld", Value);

  return Value;
}

float ADE7880::Read_Rms(unsigned int Address, String Param)
{
  int32_t Value;
  float Val = 0;
  SPI32_Read(Address);
  Value=Dec_Val_24(Param);
  Log.info("Leido: %02X, %02X,  %02X,  %02X", Valor_32[3], Valor_32[2], Valor_32[1], Valor_32[0]);

  if(Address == AIRMS_24 || Address == BIRMS_24 || Address == CIRMS_24){
    Val = Value*70.7106/3766572;
    Log.info(Param + ": %f", Val);
  }
  if(Address == AVRMS_24 || Address == BVRMS_24 || Address == CVRMS_24){
    Val = Value*70.7106/3766572;
    Log.info(Param + ": %f", Val);
  }
  return Val;
}

void ADE7880::begin()
{
    // initialize hardware
    Serial.println("called begin");
    Serial.println(Version_8);
}

/**
 * Example method.
 */
void ADE7880::process()
{
    // do something useful
    Serial.println("called process");
    doit();
}

/**
* Example private method
*/
void ADE7880::doit()
{
    Serial.println("called doit");
}
