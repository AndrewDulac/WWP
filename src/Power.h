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

double oldCurrent(int cPin)
{
  return((((analogRead(cPin)/1023)*(10))-4.99)*2.85);
}

double getCurrent(int cPin){
  return((analogRead(cPin)-23.14)/253.14);
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
