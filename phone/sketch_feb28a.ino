#include <SoftwareSerial.h>
SoftwareSerial mySerial(12, 13);

int buttons[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
int codeword[10];
int a = 0;
int b = -1;
bool c;
int supercode[10];
int beep;
int win = A0; // win condition
int prevbutt[10] = {HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH};
int red = A1;
int green = A0;

long buttlast[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int stall = 500;

//int array1[] = {1, 3, 1, 9, 6, 4, 1, 7, 4, 1};
int array1[] = {8, 1, 8, 4, 3, 7, 1, 3, 2, 0};
int array0[] = {0, 9, 5, 1, 4, 0, 2, 6, 4, 7};
int array2[] = {7, 1, 4, 7, 9, 7, 9, 6, 4, 8};
int array3[] = {7, 4, 2, 1, 7, 9, 1, 0, 1, 5};

boolean started = false;
int inByte;

void setup() {
  Serial.begin(9600);
  mySerial.begin(9600);

  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);

  beep = random(3);
  if (beep == 0)
  {
    memcpy (supercode, array0, 10 * sizeof(int));
  } else if (beep == 1) {
    digitalWrite(green, HIGH);
    delay(500);
    digitalWrite(green, LOW);
    memcpy (supercode, array1, 10 * sizeof(int));
  } else if (beep == 2) {
    digitalWrite(red, HIGH);
    delay(500);
    digitalWrite(red, LOW);
    memcpy (supercode, array2, 10 * sizeof(int));
  } else {
    digitalWrite(green, HIGH);
    digitalWrite(red, HIGH);
    delay(500);
    digitalWrite(green, LOW);
    digitalWrite(red, LOW);
    memcpy (supercode, array3, 10 * sizeof(int));
  }


  for (int i = 0; i < 10; i++) {
    pinMode(buttons[i], INPUT_PULLUP);
  }
  pinMode(win, OUTPUT);
  digitalWrite(win, LOW);
  Serial.println("Program Start");

}

void loop() {
  // put your main code here, to run repeatedly:
  //RASHID's CONNECTION CODE
 // Serial.println(started);
  while (mySerial.available() > 0)
  {
    inByte = mySerial.read();
 //   Serial.println(inByte);
  }

  if ( inByte == 21) {
    started = true;

  }
  if (started == true) {
    for (int i = 0; i < 10; i++)
    {
      if (digitalRead(buttons[i]) == LOW && prevbutt[i] == HIGH)
      {
        if (millis() > buttlast[i] + stall)
        {
          prevbutt[i] = LOW;
          buttlast[i] = millis();

          //if correct make green and a++
          if (i == supercode[a])
          {
            digitalWrite(green, HIGH);
            delay(200);
            digitalWrite(green, LOW);

            Serial.print("digits(a) = ");
            Serial.println(a);
            Serial.println("green");

            a++;
            //if win red and green blink
            if (a == 10)
            {
              mySerial.write(29);
              Serial.println("WIN");
              //infinite loop
              for (int g = 0; g < 1; g = 0)
              {
                digitalWrite(green, HIGH);
                digitalWrite(red, LOW);
                delay(50);
                digitalWrite(green, LOW);
                digitalWrite(red, HIGH);
                delay(50);
              }

            }
            //if wrong make red and a=0
          } else {
            digitalWrite(red, HIGH);
            delay(200);
            digitalWrite(red, LOW);
            Serial.println("red");
            a = 0;
            Serial.println("Wrong");
          }
          //Serial.println("button " + String(i));
          Serial.print("prevbutt(i) = ");
          Serial.println(i);
        }

      }
      if (digitalRead(buttons[i]) == HIGH && prevbutt[i] == LOW)
      {
        prevbutt[i] = HIGH;

      }
    }
  }
}



