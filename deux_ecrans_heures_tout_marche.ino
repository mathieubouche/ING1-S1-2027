
#include <Adafruit_SSD1306.h>
#define OLED_RESET 4
#include <virtuabotixRTC.h>
virtuabotixRTC myRTC(6,7,8);

#include <Wire.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
int pot=A1;
int deg;
int x=0;
int y=0;

Adafruit_SSD1306 display1(OLED_RESET);
Adafruit_SSD1306 display2(OLED_RESET);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(pot, INPUT);
  pinMode(A0, INPUT);
  pinMode(5, INPUT_PULLUP);
  display1.begin(SSD1306_SWITCHCAPVCC, 0x3C); // Default OLED address, usually
  display1.clearDisplay();

  display2.begin(SSD1306_SWITCHCAPVCC, 0x3D); // Second OLED address, via onboard jumper
  display2.clearDisplay();

  delay(200);

  display1.setTextSize(1);
  display1.setTextColor(WHITE);
  display1.setCursor(0,0);
 

  display2.setTextSize(1);
  display2.setTextColor(WHITE);
  display2.setCursor(0,0);
 
// myRTC.setDS1302Time(30,30,18,5,9,12,2022);
}

void loop() {
  // put your main code here, to run repeatedly:

while(1==1)
{
  

  
  
  
      display2.clearDisplay();
      int readin= analogRead(A0);
      int reading = analogRead(pot);
      y=64-readin%64;
      display1.drawPixel(x,y,WHITE);
      display1.display();
      myRTC.updateTime();
      display2.setCursor(30,0);
      display2.print(myRTC.hours);
      display2.setCursor(50,0);
      display2.print(myRTC.minutes);
      display2.setCursor(70,0);
      display2.print(myRTC.seconds);
        display2.setCursor(70,20);
      display2.print(reading);

    display2.display();
      
  
  

      
      x++;
       if(x>145)
        {display1.clearDisplay();
         x=0;} 
  
  
  }




  

}
