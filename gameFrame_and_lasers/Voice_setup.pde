// the text to speech class
//DO NOT CHANGE
import java.io.IOException;

// this sends the "say" command to the terminal with the appropriate args
static void say(String script, String voice, int speed) {
  try {
    Runtime.getRuntime().exec(new String[] {"say", "-v", voice, "[[rate " + speed + "]]" + script});
  }
  catch (IOException e) {
    System.err.println("IOException");
  }
}