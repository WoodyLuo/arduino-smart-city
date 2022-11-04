///////////////////////////////////////////////
// Description: DS18B20 Test (水溫感測) 
// Author: Motoduino
// Date April 2016
/////////////////////////////////////////////

#include <esp_OneWire.h>
#include <esp_DallasTemperature.h>

#define ONE_WIRE_BUS_13 13
OneWire oneWire_13(ONE_WIRE_BUS_13);
DallasTemperature sensors_13(&oneWire_13);

float Temperature_DS18B20_13(int tempUnit) {
sensors_13.requestTemperatures();
float temperature = sensors_13.getTempCByIndex(0);
if(tempUnit == 1)
   return temperature;
 else
   return ((temperature * 1.8) + 32);
}

void setup()
{
  Serial.begin(9600);
  sensors_13.begin();

}


void loop()
{
    Serial.print(Temperature_DS18B20_13(1));
    Serial.println(" C");

}
