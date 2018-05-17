

void connectTest1() {
  if ( myPort.available() > 0) 
  {  // If data is available,
    val = myPort.read();         // read it and store it in val
    println(val); //print it out in the console  /''''//'[
  }
}


void game1() {
  // FOR ARDUINO MEGA, SERIAL GROUND MUST BE ON THE SAME SIDE AS THE DIGITAL PINS THAT IM USING
  //SIMON SAYS TEST( WORKS)
  myPort.write(10);
  println("sent");
  if (val == 19) {
    println("game1Solved");
    game2();
    puzzle1Solved = true;
  }
}
void game2() {
  //RYANS PHONE( CODES ARE 30S) PINS ( 14, 15)
  //TEST MONDAY
  //Test again  

  myPort.write(21);
  println("sent");

  if (val == 29) {
    println("game2Solved");
    puzzle2Solved = true;
    //TURN OFF??
    // myPort.write(20);
  }
}
//Patcbay
void game3() {

  //WORKS??

 // myPort.write(41);
 // println("sent");

  if (val ==49) {
    println("game3Solved");
    puzzle3Solved = true;
    //TURN OFF??
    // myPort.write(20);
  }
}

void lasers() {

  if (val == 41 && lasers == true) {

    sec -= 30;
    lasers = false;
  }
}