#include <Arduino.h>
#include "Communication.h"

unsigned long Timer;
unsigned long Sample;
enum SWITCH {OPEN, CLOSE, HOLD};
SWITCH back_EMF;
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
    refreshPowerData();
    printData();    
    Timer += 1000; 
  }                   
  switch(back_EMF){
    case OPEN:
    digitalWrite(onCoil,HIGH);
    delay(15);
    digitalWrite(onCoil,LOW);
    back_EMF = HOLD;
    break;

    case CLOSE:
    digitalWrite(offCoil,HIGH);
    delay(15);
    digitalWrite(offCoil,LOW);
    back_EMF = HOLD;
    break;

    case HOLD:
    break;
    
    default:
    back_EMF = HOLD;
  }
}
