#include <ESP8266WiFi.h>
#include <SoftwareSerial.h>
#include <FirebaseArduino.h>
#include <ArduinoJson.h>
#include <ESP8266HTTPClient.h>
#include <DHT.h>
#include <Adafruit_Sensor.h>

// Set these to run example.
#define FIREBASE_HOST "smart-helmet-2b759-default-rtdb.firebaseio.com"
#define FIREBASE_AUTH "O6Ewcp7pEAUEQlyQO8QUu4ZhJ530U3CRPKeLEQ2h"
#define WIFI_SSID "Eng-Student" //provide ssid (wifi name)
#define WIFI_PASSWORD "3nG5tuDt" //wifi password
#define DHTTYPE DHT11
#define DHTPIN D4

DHT dht(DHTPIN, DHTTYPE);
int mq2sensor = A0;
int sensorvalue;
void setup()
{ 
 pinMode(mq2sensor, INPUT);
 pinMode(DHTPIN,INPUT);
 dht.begin();
 // Debug console
 Serial.begin(9600);
// connect to wifi.
 WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
 Serial.print("connecting");
 while (WiFi.status() != WL_CONNECTED)
 {
 Serial.print(".");
 delay(500);
 }
 Serial.println();
 Serial.print("connected: ");
 Serial.println(WiFi.localIP());
 
 Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
if(Firebase.failed())
 {
 Serial.print(Firebase.error());
 }
 else{
 
 Serial.print("Firebase Connected");
 
 }
}
 
void loop()
{
float h = dht.readHumidity();
float t = dht.readTemperature();
Firebase.setFloat("Temperature", t);
Firebase.setFloat("Humidity", h);
sensorvalue=analogRead(mq2sensor); /// read the MQ3 sensor
Firebase.setFloat( "MQ2 Sensor/Value",sensorvalue);

Serial.println(sensorvalue);
Serial.println(t);
Serial.println(h);
delay(50);

}
 
