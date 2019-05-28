#include <OneWire.h> 
#include <DallasTemperature.h>
#include <DHT.h>  //humidity library

// Temperatures initializtion
#define ONE_WIRE_BUS 2 
OneWire oneWire(ONE_WIRE_BUS); 
DallasTemperature sensors(&oneWire);

//Humidity initialization
#define DHTPIN 7     // what pin we're connected to
#define DHTTYPE DHT22   // DHT 22  (AM2302)
DHT dht(DHTPIN, DHTTYPE); //// Initialize DHT sensor for normal 16mhz Arduino
//Variables
int chk;
float hum;  //Stores humidity value
float temp; //Stores temperature value


void setup(void) 
{ 
 // start serial port 
 Serial.begin(9600); 
 Serial.println("Dallas Temperature IC Control Library Demo"); 
 // Temperatures
 sensors.begin(); 
 //Humidity
 dht.begin();
} 

void loop(void) 
{ 
  
/**********************reading temperatures senzors**********************************************/
   sensors.requestTemperatures(); // Send the command to get temperature readings 
   
   Serial.print("T1="); 
   Serial.print(sensors.getTempCByIndex(0)); // Why "byIndex"?  
   Serial.print(";");
   // You can have more than one DS18B20 on the same bus.  
   // 0 refers to the first IC on the wire  
   Serial.print("T2="); 
   Serial.print(sensors.getTempCByIndex(1)); // Why "byIndex"? 
   Serial.print(";");
   
/**********************reading Humidity senzors**********************************************/
    hum = dht.readHumidity();
    temp= dht.readTemperature();
    //Print temp and humidity values to serial monitor
    Serial.print("H1=");
    Serial.print(hum);
    Serial.print(";");
    Serial.print("H1_t=");
    Serial.println(temp);
    delay(300); //Delay 2 sec.
  
}
