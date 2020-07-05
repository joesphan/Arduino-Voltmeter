#define AREF_CAL 1.076000               //measure AREF using DMM and replace

#define ch1Pin A1
#define ch2Pin A2

#define ch1MeasureEN 2
#define ch2MeasureEN 3


extern int digiPot1Pos;
extern int digiPot2Pos;

float ch1Value = 0;
float ch2Value = 0;
void analogPinsInit() {
  analogReference(INTERNAL);
  pinMode(ch1MeasureEN, OUTPUT);
  pinMode(ch2MeasureEN, OUTPUT);
}
void takeMeasurement() {
  //ch1Value
  resetDigiPots();
  float measurement = 0;
  int potposBuf;
  //ch1
  digitalWrite(ch1MeasureEN, HIGH);                     //turn on measuring ch1 transistor
  measurement = analogRead(ch1Pin);
  while (measurement < 1000 && digiPot1Pos != 99) {     //increasing the digipot to clipping
    increaseDigiPot(1);
    measurement = analogRead(ch1Pin);
  }
  decreaseDigiPot(1);                                   //back it off one step
  delayMicroseconds(250);                               //settle (takes 180us to settle)
  measurement = analogRead(ch1Pin);                     //reset early, as calc step takes a while to run. HV at this state can cause damage
  potposBuf = digiPot1Pos;
  digitalWrite(ch1MeasureEN, LOW);                     //turn off measuring ch1 transistor
  resetDigiPots();
  ch1Value = measurement * (99.000000 / (potposBuf)) * (AREF_CAL / 1023.000000);
  //ch2
  digitalWrite(ch2MeasureEN, HIGH);                     //turn on measuring ch2 transistor
  measurement = analogRead(ch2Pin);
  while (measurement < 1000 && digiPot2Pos != 99) {     //increasing the digipot to clipping
    increaseDigiPot(2);
    measurement = analogRead(ch2Pin);
  }
  decreaseDigiPot(2);                                   //back it off one step
  delayMicroseconds(250);                               //settle (takes 180us to settle)
  measurement = analogRead(ch2Pin);                     //reset early, as calc step takes a while to run. HV at this state can cause damage
  potposBuf = digiPot2Pos;
  resetDigiPots();
  ch2Value = measurement * (99.000000 / (potposBuf)) * (AREF_CAL / 1023.000000);
  digitalWrite(ch2MeasureEN, LOW);                     //turn off measuring ch2 transistor
  resetDigiPots();            //AAAAAAAAAAAAAAAA
}

void sendDebugMeasurement() {
  Serial.print("ch1: ");
  Serial.print(ch1Value, 6);
  Serial.print("     pos: ");
  Serial.print(digiPot1Pos);
  Serial.print("     ch2: ");
  Serial.print(ch2Value, 6);
  Serial.print("     pos: ");
  Serial.print(digiPot2Pos);
  Serial.println(" ");

}
