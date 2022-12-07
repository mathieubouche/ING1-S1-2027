#include <virtuabotixRTC.h>
 virtuabotixRTC myRTC(6,7,8);
void setup() {
   Serial.begin(9600);
 
}

void loop() {

  myRTC.updateTime();
  Serial.print(myRTC.seconds);
  Serial.print("/");
  Serial.print(myRTC.minutes);
  Serial.print("/");
  Serial.print(myRTC.hours);
  Serial.print("/");
  Serial.print(myRTC.month);
  Serial.print("/");
  Serial.print(myRTC.dayofweek);
  Serial.print("/");
  Serial.print(myRTC.dayofmonth);
  Serial.print("/");
  Serial.println(myRTC.year);
  delay(500);
  
  
}
