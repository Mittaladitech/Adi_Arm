//Created by Aditya Mittal
//Anyone can use it.

#include <Servo.h> 
 
Servo middle, left, right, claw ;  // creates 4 "servo objects"
 float a=00,b=130,c=70,d=05,da=12,db=400;  //Set initials 
void setup() 
{ 
  Serial.begin(9600);
  middle.attach(6);  // attaches the servo on pin 6 to the middle object
  left.attach(9);  // attaches the servo on pin 9 to the left object
  //left.attach(9);
    right.attach(3);  // attaches the servo on pin 3 to the right object
  claw.attach(5);  // attaches the servo on pin 5 to the claw object
  
 pinMode(13,OUTPUT);
 digitalWrite(13,HIGH);
}

//Z1, Z2, clawc and clawo are the function to exicute define task when called.

void Z1()   //down
{ b=b+0.6;
  c=c+1.1;
  left.write(b);
  right.write(c);
  delay(da);
  }
void Z2()   //up
{ b=b-0.6;
  c=c-1.1;
  left.write(b);
  right.write(c);
  delay(da);
  }
   
 void clawc()       //clawclose
{ if(d<75)
  {d=d+7;
  claw.write(d);
  if(d==68||d==67)
     claw.write(100);
  delay(da*2);
  }
}
void clawo()       //clawopen
{ if(d>5)
  {d=d-07;
  claw.write(d); 
  delay(da);
  }
} 

void loop() 
{ while(b<=180)
   { Z1();
   Serial.println("Down");
   }
   delay (db);
    
  while(d>=5 && d<75)
   {clawc();
   Serial.println("Go cc");
   } 
   delay (db*3);
    
   while(b>=130)
   { Z2();
   Serial.println("up");
   }
   delay (db);
middle.write(30); 
middle.write(60);    
middle.write(90);
middle.write(120);
middle.write(150);

   while(b<=180)
   { Z1();
   Serial.println("Down");
   }
    delay (db*2);
    
  while(d>5 && d<=75)
   {clawo();
    Serial.println("go co");
   } 
   delay (db);
    Serial.println("co");
   while(b>=130)
   { Z2();
   Serial.println("up");
   }
   delay (db);
    
middle.write(150);
middle.write(120);   
middle.write(90);
middle.write(60);
middle.write(30);
}
    
//Thank you, Have a nice day.
