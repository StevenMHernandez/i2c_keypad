#include <Wire.h>
#include "Keypad.h"

const int KEYPAD_ADDRESS = 44;
char currentKey;

// Keypad Setup
const byte rows = 4;
const byte cols = 3;
char keys[rows][cols] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};
byte rowPins[rows] = {5, 6, 7, 8};
byte colPins[cols] = {2, 3, 4};
Keypad _keypad = Keypad( makeKeymap(keys), rowPins, colPins, rows, cols );

void setup() {
  Wire.begin(KEYPAD_ADDRESS);
  Wire.onRequest(requestEvent);
}

void loop() {
  char key = _keypad.waitForKey();
  if (key != NO_KEY){
    currentKey = key;
  }
}

void requestEvent() {
  Wire.write(currentKey);
  currentKey = ' ';
}
