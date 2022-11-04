///////////////////////////////////////////////
// Description: LM35 Test 
// Author: Motoduino
// Date April 2018
/////////////////////////////////////////////

float Temperature_LM35T_17(int tempUnit) {
int readtempValue = analogRead(17);
float temperature = (readtempValue * 0.097656);
if(tempUnit == 1)
   return temperature;
 else
   return ((temperature * 1.8) + 32);
}

void setup()
{
  Serial.begin(9600);
  pinMode(17, INPUT);

}


void loop()
{
    Serial.print("Temperature: ");
    Serial.print(Temperature_LM35T_17(1));
    Serial.println(" C");
    delay(1000);
}  
