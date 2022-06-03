// Example usage for Oled_Display library by Germán Castro.

#include "Oled_Display.h"

// Initialize objects from the lib
Oled_Display oled_Display;

void setup() {
    // Call functions on initialized library objects that require hardware
    oled_Display.begin();
}

void loop() {
    // Use the library's initialized objects and functions
    oled_Display.process();
}
