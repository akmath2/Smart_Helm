#include <RCSwitch.h>

#define RF_TX_PIN  D1 // GPIO pin connected to the RF transmitter data pin

RCSwitch mySwitch;

void setup() {
  Serial.begin(115200);
  mySwitch.enableTransmit(RF_TX_PIN);
  mySwitch.setProtocol(1); // Set the protocol used by your RF transmitter
}

void loop() {
  const char* message = "Hello, world!"; // Message to be sent
  unsigned long code = mySwitch.getReceivedValue(); // Store the message as an unsigned long
  mySwitch.send(code, strlen(message) + 1); // Send the message
  delay(1000); // Wait for a second
}


