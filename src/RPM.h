//Initialize variables
int edge_count = 0, RPM = 0, count_max = 10;
unsigned long RPM_timer;


void readRPM()
{
  if(edge_count >= count_max){
    RPM = (1000000 * count_max / (micros() - RPM_timer));
    edge_count = 0;
    RPM_timer = micros();
  }
}
void rpmInterrupt(){
  edge_count++;
}
