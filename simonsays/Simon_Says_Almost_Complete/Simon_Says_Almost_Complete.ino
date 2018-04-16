//4 Different Sequence that corresponds to each codename/color
//Each player must input their sequence to be cleared from the alarm system
//Once each player has entered their sequence, system resets, hackerman gives them the go
//Game is complete

//ss,fail = when player fails a sequences
//ss,succeed = **

int ledPins[] = {8, 9, 10, 11};
int buttons[] = {4, 5, 6, 7};
//ButtonsBuff is for the time between presses, buttonsPR is when 
//the buttons is pressed to not count multiple times 
long buttonsPR[] = {0, 0, 0, 0};
int buttonsBuff = 500;

int previousState[] = {HIGH, HIGH, HIGH, HIGH};

int pattern[7];
int userPattern[7];
int patternLength = 4;
int userIndex = 0;

int totalRounds = 4;
int currentRound = 0;
int gameState = 0;

int stateRepeat = 1;
int tries = 3;


void setup() {
  Serial.begin(9600);
  Serial.println("System Online");

  //applies to all LEDs
  for (int i = 0; i < 4; i++) {
    pinMode(ledPins[i], OUTPUT);
    pinMode(buttons[i], INPUT_PULLUP);
  }

}

void loop() {
  //create if statement that will run game when system is ready
  
  
  //gameState 0 begins, pattern is created, sequence prevented from repeating
  if (gameState == 0) {
    randomSeed(analogRead(4));

    for (int i = 0; i < patternLength; i++) {
      pattern[i] = random(4);
      Serial.print(pattern[i]);
    }
    Serial.println("");

    gameState++;
    Serial.println("gameState = " + String(gameState));

    
  }

  //gameState 1 begins, LEDs flash, pattern begins, 1st LED turns on, pattern displays
  if (gameState == 1) {
    //LEDs are OFF
    for (int i = 0; i < 4; i++) {
      digitalWrite(ledPins[i], LOW);
    }

    // used to have LED's replicate the patternLength of the sequence
    for (int i = 0; i < patternLength; i++) {
      digitalWrite(ledPins[pattern[i]], HIGH);
      delay(1000);
      digitalWrite(ledPins[pattern[i]], LOW);
      delay(1000);
    }
    gameState++;
    //Serial.println(gameState);
    Serial.println("gameState = " + String(gameState));
  }

  //gameState 2 begins, user inputs the pattern, if pattern is correct move on to next gameState
  //if user input this in wrong, pattern resets, should have 3 tries max
  if (gameState == 2) {
    for (int i = 0; i < patternLength; i++) {
      if (digitalRead(buttons[i]) == LOW && previousState[i] == HIGH) {
        // Button is pressed within a certain time so the button doesnt count multiple times 
        if (millis() > buttonsPR[i] + buttonsBuff) {

          userPattern[userIndex] = i;
          userIndex++;
          Serial.println("down");
          previousState[i] = LOW;
          buttonsPR[i] = millis();
        }
      }
      if (digitalRead(buttons[i]) == HIGH && previousState[i] == LOW) {
        Serial.println("up");
        previousState[i] = HIGH;
      }
    }

    if (userIndex == patternLength) {
      bool patternCorrect = true;

      for (int i = 0; i < patternLength; i++) {

        if (userPattern[i] != pattern[i]) {
          patternCorrect = false;

        }
      }
      if (patternCorrect == true) {
        for (int i = 0; i < 4; i++) {
          digitalWrite(ledPins[i], HIGH); 
        }
        delay(2000);
        
        for (int i = 0; i < 4; i++) {
          digitalWrite(ledPins[i], LOW);          
        }
        
        delay(1000);
        patternLength++;
        gameState = 0;
        Serial.println("gameState = " + String(gameState));
        // Resets the player's input
        userIndex = 0;
      }


      else if (patternCorrect == false) {
        Serial.println("gameState " + String(gameState));
        // Resets the player's input to 0 and replays the code
        userIndex = 0;
        gameState = 1;
        tries--;

  Serial.println("ss,fail");
  //sends message to gaming system
        
        if(tries == 0){
          gameState = 0;
          tries = 3;
          //serial will let user know when the sequence is wrong.

          if(patternLength == 7){
            gameState = 3;
          }

        }
      }
    }
  }
}
