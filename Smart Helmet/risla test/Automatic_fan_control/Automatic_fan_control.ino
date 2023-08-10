#include <DHT.h>  // Include the DHT library

#define DHTPIN D4    // Pin connected to the DHT11 sensor
#define DHTTYPE DHT11   // DHT sensor type

DHT dht(DHTPIN, DHTTYPE);   // Create a DHT object

const int fanPin = D5;   // Pin connected to the fan
const int minTemp = 20;  // Minimum temperature threshold
const int maxTemp = 30;  // Maximum temperature threshold
const int fanSpeeds[5] = {0, 100, 150, 200, 255};  // Fan speed levels (0-255)

void setup() {
  Serial.begin(115200);   // Initialize serial communication
  dht.begin();            // Initialize the DHT sensor
  pinMode(fanPin, OUTPUT);  // Set the fan pin as an output
}

void loop() {
  float temperature = dht.readTemperature();  // Read temperature from the DHT sensor

  if (isnan(temperature)) {
    Serial.println("Failed to read temperature from DHT sensor!");
    return;
  }

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");

  // Control fan speed based on temperature
  if (temperature < minTemp) {
    analogWrite(fanPin, fanSpeeds[0]);  // Set fan speed to the lowest level
  } else if (temperature >= maxTemp) {
    analogWrite(fanPin, fanSpeeds[4]);  // Set fan speed to the highest level
  } else {
    int fanSpeed = map(temperature, minTemp, maxTemp, fanSpeeds[1], fanSpeeds[3]);
    analogWrite(fanPin, fanSpeed);  // Set fan speed based on temperature
  }

  delay(2000);  // Wait for 2 seconds before taking the next temperature reading
}
