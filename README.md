#i2c Arduino Keypad

The keypad's address is set to 44. To change this, simply change the constant KEYPAD_ADDRESS to whatever you'd like.

For different keypad types, it should be possible to simply change the values in the code block under "Keypad Setup"

Simply request the latest key press in from your master device:

```
Wire.requestFrom(KEYPAD_ADDRESS, 1);
while (Wire.available() > 0) {
  char c = Wire.read();
  if (c != ' ')
    //there was a new key pressed.
    //Do something with it.
  }
}
```
