

//WHERE IT ALL COMES TOGETHER

void setup() {
  size(1280, 800);
  
  //SHIFT F2 and change size
  //SHFT PLAY LETTER BOX MODE
 // fullScreen();
  myIntroMovie = new Movie(this, "PewPew.mov");
  myMovie = new Movie(this, "Comp1.mov");
  tickAnim  = new Movie(this, "clockAnim.mov");
<<<<<<< HEAD
=======
  // photo = loadImage("test.png");
>>>>>>> 342793fdcbaf96e1a490f4d3962c2cd7a1d6b9ec


  myIntroMovie.play();


  timerToIntro = millis();//store the current time  

  //FONT
  clockFont = createFont("digital-7.ttf", 400, true); // STEP 2 Create Font
  textFont(clockFont, 80);

  //CONNECTIONS
<<<<<<< HEAD

  String portName = Serial.list()[1]; //change the 0 to a 1 or 2 etc. to match your port
  myPort = new Serial(this, portName, 9600);





  //UNLOCK AND LOCKED IMAGES

  puzzi1 = loadImage("Locked.png");
  puzzi2 = loadImage("Locked.png");
  puzzi3 = loadImage("Locked.png");


  //SOUND


 //  file = new SoundFile(this, "Victory2.mp3");
   
   
  minim = new Minim(this);
  win = minim.loadFile("Victory.mp3");
   
=======
/*
  String portName = Serial.list()[1]; //change the 0 to a 1 or 2 etc. to match your port
  myPort = new Serial(this, portName, 9600);
  */
>>>>>>> 342793fdcbaf96e1a490f4d3962c2cd7a1d6b9ec
}

void draw() {
  introScene();
  ticking();
  startClock();
<<<<<<< HEAD
  connectTest1();
  YouWin();
  game3();
=======
>>>>>>> 342793fdcbaf96e1a490f4d3962c2cd7a1d6b9ec

  //Winning - Condition
}
void keyPressed() {
  if (key == 'a') {
       game1();
  }
  if (key == 'b') {
       game2();
  }
  if (key == 'c') {
       game3();
  }
   
}


//DO NOT CHANGE
void movieEvent(Movie m) {
  if (m == myIntroMovie) {

    m.read();
  } else {
    tickAnim.read();
  }
}
