#include<Servo.h>
#define R 9
#define L 10
#define C 8
Servo s1;
Servo s2;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(R, INPUT);
  pinMode(L, INPUT);
  pinMode(C, OUTPUT);
  s1.attach(5);
  s2.attach(6);
  s1.write(90);
  s2.write(180);
  delay(1000);
}

void loop() {
  bool r = touch(C, R);
  bool l = touch(C, L);
  bool isTouch = r+l>0;
  int dir = r-l;
  Serial.println(String(isTouch)+","+String(dir));
  s2.write(isTouch?45:90);
  s1.write(90+dir*45);
  delay(500);
}
