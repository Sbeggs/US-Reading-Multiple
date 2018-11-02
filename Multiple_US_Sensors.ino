
#define TrigB = 24;
#define EchoB = 25;
#define TrigFR = 26;
#define EchoFR = 27;
#define TrigFL = 28;
#define EchoFL = 29;
#define TrigF = 30;
#define EchoF = 31;
#define TrigR = 32;
#define EchoR = 33;
#define TrigL = 34;
#define EchoL = 35;

long durationF;
double distanceF;
long old_durationF;
long durationFR;
double distanceFR;
long old_durationFR;
long durationFL;
double distanceFL;
long old_durationFL;
long durationR;
double distanceR;
long old_durationR;
long durationL;
double distanceL;
long old_durationL;
long durationB;
double distanceB;
long old_durationB;

void setup() {
  pinMode(TrigF, OUTPUT);
  pinMode(EchoF,INPUT);
  pinMode(TrigFR, OUTPUT);
  pinMode(EchoFR,INPUT);
  pinMode(TrigFL, OUTPUT);
  pinMode(EchoFL,INPUT);
  pinMode(TrigR, OUTPUT);
  pinMode(EchoR,INPUT);
  pinMode(TrigL, OUTPUT);
  pinMode(EchoL,INPUT);
  pinMode(TrigB, OUTPUT);
  pinMode(EchoB,INPUT);
  Serial.begin(9600);
}

void loop() {
  //turns off trigger
  digitalWrite(TrigF,LOW);
  digitalWrite(TrigB,LOW);
  digitalWrite(TrigFR,LOW);
  digitalWrite(TrigFL,LOW);
  digitalWrite(TrigR,LOW);
  digitalWrite(TrigL,LOW);
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
    
  // Sets TriggerFR on for 10 useconds, can't do two at same time for w.e reason
  digitalWrite(TrigFR,HIGH);
  delayMicroseconds(10);
  digitalWrite(TrigFR,LOW);
    // reads the time it took for the EchoFR to reach back
  durationB = pulseIn(EchoFR,HIGH);
   
  // Sets TriggerFL on for 10 useconds, can't do two at same time for w.e reason
  digitalWrite(TrigFL,HIGH);
  delayMicroseconds(10);
  digitalWrite(TrigFL,LOW);
    // reads the time it took for the EchoFL to reach back
  durationB = pulseIn(EchFL,HIGH);
    
  
  // Sets TriggerR on for 10 useconds, can't do two at same time for w.e reason
  digitalWrite(TrigR,HIGH);
  delayMicroseconds(10);
  digitalWrite(TrigR,LOW);
    // reads the time it took for the EchoB to reach back
  durationB = pulseIn(EchoR,HIGH);
  
    // Sets TriggerL on for 10 useconds, can't do two at same time for w.e reason
  digitalWrite(TrigL,HIGH);
  delayMicroseconds(10);
  digitalWrite(TrigL,LOW);
    // reads the time it took for the EchoL to reach back
  durationB = pulseIn(EchoL,HIGH);
  

// Filters out weird values
if (durationF > 10000) durationF=old_durationF;
if (durationB > 10000) durationB=old_durationB;  
  if (durationFR > 10000) durationB=old_durationFR;  
  if (durationFL > 10000) durationB=old_durationFL;  
  if (durationR > 10000) durationB=old_durationR;  
  if (durationL > 10000) durationB=old_durationL;  

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
  
 if (abs(old_durationFR - durationFR) > 10){
    distanceFR = .0343*durationFR/2;  
    Serial.print("Your distanceFR is ");
    Serial.println(distanceFR);
  }
  if (abs(old_durationFL - durationFL) > 10){
    distanceFL = .0343*durationFL/2;  
    Serial.print("Your distanceFL is ");
    Serial.println(distanceFL);
  }
  if (abs(old_durationR - durationR) > 10){
    distanceR = .0343*durationR/2;  
    Serial.print("Your distanceR is ");
    Serial.println(distanceR);
  }
  if (abs(old_durationL - durationL) > 10){
    distanceL = .0343*durationL/2;  
    Serial.print("Your distanceL is ");
    Serial.println(distanceL);
  }
  delay(250);
  old_durationF = durationF;
  old_durationB = durationB;
  old_durationFR= durationFR;
  old_durationFL = durationFL;
  old_durationR = durationR;
  old_durationL = durationL;
  
}
