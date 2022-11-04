#include "esp_TM1637.h"

int8_t TimeDisp[] = {0x00,0x00,0x00,0x00};
TM1637 tm1637led_13_15(13,15);

void setup()
{
  tm1637led_13_15.init();
  tm1637led_13_15.set(BRIGHT_TYPICAL);
  pinMode(13, OUTPUT);
  pinMode(15, OUTPUT);
    for (int i = 1; i <= 9999; i=i+1) {
    TimeDisp[0] = i / 1000;
    TimeDisp[1] = (i % 1000)/100;
    TimeDisp[2] = (i % 100)/10;
    TimeDisp[3] = i % 10;
    tm1637led_13_15.display(TimeDisp);
    delay(1000);
  }

}


void loop()
{

}
