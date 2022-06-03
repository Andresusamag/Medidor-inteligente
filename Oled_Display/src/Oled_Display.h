#pragma once

/* Oled_Display library by Germán Castro
 */

// This will load the definition for common Particle variable types
#include "Particle.h"
#include "Iconos.h"
#include "Adafruit_SH1106.h"

//Adafruit_SH1106 Display{-1};
// This is your main class that users will import into their application
class Oled_Display
{
public:
  /**
   * Constructor
   */
  Oled_Display(Adafruit_SH1106 *ptr_dpy);
  
  /**
   * Example method
   */
  void Inicio_Oled();
  void Iconos_Oled(byte St_Br, byte St_Wf, byte St_Er, int Bk, float *Ir, float *Vr);
  void Icon_Act(byte St_Er, int Bk, float *Ir, float *Vr);

  /**
   * Example method
   */
  void process();
  //Adafruit_SH1106 *display = new Adafruit_SH1106{-1};
  Adafruit_SH1106 *display;
  const uint8_t *ptr_Br;
  const uint8_t *ptr_Wf;
  byte St_BrA, St_WfA, St_ErA = 0;
private:
  /**
   * Example private method
   */
  void doit();
};
