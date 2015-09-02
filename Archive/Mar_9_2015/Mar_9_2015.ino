/* On Mar 9, 2015 6:09PM Eastern Time. 
The Hero Jr become 98.99% complete, power was given to him via his on board battery
and he sung Daisy for the 1st time! */

/*
At this point, a lot more of the code needs to be written, but all of the 
hardware is hooked up. 
Only optional hardware may need to be added.
Some type of wireless device, a RTC, and a PIR sensor.
*/

#include <Wire.h>
#include <Keypad.h>
#include <NewPing.h>
#include <Stepper.h>

/*Hero Jr Control - Arduino Mega
Commands so far:
key() - read a button push from the keypad
ping() - read distance from ping sensor
led(#) - turn on led # 0 to 7 state is toggled on or off
forward(distance) - move forward 
reverse(distance) - move backward
left(degree) - turn to the left 
right(degree) - turn to the right
light() - read the light sensor
volt() - check the voltage levels for the drive battery
test() - don't know yet
rinit() - reset Arduino Mega board to power on conditions
listen() - returns when it hears a sound (Signal Wire hooks up to pin 53 on the Mega. Sound sensor works at 5v)
speak(string) - string of what to say
speakint(int) - say an int number by converting it to a string
speakcmd(command) - gives a way to change the speech output
singhbd() - sing Happy Birthday
singdaisy() - sing Daisy


*** Voltage Sensor Information
This seems to work 3.3v hooked to output side
and "S" hooked to Analog input 1
It qives whole numbers as output
Tested on the UNO, and not sure why it needs "Wire.h"

Just for run ** New Command: 
cylon(times) - will cause the leds to cycle back and forth the number of times given

More Functions to add relating to the Keypad:
sing - mapped to key 4 - randomly sign one of three songs 
play - mapped to key 5 - not sure what this did
help - mapped to key 6 - 
speak - mapped to key 7 - 
gab - mapped to key 8 -
poet - mapped to key 9 - tells a random poem (one of three)
demo - mapped to key A - not sure yet
guard - mapped to key B - random move, using ultra sonic and drive
alarm - mapped to key C - Using PIR or Ultrasonic to watch something and make sure it doesn't move - if it does sound alarm (probably loud speech)
plan - mapped to key D - not sure what this does
setup - mapped to key E - 
enter - mapped to key F - enter key
*/

int lightPin = 0; //analog pin0 for photoresistor

#define TRIGGER_PIN  13  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     12  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 200 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm. About 78 Inches
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.

int val11; 
int val2; 
int led0 = 22;
int led1 = 24;
int led2 = 26;
int led3 = 28;
int led4 = 30;
int led5 = 32;
int led6 = 34;
int led7 = 36;
int state0 = 1;
int state1 = 1;
int state2 = 1;
int state3 = 1;
int state4 = 1;
int state5 = 1;
int state6 = 1;
int state7 = 1;
int timea;
int sound = 0;
int count = 0;
int enA = 38;
int in1 = 40;
int in2 = 50;


const int stepsPerRevolution = 200; 
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
byte rowPins[ROWS] = { 4, 5, 6, 7 };
// Connect keypad COL0, COL1 and COL2 to these Arduino pins.
byte colPins[COLS] = { 8, 9, 10, 11 };

// Create the Keypad
Keypad kpd = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
Stepper myStepper(stepsPerRevolution, 46, 44, 42, 48); 

int stepCount = 0;  
int number;
int state;
String command;
int distance;
int speed;
int degree;
int fl;
String str; //use this to convert a int to a char for speech.

void setup() 
{   
   
Serial.begin(9600);
Serial1.begin(9600); //Serial 1 is used for the eMIC 2 
delay(3000); //wait for eMIC 2 to come online
Serial1.flush();
Serial1.println();
Serial1.print("v10"); //set volume to level 10
delay(100);
Serial1.println("p0"); //set pharser for DECtalk
pinMode(52, OUTPUT); //Pin 52 is used to provide 5v to the Sound sensor
digitalWrite(52, HIGH); 
   pinMode(led0, OUTPUT);
   pinMode(led1, OUTPUT);
   pinMode(led2, OUTPUT);
   pinMode(led3, OUTPUT);
   pinMode(led4, OUTPUT);
   pinMode(led5, OUTPUT);
   pinMode(led6, OUTPUT);
   pinMode(led7, OUTPUT);
   pinMode(enA, OUTPUT);
   pinMode(in1, OUTPUT);
   pinMode(in2, OUTPUT);
   digitalWrite(led0, 1);
   digitalWrite(led1, 1);
   digitalWrite(led2, 1);
   digitalWrite(led3, 1);
   digitalWrite(led4, 1);
   digitalWrite(led5, 1);
   digitalWrite(led6, 1);
   digitalWrite(led7, 1);
   Serial.println("");
   Serial.println("");
   Serial.println("Hero Jr Control Program");
   Serial.println("Ready");
   Serial.println(">");
   myStepper.setSpeed(75);
   } 

