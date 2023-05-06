#include "BluetoothSerial.h"

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

#if !defined(CONFIG_BT_SPP_ENABLED) 
#error Serial Bluetooth not available or not enabled. It is only available for the ESP32 chip.
#endif

BluetoothSerial SerialBT;

// Variable for storing incoming value
char Incoming_value = 0;

#define LED_Pin 2

void setup()
{
  // Sets the data rate in bits per second (baud)
  // for serial data transmission
  Serial.begin(115200);
  SerialBT.begin("Azhar"); //Bluetooth device name

  // Sets digital pin LED_Pin as output pin
  pinMode(LED_Pin, OUTPUT);

  // Initializes the pin LED_Pin to LOW (i.e., OFF)
  digitalWrite(LED_Pin, LOW);
}

void loop()
{
  if (SerialBT.available() > 0)
  {
    // Read the incoming data and store it in the variable
    Incoming_value = SerialBT.read();

    // Print value of Incoming_value in Serial monitor
    Serial.print(Incoming_value);
    Serial.print("\n");

    // Checking whether value of the variable
    // is equal to 0
    if (Incoming_value == '0')
      digitalWrite(LED_Pin, LOW); // If value is 0, turn OFF the device

    // Checking whether value of the variable
    // is equal to 1
    else if (Incoming_value == '1')
      digitalWrite(LED_Pin, HIGH); // If value is 1, turn ON the device
  }

  // Adding a delay before running the loop again
  delay(1);

}
