#include <RCSwitch.h>

RCSwitch mySwitch = RCSwitch();

void setup() {
  Serial.begin(9600); // Start serial communication
  mySwitch.enableTransmit(2); // Data pin connected to D4
}

void loop() {
  mySwitch.send(12345, 24); // Data to be transmitted
  delay(1000); // Wait 1 second before transmitting again
}
