#include <RCSwitch.h>

RCSwitch mySwitch = RCSwitch();

void setup() {
  Serial.begin(9600); // Start serial communication
  mySwitch.enableReceive(4); // Data pin connected to D4
}

void loop() {
  if (mySwitch.available()) {
    int value = mySwitch.getReceivedValue(); // Data received by the RF module
    Serial.println(value); // Print the received value to the serial monitor
    mySwitch.resetAvailable(); // Reset the available flag to receive more data
    }
}

