/*

*/

#include "SparkFun_SHTC3.h" // Click here to get the library: http://librarymanager/All#SparkFun_SHTC3

SHTC3 mySHTC3;

const byte statLED = 13;

void setup() {
  Serial.begin(115200);
  Serial.println("SHTC3 Tester");

  pinMode(statLED, OUTPUT);
  digitalWrite(statLED, LOW);
}

void loop() {
  if (mySHTC3.begin() == SHTC3_Status_Nominal)
  {
    while (mySHTC3.lastStatus == SHTC3_Status_Nominal)
    {
      mySHTC3.update();
      Serial.print("RH = ");
      Serial.print(mySHTC3.toPercent());
      Serial.println();

      if(mySHTC3.toPercent() > 1.0 && mySHTC3.toPercent() < 99.0)
      {
        digitalWrite(statLED, HIGH); //Indicate good board        
      }

      delay(50);
    }
  }
  else
  {
    Serial.println("No sensor detected");
    digitalWrite(statLED, LOW);
  }

  delay(100);
}
