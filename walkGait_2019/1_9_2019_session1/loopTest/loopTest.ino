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
  spinservo1.write(100);
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
 myDelay(400);

  
 }
void loop()
{
//step 1

  for(poslift = 150; poslift > 110; poslift--){    //lift legs 1 and 4 starting point is first, lifting point is second
    liftservo1.write(poslift);
    liftservo4.write(poslift);
    myDelay(10);
  }
  myDelay(200);

 for(posspin = 0; posspin < 20; posspin++){      // rotate legs 1 and 4 forward, legs 2 and 3 backward
    A = 90 - posspin;
    B = 90 + posspin;
    spinservo1.write(A);
    spinservo4.write(B);
    spinservo2.write(A);
    spinservo3.write(B);
    myDelay(10);
  
    }
  myDelay(200);
 
  for(poslift = 110; poslift < 150; poslift++){    //drop legs 1 and 4 first variable must match lift routines second variable
    liftservo1.write(poslift);
    liftservo4.write(poslift);
    myDelay(10);
    }
  myDelay(500); 
//step 2

  for(poslift = 150; poslift > 110; poslift--){    //lift legs 2 and 3
    liftservo2.write(poslift);
    liftservo3.write(poslift);
    myDelay(10);
    }
  myDelay(200);

  for(posspin = 0; posspin < 20; posspin++){      // rotate legs 2 and 3 forward, legs 1 and 4 backward
    B = 90 - posspin;
    A = 90 + posspin;
    spinservo1.write(A);
    spinservo4.write(B);
    spinservo2.write(A);
    spinservo3.write(B);
    myDelay(10);
  
    }
  myDelay(200);
  
  for(poslift = 110; poslift < 150; poslift++){    //drop legs 2 and 3
    liftservo2.write(poslift);
    liftservo3.write(poslift);
    myDelay(10);
    }

  myDelay(5000);

  }

 void myDelay( int mSecs ) {
    for (int i=0; i<(mSecs/10); i++) {
      SoftwareServo::refresh();
      delay(10);
  }
}


