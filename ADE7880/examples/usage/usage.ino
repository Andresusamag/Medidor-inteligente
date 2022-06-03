// Example usage for ConFile library by German Castro.

#include "ConFile.h"

// Initialize objects from the lib
ConFile conFile;

void setup() {
    // Call functions on initialized library objects that require hardware
    conFile.begin();
}

void loop() {
    // Use the library's initialized objects and functions
    conFile.process();
}
