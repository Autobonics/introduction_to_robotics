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

//L293D
//Motor A
const int motorPin1  = 26;  // Pin 14 of L293
const int motorPin2  = 25;  // Pin 10 of L293
//Motor B
const int motorPin3  = 33; // Pin  7 of L293
const int motorPin4  = 32;  // Pin  2 of L293

//This will run only one time.
void setup(){
    // for serial data transmission
    Serial.begin(115200);
    SerialBT.begin("Azhar"); //Bluetooth device name
 
    //Set pins as outputs
    pinMode(motorPin1, OUTPUT);
    pinMode(motorPin2, OUTPUT);
    pinMode(motorPin3, OUTPUT);
    pinMode(motorPin4, OUTPUT);
  
}


void loop(){
{
  if (SerialBT.available() > 0)
  {
    // Read the incoming data and store it in the variable
    Incoming_value = SerialBT.read();

    // Print value of Incoming_value in Serial monitor
    Serial.print(Incoming_value);
    Serial.print("\n");

    // Checking whether value of the variable
    if (Incoming_value == 'f')
      forward();
    else if (Incoming_value == 'b')
      backward();
    else if (Incoming_value == 'l')
      left();
    else if (Incoming_value == 'r')
      right();
     else if (Incoming_value == 's')
      stopRobot();
  }

  // Adding a delay before running the loop again
  delay(1);

}
}

void forward(){
    digitalWrite(motorPin1, HIGH);
    digitalWrite(motorPin2, LOW);
    digitalWrite(motorPin3, HIGH);
    digitalWrite(motorPin4, LOW);  
}

void backward(){
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, HIGH);
    digitalWrite(motorPin3, LOW);
    digitalWrite(motorPin4, HIGH);
}

void left(){
    digitalWrite(motorPin1, HIGH);
    digitalWrite(motorPin2, LOW);
    digitalWrite(motorPin3, LOW);
    digitalWrite(motorPin4, LOW);
}

void right(){
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, LOW);
    digitalWrite(motorPin3, HIGH);
    digitalWrite(motorPin4, LOW);
}

void stopRobot(){
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, LOW);
    digitalWrite(motorPin3, LOW);
    digitalWrite(motorPin4, LOW);  
}
