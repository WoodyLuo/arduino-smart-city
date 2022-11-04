// Example testing sketch for various DHT humidity/temperature sensors

#include "esp_DHTesp.h"

DHTesp dht;

void setup()
{
  Serial.begin(9600);
  pinMode(13, INPUT);
  dht.setup(13);

}


void loop()
{
    Serial.print("Humidity:");
    Serial.print(dht.getHumidity());
    Serial.print(" %\t");
    Serial.print("Temperature:");
    Serial.print(dht.getTemperature());
    Serial.println(" *C");

}
