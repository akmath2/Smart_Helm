int Input = A0;
int SensorVal = 0;

int Check = 0;

void setup() {
  Serial.begin(9600);
  pinMode(Input, INPUT);
  Serial.println("Interfacing of Smoke Sensor with Arduino");
  Serial. println("Design by www.TheEngineeringProjects.com");
  Serial.println();
}

void loop() {

  SensorVal = analogRead(Input);
  if((SensorVal > 500) && (Check == 1))
  {
    Serial.println("Smoke Detected . . .");
    Check = 0;
  }

  if((SensorVal < 500) && (Check == 0))
  {
    Serial.println("All Clear . . .");
    Check = 1;
  }
  //Serial.println(SensorVal);
  delay(500);
}
