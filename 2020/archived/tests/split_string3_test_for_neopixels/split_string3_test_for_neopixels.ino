/*
 * In this example, we break down the topic which is "blink", then we get the message (as cmd) which in this case is 1x01x02x03
 * next we pull the color information from the message (cmd) which ends up being 000000, and finally we pull the 
 * led which to light from the message (cmd) which in this case is 1
 * 
 * saves states as ints, shows how to convert to the string to int, shows how to save the state
 */ 

#include <Adafruit_NeoPixel.h>

#define LED_PIN    30

// How many NeoPixels are attached to the Arduino?
#define LED_COUNT 8


String msg = "{cmd\":\"MQTT-PUB\",\"topic\":\"src/myTopic/blink\",\"message\":\"1x0x255x0\"}";

struct RGB {
  String R; 
  String G;
  String B;
};


RGB colors; 

int states[9][4];
String tP;

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
  strip.show();            // Turn OFF all pixels ASAP
  strip.setBrightness(50); // Set BRIGHTNESS to about 1/5 (max = 255)
  Serial.begin(115200);
  String msg2 = getValue(msg, ':', 2);
  String topic = getValue(msg2, ',', 0);
  Serial.println(topic);
  topic = removeQuotes(topic);
  Serial.println(topic);
  topic = getValue(topic, '/', 2);
  Serial.println(topic);
  //Serial.println(topic);
  String cmd = getValue(msg, ':', 3);
  cmd = removeQuotes(cmd);
  cmd = removeBrace(cmd);
  Serial.println(cmd);

  
  //Serial.println(getValue(msg, ':', 2));
  
 // colors.R = getValue(cmd, 'x',1);
 // colors.G = getValue(cmd, 'x',2);
 // colors.B = getValue(cmd, 'x',3);
  colors = {getValue(cmd, 'x',1), getValue(cmd, 'x', 2), getValue(cmd, 'x', 3)};
  //Serial.println(colors);
  Serial.print(colors.R); Serial.println(" " + colors.G + " " + colors.B);
  cmd.remove(1);
  Serial.println(cmd);
  
  states[cmd.toInt()][0] = colors.R.toInt(); states[cmd.toInt()][1] = colors.G.toInt(); states[cmd.toInt()][2] = colors.B.toInt();
  Serial.println(states[1][1]);
tP = cmd;

}

void loop() {
  displayLED(tP.toInt(),colors);
delay(1000);
  displayLED(tP.toInt(),RGB {"255","0","0"}); //create a states RGB thing
  delay(1000);
}

void displayLED(int pin, RGB color) {

    strip.setPixelColor(pin, strip.Color(color.R.toInt(), color.G.toInt(), color.B.toInt()));         //  Set pixel's color (in RAM)
    strip.show();                          //  Update strip to match
 }

//found at https://stackoverflow.com/questions/9072320/split-string-into-string-array
String getValue(String data, char separator, int index)
{
  int found = 0;
  int strIndex[] = {0, -1};
  int maxIndex = data.length()-1;

  for(int i=0; i<=maxIndex && found<=index; i++){
    if(data.charAt(i)==separator || i==maxIndex){
        found++;
        strIndex[0] = strIndex[1]+1;
        strIndex[1] = (i == maxIndex) ? i+1 : i;
    }
  }

  return found>index ? data.substring(strIndex[0], strIndex[1]) : "";
}


//based on code found at: https://stackoverflow.com/questions/40093116/remove-character-from-string-c-arduino-uno
String removeQuotes(String data) {
  char c;
    char no = '\"'; //character I want removed.

    for (int i=0; i<data.length();++i){
        c = data.charAt(i);
        if(c==no){
            data.remove(i, 1);
        }
    }
    return data;
}

String removeBrace(String data) {
  char c;
    char no = '}'; //character I want removed.

    for (int i=0; i<data.length();++i){
        c = data.charAt(i);
        if(c==no){
            data.remove(i, 1);
        }
    }
    return data;
}