void (* resetFunc) (void) = 0;

void loop() 
{       

test();
delay(15000);

}                  

void speakcmd(char say[]) {
	
	//Serial1.println();
	Serial1.println(say);
	while(Serial1.read() != ':');
	delay(500);
	
}

void singdaisy() {
	
	//Serial1.println();
	Serial1.println("d1");
	while(Serial1.read() != ':');
	delay(500);
}
void singhbd() {

	//Serial1.println();
	Serial1.println("s[:phone arpa speak on][:rate 200][:n0][hxae<300,10>piy<300,10>brrrx<600,12>th<100>dey<600,10>tuw<600,15> yu<1200,14>_<300> hxae<300,10>piy<300,10>brrrx<600,12>th<100>dey<600,10> tuw<600,17>yu<1200,15>_<300> hxae<300,10>piy<300,10>brrrx<600,22>th<100>dey<600,19> _<150>_<300>hxae<300,20>piy<300,20>brrrx<600,19>th<100>dey<600,15> tuw<600,17> yu<1200,15>][:n0]");
while(Serial1.read() != ':');
	delay(500);

}

void speak(char say[]) {
	
	//Serial1.println();
	Serial1.print("s");
	Serial1.println(say);
	while(Serial1.read() != ':');
	delay(500);
}

/*void speakint(int say2) {
	String say1 = String(say2);
	int strlen = say1.length()+1;
	char say[strlen];
	say1.toCharArray(say,strlen);
	//Serial1.println();
	Serial1.print("s");
	Serial1.println(say);
	while(Serial1.read() != ':');
	delay(500);
}
*/

void speakint(int say) {
	
	Serial1.print("s");
	Serial1.println(say);
	while(Serial1.read() != ':');
	delay(500);
}

int listen() {
	delay(1000);
	/*while(digitalRead(53) != 0) {
		delay(100);
	}
	Serial.println("Sound Detected! Return");
	*/
	//wait for about 15 seconds and move on
	for (int waiting=0; waiting <= 25000; waiting++) {
	sound = digitalRead(53);
	if (sound == 0) { 
		Serial.print("Sound detected! :");
		return 1;
			}
	delay(250);		
	return 0;
	}
}



void key() {
//Need to work on this part of the code
	delay(100);
	char key = kpd.getKey();

	Serial.println(key);
}

int ping() {
 unsigned int uS = sonar.ping(); // Send ping, get ping time in microseconds (uS).
   Serial.println(uS / US_ROUNDTRIP_IN); // Convert ping time to distance in cm and print result (0 = outside set distance range)
   return(uS/US_ROUNDTRIP_IN);
}

