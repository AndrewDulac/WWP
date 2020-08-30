int calcPitch(int sig)
{
//do something
return 0;
}

void controlPitch()
{
  analogWrite(pwrControl, calcPitch(manualCtrl));
}
