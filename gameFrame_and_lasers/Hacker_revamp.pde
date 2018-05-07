//WHERE IT ALL COMES TOGETHER

void setup() {
  //   String voice = "Ralph";
  size(1280, 800);
  myIntroMovie = new Movie(this, "PewPew.mov");
  myMovie = new Movie(this, "Comp1.mov");
  tickAnim  = new Movie(this, "clockAnim.mov");
  // photo = loadImage("test.png");


  myIntroMovie.play();


  timerToIntro = millis();//store the current time  

  //FONT
  clockFont = createFont("digital-7.ttf", 400, true); // STEP 2 Create Font
  textFont(clockFont, 80);

  //CONNECTIONS
/*
  String portName = Serial.list()[1]; //change the 0 to a 1 or 2 etc. to match your port
  myPort = new Serial(this, portName, 9600);
  */
}

void draw() {
  introScene();
  ticking();
  startClock();

  //Winning - Condition
}


//DO NOT CHANGE
void movieEvent(Movie m) {
  if (m == myIntroMovie) {
    m.read();
  } else {
    tickAnim.read();
  }
}
