#include <ESP8266WiFi.h>

WiFiClient client;

void setup()
{
  Serial.begin(9600);
  pinMode(13, INPUT);
    WiFi.begin("Motoduino","123456789");
  while(WiFi.status() != WL_CONNECTED) {
   delay(500);
   Serial.print(".");
  }
  Serial.println(WiFi.localIP());

}


void loop()
{
    if (digitalRead(13) == 1) {
      if (client.connect("maker.ifttt.com", 80)) {
           String data = "\r\n{\"value1\":"+ String(12)+",\"value2\": "+String(43)+",\"value3\": "+String(55)+"}";
           client.println("POST /trigger/yourEventName/with/key/yourMakerChannelKey HTTP/1.1");
           client.println("Host: maker.ifttt.com");
           client.println("User-Agent: Esp8266");
           client.println("Accept: */*");
           client.print("Content-Length: ");
           client.println(data.length());
           client.println("Content-Type: application/json");
           client.println("Connection: close");
           client.println(data);
      }
      Serial.print("Sent out...");
      delay(1000);

    }

}
