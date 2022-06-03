/* Oled_Display library by Germán Castro
 */

#include "Oled_Display.h"

/**
 * Constructor.
 */
Oled_Display::Oled_Display(Adafruit_SH1106 *ptr_dpy)
{
  // be sure not to call anything that requires hardware be initialized here, put those in begin()
  display = ptr_dpy;
  ptr_Wf = Wifi_Icon;
}

/**
 * Example method.
 */
void Oled_Display::Inicio_Oled()
{
    Log.info("Inicio Oled");
    display->begin(SH1106_SWITCHCAPVCC, 0x3C); 
    display->display();
    delay(1000);
    display->clearDisplay();
    display->setTextColor(WHITE);
    display->setTextSize(1);
    display->setCursor(0, 40);
    display->println("Iniciando...");
    //display->drawBitmap(0, 0, Wifi_Icon, 14, 14, 1);
    //display->drawBitmap(30, 0, Bkr_On_Icon, 14, 14, 1);
    //display->drawBitmap(60, 0, Bkp_Icon, 14, 14, 1);
    //display->drawBitmap(90, 0, Alr_Icon, 14, 14, 1);
    display->display();
}

void Oled_Display::Iconos_Oled(byte St_Br, byte St_Wf, byte St_Er, int Bk, float *Ir, float *Vr)
{   
    bool Act = false;
    if(St_Br != St_BrA){
        Act = true;
        if(St_Br == 1){
            Log.info("Dibujar icono");
            ptr_Br = Bkr_On_Icon;
            //display->drawBitmap(30, 0, ptr_Br, 14, 14, 1);
            //display->display();
        }
        if(St_Br == 0){
            ptr_Br = Bkr_Off_Icon;
        }
        St_BrA = St_Br;
    }
    if(St_Wf != St_WfA){
        Act = true;
        if(St_Wf == 1){
            ptr_Wf = Wifi_Icon;
        }
        if(St_Wf == 0){
            ptr_Wf = No_Wifi_Icon;
        }
        St_WfA = St_Wf;
    }
    if(St_Er != 0 || Bk != 0){
        Act = true;
    }
    
    /*if(Act == true){
        Icon_Act(St_Er, Bk);
    }*/
    Icon_Act(St_Er, Bk, Ir, Vr);
}

void Oled_Display::Icon_Act(byte St_Er, int Bk, float *Ir, float *Vr){
    //float val = 0.2563;
    Log.info("Actualizar Display");
    display->clearDisplay();
    display->drawBitmap(0, 0, ptr_Wf, 14, 14, 1);
    display->drawBitmap(30, 0, ptr_Br, 14, 14, 1);
    if(St_Er != 0){
        display->drawBitmap(60, 0, Alr_Icon, 14, 14, 1);
    }
    if(Bk != 0){
        display->drawBitmap(90, 0, Bkp_Icon, 14, 14, 1);
    }
    display->setTextSize(1);
    display->setTextColor(WHITE);
    display->setCursor(0,20);
    display->print("Vr1: ");   
    display->println(Vr[0]);    
    display->setCursor(68,20);
    display->print("Vr2: ");
    display->println(Vr[1]);  
    display->setCursor(0,30);
    display->print("Vr3: ");
    display->println(Vr[2]);  
    display->setCursor(68,30);
    display->print("Ir1: ");
    display->println(Ir[0],2);  
    display->setCursor(0,40);
    display->print("Ir2: ");
    display->println(Ir[1],2);
    display->setCursor(68,40);
    display->print("Ir3: ");    
    display->println(Ir[2],2);        
    display->display();
}

/**
 * Example method.
 */
void Oled_Display::process()
{
    // do something useful
    Serial.println("called process");
    doit();
}

/**
* Example private method
*/
void Oled_Display::doit()
{
    Serial.println("called doit");
}
