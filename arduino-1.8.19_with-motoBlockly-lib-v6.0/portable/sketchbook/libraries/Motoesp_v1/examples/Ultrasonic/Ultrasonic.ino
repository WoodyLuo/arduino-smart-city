float ultrasonic_distance_13_15() {
  digitalWrite(13, LOW);
  digitalWrite(15, LOW);
  delayMicroseconds(5);
  digitalWrite(13, HIGH);
  delayMicroseconds(10);
  digitalWrite(13, LOW);
  unsigned long sonic_duration = pulseIn(15, HIGH);
  float distance_cm = (sonic_duration / 2.0) / 29.1;
  return distance_cm;
}

void setup()
{
  Serial.begin(9600);
  pinMode( 13 , OUTPUT);
  pinMode( 15 , INPUT);

}


void loop()
{
    Serial.print((ultrasonic_distance_13_15( )));
    Serial.println("cm");

}
