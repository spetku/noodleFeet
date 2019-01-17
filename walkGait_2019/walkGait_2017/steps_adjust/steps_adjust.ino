
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
 
int pos = 0;    // variable to store the servo position 
 
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

 //postion legs in triangle pose of stability...
  spinservo1.write(90);
  spinservo2.write(90);
  spinservo3.write(90);
  spinservo4.write(90);
  liftservo1.write(150);
  liftservo2.write(150);
  liftservo3.write(150);
  liftservo4.write(150);
   headservo.write(90);
 digitalWrite(ledRED, HIGH);
 digitalWrite(ledGRN, HIGH);  
 myDelay(5000);
  
//step 1
liftservo1.write(110); //setup
myDelay(500);
liftservo1.write(150); //setup
myDelay(500);
liftservo3.write(110); //setup
myDelay(500);
liftservo3.write(150); //setup
myDelay(1000); //originally 1000
liftservo1.write(90);
myDelay(500);
spinservo1.write(90); //forward lEG
myDelay(1000); //originally 1000
spinservo2.write(30); //balance leg
spinservo3.write(90); //balance leg
myDelay(500);
liftservo1.write(120);
liftservo4.write(60);
myDelay(500);
spinservo4.write(150);
myDelay(500);
liftservo4.write(150);
myDelay(500);
liftservo1.write(140);
myDelay(500);
liftservo1.write(150);
myDelay(1000);

//step 2
liftservo2.write(110); //setup
myDelay(500);
liftservo2.write(150); //setup
myDelay(500);
liftservo4.write(110); //setup
myDelay(500);
liftservo4.write(150); //setup
myDelay(1000); //originally 1000
liftservo2.write(90);
myDelay(500);
spinservo2.write(90); //forward Leg
myDelay(1000); //originally 1000
spinservo1.write(150); //balance leg
spinservo4.write(90); //balance leg
myDelay(500);
liftservo2.write(120);
liftservo3.write(60);
myDelay(500);
spinservo3.write(30);
myDelay(500);
liftservo3.write(150);
myDelay(500);
liftservo2.write(140);
myDelay(500);
liftservo2.write(150);
myDelay(1000);

 digitalWrite(ledBLU, LOW);
  SoftwareServo::refresh();

//step 1
liftservo1.write(110); //setup
myDelay(500);
liftservo1.write(150); //setup
myDelay(500);
liftservo3.write(110); //setup
myDelay(500);
liftservo3.write(150); //setup
myDelay(1000); //originally 1000
liftservo1.write(90);
myDelay(500);
spinservo1.write(90); //forward lEG
myDelay(1000); //originally 1000
spinservo2.write(30); //balance leg
spinservo3.write(90); //balance leg
myDelay(500);
liftservo1.write(120);
liftservo4.write(60);
myDelay(500);
spinservo4.write(150);
myDelay(500);
liftservo4.write(150);
myDelay(500);
liftservo1.write(140);
myDelay(500);
liftservo1.write(150);
myDelay(1000);

//step 2
liftservo2.write(110); //setup
myDelay(500);
liftservo2.write(150); //setup
myDelay(500);
liftservo4.write(110); //setup
myDelay(500);
liftservo4.write(150); //setup
myDelay(1000); //originally 1000
liftservo2.write(90);
myDelay(500);
spinservo2.write(90); //forward Leg
myDelay(1000); //originally 1000
spinservo1.write(150); //balance leg
spinservo4.write(90); //balance leg
myDelay(500);
liftservo2.write(120);
liftservo3.write(60);
myDelay(500);
spinservo3.write(30);
myDelay(500);
liftservo3.write(150);
myDelay(500);
liftservo2.write(140);
myDelay(500);
liftservo2.write(150);
myDelay(1000);
} 
 
 
void loop(){
  
//lol fruit

 SoftwareServo::refresh();
}

void myDelay( int mSecs ) {
    for (int i=0; i<(mSecs/20); i++) {
      SoftwareServo::refresh();
      delay(18);
  }
}
