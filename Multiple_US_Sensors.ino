int TrigF = 9;
int EchoF = 10;
int TrigB = 4;
int EchoB = 3;
long durationF;
double distanceF;
long old_durationF;
long durationB;
double distanceB;
long old_durationB;

void setup() {
  pinMode(TrigF, OUTPUT);
  pinMode(EchoF,INPUT);
  pinMode(TrigB, OUTPUT);
  pinMode(EchoB,INPUT);
  Serial.begin(9600);
}

void loop() {
  //turns off trigger
  digitalWrite(TrigF,LOW);
  digitalWrite(TrigB,LOW);
  delayMicroseconds(2);
  
  
  // Sets TriggerF on for 10 useconds
  digitalWrite(TrigF,HIGH);
  delayMicroseconds(10);
  digitalWrite(TrigF,LOW);
  // reads the time it took for the EchoF to reach back
  durationF = pulseIn(EchoF,HIGH);

  // Sets TriggerB on for 10 useconds, can't do two at same time for w.e reason
  digitalWrite(TrigB,HIGH);
  delayMicroseconds(10);
  digitalWrite(TrigB,LOW);
    // reads the time it took for the EchoB to reach back
  durationB = pulseIn(EchoB,HIGH);

// Filters out weird values
if (durationF > 10000) durationF=old_durationF;
if (durationB > 10000) durationB=old_durationB;  

// Checks to see if change in duration, if not calculate distance and print!
if (abs(old_durationF - durationF) > 10){
    distanceF = .0343*durationF/2;  
    Serial.print("Your distanceF is ");
    Serial.println(distanceF);
  }
if (abs(old_durationB - durationB) > 10){
    distanceB = .0343*durationB/2;  
    Serial.print("Your distanceB is ");
    Serial.println(distanceB);
  }  
  
  delay(250);
  old_durationF = durationF;
  old_durationB = durationB;
  
}
