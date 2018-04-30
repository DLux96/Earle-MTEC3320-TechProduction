import processing.serial.*;

Serial myPort;  // Create object from Serial class
int val;        // Data received from the serial port

void setup() 
{
  size(200, 200);
  // I know that the first port in the serial list on my mac
  // is always my  FTDI adaptor, so I open Serial.list()[0].
  // On Windows machines, this generally opens COM1.
  // Open whatever port is the one you're using.
  printArray(Serial.list());
  String portName = Serial.list()[2];
  myPort = new Serial(this, portName, 9600);
}

void draw() {
  
}

void keyPressed() {
  if(key == '1') {
    myPort.write(1);
  }
  
  if(key == '2') {
    myPort.write(2);
  }
  
  if(key == '3') {
    myPort.write(3);
  }
}