/*
void connectTest1(){
 if ( myPort.available() > 0) 
 {  // If data is available,
 val = myPort.readStringUntil('\n');         // read it and store it in val
 } 
 println("solved"); //print it out in the console
 
 
 }
 */
void puzzle1() {
  //Status of First Puzzle
  //Puzzle1 on
  if (game1Status == 02)
  {
    myPort.write("02");
  }
  //Puzzle1 off
  if (game1Status == 12)
  {
    myPort.write("12");
  }
  //Puzzle1 right
  if (game1Status == 32)
  {
    myPort.write("22");
  }
  //Puzzle1 wrong
  if (game1Status == 32)
  {
    myPort.write("32");
  }
  //Puzzle1 Solved
  if (game1Status == 32)
  {
    myPort.write("32");
  }
}

void puzzle2() {
}
void puzzle3() {
}













void Lasers() {

  //TIMER FOR LASERS

  //TURN ON AND OFF LASERS


  //Turn LAsers on
  if (laserState == 01) 
  {
    myPort.write('1');         //send a 1
  }
  //Turn Lasers off
  if (laserState == 11) 
  {
    myPort.write("11");         //send a 11
  }
  //Lasers are tripped
  if (laserState == 21) 
  {
    myPort.write("21");         //send a 11
  }
}
