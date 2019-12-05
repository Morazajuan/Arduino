//Juan Moraza
//Youtube Tutorial - Two photoresitors and processing
//www.MorazaPower.com

import processing.serial.*;

Serial myPort;        // The serial port
int xPos = 1;         // horizontal position of the graph
float inByte = 0;

void setup () {
size(1500, 500);


println(Serial.list());


myPort = new Serial(this, "/dev/cu.usbmodem1201", 9600);

// set initial background:
background(0);
}

void draw () {
// draw the line:
stroke(80, 20, 180);
line(xPos, height, xPos, height - inByte);

// at the edge of the screen, go back to the beginning:
if (xPos >= width) {
xPos = 0;
background(0);
} else {
// increment the horizontal position:
xPos++;
}
}

void serialEvent (Serial myPort) {
// get the ASCII string:
String inString = myPort.readStringUntil('\n');

if (inString != null) {
// trim off any whitespace:
inString = trim(inString);
// convert to an int and map to the screen height:
inByte = float(inString);
println(inByte);
inByte = map(inByte, 0, 1023, 0, height);
}
}
}"")
}
