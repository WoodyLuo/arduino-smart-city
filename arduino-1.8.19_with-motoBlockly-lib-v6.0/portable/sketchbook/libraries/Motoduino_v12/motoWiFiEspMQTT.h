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

#ifndef WiFiEspMQTT_h
#define WiFiEspMQTT_h

typedef struct {
    char * topic;
    char * payload;
    unsigned int length;
    boolean retained;
} MQTTMessage;

void messageReceived(String topic, String payload,char * bytes, unsigned int length);

class WiFiEspMQTT{
private:
  uint8_t _sock;     // connection id
public:
  WiFiEspMQTT();
  boolean begin(char* client_id,const char *username,const char *passphrase);
  boolean begin(char* client_id);
  boolean connect(const char* host, uint16_t port);
  boolean connect(const char* host);
  boolean publish(String topic);
  boolean publish(String topic, String payload);
  boolean publish(const char * topic, String payload);
  boolean publish(const char * topic, const char * payload);
  boolean subscribe(String topic);
  boolean subscribe(const char * topic);
  boolean unsubscribe(String topic);
  boolean unsubscribe(const char * topic);
  void loop();
};

#endif
