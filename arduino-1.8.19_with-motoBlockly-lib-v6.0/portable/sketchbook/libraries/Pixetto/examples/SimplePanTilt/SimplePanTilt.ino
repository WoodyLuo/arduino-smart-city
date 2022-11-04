/*
 * Copyright 2020 VIA Technologies, Inc. All Rights Reserved.
 *
 * This PROPRIETARY SOFTWARE is the property of WonderMedia Technologies, Inc.
 * and may contain trade secrets and/or other confidential information of
 * WonderMedia Technologies, Inc. This file shall not be disclosed to any third
 * party, in whole or in part, without prior written consent of WonderMedia.
 *
 * THIS PROPRIETARY SOFTWARE AND ANY RELATED DOCUMENTATION ARE PROVIDED AS IS,
 * WITH ALL FAULTS, AND WITHOUT WARRANTY OF ANY KIND EITHER EXPRESS OR IMPLIED,
 * AND WonderMedia TECHNOLOGIES, INC. DISCLAIMS ALL EXPRESS OR IMPLIED
 * WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, QUIET
 * ENJOYMENT OR NON-INFRINGEMENT.
*/

#include <Pixetto.h>
#include <Servo.h>

Pixetto ss(0, 1);

Servo servo_9;
Servo servo_10;

void setup()
{
  ss.begin();

  servo_9.attach(9);
  servo_10.attach(10);
  
  servo_9.write(90);   /* counterclockwise,  0 - 180, right-to-left */
  servo_10.write(135); /* counterclockwise, 90 - 160, up-to-down */
}

void loop()
{ 
  if (ss.isDetected()) {
    int x = ss.getPosX() + ss.getWidth() / 2;
    int dx = x - 50;
    int y = ss.getPosY() + ss.getHeight() / 2;
    int dy = y - 50;

    if (dx < ss.getWidth()/-2) {
      servo_9.write(servo_9.read() + map(dx, 0, -50, 0, 4)); // turn left
    } else if (dx > ss.getWidth()/2) {
      servo_9.write(servo_9.read() - map(dx, 0, 50, 0, 4)); // turn right
    }
    if (dy < ss.getHeight()/-2) {
      servo_10.write(servo_10.read() - map(dy, -10, -50, 0, 3)); // turn up
    } else if (dy > ss.getHeight()/2) {
      servo_10.write(servo_10.read() + map(dy, 10, 50, 0, 3)); // turn down
    }
  }
  delay(20);
}
