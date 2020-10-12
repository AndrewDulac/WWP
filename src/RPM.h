//Initialize variables
double RPM = 0.0, poles = 20.0;
unsigned long RPM_timer;

void rpmInterrupt()
{
  RPM = ((60000000 / (micros() - RPM_timer)) / (poles));
  RPM_timer = micros();
}

