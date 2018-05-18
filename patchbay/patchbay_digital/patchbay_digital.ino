/*
  patchbay proof of concept
 
 momentarily set output pins to LOW and check
 each input pin if it is connected to a LOW pin
 if it is, you know that it is connected to the
 pin that just went LOW
 
 the connections array contains a list of current
 connections
 
 the pass array contains a list of desired
 connections
 
 a 9 represents that an input pin is not connected
 to any used output pin
 
 */

int pass[4] = {
  3,2,1,0};

int inputPins[] = {
  2,3,4,5};
int outputPins[] = {
  8,9,10,11};

// let's say 9 means not connected at all
int connections[] = {
  9,9,9,9};

void setup() {
  Serial.begin(9600);
  Serial.println("system online");

  // set up digital pins for inputs and outputs
  // write output pins high by default
  for(int i = 0; i < 4; i++) {
    pinMode(inputPins[i], INPUT_PULLUP);
    pinMode(outputPins[i], OUTPUT);

    digitalWrite(outputPins[i], HIGH); // default to high
  }
}

void loop() {
  // reset connections to not-connected before checking
  for(int i = 0; i < 4; i++) {
    connections[i] = 9;
  }

  // loop thru each output pin
  for(int i = 0; i < 4; i++) {
    digitalWrite(outputPins[i], LOW); // go low for a sec

    // now check which input pin is connected to the LOW pin
    for(int n = 0; n < 4; n++) {
      if(digitalRead(inputPins[n]) == LOW) {
        // found it!
        connections[i] = n;
      }
    }

    // go back to high so you can check the next one
    digitalWrite(outputPins[i], HIGH); 
  }

  // now print all the diagnostic info
  Serial.print("current connections: ");
  for(int i = 0; i < 4; i++) {
    Serial.print(connections[i]);
    Serial.print(",");
  }
  Serial.print("  /  desired connections: ");
  for(int i = 0; i < 4; i++) {
    Serial.print(pass[i]);
    Serial.print(",");
  }

  boolean bad = false;
  // check if arrays match
  for(int i = 0; i < 4; i++) {
    if(connections[i] != pass[i]) {
      // if they dont match then set bad to true
      bad = true;
    }
  }

  // are they all correct?
  if(!bad) {
    Serial.print(" .. good!");
  } 
  else {
    Serial.print(" .. bad!");
  }

  Serial.println();

  delay(500);
}








