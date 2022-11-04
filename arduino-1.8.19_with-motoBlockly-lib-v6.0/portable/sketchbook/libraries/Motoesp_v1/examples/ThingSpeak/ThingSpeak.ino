#include <ESP8266WiFi.h>

WiFiClient client;

void setup()
{
  pinMode(17, INPUT);
    WiFi.begin("Motoduino","123456789");
  while(WiFi.status() != WL_CONNECTED) {
   delay(500);
   Serial.print(".");
  }
  if(client.connect("api.thingspeak.com", 80)) {
     String  things_request = "GET /update?api_key=yourWriteAPIKey&field1="+ String(analogRead(17))+"\r\n\r\n";
       client.print(things_request);
       client.stop();
  }
  Serial.println("Sent...");

}


void loop()
{

}
