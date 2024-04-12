#include<Servo.h>
#include <LiquidCrystal.h>
const int rs = 12, en = 11, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
Servo servo1;
Servo servo2;
void setup() {

  lcd.begin(16,2);
  servo1.attach(9);
  servo2.attach(10);
  pinMode(2,INPUT);
  pinMode(3,INPUT);
  pinMode(9,OUTPUT);
  servo1.write(0);
}

void loop() {
  lcd.setCursor(0,0);
lcd.print("Place your waste");
lcd.setCursor(2, 1);
lcd.print("above |^_^|");
lcd.blink();
int  read=digitalRead(2);
int  reaad=digitalRead(3);
delay(1000);
servo1.write(0);
servo2.write(0);

  if(read == HIGH)
  {
    servo1.write(0);
     lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("It's a mettalic");
    lcd.setCursor(5,1);
    lcd.print("waste!!");
    delay(4000);
    servo1.write(0);
    lcd.clear();
    lcd.setCursor(1,0);
    lcd.print("Thank you for");
    lcd.setCursor(4,1);
    lcd.print("using me");
    delay(1000);
  }
  else if(reaad !=HIGH)
  {
    if(read !=HIGH)
    {
      servo2.write(90);
      lcd.clear();
      lcd.setCursor(3,0);
      lcd.print("It's a non");
      lcd.setCursor(0,1);
      lcd.print("mettalic waste!!");
      delay(3000);
      servo2.write(0);
       lcd.clear();
    lcd.setCursor(1,0);
    lcd.print("Thank you for");
    lcd.setCursor(1,1);
    lcd.print("using me (^_^)");
    delay(2000);
      
      
    }
  }
lcd.clear();

}
