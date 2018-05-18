<<<<<<< HEAD
void YouWin() {



  if (puzzle1Solved == true && puzzle2Solved == true) {

    //Play win video
    stopped = true;
    println("I dont feel so good");

    // file.play();
    win.play();
  }
}

void Loser() {
  //PLauy a sound
  // A lose screen
  //Game over????
}
=======
void YouWin(){

if(val == 19){
    puzzle1Solved = true;
}
 if(val == 29){
    puzzle2Solved = true;
}
 if(val == 39){
    puzzle3Solved = true;
    
 }
 
 if(puzzle1Solved && puzzle2Solved && puzzle3Solved){
   
   //Play win video
   stopped = true;
   
   
 }

}

void Loser(){
  //PLauy a sound
  // A lose screen
  //Game over????
  
}
>>>>>>> 342793fdcbaf96e1a490f4d3962c2cd7a1d6b9ec
