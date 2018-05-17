void ticking()
{
  //TIMER FOR SOMETHING-- FOR THE TIMER TO START UP/TIME DISPLAY

  if (millis() - timerToIntro >= wait2 && started2 == false) {
    background(0);
    timerToStart = millis();//also update the stored time
    println("Yerrr");
    started2 = true;

    myIntroMovie  = new Movie(this, "clockAnim.mp4");
    myIntroMovie.loop();
    //    myIntroMovie.mask(maskImage);
    //  image(photo,0,0);
  }

  // delay(30000);
}

void startClock() {
  if (started2 == true) {
    //      delay(1000);
    newClock();
  //  game1();
  }
}