#if !defined(POWER_H)
#define POWER_H

double Current;
double Voltage;
double Power;
int temp_read;
int curRequested;
int maxPower;


double getVoltage(int vPin )
{
  return (analogRead(vPin) * (25.0/1023.0));
}

double getCurrent(int cPin)
{
  return((((analogRead(cPin)/1023)*(10))-4.99)*2.85);
}

double newCurrent(int cPin){
  return((analogRead(cPin)/245.04)-23.7158);
}

double getPower()
{
  double p = ( Current * Voltage );
  return p;
}


void refreshPowerData()
{
  Current = getCurrent(currentPin);
  Voltage = getVoltage(voltagePin);
  Power = getPower();
}

#endif // POWER_H



