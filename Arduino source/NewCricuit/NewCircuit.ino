//www.elegoo.com
//2016.06.13

/*
  LiquidCrystal Library - Hello World

 Demonstrates the use a 16x2 LCD display.  The LiquidCrystal
 library works with all LCD displays that are compatible with the
 Hitachi HD44780 driver. There are many of them out there, and you
 can usually tell them by the 16-pin interface.

 This sketch prints "Hello World!" to the LCD
 and shows the time.

  The circuit:
 * LCD RS pin to digital pin 7
 * LCD Enable pin to digital pin 8
 * LCD D4 pin to digital pin 9
 * LCD D5 pin to digital pin 10
 * LCD D6 pin to digital pin 11
 * LCD D7 pin to digital pin 12
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)

 Library originally added 18 Apr 2008
 by David A. Mellis
 library modified 5 Jul 2009
 by Limor Fried (http://www.ladyada.net)
 example added 9 Jul 2009
 by Tom Igoe
 modified 22 Nov 2010
 by Tom Igoe

 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/LiquidCrystal
 */

// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);


int sensorThres = 400;
int warning = sensorThres/2;

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);

  //pinMode(0, OUTPUT);
  //pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  Serial.begin(9600);
}

void loop() 
{
  lcd.clear();
  int analogSensor = analogRead(0);
  lcd.print(analogSensor);
  lcd.setCursor(0,0);
  Serial.println(analogSensor);

  digitalWrite(0, LOW);
  digitalWrite(1, LOW);
  digitalWrite(2, HIGH);
/*
  if(analogSensor > warning && analogSensor < sensorThres)
  {
    digitalWrite(0, LOW);
    digitalWrite(1, HIGH);
    digitalWrite(2, LOW);
    
    lcd.setCursor(0,1);
    lcd.print("ALERT!");
  }

  else if(analogSensor >= sensorThres)
  {
    digitalWrite(0, HIGH);
    digitalWrite(1, LOW);
    digitalWrite(2, LOW);
    
    lcd.setCursor(0,1);
    lcd.print("WARNING!");    
  }
*/
  delay(1000);
}

