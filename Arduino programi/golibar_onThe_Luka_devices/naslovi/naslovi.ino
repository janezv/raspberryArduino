#include <OneWire.h>
#include <DallasTemperature.h>
#include <LiquidCrystal.h>

OneWire oneWire(5);
DallasTemperature sensors(&oneWire);
LiquidCrystal lcd(A3,A2,A1,A0,13,12);

int n;
//#define DHTTYPE DHT11

void setup() {
  lcd.begin(16, 2);
  delay(200);
  sensors.begin();
  n = sensors.getDeviceCount();
  lcd.setCursor(0, 0);
  lcd.print("found ");
  lcd.print(n);
  lcd.print(" devices         ");
  delay(1000);
  lcd.clear();
}

void loop() {
  float temp;
  int i;
//  uint8_t *naslov[8];
  byte naslov[8];
//  int naslov;
  
  sensors.requestTemperatures();
  for (i=0; i<n; i++) {

    (void)sensors.getAddress(naslov, i);
    lcd.setCursor(0, 0);
    lcd.print(i);
    lcd.print(": ");
    lcd.print(naslov[0], HEX); lcd.print(" ");
    lcd.print(naslov[1], HEX); lcd.print(" ");
    lcd.print(naslov[2], HEX); lcd.print(" ");
    lcd.print(naslov[3], HEX); lcd.print("           ");
    lcd.setCursor(0,1);
    lcd.print(naslov[4], HEX); lcd.print(" ");
    lcd.print(naslov[5], HEX); lcd.print(" ");
    lcd.print(naslov[6], HEX); lcd.print(" ");
    lcd.print(naslov[7], HEX); lcd.print(" :");
    
    temp = sensors.getTempCByIndex(i);
    lcd.print(temp,1);
    lcd.print("                  ");
    
    delay(5000);
  }

//  delay(1000);
}
// EOF

