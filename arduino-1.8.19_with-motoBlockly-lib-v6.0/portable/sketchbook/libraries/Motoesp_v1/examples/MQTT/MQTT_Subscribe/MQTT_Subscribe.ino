#include <ESP8266WiFi.h>
#include <esp_PubSubClient.h>

WiFiClient client;

esp_PubSubClient mqtt_client(client);

String getTopicData(String myTopic, String inTopic, byte* payload ,unsigned int length) {
String TopicData;
if(inTopic == myTopic){
 for (int i = 0; i < length; i++) {
  TopicData += (char)payload[i];}
     return TopicData;
  }else{
     return "";}
}

void callback(char* topic, byte* payload, unsigned int length)
{
  Serial.println(getTopicData("watering", topic, payload,length));
  if (getTopicData("watering", topic, payload,length) == "on") {
    digitalWrite(13,HIGH);

  } else if (getTopicData("inTopic", topic, payload,length) == "off") {
    digitalWrite(13,LOW);
  }
}

void setup()
{
  Serial.begin(9600);
    WiFi.begin("Motoduino","motoS4A123");
  while(WiFi.status() != WL_CONNECTED) {
   delay(500);
   Serial.print(".");
  }
  Serial.println(WiFi.localIP());
  mqtt_client.setServer("iot.eclipse.org",1883);
    while (!mqtt_client.connect("Arduino123456789")) {
      Serial.print(".");
      delay(1000);
    }
  Serial.println("Connected !");
  mqtt_client.subscribe("watering");
  mqtt_client.setCallback(callback);
  pinMode(13, OUTPUT);
}


void loop()
{
    mqtt_client.loop();
}
