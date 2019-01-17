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
  liftservo1.write(150);
  liftservo2.write(150);
  liftservo3.write(150);
  liftservo4.write(150);
  headservo.write(90);
  digitalWrite(ledRED, LOW);
  //digitalWrite(ledRED, HIGH);
  //digitalWrite(ledGRN, HIGH);
  myDelay(400);
  bounce();
  digitalWrite(ledRED, HIGH);


}

void loop() {
  setLift(90);
  myDelay(300);
  sweepMotor( liftservo1 );
  sweepMotor( liftservo2 );
  sweepMotor( liftservo3 );
  sweepMotor( liftservo4 );

  myDelay(3000);
  sweepMotor( spinservo1 );
  sweepMotor( spinservo1 );
  sweepMotor( spinservo1 );
  sweepMotor( spinservo1 );
  myDelay(3000);

}

void myDelay( int mSecs ) {
  for (int i = 0; i < (mSecs / 10); i++) {
    SoftwareServo::refresh();
    delay(10);
  }
}

void sweepMotor( SoftwareServo mot ) {
  int i;

  // Start at 90 and sweep to 150
  for ( i=90; i<150; i++ ) {
    //mot.write(i);
    liftservo1.write(i);
    liftservo2.write(i);
    liftservo3.write(i);
    liftservo4.write(i);
   myDelay(40);
  }
  // Sweep from last pos (150) down to 30
  for ( ; i>30; i-- ) {
    //mot.write(i);
    liftservo1.write(i);
    liftservo2.write(i);
    liftservo3.write(i);
    liftservo4.write(i);
    myDelay(40);
  }
  // Sweep back to 90
  for ( ; i<90; i++ ) {
    //mot.write(i);
    liftservo1.write(i);
    liftservo2.write(i);
    liftservo3.write(i);
    liftservo4.write(i);
   myDelay(40);
  }

  myDelay(500);
  // Start at 90 and sweep to 150
  for ( i=90; i<150; i++ ) {
    //mot.write(i);
    spinservo1.write(i);
    spinservo2.write(i);
    spinservo3.write(i);
    spinservo4.write(i);
   myDelay(40);
  }
  // Sweep from last pos (150) down to 30
  for ( ; i>30; i-- ) {
    //mot.write(i);
    spinservo1.write(i);
    spinservo2.write(i);
    spinservo3.write(i);
    spinservo4.write(i);
    myDelay(40);
  }
  
  // Sweep back to 90
  for ( ; i<90; i++ ) {
    //mot.write(i);
    spinservo1.write(i);
    spinservo2.write(i);
    spinservo3.write(i);
    spinservo4.write(i);
   myDelay(40);
  }

  myDelay(500);
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

void setLift( int lift ) {
  liftservo1.write(lift);
  liftservo2.write(lift);
  liftservo3.write(lift);
  liftservo4.write(lift);
  myDelay(10);
}

