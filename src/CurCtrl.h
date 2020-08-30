int calcIPWM( int sig)
{
  temp_read = analogRead(sig);
  return map(temp_read, 0, 1024, 0, 240); 
}

int calcCurCtrlwPWR(double pwr)
{
  if( pwr < 0.0)
  {
    return 255;  
  }
  else if(pwr > maxPower){
    return 0;
  }
  else
  {
    return map(pwr, 0, maxPower, 255, 0);
  }
}

void controlCurrent()
{
    analogWrite(pwrControl, calcIPWM(manualCtrl));
}
