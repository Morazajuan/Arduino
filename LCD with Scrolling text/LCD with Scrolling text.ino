//Juan Moraza
//Youtube Tutorial
//LCD with scrolling text

#include <LiquidCrystal.h>

//K,A,d7,d6,d5,d4 LCD connected to 2,3,4,5,6,7 on Arduino  
LiquidCrystal lcd(7,6,5,4,3,2);


//this variables will be use to show text in different possition 
//at different times
 int start = 0;
  int stop = 0;
   int scroll = 16;

     //quote and name strings used to show on LCD
      String quote = "Scrolling screen LCD Arduino tutorial ";
       String fullName = "  Subscribe! ";

        void setup() {

            //we want to use both lines
             lcd.begin(16,2);
        }

        void loop() {

            lcd.setCursor(scroll, 0);
             lcd.print(quote.substring(start,stop));

                 lcd.setCursor(0, 1);
                  lcd.print(fullName);
                   delay(300);
                    lcd.clear();


                        if(start == 0 && scroll > 0){
                            scroll--;
                              stop++;
                        } else if (start == stop){
                            start = stop = 0;
                              scroll = 16;
                        } else if (stop == quote.length() && scroll == 0) {
                            start++;
                        } else {
                            start++;
                              stop++;
                        }
        }
                        }
        }
