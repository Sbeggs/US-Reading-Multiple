// define all Digital Pins for Mega(Even is Trig, Odd is Echo)
#define TrigB 24
#define EchoB 25
#define TrigFR 26
#define EchoFR 27
#define TrigFL 28
#define EchoFL 29
#define TrigF 30
#define EchoF 31
#define TrigR 32
#define EchoR 33
#define TrigL 34
#define EchoL 35
// Changes Parameters
#define WaitForEcho 10
#define WackValue 10000
#define DurationCheck 10

//Declaring the Final Array
double DisArray[6];
char Names [8] = {'F', 'F', 'R', 'F', 'L', 'R', 'L', 'B'};


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
  pinMode(EchoF, INPUT);
  pinMode(TrigFR, OUTPUT);
  pinMode(EchoFR, INPUT);
  pinMode(TrigFL, OUTPUT);
  pinMode(EchoFL, INPUT);
  pinMode(TrigR, OUTPUT);
  pinMode(EchoR, INPUT);
  pinMode(TrigL, OUTPUT);
  pinMode(EchoL, INPUT);
  pinMode(TrigB, OUTPUT);
  pinMode(EchoB, INPUT);
  Serial.begin(9600);
}

void loop() {
  //turns off trigger
  digitalWrite(TrigF, LOW);
  digitalWrite(TrigB, LOW);
  digitalWrite(TrigFR, LOW);
  digitalWrite(TrigFL, LOW);
  digitalWrite(TrigR, LOW);
  digitalWrite(TrigL, LOW);
  delayMicroseconds(2);


  // Sets TriggerF on for WaitForEcho useconds
  digitalWrite(TrigF, HIGH);

  delayMicroseconds(WaitForEcho);
  digitalWrite(TrigF, LOW);

  // reads the time it took for the EchoF to reach back
  durationF = pulseIn(EchoF, HIGH);



  // Sets TriggerB on for WaitForEcho useconds, can't do two at same time for w.e reason
  digitalWrite(TrigB, HIGH);
  delayMicroseconds(WaitForEcho);
  digitalWrite(TrigB, LOW);
  // reads the time it took for the EchoB to reach back
  durationB = pulseIn(EchoB, HIGH);

  // Sets TriggerFR on for WaitForEcho useconds, can't do two at same time for w.e reason
  digitalWrite(TrigFR, HIGH);
  delayMicroseconds(WaitForEcho);
  digitalWrite(TrigFR, LOW);
  // reads the time it took for the EchoFR to reach back
  durationFR = pulseIn(EchoFR, HIGH);

  // Sets TriggerFL on for WaitForEcho useconds, can't do two at same time for w.e reason
  digitalWrite(TrigFL, HIGH);
  delayMicroseconds(WaitForEcho);
  digitalWrite(TrigFL, LOW);
  // reads the time it took for the EchoFL to reach back
  durationFL = pulseIn(EchoFL, HIGH);


  // Sets TriggerR on for WaitForEcho useconds, can't do two at same time for w.e reason
  digitalWrite(TrigR, HIGH);
  delayMicroseconds(WaitForEcho);
  digitalWrite(TrigR, LOW);
  // reads the time it took for the EchoB to reach back
  durationR = pulseIn(EchoR, HIGH);

  // Sets TriggerL on for WaitForEcho useconds, can't do two at same time for w.e reason
  digitalWrite(TrigL, HIGH);
  delayMicroseconds(WaitForEcho);
  digitalWrite(TrigL, LOW);
  // reads the time it took for the EchoL to reach back
  durationL = pulseIn(EchoL, HIGH);


  // Filters out wack values
  if (durationF > WackValue) durationF = old_durationF;
  if (durationB > WackValue) durationB = old_durationB;
  if (durationFR > WackValue) durationFR = old_durationFR;
  if (durationFL > WackValue) durationFL = old_durationFL;
  if (durationR > WackValue) durationR = old_durationR;
  if (durationL > WackValue) durationL = old_durationL;

  // Checks to see if change in duration, if not calculate distance and print!
  if (abs(old_durationF - durationF) > DurationCheck) {
    distanceF = .0343 * durationF / 2;
   //Serial.print("Your distanceF is ");
   //Serial.println(distanceF);
  }
  if (abs(old_durationB - durationB) > DurationCheck) {
    distanceB = .0343 * durationB / 2;
   //Serial.print("Your distanceB is ");
   //Serial.println(distanceB);
  }

  if (abs(old_durationFR - durationFR) > DurationCheck) {
    distanceFR = .0343 * durationFR / 2;
  //Serial.print("Your distanceFR is ");
   //Serial.println(distanceFR);
  }
  if (abs(old_durationFL - durationFL) > DurationCheck) {
    distanceFL = .0343 * durationFL / 2;
  //Serial.print("Your distanceFL is ");
    //Serial.println(distanceFL);
  }
  if (abs(old_durationR - durationR) > DurationCheck) {
    distanceR = .0343 * durationR / 2;
   //Serial.print("Your distanceR is ");
   //Serial.println(distanceR);
  }
  if (abs(old_durationL - durationL) > DurationCheck) {
    distanceL = .0343 * durationL / 2;
   //Serial.print("Your distanceL is ");
   //Serial.println(distanceL);
  }
  DisArray[0] = distanceF;
  DisArray[1] = distanceB;
  DisArray[2] = distanceFR; 
  DisArray[3] = distanceFL;
  DisArray[4] = distanceR;
  DisArray[5] = distanceL;
  delay(100);

  
  Serial.print(Names[0]);
  Serial.print(",    ");
  Serial.print(Names[1]);
  Serial.print(Names[2]);
  Serial.print(",    ");
  Serial.print(Names[3]);
  Serial.print(Names[4]);
  Serial.print(",    ");
  Serial.print(Names[5]);
  Serial.print(",    ");
  Serial.print(Names[6]);
  Serial.print(",    ");
  Serial.print(Names[7]);
  Serial.println("");
  
  for (int i = 0; i<= 5; i++){
    Serial.print(DisArray[i]);
    Serial.print(", ");
  }
  Serial.println("");
  Serial.println("");


  
  old_durationF = durationF;
  old_durationB = durationB;
  old_durationFR = durationFR;
  old_durationFL = durationFL;
  old_durationR = durationR;
  old_durationL = durationL;

}
