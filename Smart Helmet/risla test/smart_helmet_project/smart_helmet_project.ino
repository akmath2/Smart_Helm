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
String value;
const unsigned char Passive_buzzer = 2;
const unsigned char Active_buzzer = 14;
const unsigned char built_in_led = 16;

void buzzerOn(){
  digitalWrite(built_in_led,LOW) ; //Turn on the built in led
  digitalWrite(Active_buzzer,HIGH) ; //Turn on active buzzer
  delay (1000);
 
  digitalWrite(built_in_led,HIGH) ; //Turn off the built in led
  digitalWrite(Active_buzzer,LOW) ; //Turn off active buzzer
  delay (1000); 
}
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

pinMode (Active_buzzer,OUTPUT) ;
pinMode (built_in_led,OUTPUT) ;
 }

void loop()
{
int h = dht.readHumidity();
int t = dht.readTemperature();
Firebase.setFloat("Temperature", t);
Firebase.setFloat("Humidity", h);
sensorvalue=analogRead(mq2sensor); /// read the MQ3 sensor
Firebase.setFloat( "MQ2 Sensor",sensorvalue);

Serial.println(sensorvalue);
Serial.println(t);
Serial.println(h);
delay(2000);
String value = Firebase.getString( "/Readbuzzer");

  if (Firebase.failed()) {
    Serial.println("Error reading from Firebase");
    Serial.println(Firebase.error());
    return;
  }



int buz=atoi(value.c_str());
Serial.println(buz);
if (buz==1){
  buzzerOn();
}

  if (h<60 ){
    if (t>36.5){
      buzzerOn();
  }
}
  else if (h<75){
    if (t>32){
      buzzerOn();
  }
}
  else if (h<90){
    if (t>30){
      buzzerOn();
  }
}
  else {
    if (t>28){
     buzzerOn();
  }
}
}
 
