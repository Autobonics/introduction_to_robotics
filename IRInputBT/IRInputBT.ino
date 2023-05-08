#include "BluetoothSerial.h"

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

#if !defined(CONFIG_BT_SPP_ENABLED) 
#error Serial Bluetooth not available or not enabled. It is only available for the ESP32 chip.
#endif

BluetoothSerial SerialBT;

// digital pin 2 has a pushbutton attached to it. Give it a name:
int irInput = 27;

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(115200);
  SerialBT.begin("Azhar"); //Bluetooth device name
  // make the pushbutton's pin an input:
  pinMode(irInput, INPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input pin:
  int buttonState = digitalRead(irInput);
  // print out the state of the button:
  Serial.println(buttonState);
  SerialBT.println(buttonState);
  delay(300);        // delay in between reads for stability
}
