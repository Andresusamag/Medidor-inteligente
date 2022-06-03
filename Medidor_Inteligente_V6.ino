/*
 * Project Medidor_Inteligente_V3
 * Description:
 * Author:
 * Date:
 */
#include "ADE7880.h"
#include "SdFat.h"
#include "Oled_Display.h"
#include "MQTT.h"
#include "NTPCliente.h"

SerialLogHandler logHandler(LOG_LEVEL_WARN, {
  { "app", LOG_LEVEL_INFO }
});

SYSTEM_MODE(SEMI_AUTOMATIC)
SYSTEM_THREAD(ENABLED)

#define OLED_RESET D8
#define SD_CHIP_SELECT D5
#define ADE_IRQ0 A0
#define ADE_IRQ1 A1
#define ADE_SS A5
#define ADE_RESET A4

typedef enum {
  WIFI_STATE_STANDBY = 0,
  WIFI_STATE_PON = 1,
  WIFI_STATE_CON = 2,
  WIFI_STATE_RDY = 3
}Wifi_State;

bool IRQ1_FLG = false;
int cont_irq = 0;
bool Oled_B = false;
byte St_WiFi = 0;
bool Conexion = false;

unsigned long TWiFi_Con = 0;
long timeNow = 0;

char Server1[] = "192.168.1.195";
char BufLocal[300];

bool Get_Ntp = false;
bool *ptr_Ntp = &Get_Ntp;

ADE7880 ADE7880_(ADE_SS, 1000000); 
Adafruit_SH1106 display(-1);
Adafruit_SH1106 *ptr_dpy = &display;
Oled_Display Oled(ptr_dpy);
SdFat sd(&SPI1);
MQTT cliente("campusverde.udenar.edu.co", 1884, callback, true);
Timer Tr_Oled(5000, Oled_Tr);
NTPCliente ClienteNTP(ptr_Ntp);

void ISR_IRQ1()
{
  IRQ1_FLG = true;
  cont_irq++;
}

void Oled_Tr(){
  Oled_B = true;
}

void callback(char* topic, byte* payload, unsigned int length){
  Log.info("Mensaje MQTT recibido...");
}
// setup() runs once, when the device is first turned on.
void setup() {
  // Put initialization like pinMode and begin functions here.
  pinMode(ADE_RESET, OUTPUT_OPEN_DRAIN);
  pinMode(ADE_IRQ0, INPUT);
  pinMode(ADE_IRQ1, INPUT);
  attachInterrupt(ADE_IRQ1, ISR_IRQ1, FALLING);
  digitalWrite(ADE_RESET, HIGH);
  Serial.begin(115200);
  Serial1.begin(9600);
  delay(2000);  
  Time.zone(5);
  Oled.Inicio_Oled();
  if (!sd.begin(SD_CHIP_SELECT, SD_SCK_MHZ(4))){
    Serial.println("Falló inicializar");
    //sd.initErrorHalt();
    sd.initErrorPrint();
  }
  else{
    Serial.println("SD inicializada con exito...");
  }
  ADE7880_.SPI_Select();
  Log.info("End ADE7880");
  //delay(2000);
  Oled.Iconos_Oled(1,0,0,0,0,0);
  Tr_Oled.start();
  St_WiFi = WIFI_STATE_STANDBY;
}

// loop() runs over and over again, as quickly as it can execute.
void loop() {
  // The core of your code will likely live here.
  if(Oled_B){
    Oled_B = false;
    Log.info("Publicar MQTT");
    if(cliente.isConnected()){
      TramaLocal();
      cliente.publish("electricMeter-mqtt", BufLocal);
    }    
  }
  if(!WiFi.ready()){
    Wifi_Con("Conectar");
  }
  else{
    ClienteNTP.status();
    ClienteNTP.recibido();
    if(!Conexion){
      Log.info("WiFi Conectado");
      Conexion = true;
      if(!cliente.isConnected()){
        if(cliente.connect("Medidor_1", "campusVerde", "2m7eY8DDUU3MNQFcVN4LmDuvEv7a8LB2")){
          Log.info("MQTT conectado");
        }
        else{
          Log.info("No se pudo conectar a MQTT");
        }
      }
    }
    else{
      if(cliente.isConnected()){
        cliente.loop();
      }
    }
  }
}

void TramaLocal(){
  JSONBufferWriter writer(BufLocal, sizeof(BufLocal));
  timeNow = Time.local();
  writer.beginObject();
  writer.name("macAddress").value("30aea4e550f9");
  writer.name("date").value((unsigned int)timeNow);
  writer.name("status").value(1);
  writer.name("error").value(0);
  writer.name("backup").value(0);
  writer.name("RSSI").value(-46);
  writer.name("Fase_1");
  writer.beginObject();
  writer.name("Vrms").value(120.2);
  writer.name("Irms").value(2.3);
  writer.name("Fase").value(60.2);
  writer.endObject();
  writer.name("Fase_2");
  writer.beginObject();
  writer.name("Vrms").value(120.5);
  writer.name("Irms").value(3.3);
  writer.name("Fase").value(50.3);
  writer.endObject();
  writer.name("Fase_3");
  writer.beginObject();
  writer.name("Vrms").value(120.8);
  writer.name("Irms").value(5.6);
  writer.name("Fase").value(80.3);
  writer.endObject();
  writer.endObject();
  Log.print(BufLocal);
  Log.print("\n");

}

void Wifi_Con(String Comando){
  if(Comando == "Conectar"){
    //Log.info("Función Conectar WiFi");
    if(WiFi.isOff() && St_WiFi == WIFI_STATE_STANDBY){
      Log.info("WiFi apagado");
      WiFi.on();
      St_WiFi = WIFI_STATE_PON;
    }
    else{
      if(WiFi.isOn() && St_WiFi == WIFI_STATE_PON){
        if(!WiFi.connecting()){
          Log.info("Conectar WiFi");
          WiFi.setCredentials("SMARTECH","osopanda1313");
          WiFi.connect();
          TWiFi_Con = millis();
          St_WiFi = WIFI_STATE_CON;
        }
      }
    }
  }
  if(Comando == "Apagar"){
    if(WiFi.isOn() && St_WiFi != WIFI_STATE_STANDBY){
      Log.info("Apagar WiFi");
      WiFi.off();
      St_WiFi = WIFI_STATE_STANDBY;
    }
  }
}