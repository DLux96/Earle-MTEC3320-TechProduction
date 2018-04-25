void introScene() {

  image(myIntroMovie, 0, 0);
  // delay(500);

  /// testing...
  //  myMovie.mask(mask);

//  image(myMovie, 0, 0);

  //WHEN VOICE STARTS

  if (millis() - timerToIntro >= wait && started == false) {
    println("tick");//if it is, do something
    timerToIntro = millis();//also update the stored time
    say(script1, "Ralph", 180);
    started = true;
  }
}
/*
//TIMER FOR SOMETHING-- FOR THE TIMER TO START UP/TIME DISPLAY
void toCountDown() {

  if (millis() - timerToIntro >= wait2 && started2 == false) {
    background(0);
    timerToStart = millis();//also update the stored time
    println("Yerrr");
    started2 = true;
  }
  */
