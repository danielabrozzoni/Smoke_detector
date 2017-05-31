#include <Firebase.h>
#include <FirebaseArduino.h>
#include <FirebaseCloudMessaging.h>
#include <FirebaseError.h>
#include <FirebaseHttpClient.h>
#include <FirebaseObject.h>

/*******
 
 It prints random numbers on serial port
 
*******/

 
void setup(){
  
  Serial.begin(9600);
}

void loop(){
  //for(int i = 0;;i++)
  {
    Serial.println(rand()%1000);
   // FirebaseArduino.begin("https://alternanza-c2cd2.firebaseio.com/");
    delay(1000);
  }
}

