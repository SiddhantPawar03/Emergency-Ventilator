
#include<LiquidCrystal.h>
#include<Servo.h>
#define pinServo 10
 
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
Servo S1;
int potPos1;
int potPos2;
int deg=0;

void setup(){
  lcd.begin(16,2);
  lcd.clear();
  lcd.setCursor(3,0);
  lcd.print("Emergency");
  lcd.setCursor(3,1);
  lcd.print("Ventilator");
  delay(1000);
  lcd.clear();
  S1.attach(pinServo);
  Serial.begin(9600);
  S1.write(0);           //setting 0 degree.
  delay(1000);
  pinMode(10,OUTPUT);
  pinMode(13,OUTPUT);
}

void loop(){
  potPos1 = map(analogRead(A0), 0, 1023, 0, 100);
  potPos2 = map(analogRead(A1), 0, 1023, 0, 180);
  Serial.print(potPos2);
  Serial.print(":");
  Serial.print(potPos1);
  Serial.println("units");
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("BPM:");
  lcd.print(potPos1);
  lcd.setCursor(9,0);
  lcd.print("SpO2:--");
  lcd.setCursor(0,1);
  lcd.print("VOL:");
  lcd.print(potPos2);
  lcd.print("cu.");
  delay(500);
  S1.write(0);
  if (potPos2==0){
    tone(13, 1000, 500);
    if(potPos1==0){
      tone(13, 1000, 500);
      S1.write(0);
    delay(10);
      S1.write(0);
    delay(15);
    }
   //delay(50);  
}
 else if((potPos2>0)&&(potPos2<=18)){
   tone(13, 500, 300);
   if ((potPos1>=0)&&(potPos1<=5)){
    S1.write(0);
   delay(1000);
   tone(13, 500, 300);
   S1.write(75);
   delay(1500);
} 
  else if ((potPos1>5)&&(potPos1<=11)){
    S1.write(0);
    delay(1000);
    tone(13, 250, 300);
    S1.write(60);
    delay(1500);
}
   else if ((potPos1>11)&&(potPos1<=20)){
    S1.write(0);
    delay(1000);
   S1.write(45);
    delay(1500);
} 
  else if ((potPos1>20)&&(potPos1<=50)){
    S1.write(0);
   delay(1000);
    tone(13, 500, 200);
    S1.write(30);
    delay(1500);
} 
  else if ((potPos1>50)&&(potPos1<=100)){
    S1.write(0);
    delay(1000);
    tone(13, 750, 300);
    S1.write(20);
    delay(1500);
}
  //delay(100);
}
  else if((potPos2>18)&&(potPos2<=180)){
    
  if ((potPos1>=0)&&(potPos1<=5)){
    S1.write(0);
   delay(1000);
   tone(13, 500, 300);
   S1.write(75);
   delay(1500);
} 
  else if ((potPos1>5)&&(potPos1<=11)){
    S1.write(0);
    delay(1000);
    tone(13, 250, 300);
    S1.write(60);
    delay(1500);
}
   else if ((potPos1>11)&&(potPos1<=20)){
    S1.write(0);
    delay(1000);
   S1.write(45);
    delay(1500);
} 
  else if ((potPos1>20)&&(potPos1<=50)){
    S1.write(0);
   delay(1000);
    tone(13, 500, 200);
    S1.write(30);
    delay(1500);
} 
  else if ((potPos1>50)&&(potPos1<=100)){
    S1.write(0);
    delay(1000);
    tone(13, 750, 300);
    S1.write(20);
    delay(1500);
}
  //delay(100);
  }
}

