#pragma once 
//Initialize variables
int count_max = 10;
double RPS = 0.0, RPM = 0.0, poles = 12.0, edge_count = 0.0;
unsigned long RPM_timer;


void readRPM()
{
  if(edge_count >= count_max)
  {
    RPS = (1000000 * edge_count / (micros() - RPM_timer))/poles;
    edge_count = 0.0;
    RPM = RPS * 60.0;
    RPM_timer = micros();
  }
}
void rpmInterrupt()
{
  edge_count++;
}
