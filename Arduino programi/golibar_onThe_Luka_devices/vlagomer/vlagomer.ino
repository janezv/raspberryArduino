#include <OneWire.h>
#include <DallasTemperature.h>
#include <LiquidCrystal.h>
#include "DHT.h"
#define DHTPIN 2     // what pin we're connected to

OneWire oneWire(5);
DallasTemperature sensors(&oneWire);
LiquidCrystal lcd(A3,A2,A1,A0,13,12);

#define DHTTYPE DHT22
DHT dht(6, DHTTYPE);
int n;
//dht hygro;

void setup() {
  lcd.begin(16, 2);
  delay(200);
  sensors.begin();
  n = sensors.getDeviceCount();
    dht.begin();
}

void loop() {
  float temp;
  int i;

   float h = dht.readHumidity();
  // Read temperature as Celsius
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit
  float f = dht.readTemperature(true);
  
//  sensors.requestTemperatures();
  lcd.setCursor(0, 0);
//  lcd.print("T: ");
//  for (i=0; i<n; i++) {
//    temp = sensors.getTempCByIndex(i);
//    lcd.print(temp,1);
//    lcd.print(" ");
//  }
//  int chk = hygro.read22(6);
//  lcd.print(hygro.humidity, 1);
//  lcd.print(hygro.temperature, 1);
lcd.print("vlaga ");
lcd.print(h);
  lcd.print("    ");
  lcd.setCursor(0, 1);
  lcd.print("temp ");
lcd.print(t);
  lcd.print("    ");
  delay(2000);
}
// EOF

