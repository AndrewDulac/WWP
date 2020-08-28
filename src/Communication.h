#include "Pins.h"
#include "Power.h"
#include "RPM.h"
#include "Pitch.h"
#include "CurCtrl.h"

void printData(double rpm, double power, double voltIn, double CurrIn, double Vrectifier)
{
  Serial.println(rpm);
}

void printData()
{
  Serial.print("Voltage: ");
  Serial.print(Voltage);
  Serial.println(" V");
  Serial.print("Current Requested: ");
  Serial.println(curRequested);
  Serial.print("Current: ");
  Serial.print(Current);
  Serial.println(" A");
  Serial.print("Power: ");
  Serial.print(Power);
  Serial.println(" W");
  Serial.print(RPM);
  Serial.println(" RPM");
}
