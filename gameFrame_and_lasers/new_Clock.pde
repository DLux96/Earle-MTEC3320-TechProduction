void newClock()
{

  if (millis() - prevTime >= 1000  && stopped == false) {
    sec -= 1;
    prevTime = millis();//also update the stored time
    if (sec < 0) {
      sec = 59;
      min -= 1;
    }
  }

  //End

  if (min <= 0 && sec == 0) {
    stopped = true;
    println("LOST");
    Loser();
  }

 


  //  textSize(30);
  fill(0, 102, 153, 204);
  text(floor(sec), width/2, height/2);
  text(floor(min), width/2 - 180, height/2);
  //  text(floor(hour), width/2 +60, height/2);

  //Blinking Dots

  if (sec % 2 == 0) {
    col = color(255);
  } else {
    col = color(0);
  }
  fill(0, 102, 153, 204);
  ellipse(width/2 - 50, height/2 -50, 8, 8);
  ellipse(width/2 - 50, height/2, 8, 8);
  //  ellipse(width/2 +25, height/2, -15, 8);
  //  ellipse(width/2 +25, height/2 + 15, 8, 8);
}
