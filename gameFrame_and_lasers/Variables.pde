import processing.video.*;
import processing.serial.*;

//VIDEO IMPORTS

Movie myMovie;
Movie myIntroMovie;
Movie tickAnim;

//PImage mask;
Movie mask;

//COUNTDOWN FOR VOICE
int timerToIntro;
int wait = 1000;
boolean started;

//SECOND TIMER FOR SOMETHING

int timerToStart;
//int wait2 = 34000;
int wait2 = 1000;
public boolean started2;

//FONT FOR TIMER

PFont clockFont;
String tD = "YERRR";

//VARIABLES FOR CLOCK

int cbegin; 
int cduration = 100;
int ctime = 300;

//Mask
PImage photo, maskImage;

//NEW CLOCK

float sec= 00,min = 1,hour = 14;
color col = color(255);
int interval  =  60;

float dt;
boolean setting = true;

//NEW NEW COUNTDOWN

float prevTime;

//CONNECTION SETUP

Serial myPort;
String val;

boolean stopped = false ;
boolean youWin = false;

//PUZZLE SOLVED INPUTS



//LASER INPUTS

boolean LasersOn = false;

//Game States

int game1Status;
int game1Status2;
int game1Status3;

int laserState;
//boolean laserTrip;
