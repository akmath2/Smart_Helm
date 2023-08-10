#include <RCSwitch.h>

#define RF_RX_PIN  2 // Arduino pin connected to the RF receiver data pin

RCSwitch mySwitch;

void setup() {
  Serial.begin(115200);
  mySwitch.enableReceive(RF_RX_PIN);
  mySwitch.setProtocol(1); // Set the protocol used by your RF receiver
}

void loop() {
  if (mySwitch.available()) {
    unsigned long receivedCode = mySwitch.getReceivedValue(); // Get the received code
    if (receivedCode != 0) {
      Serial.print("Received code: ");
      Serial.println(receivedCode);
      Serial.print("Received bits: ");
      Serial.println(mySwitch.getReceivedBitlength());
      Serial.print("Received protocol: ");
      Serial.println(mySwitch.getReceivedProtocol());
      Serial.print("Received delay: ");
      Serial.println(mySwitch.getReceivedDelay());
      Serial.print("Received raw data: ");
      unsigned int* rawData = mySwitch.getReceivedRawdata();
      int rawDataLength = mySwitch.getReceivedBitlength() / 8;
      for (int i = 0; i < rawDataLength; i++) {
        Serial.print(rawData[i]);
        Serial.print(" ");
      }
      Serial.println();
    }
    mySwitch.resetAvailable();
  }
}