void led(int number1) {

switch (number1) {
	case 0:
	state0 = !state0;
		digitalWrite(led0, state0);
		break;
	case 1:
	state1 = !state1;
		digitalWrite(led1, state1);
		break;
	case 2:
	state2 = !state2;
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
}

void forward(int distance) {
	digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    analogWrite(enA, 255);
    delay(1000*distance); //how long the motor should be left on 
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
}

void reverse(int distance) {
	digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    analogWrite(enA, 255);
    delay(1000*distance); //how long the motor should be left on
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
}

void left(int degree) {
/*	if (stepCount >= 600) {return;}
stepCount = stepCount + 100;
	 myStepper.step(100);
  */
  if (degree > 90) {speak("Error in Degree"); return;}
  myStepper.step(100*(degree/15));
}

void right(int degree) {
/*	if (stepCount <= -600) {return;}
	stepCount = stepCount - 100;
myStepper.step(-100);
*/
if (degree > 90) {speak("Error in Degree"); return;}
  myStepper.step(100*(degree/15));
}

int light() {
	int photor = analogRead(lightPin);
	Serial.println(photor);
	delay(50);
	return(photor);
}

int volt() {
float temp;       
val11=analogRead(1);
temp=val11/4;       
val11=(int)temp;       
val2=((val11)/10);
Serial.println(val2);          
return(val2);
}

void test() {
	
	//This routine will test the functions of the robot
	credit();
	delay(500);
	speak("I will run some self tests now. ");
	delay(500);
	speak("Test 1 Voltage reading.");
	int voltage = volt();
	speak("The current battery voltage is ");
	delay(500);
	//str = String(voltage);
	speakint(voltage);
	delay(500);
	speak("volts");
	delay(500);
	speak("Test 2 Ultrasonic Test");
	int pings = ping();
	speak("Current Distance from closest object is ");
	delay(500);
	//str = String(pings);
	speakint(pings);
	delay(500);
	speak(" inches.");
	delay(500);
	speak("Test 3 LEDS");
	delay(500);
	speak("I will toggle all the leds, on and off.");
	delay(500);
	led(0);
	delay(800);
	led(1);
	delay(800);
	led(2);
	delay(800);
	led(3);
	delay(800);
	led(4);
	delay(800);
	led(5);
	delay(800);
	led(6);
	delay(800);
	led(7);
	delay(800);
	led(0);
	delay(800);
	led(1);
	delay(800);
	led(2);
	delay(800);
	led(3);
	delay(800);
	led(4);
	delay(800);
	led(5);
	delay(800);
	led(6);
	delay(800);
	led(7);
	delay(800);
	speak("I will now do a Cyclon pattern with the LEDs 10 times.");
	cylon(10);
	delay(500);
	speak("Test 4 Drive Motor Forward");
	forward(1);
	delay(500);
	speak("Test 5 Drive Motor Reverse");
	reverse(1);
	delay(500);
	speak("Test 6 Turn left 90 degrees");
	left(90);
	delay(500);
	forward(1);
	delay(500);
	speak("And back.");
	right(90);
	delay(500);
	reverse(1);
	delay(500);
	speak("Test 7 Turn Right 90 degrees");
	right(90);
	delay(500);
	forward(1);
	delay(500);
	speak("And back.");
	left(90);
	delay(500);
	reverse(1);
	delay(500);
	speak("Test 8 Read Light Sensor");
	int lights = light();
	delay(500);
	speak("Current light reading is ");
	delay(500);
	//str = String(lights);
	speakint(lights);
	delay(500);
	speak("Test 9 Can I hear a Sound? ");
	delay(500);
	speak("Please make a sound in the next 15 seconds.");
	delay(500);
	int listens = listen();
	if (listens == 1) {speak ("Sound was heard."); } else {
		speak("I didn't hear a thing.");
	}
	delay(500);
	speak("Test 10 I will sing to you. ");
	delay(500);
	singdaisy();
	delay(500);
	speak("And one more song. ");
	delay(500);
	singhbd();
	delay(500);
	speak("This conculdes my tests, thank you!");
	delay(500);
}

void cylon(int times) {
   digitalWrite(led0, 1);
   digitalWrite(led1, 1);
   digitalWrite(led2, 1);
   digitalWrite(led3, 1);
   digitalWrite(led4, 1);
   digitalWrite(led5, 1);
   digitalWrite(led6, 1);
   digitalWrite(led7, 1);
   for (int i = 1; i < times; i++){
   	digitalWrite(led0, 0);
   	delay(100);
   	digitalWrite(led0, 1);
   	digitalWrite(led1, 0);
   	delay(100);
   	digitalWrite(led1, 1);
   	digitalWrite(led2, 0);
   	delay(100);
   	digitalWrite(led2, 1);
   	digitalWrite(led3, 0);
   	delay(100);
   	digitalWrite(led3, 1);
   	digitalWrite(led4, 0);
   	delay(100);
   	digitalWrite(led4, 1);
   	digitalWrite(led5, 0);
   	delay(100);
   	digitalWrite(led5, 1);
   	digitalWrite(led6, 0);
   	delay(100);
   	digitalWrite(led6, 1);
   	digitalWrite(led7, 0);
   	delay(100);
   	digitalWrite(led7, 1);
   	digitalWrite(led6, 0);
   	delay(100);
   	digitalWrite(led6, 1);
   	digitalWrite(led5, 0);
   	delay(100);
   	digitalWrite(led5, 1);
   	digitalWrite(led4, 0);
   	delay(100);
   	digitalWrite(led4, 1);
   	digitalWrite(led3, 0);
   	delay(100);
   	digitalWrite(led3, 1);
   	digitalWrite(led2, 0);
   	delay(100);
   	digitalWrite(led2, 1);
   	digitalWrite(led1, 0);
   	delay(100);
   	digitalWrite(led1, 1);
   	
   }
   digitalWrite(led0, state0);
   digitalWrite(led1, state1);
   digitalWrite(led2, state2);
   digitalWrite(led3, state3);
   digitalWrite(led4, state4);
   digitalWrite(led5, state5);
   digitalWrite(led6, state6);
   digitalWrite(led7, state7);
   Serial.println(">");
}

void credit() {
	
	speak("I am a Heath Kit Hero Junior Robot, I came online");
	delay(500);
	speak("on March 9th 2015, at 6:09 P.M. Eastern Time!");
	delay(500);
	speak("I was restored by LeRoy Miller, using modern electronic hardware.");
	delay(500);
	
}
