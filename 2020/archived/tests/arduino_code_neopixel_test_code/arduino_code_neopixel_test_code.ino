/* Copyright 2020 LeRoy Miller
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses
 */
    
#include <Keypad.h>
#include <NewPing.h>
#include <Adafruit_NeoPixel.h>

//MQTT Defines
#define SUB "\"cmd\":\"MQTT-SUB\""
#define PUB "\"cmd\":\"MQTT-PUB\""

//UltraSonic Sensor
#define TRIGGER_PIN  3  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     2  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 500 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm. About 78 Inches
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.

//PIN Defines
#define lightPin A1 //analog pin0 for photoresistor
#define voltPin A3 //analog pin1 for voltage meter
#define LED_PIN 30
#define in1  7
#define in2  6

//Neopixel Defines
#define LED_COUNT 8
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_RGB + NEO_KHZ800);

//variables
float val11; 
float val2;
float voltage;
int pings;
int lights;
String inputString = "";         // a String to hold incoming data
bool stringComplete = false;  // whether the string is complete
String topic;
String cmd;
bool mouth = 0;

//setup keypad
const byte ROWS = 4; // Four rows
const byte COLS = 4; // four columns
// Define the Keymap

char keys[ROWS][COLS] = {
  {'C','D','E','F'},
  {'8','9','A','B'},
  {'4','5','6','7'},
  {'0','1','2','3'}
};

// Connect keypad ROW0, ROW1, ROW2 and ROW3 to these Arduino pins.
byte rowPins[ROWS] = { 33, 35, 37, 39 };
// Connect keypad COL0, COL1 and COL2 to these Arduino pins.
byte colPins[COLS] = { 41, 43, 45, 47 };

// Create the Keypad
Keypad kpd = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

//setup for neopixels
struct RGB {
  String R; 
  String G;
  String B;
};


RGB colors; 

int states[9][4];
String tP;

void setup() {
 Serial.begin(115200);
 pinMode(voltPin, INPUT);
 pinMode(lightPin, INPUT_PULLUP);
 
 strip.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
 strip.show();            // Turn OFF all pixels ASAP
 strip.setBrightness(15); // (max = 255)
 //Serial.println("{"SUB",\"topic\":\"src/myTopic/blink\"}");
}

void loop() {
 
  //check serial complete and phrase commands as needed
  if (stringComplete) {
    
    String msg2 = getValue(inputString, ':', 2);
    topic = getValue(msg2, ',', 0);
    topic = removeQuotes(topic);
    topic = getValue(topic, '/', 2);
    cmd = getValue(inputString, ':', 3);
    cmd = removeQuotes(cmd);
    cmd = removeBrace(cmd);
    inputString = "";
    stringComplete = false;
    if (topic == "somecommand1-blink") {       }
    if (topic == "someothercommand-count") {    }
    
  }

  //check keypad input 
  key();
  //check ultrasonic
  ping();
  //check voltage
  light();
  volt();
  delay(50);
}


void serialEvent() {
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read();
    // add it to the inputString:
    inputString += inChar;
    // if the incoming character is a newline, set a flag so the main loop can
    // do something about it:
    //if (inChar == '\n') {
    if (inChar == '}') {
      stringComplete = true;
    }
  }
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

int key() {


 char key = kpd.getKey();
 if(key)  // Check for a valid key.
  {
    switch (key)
    {
        default:
     Serial.print("Key Pressed: ");
    Serial.println(key);
        if (key-48>=17) {return (key-55);} else { return(key-48);}
        
    }
}

}

int ping() {
 unsigned int uS = sonar.ping(); // Send ping, get ping time in microseconds (uS).
   Serial.println(uS / US_ROUNDTRIP_IN); // Convert ping time to distance in cm and print result (0 = outside set distance range)
   return(uS/US_ROUNDTRIP_IN);
}

void led(int number1) {

/*
switch (number1) {
  case 0:
  //state0 = !state0;
    digitalWrite(led0, state0);
    break;
  case 1:
  //state1 = !state1;
    digitalWrite(led1, state1);
    break;
  case 2:
  //state2 = !state2;
    digitalWrite(led2, state2);
    break;
  case 3:
  state3 = !state3;
    digitalWrite(led3, state3);
    break;
  case 4:
  state4 = !state4;
    digitalWrite(led4, state4);
    break;
  case 5:
  state5 = !state5;
    digitalWrite(led5, state5);
    break;
  case 6:
  state6 = !state6;
    digitalWrite(led6, state6);
    break;
  case 7:
  state7 = !state7;
    digitalWrite(led7, state7);
    break;
  }
  */
}

void forward() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  
}

void reverse() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  
}

void stop() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
}

/*void left(float degree) {

  if (degree > 90) {speak("Error in Degree"); return;}
  myStepper.step(100*(degree/15));
}

void right(float degree) {

if (degree > 90) {speak("Error in Degree"); return;}
  myStepper.step(-100*(degree/15));
}
*/

