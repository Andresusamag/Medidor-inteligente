// Example usage for saludo library by German Castro.

#include "saludo.h"

// Initialize objects from the lib
Saludo saludo;

void setup() {
    // Call functions on initialized library objects that require hardware
    saludo.begin();
}

void loop() {
    // Use the library's initialized objects and functions
    saludo.process();
}
