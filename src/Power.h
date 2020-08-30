double Current;
double Voltage;
double Power;
int temp_read;
int curRequested;
int maxPower;

double getVoltage( int vPin )
{
  double voltage = analogRead(vPin);
  //Serial.println(voltage);    //USED TO DIAGNOSE SENSOR ERRORS
  double Voltage = voltage * (25.0/ 1023.0);

  return Voltage;
}

double getVoltageCondensed( int vPin )
{
  return (analogRead(vPin) * (25.0/1023.0));
}

double getCurrent(int cPin)
{
  double current = analogRead(cPin);
  //Serial.println(current);    //USED TO DIAGNOSE SENSOR ERRORS
  double Current = ((((current/1023)*(10))-4.99)*2.85);
 
  return Current;
}

double getCurrentCondensed(int cPin)
{
  return((((analogRead(cPin)/1023)*(10))-4.99)*2.85);
}

double getPower()
{
  double p = ( Current * Voltage );
  return p;
}

int calcCurPercent(int sig){
  temp_read = analogRead(sig);
  return map(temp_read, 0, 1024, 0, 100);
}

void refreshPowerData()
{
  curRequested = calcCurPercent(manualCtrl);
  Current = getCurrent(currentPin);
  Voltage = getVoltage(voltagePin);
  Power = getPower();
}
