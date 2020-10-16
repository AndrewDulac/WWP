#include <Arduino.h>
#include "Communication.h"
#include "LowPower.h"

unsigned long Timer;
unsigned long Sample;
enum SWITCH {OPEN, CLOSE, HOLD};
SWITCH back_EMF;
/* This is our setup loop - it runs once
 *  1) initializes all of the variables
 *  2) sets all input and output pins
 *  3) begins our timers
 */

void setup() 
{
  back_EMF = OPEN;
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
  refreshPowerData();
  if( millis() - Timer >= 1000)
  {
    printData();    
    Timer += 1000; 
  }     
  /*   
  if(Current == 0 && Voltage >= 1 && RPM >= 200)
  {
    back_EMF = CLOSE;
  }   
  */        
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
    LowPower.powerDown(SLEEP_2S, ADC_OFF, BOD_OFF);
    break;

    case HOLD:
    break;
    
    default:
    back_EMF = HOLD;
  }
}
