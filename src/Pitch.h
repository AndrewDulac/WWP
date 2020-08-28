int calcPitch(int sig)
{
  temp_read = analogRead(sig);
  return map(temp_read, 0, 1024, 0, 255); 
}

void controlPitch()
{
  analogWrite(pwrControl, calcPitch(manualCtrl));
}
