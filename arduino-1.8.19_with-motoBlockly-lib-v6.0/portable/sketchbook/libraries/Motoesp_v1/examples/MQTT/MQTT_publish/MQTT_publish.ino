#include <ESP8266WiFi.h>

#include <esp_PubSubClient.h>

WiFiClient client;

esp_PubSubClient mqtt_client(client);

void callback(char* topic, byte* payload, unsigned int length)
{
}

void setup()
{
  Serial.begin(9600);
  pinMode(13, INPUT);
    WiFi.begin("SSID","Password");
  while(WiFi.status() != WL_CONNECTED) {
   delay(500);
   Serial.print(".");
  }
  mqtt_client.setServer("iot.eclipse.org",1883);
    while (!mqtt_client.connect("Arduino123456789")) {
      Serial.print(".");
      delay(1000);
    }
  Serial.println("Connected !");

  mqtt_client.setCallback(callback);
}


void loop()
{
    mqtt_client.loop();
    if (digitalRead(13) == 1) {
      mqtt_client.publish("outTopic", "Hello");
      delay(1000);

    }

}
