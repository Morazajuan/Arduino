//Juan Moraza 
//Youtube Tutorial - Two photoresitors and processing
//www.MorazaPower.com

void setup() {
  // initialize the serial communication:
  Serial.begin(9600);
}

void loop() {
  // send the value of analog input 0:
  Serial.println(analogRead(A0));
  // wait a bit for the analog-to-digital converter to stabilize after the last
  // reading:
  Serial.println(analogRead(A1));
  delay(2);
}
