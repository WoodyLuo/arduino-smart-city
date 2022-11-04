
#include <esp_DS3231.h>
#include <Wire.h>

DS3231 Clock;

bool Century=false;

bool h12;
bool PM;

void setup()
{
  Serial.begin(9600);
  Wire.begin();

}


void loop()
{
    Serial.print(Clock.getYear());
    Serial.print(" ");
    Serial.print(Clock.getMonth(Century));
    Serial.print(" ");
    Serial.print(Clock.getDate());
    Serial.print(" ");
    Serial.print(Clock.getHour(h12, PM));
    Serial.print(":");
    Serial.print(Clock.getMinute());
    Serial.print(":");
    Serial.print(Clock.getSecond());
    Serial.print(":");
    Serial.println(Clock.getDoW());
    delay(1000);
}
