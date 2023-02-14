#include <LiquidCrystal.h>

int rs=7;
int en=8; 
int d4=9; 
int d5=10;
int d6=11; 
int d7=12; 
// set variables for the pins 

int dt=2000;

// set up the LCD display 
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);

#include "DHT.h"

// setup the DHT11 sensor 
#define Type DHT11
int sensePin=2; 
DHT HT(sensePin, Type); 

float humidity; 
float tempC; 
float tempF;

void setup() {
HT.begin(); 
lcd.begin(16,2); 
Serial.begin(9600); 
}

void loop() {
Serial.println("============="); 

humidity=HT.readHumidity();
tempF=HT.readTemperature(true); 
tempC=HT.readTemperature(); 

if ( isnan(humidity)|| isnan(tempF) || isnan(tempC)){
  Serial.println("error reading from sensor"); 
  return; 
}

lcd.setCursor(0,0); 
lcd.print("Temp "); 
lcd.print(tempC); 
lcd.print(" C"); 

lcd.setCursor(0,1); 
lcd.print("Humidity "); 
lcd.print(humidity); 
lcd.print(" %"); 


Serial.print("Temprature: "); 
Serial.print(tempC);
Serial.print(" C "); 
Serial.print("Humidity: ");
Serial.print(humidity); 
Serial.println(" %"); 

delay(dt); 
lcd.clear(); 
}
