#include <Arduino.h>
#include "Communication.h"

enum state { NORM, BRAKE };

state emerState;
int emerSwitchVal;
unsigned long Timer;
unsigned long Sample;

/* This is our setup loop - it runs once
 *  1) initializes all of the variables (for logic purposes)
 *  2) sets all input and output pins
 *  3) begins our timers
 */

void setup() 
{
  Serial.begin(9600); 
  ConfigurePins();
  RPM_timer = micros();
  Timer = millis();
  Sample = millis();
}

/* This is our main loop - it runs as fast as it can
 *  1) can go into variables (see int Sample_Time) to adjust the rate at which we control the servo
 *  2) not much else should be adjusted here
 */
void loop() 
{
  readRPM();
  if( millis() - Timer >= 1000)
  {
    Serial.println(emerSwitchVal);
    refreshPowerData();
    printData();    
    Timer += 1000; 
  }                   

  
  emerSwitchVal = analogRead(emergencySwitch);
  if(emerSwitchVal <= 250)
  {
    emerState = NORM;
  }
  else
  {
    emerState = BRAKE;
  }
  
  switch(emerState)
  {
    case NORM:
      controlPitch();
      controlCurrent();
      
      digitalWrite(relay_ICtrl, LOW);
      /*
      digitalWrite(relay_Cap[0], LOW);
      digitalWrite(relay_Cap[1], LOW);
      digitalWrite(relay_BEMF[0], LOW);
      digitalWrite(relay_BEMF[1], LOW);
      digitalWrite(relay_BEMF[2], LOW);
      */
    break;

    case BRAKE:
      controlPitch();
      controlCurrent();

      digitalWrite(relay_ICtrl, HIGH);
      /*
      digitalWrite(relay_Cap[0], HIGH);
      digitalWrite(relay_Cap[1], HIGH);
      digitalWrite(relay_BEMF[0], HIGH);
      digitalWrite(relay_BEMF[1], HIGH);
      digitalWrite(relay_BEMF[2], HIGH);
      */
      // analogWrite(pitchCtrl, 100);
      // analogWrite(pwrControl, 100);

    break;
  }
}
