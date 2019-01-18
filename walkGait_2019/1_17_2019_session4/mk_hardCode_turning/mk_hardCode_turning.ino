#include <SoftwareServo.h>


SoftwareServo spinservo1;
SoftwareServo liftservo1;
SoftwareServo spinservo2;
SoftwareServo liftservo2;
SoftwareServo spinservo3;
SoftwareServo liftservo3;
SoftwareServo spinservo4;
SoftwareServo liftservo4;
SoftwareServo headservo;
int ledRED = 11;
int ledGRN = 12;
int ledBLU = 13;

int poslift = 0;    // variable to store the lift servo position
int posspin = 0;    // variable to store the spin servo position
int rest = 90;      // variable for center leg location
int A = 0;
int B = 0;

#define LIFT_MID  120
#define LIFT_UP   80

#define SPIN_MID  90

void setup()
{
  // if noodle is face forward :
  liftservo1.attach(2); //lift front right leg
  liftservo2.attach(3); //lift front left leg
  liftservo3.attach(4); //lift back right leg
  liftservo4.attach(5); //lift back left leg
  spinservo1.attach(6); //rotate front right leg
  spinservo2.attach(7); //rotate front left leg
  spinservo3.attach(8); //rotate back right leg
  spinservo4.attach(9); //rotate back left leg
  headservo.attach(10); //turns eye stalk gantry
  pinMode(ledRED, OUTPUT);
  pinMode(ledGRN, OUTPUT);
  pinMode(ledBLU, OUTPUT);

  //postion legs in square to start walking...
  spinservo1.write(90);
  spinservo2.write(90);
  spinservo3.write(90);
  spinservo4.write(90);
  liftservo1.write(120);
  liftservo2.write(120);
  liftservo3.write(120);
  liftservo4.write(120);
  headservo.write(90);
  digitalWrite(ledRED, LOW);
  //digitalWrite(ledRED, HIGH);
  //digitalWrite(ledGRN, HIGH);
  myDelay(400);
  bounce();
  digitalWrite(ledRED, HIGH);

}

void loop() {
  // Walking
  
  for ( int i=0; i<4; i++) {
    stepLeft();
    myDelay(200);
    stepRight();
    myDelay(200);
  }

  
  setLift(120);
  turn();
  setSpin(90);
  myDelay(500);
  
}

void turn() {
  turnLeg(&liftservo1, &spinservo1, &liftservo4);
  turnLeg(&liftservo2, &spinservo2, &liftservo3);
  turnLeg(&liftservo4, &spinservo4, &liftservo1);
  turnLeg(&liftservo3, &spinservo3, &liftservo2);
  
}
void turnLeg( SoftwareServo *leg, SoftwareServo *spin, SoftwareServo *opposingLeg ) {
  leg->write(130);
  opposingLeg->write(100);
  myDelay(250);
  leg->write(LIFT_UP);
  myDelay(250);

  // Spin leg
  spin->write(40);
  myDelay(100);
  opposingLeg->write(105);
  myDelay(220);
  leg->write(LIFT_MID);
  opposingLeg->write(LIFT_MID);
  myDelay(250);
}

void stepLeft() {
  int amount = 20;
  //step 1
  liftservo1.write(90);
  liftservo4.write(130);
  myDelay(100);  // Time it takes to lift up.
  liftservo4.write(90);
  liftservo2.write(130);
  liftservo3.write(130);  
  myDelay(40);
  spinservo1.write(90-amount);
  spinservo4.write(90+amount);
  spinservo2.write(90);
  spinservo3.write(90);  
  myDelay(200); // Time it takes to rotate.
  setLift(120);
}

void stepRight() {
  liftservo2.write(90);
  liftservo3.write(130);
  myDelay(100);
  liftservo3.write(90);
  liftservo1.write(130);
  liftservo4.write(130);

  myDelay(40);
  spinservo2.write(110);
  spinservo3.write(70);
  spinservo1.write(90);
  spinservo4.write(90);
 
  myDelay(200);
  setLift(120);

}

void myDelay( int mSecs ) {
  for (int i = 0; i < (mSecs / 10); i++) {
    SoftwareServo::refresh();
    delay(10);
  }
}

void bounce() {
  setLift(150);
  myDelay(200);
  setLift(140);
  myDelay(200);
  setLift(150);
  myDelay(200);
  setLift(140);
  myDelay(200);
  setLift(150);
  myDelay(200);
  setLift(140);
  myDelay(200);
  setLift(150);
  myDelay(200);
}

void setSpin( int spin ) {
  spinservo1.write(spin);
  spinservo2.write(spin);
  spinservo3.write(spin);
  spinservo4.write(spin);
}
void setLift( int lift ) {
  liftservo1.write(lift);
  liftservo2.write(lift);
  liftservo3.write(lift);
  liftservo4.write(lift);
}

