//Juan Moraza
//www.MorazaJuan.com
//www.MorazaPower.com


int INCREASE = 3;
int DECREASE = 5;
int LED1 = 6;
int LED2 = 2;
int LED3 = 4;
int LED4 = 7;
int decreaseState = 0;
int increaseState = 0;
int count = 0;

void setup() {
 
    pinMode(LED1,OUTPUT);
    pinMode(LED2,OUTPUT);
    pinMode(LED3,OUTPUT);
    pinMode(INCREASE,INPUT);
    pinMode(DECREASE,INPUT);
    
}

void loop() {

    increaseState = digitalRead(INCREASE);
    decreaseState = digitalRead(DECREASE);
    
    
    if(increaseState == HIGH)
    {
        count++;
        delay(100);
    }
    
    if(decreaseState == HIGH)
    {
        count--;
        delay(100);
    }
    
     
    
    if(count > 15)
    {
        count = 0;
    }
    if(count < 0)
    {
        count = 0;
    }
    
    int count2 = count;
    if(count2%2 == 1)
    {
        digitalWrite(LED1,HIGH);
    }
    else
    {
        digitalWrite(LED1,LOW);
    }
    count2 = count2 >> 1;
    
    if(count2%2 == 1)
    {
        digitalWrite(LED2,HIGH);
    }
    else
    {
        digitalWrite(LED2,LOW);
    }
    count2 = count2 >> 1;
    
    if(count2%2 == 1)
    {
        digitalWrite(LED3,HIGH);
    }
    else
    {
        digitalWrite(LED3,LOW);
    }
    count2 = count2 >> 1;
     if(count2%2 == 1)
    {
        digitalWrite(LED4,HIGH);
    }
    else
    {
        digitalWrite(LED4,LOW);
    }
    count2 = count2 >> 1;
    
    
    delay(100);
    
    
}
