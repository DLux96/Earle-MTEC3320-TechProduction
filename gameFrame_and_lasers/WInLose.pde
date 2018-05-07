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