int light() {
  int photor = analogRead(lightPin);
  Serial.print("Light: ");
  Serial.println(map(photor, 0, 1023, 100, 0));
  delay(50);
  return(map(photor,0,1023,100,0));
}

float volt() {
float temp;       
val11=analogRead(voltPin);
temp=val11/4;       
val11=temp;       
val2=((val11)/10);
Serial.print("val2: ");
Serial.println(val2);
//Serial.print("val11: ");
//Serial.println(val11);
//Serial.print("temp: ");
//Serial.println(temp);
return(val2);

}

void allLedsOff() {
  for (int i=0; i<8; i++) {
    strip.setPixelColor(1, strip.Color(0, 0, 0));         //  Set pixel's color (in RAM)
  }
  strip.show();
}

void ledmouth() {
  
allLedsOff();
 
 
  strip.setPixelColor(3, strip.Color(255, 0, 0));         //  Set pixel's color (in RAM)
  strip.setPixelColor(4, strip.Color(255, 0, 0));         //  Set pixel's color (in RAM)
  strip.show();
  delay(50);
  
  strip.setPixelColor(2, strip.Color(255, 0, 0));         //  Set pixel's color (in RAM)
  strip.setPixelColor(5, strip.Color(255, 0, 0));         //  Set pixel's color (in RAM)
  strip.show();
  delay(50);
  
  strip.setPixelColor(1, strip.Color(255, 0, 0));         //  Set pixel's color (in RAM)
  strip.setPixelColor(6, strip.Color(255, 0, 0));         //  Set pixel's color (in RAM)
  strip.show();
  delay(50);
  
  strip.setPixelColor(0, strip.Color(255, 0, 0));         //  Set pixel's color (in RAM)
  strip.setPixelColor(7, strip.Color(255, 0, 0));         //  Set pixel's color (in RAM)
  strip.show();
  delay(50);
  strip.setPixelColor(0, strip.Color(0, 0, 0));         //  Set pixel's color (in RAM)
  strip.setPixelColor(7, strip.Color(0, 0, 0));         //  Set pixel's color (in RAM)
  strip.show();
  delay(50);
  strip.setPixelColor(1, strip.Color(0, 0, 0));         //  Set pixel's color (in RAM)
  strip.setPixelColor(6, strip.Color(0, 0, 0));         //  Set pixel's color (in RAM)
  strip.show();
  delay(50);
  strip.setPixelColor(2, strip.Color(0, 0, 0));         //  Set pixel's color (in RAM)
  strip.setPixelColor(5, strip.Color(0, 0, 0));         //  Set pixel's color (in RAM)
  strip.show();
  delay(50);
  strip.setPixelColor(3, strip.Color(0, 0, 0));         //  Set pixel's color (in RAM)
  strip.setPixelColor(4, strip.Color(0, 0, 0));         //  Set pixel's color (in RAM)
  strip.show();
  delay(50);
  strip.setPixelColor(1, strip.Color(0, 0, 0));         //  Set pixel's color (in RAM)
  strip.setPixelColor(6, strip.Color(0, 0, 0));         //  Set pixel's color (in RAM)
  strip.show();
  delay(50);
  strip.setPixelColor(0, strip.Color(0, 0, 0));         //  Set pixel's color (in RAM)
  strip.setPixelColor(7, strip.Color(0, 0, 0));         //  Set pixel's color (in RAM)
  strip.show();
  delay(50);

allLedsOff();
if (mouth == 0 ) {resetState();}

}

void resetState() {

//  digitalWrite(led0, state0);
//  digitalWrite(led1, state1);
//  digitalWrite(led2, state2);
//  digitalWrite(led3, state3);
//  digitalWrite(led4, state4);
//  digitalWrite(led5, state5);
//  digitalWrite(led6, state6);
//  digitalWrite(led7, state7);
   
}



int multikey() {
  int digitone = 0;
  int digittwo = 0;
  int digitthree = 0;
  int digitfour = 0;
  int finaldigit = 0;
  digitone = key();
  if (digitone == 15) {return(digitone);} else {
  led(0);
  }
  digittwo = key();
  if (digittwo == 15) {
    finaldigit = digitone;
    led(0);
    return(finaldigit);
  } else { 
    led(1);
  }
  digitthree = key();
  if (digitthree == 15) {
    finaldigit = (digitone * 10) + (digittwo);
    led(0);
    led(1);
    return(finaldigit);
  } else {
    led(2);
  }
  digitfour = key();
  if (digitfour == 15) {
    finaldigit = (digitone * 100) + (digittwo * 10) + (digitthree);
    led(0);
    led(1);
    led(2);
    return(finaldigit);
  } else {
    finaldigit = (digitone * 1000) + (digittwo * 100) + (digitthree *10) + (digitfour);
    led(0);
    led(1);
    led(2);
    return(finaldigit);
  }
}
