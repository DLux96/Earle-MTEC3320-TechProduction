
int lastJackNumber;
int jackIn01_state = 0;
int jackIn02_state = 0;
int jackIn03_state = 0;
int jackIn04_state = 0;

String jackin_01 = "Jackin_1:";
String jackin_02 = "Jackin_2:";
String jackin_03 = "Jackin_3:";
String jackin_04 = "Jackin_4:";
long lastDebounceTime = 0;

const int led01R_pin = 22;
const int led01G_pin = 23;
const int led01B_pin = 24;

const int led02R_pin = 25;
const int led02G_pin = 26;
const int led02B_pin = 27;

const int led03R_pin = 28;
const int led03G_pin = 29;
const int led03B_pin = 30;

const int led04R_pin = 31;
const int led04G_pin = 32;
const int led04B_pin = 33;

//RGB LEDs - Bottom Row
const int led05R_pin = 34;
const int led05G_pin = 35;
const int led05B_pin = 36;

const int led06R_pin = 37;
const int led06G_pin = 38;
const int led06B_pin = 39;

const int led07R_pin = 40;
const int led07G_pin = 41;
const int led07B_pin = 42;

const int led08R_pin = 43;
const int led08G_pin = 44;
const int led08B_pin = 45;

//INPUT JACKS - Bottom Row
const int jackIn01_pin = A0;
const int jackIn02_pin = A1;
const int jackIn03_pin = A2;
const int jackIn04_pin = A3;

const int button01_pin = 10;

bool buttonState = 0;



int debounce(int jackValue, long debounceDelay, int comparedTime){
  int lastValue = jackValue; 
  int newJackValue;
  
  if (jackValue != lastValue) {
    // reset the debouncing timer
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    // whatever the reading is at, it's been there for longer than the debounce
    // delay, so take it as the actual current state:

    

    // if the button state has changed:
    if (jackValue == newJackValue) {
      newJackValue = jackValue;
      lastDebounceTime = millis();

      return newJackValue;
    }
    
  }

  return 0;
}

void setup() {
  
    pinMode(jackIn01_pin, INPUT);
    pinMode(jackIn02_pin, INPUT);
    pinMode(jackIn03_pin, INPUT);
    pinMode(jackIn04_pin, INPUT);
    
    pinMode(led01R_pin, OUTPUT);
    pinMode(led01G_pin, OUTPUT);
    pinMode(led01B_pin, OUTPUT);
    
    pinMode(led02R_pin, OUTPUT);
    pinMode(led02G_pin, OUTPUT);
    pinMode(led02B_pin, OUTPUT);
    
    pinMode(led03R_pin, OUTPUT);
    pinMode(led03G_pin, OUTPUT);
    pinMode(led03B_pin, OUTPUT);
    
    pinMode(led04R_pin, OUTPUT);
    pinMode(led04G_pin, OUTPUT);
    pinMode(led04B_pin, OUTPUT);
    
    pinMode(led05R_pin, OUTPUT);
    pinMode(led05G_pin, OUTPUT);
    pinMode(led05B_pin, OUTPUT);
    
    pinMode(led06R_pin, OUTPUT);
    pinMode(led06G_pin, OUTPUT);
    pinMode(led06B_pin, OUTPUT);
    
    pinMode(led07R_pin, OUTPUT);
    pinMode(led07G_pin, OUTPUT);
    pinMode(led07B_pin, OUTPUT);
    
    pinMode(led08R_pin, OUTPUT);
    pinMode(led08G_pin, OUTPUT);
    pinMode(led08B_pin, OUTPUT);
    
    pinMode(jackIn01_pin, INPUT);
    pinMode(jackIn02_pin, INPUT);
    pinMode(jackIn03_pin, INPUT);
    pinMode(jackIn04_pin, INPUT);

    
    Serial.begin(9600);
}

void loop() {
  
 // jackIn01_state = analogRead(jackIn01_pin);
 //jackIn02_state = analogRead(jackIn02_pin);
 // jackIn03_state = analogRead(jackIn03_pin);
// jackIn04_state = analogRead(jackIn04_pin);

  //Serial.println(jackin_01 + jackIn01_state);
  // Serial.println(jackin_02 + jackIn02_state);
   // Serial.println(jackin_03 + jackIn03_state);
   //Serial.println(jackin_04 + jackIn04_state);
   //delay(100);

    
    int val01 = jackRead(jackIn01_pin);
    int val02 = jackRead(jackIn02_pin);
    int val03 = jackRead(jackIn03_pin);
    int val04 = jackRead(jackIn04_pin);


   //Serial.println(val02);
   //Serial.println(val03);
 //  Serial.println(val04);

    checkAuxCloseCurcuit(val01, led01R_pin,led01G_pin, led01B_pin, 797, "circuit1");
    checkAuxCloseCurcuit(val01, led05R_pin,led05G_pin, led05B_pin, 797, "circuit1");

    checkAuxCloseCurcuit(val02, led02R_pin,led02G_pin, led02B_pin, 414, "circuit2");
    checkAuxCloseCurcuit(val02, led06R_pin,led06G_pin, led06B_pin, 414, "circuit2");

    checkAuxCloseCurcuit(val03, led03R_pin,led03G_pin, led03B_pin, 614, "circuit3");
    checkAuxCloseCurcuit(val03, led07R_pin,led07G_pin, led07B_pin, 614, "circuit3");


    checkAuxCloseCurcuit(val04, led04R_pin,led04G_pin, led04B_pin, 275, "circuit4");
    checkAuxCloseCurcuit(val04, led08R_pin,led08G_pin, led08B_pin, 275, "circuit4");

}
//function that turn on which pin that is connected
void checkAuxCloseCurcuit(int jack, int RLEDPin, int GLEDPin, int BLEDPin, int value, String circuit){
  if (jack >= (value - 1) && jack <= (value + 1) ){
   digitalWrite(RLEDPin, LOW);
   digitalWrite(GLEDPin, HIGH);
   digitalWrite(BLEDPin, LOW);
   Serial.println(circuit + " on");
   }
   else {
    digitalWrite(RLEDPin, HIGH);
    digitalWrite(GLEDPin, LOW);
    digitalWrite(BLEDPin, LOW);
    Serial.println(circuit + " off");
    }
}

int jackRead(int jack) 
{
  int value = analogRead(jack);
  return value;
}




 

