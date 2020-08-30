//PWM Pins include 3, 5, 6, 9, 10, 11

int currentPin = A0;    // current sensor input 
int voltagePin = A1;    // voltage sensor input
int Sensor = A2;        // RPM sensor input
int emergencySwitch = A3;
int manualCtrl = A4;
int voltagePin_2 = A6;

int relay_ICtrl = 2; 
// Relay #1 (switch off current control)
int relay_Cap[] = {3, 4}; 
// Relays #2 and #3 (Capacitor Power during braking)
int relay_BEMF[] = {5, 6, 7}; 
// Relays #4, #5 , #6 (Back EMF Brake)

int pitchCtrl = 9;
// Pitch Position PWM pin
int pwrControl = 10;
// Current Power PWM

void ConfigurePins()
{
  pinMode(manualCtrl, INPUT);
  pinMode(currentPin, INPUT);
  pinMode(voltagePin, INPUT);
  pinMode(voltagePin_2, INPUT);
  pinMode(Sensor, INPUT);
  pinMode(emergencySwitch, INPUT);
  pinMode(relay_ICtrl, OUTPUT);
  pinMode(relay_Cap[0], OUTPUT);
  pinMode(relay_Cap[1], OUTPUT);
  pinMode(relay_BEMF[0], OUTPUT);
  pinMode(relay_BEMF[1], OUTPUT);
  pinMode(relay_BEMF[2], OUTPUT);
  pinMode(pitchCtrl, OUTPUT);
  pinMode(pwrControl, OUTPUT);

  
  digitalWrite(relay_ICtrl, LOW);
  digitalWrite(relay_Cap[0], LOW);
  digitalWrite(relay_Cap[1], LOW);
  digitalWrite(relay_BEMF[0], LOW);
  digitalWrite(relay_BEMF[1], LOW);
  digitalWrite(relay_BEMF[2], LOW);
  digitalWrite(pitchCtrl, LOW);
  digitalWrite(pwrControl, LOW);
}
