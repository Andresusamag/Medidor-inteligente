#pragma once

/* saludo library by German Castro
 */

// This will load the definition for common Particle variable types
#include "Particle.h"

// This is your main class that users will import into their application
class NTPCliente
{
public:
  /**
   * Constructor
   */
  NTPCliente(bool *ptrsnd);
  /**
   * Example method
   */
  void begin();
  void begin(const char *ServerName);
  void begin(unsigned char *ServerIP);
  void status();

  /**
   * Example method
   */
  void process();
  void recibido();
  //unsigned char timeServer[4] = {0x84, 0xA3, 0x60, 0x1}; 
  //unsigned char timeServer[4] = {0xC0, 0xA8, 0x1, 0xC3}; 
  unsigned char timeServer[4] = {0xA2, 0x9F, 0xC8, 0x7B}; 
  char EstadoActual = 0;
  const char EstNoActual = 0;
  const char EstIniciaSol = 1;
  const char EstSolEnviada = 2;
  const char EstRtaRecibida = 3;
  unsigned long last_act = 0;
  unsigned long last_sol = 0;
  unsigned long intervalo = 300;
  unsigned long timer_sol = 5;
  //unsigned char NTPIP[4] = {0x88, 0x06, 0x0F, 0x1D};
  //unsigned char NTPIP[4] = {0xC0, 0xA8, 0x01, 0xC3};        //ip 192.168.1.195
  unsigned char NTPIP[4] = {0x84, 0xA3, 0x60, 0x1}; 
  bool *ptr_snd;
  int ntp_try;
  //unsigned char NTPIP[4] = {0xC0, 0xA8, 0x1, 0xC3};
  
private:
  /**
   * Example private method
   */
  UDP* UDPClient;
  unsigned long localPort =  123;
  unsigned char packetBuffer[48];
  void doit();
  void sendNTPpacket(unsigned char *server);
  void sendNTPpacket(const char *server);
  void StampPacket(unsigned char *paquete);
};
