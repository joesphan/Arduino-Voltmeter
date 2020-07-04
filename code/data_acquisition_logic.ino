#define AREF_CAL 1.100000

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
  //ch1
  measurement = analogRead(ch1Pin);
  while (measurement < 1000 && digiPot1Pos != 99) {     //increasing the digipot to clipping
    increaseDigiPot(1);
    measurement = analogRead(ch1Pin);
  }
  decreaseDigiPot(1);                                   //back it off one step
  delay(100);  //settle
  measurement = analogRead(ch1Pin);
  ch1Value = measurement * (99.000000 / (digiPot1Pos)) * (AREF_CAL / 1023.000000);
  //ch2
  measurement = analogRead(ch2Pin);
  while (measurement < 1000 && digiPot2Pos != 99) {     //increasing the digipot to clipping
    increaseDigiPot(2);
    measurement = analogRead(ch2Pin);
  }
  decreaseDigiPot(2);                                   //back it off one step
  delay(100);  //settle
  measurement = analogRead(ch2Pin);
  ch2Value = measurement * (99.000000 / (digiPot2Pos)) * (AREF_CAL / 1023.000000);
  
  //resetDigiPots();            //AAAAAAAAAAAAAAAA
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
