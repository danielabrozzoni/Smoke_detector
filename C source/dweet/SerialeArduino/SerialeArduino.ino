/*******
 
 It prints random numbers on serial port
 
*******/

 
void setup(){
  
  Serial.begin(9600);
}

void loop(){
  //for(int i = 0;;i++)
  {
    Serial.println(34530);
    delay(1000);
  }
}

