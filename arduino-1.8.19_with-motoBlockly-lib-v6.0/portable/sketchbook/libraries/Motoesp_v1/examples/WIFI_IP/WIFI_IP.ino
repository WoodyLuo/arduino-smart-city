#include <ESP8266WiFi.h>

void setup()
{
  Serial.begin(9600);
  WiFi.begin("","");
  while(WiFi.status() != WL_CONNECTED) {
   delay(500);
   Serial.print(".");
  }
  Serial.println(WiFi.localIP());
}

void loop()
{

}
