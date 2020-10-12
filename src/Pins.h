#if !defined(PINS_H)
#define PINS_H

//PWM Pins include 3, 5, 6, 9, 10, 11

#define currentPin A0  // current sensor input 
#define voltagePin A1    // voltage sensor input
#define Sensor 2    // RPM sensor input
#define emergencySwitch A3
#define manualCtrl A4
#define voltagePin_2 A6

#define relay_ICtrl 8   // Relay #1 (switch off current control)
int relay_Cap[] = {3, 4}; 
// Relays #2 and #3 (Capacitor Power during braking)
int relay_BEMF[] = {5, 6, 7}; 
// Relays #4, #5 , #6 (Back EMF Brake)

#define pitchCtrl  9   // Pitch Position PWM pin
#define pwrControl 10  // Current Power PWM
#define onCoil 11      //On Coil PIN
#define offCoil 12     //OFF coil PIN

void ConfigurePins()
{
  pinMode(manualCtrl, INPUT);
  pinMode(currentPin, INPUT);
  pinMode(voltagePin, INPUT);
  pinMode(voltagePin_2, INPUT);
  pinMode(Sensor, INPUT);
  attachInterrupt(digitalPinToInterrupt(Sensor), rpmInterrupt, RISING);
  pinMode(emergencySwitch, INPUT);
  pinMode(relay_ICtrl, OUTPUT);
  pinMode(relay_Cap[0], OUTPUT);
  pinMode(relay_Cap[1], OUTPUT);
  pinMode(relay_BEMF[0], OUTPUT);
  pinMode(relay_BEMF[1], OUTPUT);
  pinMode(relay_BEMF[2], OUTPUT);
  pinMode(pitchCtrl, OUTPUT);
  pinMode(pwrControl, OUTPUT);
  pinMode(onCoil, OUTPUT);
  pinMode(offCoil, OUTPUT);
  
  digitalWrite(relay_ICtrl, LOW);
  digitalWrite(relay_Cap[0], LOW);
  digitalWrite(relay_Cap[1], LOW);
  digitalWrite(relay_BEMF[0], LOW);
  digitalWrite(relay_BEMF[1], LOW);
  digitalWrite(relay_BEMF[2], LOW);
  digitalWrite(pitchCtrl, LOW);
  digitalWrite(pwrControl, LOW);
}




#endif // PINS_H




