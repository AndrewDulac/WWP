//these are just variable setups, pitchCtrl indicates which pin on the arduino the motor is hooked up to. RPM holds the calculated RPM value.
bool linear = true;
bool exponential = false;
bool expowithcap = false;
int calcPitch(int);

// when this is called, we calculate the pitch (calcPitch()), given the current RPM our turbine is operating at (RPM). Then we send that resulting signal to the servo via the servo pitch control pin (pitchCtrl)
void controlPitch()
{
  analogWrite(pitchCtrl, calcPitch(RPM));
}

//method used to calculate the Pitch signal, assuming max RPM of 5000.
int calcPitch(int RPM)
{
  //if we want a linear relationship... reference excel sheet for value that will be returned
  if(linear){
    return RPM/19.607;
  }
  if(exponential){
    return 2^(RPM/625);
  }
  //in this case, we can see that if the RPM is greater than or equal to 3000, we would like to write the maximum value to the servo (256), we don't want to surpass this value, as the servo might do things we won't expect.
  if(expowithcap){
    if(RPM >= 3000){
      return 256;
    }
    else{
      return 2^(RPM/375);
    }
  }
  else{return 0;}
}
