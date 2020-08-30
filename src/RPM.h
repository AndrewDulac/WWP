//Initialize variables
int ButtonState = 1; // Create int named ButtonState start at idle state
int stopwatch = 1;
int RPM;
int Reflect_Val = 450;

unsigned long count;
unsigned long RPM_Timer;


void readRPM()
{
  switch (stopwatch)
  {
    case 1:
     
      RPM_Timer = micros();
      if(analogRead(Sensor)> Reflect_Val)
      {
        stopwatch = 2;
      }
      break;
    case 2:
      if(analogRead(Sensor)< Reflect_Val)
      {
        stopwatch = 3;
      }
      
      break;
    case 3:
      if(analogRead(Sensor)> Reflect_Val)
      {
        count = micros() - RPM_Timer;
        RPM = (60000000/(count))/4; // 60 * 1000 * 1000
        stopwatch=1;
      }
      break;
  }
}
