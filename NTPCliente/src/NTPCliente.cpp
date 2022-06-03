/* saludo library by German Castro
 */

#include "NTPCliente.h"

/**
 * Constructor.
 */
NTPCliente::NTPCliente(bool *ptrsnd)
{
  // be sure not to call anything that requires hardware be initialized here, put those in begin()
  UDPClient = new UDP();
  ptr_snd = ptrsnd;
}

/**
 * Example method.
 */
void NTPCliente::begin()
{
    // initialize hardware
    //Serial.println("Begin default");
    Log.info("Begin NTP Default");
    //UDPClient = new UDP();
    UDPClient->begin(localPort);
    EstadoActual = EstIniciaSol;
    //sendNTPpacket(timeServer);
    sendNTPpacket(NTPIP);
    ntp_try++;
}

void NTPCliente::begin(unsigned char *ServerIP)
{
    // initialize hardware
    ntp_try++;
    //Serial.println("Begin IP SERVER");
    Log.info("Begin NTP IP Server");
    //UDPClient = new UDP();
    UDPClient->begin(localPort);
    EstadoActual = EstIniciaSol;
    sendNTPpacket(ServerIP);    
}

void NTPCliente::begin(const char *ServerName)
{
    // initialize hardware
    ntp_try++;
    //Serial.println("Begin URL");
    Log.info("Begin URL");
    //UDPClient = new UDP();
    UDPClient->begin(localPort);
    EstadoActual = EstIniciaSol;
    sendNTPpacket(ServerName);
}

void NTPCliente::status()
{   
    if(EstadoActual == EstNoActual)
    {
        //Serial.println("Tiempo desactualizado");
        //Log.info("Estado actualizar");
        *ptr_snd = true;
        if(ntp_try<3 && WiFi.ready()){
            Log.info("Tiempo desactualizado");
            begin(NTPIP);
        }        
    }
    if(EstadoActual == EstRtaRecibida)
    {
        unsigned long lapse = Time.now()-last_act;
        if(lapse > intervalo)
        {
            EstadoActual = EstNoActual;
            ntp_try = 0;
            Log.info("Transcurrido NTP: %lu", lapse);
        }
    }
    if(EstadoActual == EstSolEnviada)
    {
        unsigned long t_sol = Time.now()-last_sol;
        if(t_sol > timer_sol)
        {
            EstadoActual = EstNoActual;
            UDPClient->stop();
            Log.info("Timer sol: %lu", t_sol);
            if(ntp_try == 3){
                Log.info("Intentos NTP cumplidos");
                EstadoActual = EstRtaRecibida;
                last_act = Time.now();
                *ptr_snd = false;
            }
        }
    }
}
/**
 * Example method.
 */
void NTPCliente::process()
{
    // do something useful
    Serial.println("called process");
    //doit();
}

/**
* Example private method
*/
void NTPCliente::doit()
{
    Serial.println("called doit");
}

void NTPCliente::sendNTPpacket(unsigned char *server)
{
    byte enviado = 0;
    //unsigned char packetBuffer[48];
    //Serial.println("Enviar Paquete NTP IP");
    Log.info("Enviar paquete NTP IP");
    // set all bytes in the buffer to 0
    memset(packetBuffer, 0, 48);
    // Initialize values needed to form NTP request
    // (see URL above for details on the packets)
    packetBuffer[0] = 0b11100011;   // LI, Version, Mode
    packetBuffer[1] = 0;     // Stratum, or type of clock
    packetBuffer[2] = 6;     // Polling Interval
    packetBuffer[3] = 0xEC;  // Peer Clock Precision
  // 8 bytes of zero for Root Delay & Root Dispersion
    packetBuffer[12]  = 49;
    packetBuffer[13]  = 0x4E;
    packetBuffer[14]  = 49;
    packetBuffer[15]  = 52;

    // all NTP fields have been given values, now
    // you can send a packet requesting a timestamp:       
    UDPClient->beginPacket(server, 123);
    UDPClient->write(packetBuffer, 48); //NTP requests are to port 123
    enviado = UDPClient->endPacket();
    UDPClient->endPacket();
    EstadoActual = EstSolEnviada;
    last_sol = Time.now();
    //Serial.print("Enviado: ");
    //Serial.println(enviado);
}

void NTPCliente::sendNTPpacket(const char *server)
{
    //unsigned char packetBuffer[48];
    //Serial.println("Enviar Paquete NTP URL");
    Log.info("Enviar paquete NTP URL");
    // set all bytes in the buffer to 0
    memset(packetBuffer, 0, 48);
    // Initialize values needed to form NTP request
    // (see URL above for details on the packets)
    packetBuffer[0] = 0b11100011;   // LI, Version, Mode
    packetBuffer[1] = 0;     // Stratum, or type of clock
    packetBuffer[2] = 6;     // Polling Interval
    packetBuffer[3] = 0xEC;  // Peer Clock Precision
  // 8 bytes of zero for Root Delay & Root Dispersion
    packetBuffer[12]  = 49;
    packetBuffer[13]  = 0x4E;
    packetBuffer[14]  = 49;
    packetBuffer[15]  = 52;

    // all NTP fields have been given values, now
    // you can send a packet requesting a timestamp:       
    UDPClient->beginPacket(server, 123);
    UDPClient->write(packetBuffer, 48); //NTP requests are to port 123
    UDPClient->endPacket();
    EstadoActual = EstSolEnviada;
    last_sol = Time.now();
}

void NTPCliente::recibido()
{
    //Serial.println("Funcion recibido");
    //unsigned char packetBuffer[48];
    if(UDPClient->parsePacket())
    {
       //Serial.println("Paquete recibido");
       Log.info("Paquete NTP recibido");
       UDPClient->read(packetBuffer,48);
       StampPacket(packetBuffer);
       EstadoActual = EstRtaRecibida;
       *ptr_snd = false;
       last_act = Time.now(); 
       UDPClient->stop();
    }
    
}

void NTPCliente::StampPacket(unsigned char *paquete)
{  
    unsigned long highWord = (paquete[40] << 8) + paquete[41];
    unsigned long lowWord = (paquete[42] << 8) + paquete[43];  
    unsigned long secsSince1900 = highWord << 16 | lowWord;
    secsSince1900 -= 5*60*60;
    const unsigned long seventyYears = 2208988800UL;
    unsigned long epoch = secsSince1900 - seventyYears;
    //Serial.print("Timestamp: ");
    //Serial.println(epoch);
    Log.info("Timestamp: %lu", epoch);
    Time.setTime(epoch);
    //Serial.println(paquete)
}