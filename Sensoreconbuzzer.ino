/*******
 
 All the resources for this project:
 https://www.hackster.io/Aritro

*******/


int redLed = 12;
int greenLed = 11;
int buzzer = 10;
int smokeA0 = A5;
//Valore di soglia
int sensorThres = 700;


void setup(){
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(smokeA0, INPUT);
  Serial.begin(9600);
}

void loop(){
  int analogSensor = analogRead(smokeA0);
  Serial.println(analogSensor);
  if(analogSensor > sensorThres)
  {
    digitalWrite(redLed, HIGH);
    digitalWrite(greenLed, LOW);
    tone(buzzer, 1000, 200);
  }
  else
  {
    digitalWrite(redLed, LOW);
    digitalWrite(greenLed, HIGH);
    noTone(buzzer);
  }
  delay(100);
}

