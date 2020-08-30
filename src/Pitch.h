int calcPitch(int RPM)
{
  //function return map(temp_read, 0, 1024, 0, 255); 
  return 0;
}

void controlPitch()
{
  analogWrite(pwrControl, calcPitch(manualCtrl));
}
