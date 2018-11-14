//Juan Moraza
//www.MorazaPower.com


#include <LiquidCrystal.h>
#include <TimeLib.h>

 
//K,A,d7,d6,d5,d4 LCD connected to 2,3,4,5,6,7 on Arduino  
const int rs = 7, en = 6, d4 = 5, d5 = 4, d6 = 3, d7 = 2;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
 
//this variables will be use to show text in different possition 
//at different times
const int btn1 = 8;
const int btn2 = 9;
time_t start;
time_t eSecs;
int buttonState = 2;

String interruptMessage = "Interrupt received!";
int startT = 0;
int stop = 0;
int scroll = 16;

//Sets the time to now
void updateTime(){
  start = now();
}


//Returns the time since t
time_t elapsed(){
  time_t e = now()-start;
  Serial.print("Waiting for ");
  Serial.print(e);
  Serial.println(" seconds");
  return e;
}

void button2(){
  buttonState = 2;
  time_t e = elapsed();
  if(e != eSecs){ //Update LCD if seconds changed
    eSecs = e;
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Waiting for");
    lcd.setCursor(0,1); 
    lcd.print(e);
    lcd.print(" sec");
  }
}


//return value of button
boolean buttonPressed(int b){
  boolean pressed = false;
  if(digitalRead(b)){
    while(digitalRead(b)){} //Wait for release
    pressed = true;
  }
  return pressed;
}


void button1(){
  buttonState = 1;
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Interrupted!");

 lcd.setCursor(scroll, 0);
  lcd.print(interruptMessage.substring(startT, stop));

  
  
  lcd.setCursor(0,1);
  lcd.print(" Press btn 2");


if (startT == 0 && scroll > 0) {
    scroll--;
    stop++;
  } else if (startT == stop) {
    start = stop = 0;
    scroll = 16;
  } else if (stop == interruptMessage.length() && scroll == 0) {
    startT++;
  } else {
    startT++;
    stop++;
  }
 



}

void wait(){
  if(buttonState == 2){
    while(!digitalRead(btn1)){
      button2();
    }
    button1();
  }
}

void interrupt(){
  if(buttonState == 1){
    while(!buttonPressed(btn2)){} //Wait for Button2
    updateTime();
    button2();
  }
}

void setup() {
   // set up the LCD 
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.clear();

  pinMode(btn1, INPUT);
  pinMode(btn2, INPUT);
  
  updateTime();
  delay(1000);
}

void loop() {
  //when waiting
  wait();

  //if interrupt
  interrupt();
}
