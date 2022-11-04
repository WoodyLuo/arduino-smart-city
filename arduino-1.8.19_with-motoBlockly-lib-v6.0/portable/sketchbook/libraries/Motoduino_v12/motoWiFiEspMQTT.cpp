/*--------------------------------------------------------------------
This file is part of the Arduino WiFiEsp library.

The Arduino WiFiEsp library is free software: you can redistribute it
and/or modify it under the terms of the GNU General Public License as
published by the Free Software Foundation, either version 3 of the
License, or (at your option) any later version.

The Arduino WiFiEsp library is distributed in the hope that it will be
useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with The Arduino WiFiEsp library.  If not, see
<http://www.gnu.org/licenses/>.
--------------------------------------------------------------------*/

#include "motoWiFiEsp.h"
#include "motoWiFiEspMQTT.h"

#include "utility/EspDrv.h"
#include "utility/debug.h"

WiFiEspMQTT::WiFiEspMQTT() {}

boolean WiFiEspMQTT::begin(char* client_id,const char *username,const char *passphrase)
{
	return EspDrv::MQTTConfigur(client_id,username,passphrase);
}
boolean WiFiEspMQTT::begin(char* client_id)
{
	return this->begin(client_id,"","");
}
boolean WiFiEspMQTT::connect(const char* host, uint16_t port)
{
	_sock = 1;
	return EspDrv::MQTTConnect(host,port);
}
boolean WiFiEspMQTT::connect(const char* host)
{
	return this->connect(host,1883);
}
boolean WiFiEspMQTT::publish(String topic) {
  return this->publish(topic.c_str(), "");
}

boolean WiFiEspMQTT::publish(String topic, String payload) {
  return this->publish(topic.c_str(), payload.c_str());
}

boolean WiFiEspMQTT::publish(const char * topic, String payload) {
  return this->publish(topic, payload.c_str());
}

boolean WiFiEspMQTT::publish(const char * topic, const char * payload) {
  return EspDrv::publish(topic,payload);
}
boolean WiFiEspMQTT::subscribe(String topic) {
  return this->subscribe(topic.c_str());
}

boolean WiFiEspMQTT::subscribe(const char * topic) {
  return EspDrv::subscribe(topic);
}

boolean WiFiEspMQTT::unsubscribe(String topic) {
  return this->unsubscribe(topic.c_str());
}

boolean WiFiEspMQTT::unsubscribe(const char * topic) {
  return EspDrv::unsubscribe(topic);
}
void WiFiEspMQTT::loop() {
  if(EspDrv::mqtt_read()>0){
	String data =EspDrv::subscribe_data();
	data =data.substring(data.indexOf(",")+1);
	int first_index=data.indexOf(",");
	int last_index=data.lastIndexOf(",");
	String topic= data.substring(1,first_index-1);
	String data_length= data.substring(first_index+1,last_index);
	String payload= data.substring(last_index+1,data.length()-1);
	messageReceived(topic,payload,payload.c_str(),data_length.toInt());
  }
}