
#include <esp_DS3231.h>
#include <Wire.h>

DS3231 Clock;
void setup()
{
  Serial.begin(9600);
  Wire.begin();
}

void loop()
{
  // Send current temperature
  Serial.print("Temperature: ");
  Serial.print(Clock.getTemperature());
  Serial.println(" C");
  delay (1000);
}
