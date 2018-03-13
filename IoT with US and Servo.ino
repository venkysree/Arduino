#include <Ultrasonic.h>
#include<Servo.h>
Ultrasonic u(5, 16);
Servo s;
int pos = 0;
void setup() 
{
  Serial.begin(9600);
  s.attach(14);
}
void loop() {
  int a,b;
  b=20;
  a=u.distanceRead();
  if(a>b)
  {
    Serial.println("LID CLOSE");
    s.write(10);
  }
  if(a<b && a>0)
  {
    delay(500);
      a=u.distanceRead();
      if(a<b)
      {
      delay(500);
       a=u.distanceRead();
       if(a<b)
       {
      delay(500);
       a=u.distanceRead();
       if(a<b)
       {
      delay(500);
       a=u.distanceRead();
    if(a<b && a>0)
    {
    Serial.println("LID OPEN"); 
    s.write(90);
  }
  }}}}
  Serial.print("Distance ");
  Serial.println(a);
  delay(1000);
}
