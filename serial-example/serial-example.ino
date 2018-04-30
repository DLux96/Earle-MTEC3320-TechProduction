#include <SoftwareSerial.h>
SoftwareSerial mySerial(2, 3); // RX, TX

int myID = 1;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.flush();

  mySerial.begin(4800);
  mySerial.flush();

  // just for testing, using LEDs
  pinMode(13, OUTPUT);
}

void loop() {

  // check on USB port
  while (Serial.available() > 0) {

    int inByte = Serial.read();

    mySerial.write(inByte);

    if (inByte == myID) {
      // this message is for me, ...
      digitalWrite(13, HIGH);
      delay(1000);
      digitalWrite(13, LOW);
    }
  }

  // check for serial data on software serial port
  while (mySerial.available() > 0) {

    // store it to inByte
    int inByte = mySerial.read();

    Serial.println(inByte);

    // write conditional logic for any info
    // relevant to your puzzle
    if (inByte == myID) {
      // this message is for me, ...
      digitalWrite(13, HIGH);
      delay(500);
      digitalWrite(13, LOW);

    } else {
      // otherwise, pass it along
      mySerial.write(inByte);
    }
  }
}
