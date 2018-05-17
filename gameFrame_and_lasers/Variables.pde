import processing.video.*;
import processing.serial.*;
import processing.sound.*;


//MINIM

import ddf.minim.*;
import ddf.minim.analysis.*;
import ddf.minim.effects.*;
import ddf.minim.signals.*;
import ddf.minim.spi.*;
import ddf.minim.ugens.*;




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

float sec= 00, min = 15 , hour = 14;
color col = color(255);
int interval  =  60;

float dt;
boolean setting = true;

//NEW NEW COUNTDOWN

float prevTime;

//CONNECTION SETUP

Serial myPort;
int val;

boolean stopped = false ;
boolean youWin = false;

//PUZZLE SOLVED INPUTS




//PUZZLE ICONS
PImage puzzi1;
PImage puzzi2;
PImage puzzi3;




//LASER INPUTS

boolean LasersOn = false;
boolean lasers = false;

//Game States

boolean puzzle1Solved = false;
boolean puzzle2Solved = false;
boolean puzzle3Solved = false;

int laserState;
//boolean laserTrip;

//SOUND FILES

//SoundFile file;

Minim minim;
AudioPlayer win;

//Variables 