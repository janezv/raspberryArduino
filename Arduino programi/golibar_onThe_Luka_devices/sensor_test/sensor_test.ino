#include <OneWire.h>
#include <DallasTemperature.h>

OneWire oneWire(3);
DallasTemperature sensors(&oneWire);

int n;

void setup() {
  Serial.begin(9600);
  delay(200);
  sensors.begin();
  n = sensors.getDeviceCount();
}

void loop() {
  float temp;
  
  sensors.requestTemperatures();
  temp = sensors.getTempCByIndex(0);
  Serial.println(n);

  Serial.println(temp);
//  delay(1000);
}
// EOF

