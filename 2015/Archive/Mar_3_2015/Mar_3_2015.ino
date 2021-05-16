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
backward(distance) - move backward
left() - turn to the left 
right() - turn to the right
light() - read the light sensor
volt() - check the voltage levels for the drive battery
test() - don't know yet
rinit() - reset Arduino Mega board to power on conditions
listen() - returns when it hears a sound (Signal Wire hooks up to pin 53 on the Mega. Sound sensor works at 5v)

*** left() and right() will turn the wheel about 15 degrees at a time, with a max of 90 degree, and needs to be called the same number of times in both directions to set the wheel back to the center point, there is no test for this yet
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

void setup() 
{   
   
Serial.begin(9600);   
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


}                  

void listen() {
	delay(1000);
	while(digitalRead(53) != 0) {
		delay(100);
	}
	Serial.println("Sound Detected! Return");
	
	/*	sound = digitalRead(53);
	if (sound == 0) { 
		Serial.print("Sound detected! :");
		Serial.println(count);
		count = count + 1;
		delay(100);
	}
	*/
}

void key() {

	delay(100);
	char key = kpd.getKey();

	Serial.println(key);
}

void ping() {
 unsigned int uS = sonar.ping(); // Send ping, get ping time in microseconds (uS).
   Serial.println(uS / US_ROUNDTRIP_IN); // Convert ping time to distance in cm and print result (0 = outside set distance range)
   
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

void backward(int distance) {
	digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    analogWrite(enA, 255);
    delay(1000*distance); //how long the motor should be left on
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
}

void left(int degree) {
	if (stepCount >= 600) {return;}
stepCount = stepCount + 100;
	 myStepper.step(100);
  
}

void right(int degree) {
	if (stepCount <= -600) {return;}
	stepCount = stepCount - 100;
myStepper.step(-100);

}

void light() {
	int photor = analogRead(lightPin);
	Serial.println(photor);
	delay(50);
}

void volt() {
float temp;       
val11=analogRead(1);
temp=val11/4;       
val11=(int)temp;       
val2=((val11)/10);
Serial.println(val2);          
}

void test() {
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

