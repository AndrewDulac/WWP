//Initialize variables
double RPM, poles = 20.0;
unsigned long RPM_timer;

void rpmInterrupt()
{
  RPM = ((60000000 / (micros() - RPM_timer)) / (poles));
  RPM_timer = micros();
}

