#define ch1DigiPotINC 4
#define ch2DigiPotINC 5

#define ch1DigiPotUD 6
#define ch2DigiPotUD 7
int digiPot1Pos;
int digiPot2Pos;

void digipotInit() {
  pinMode(ch1DigiPotINC, OUTPUT);
  pinMode(ch2DigiPotINC, OUTPUT);

  pinMode(ch1DigiPotUD, OUTPUT);
  pinMode(ch2DigiPotUD, OUTPUT);
}
void activeLowTrig(int pin) {
  digitalWrite(pin, HIGH);
  digitalWrite(pin, LOW);
  digitalWrite(pin, HIGH);
}

//ch1DigiPotINC, ch2DigiPotINC, ch1DigiPotUD, ch2DigiPotUD
void resetDigiPots() {    //moves pots to 0 position
  digitalWrite(ch1DigiPotUD, LOW);    //set down
  digitalWrite(ch2DigiPotUD, LOW);
  digiPot1Pos = 0;
  digiPot2Pos = 0;
  for (int i = 0; i < 100; i++) {
    activeLowTrig(ch1DigiPotINC);
    activeLowTrig(ch2DigiPotINC);
  }
}

void resetHighDigiPots() {    //moves pots to 99 position
  digitalWrite(ch1DigiPotUD, HIGH);    //set up
  digitalWrite(ch2DigiPotUD, HIGH);
  digiPot1Pos = 98;
  digiPot2Pos = 98;
  for (int i = 0; i < 100; i++) {
    activeLowTrig(ch1DigiPotINC);
    activeLowTrig(ch2DigiPotINC);
  }
  digitalWrite(ch1DigiPotUD, HIGH);    //set up
  digitalWrite(ch2DigiPotUD, HIGH);
}

void increaseDigiPot(int device) {      //call to increase digipot (dev1/2) up by one step
  switch (device) {
    case 1:
      digitalWrite(ch1DigiPotUD, HIGH);   //set up
      activeLowTrig(ch1DigiPotINC);
      if (digiPot1Pos < 99) {
        digiPot1Pos++;
      }
      break;
    case 2:
      digitalWrite(ch2DigiPotUD, HIGH);
      activeLowTrig(ch2DigiPotINC);
      if (digiPot2Pos < 99) {
        digiPot2Pos++;
      }
      break;
    default:
      break;
  }
}

void decreaseDigiPot(int device) {      //call to decrease digipot (dev1/2) down by one step
  switch (device) {
    case 1:
      digitalWrite(ch1DigiPotUD, LOW);   //set up
      activeLowTrig(ch1DigiPotINC);
      if (digiPot1Pos > 0) {
        digiPot1Pos--;
      }
      break;
    case 2:
      digitalWrite(ch2DigiPotUD, LOW);
      activeLowTrig(ch2DigiPotINC);
      if (digiPot2Pos > 0) {
        digiPot2Pos--;
      }
      break;
    default:
      break;
  }
}
