#include <RH_ASK.h>
#include <ESP8266WiFi.h>   // Include ESP8266WiFi library
 
RH_ASK rf_driver;
const int TRANSMIT_PIN = 4;

void setup()
{
  // Initialize ASK Object
  rf_driver.init();
  
  // Initialize WiFi
  WiFi.begin("Corona Virus", "CORONA2019yoyo"); // Replace with your network credentials
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  pinMode(TRANSMIT_PIN, OUTPUT);  // Set the transmit pin as an output
  digitalWrite(TRANSMIT_PIN, LOW);
}
 
void loop()
{
  const char *msg = "Hello World";
  rf_driver.send((uint8_t *)msg, strlen(msg));
  rf_driver.waitPacketSent();
  delay(1000);
}

