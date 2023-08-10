#include <dht11.h>

#define DHT_PIN 2
#define MQ_PIN A0

dht11 DHT11;

void setup() {
  Serial.begin(9600);  
}

void loop() {
  // Read data from DHT11 sensor
  int chk = DHT11.read(DHT_PIN);
  float temperature = DHT11.temperature;
  float humidity = DHT11.humidity;

  // Read data from MQ-02 sensor
  int gasValue = analogRead(MQ_PIN);

  // Print the sensor readings
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");

  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");

  Serial.print("Gas Value: ");
  Serial.println(gasValue);

  delay(2000);
}
