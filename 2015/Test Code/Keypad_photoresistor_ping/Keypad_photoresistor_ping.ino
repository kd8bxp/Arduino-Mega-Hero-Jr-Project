/*  
 Step 1) Keyboard Matrix off Hero Jr - working
 Digital Pins 4 to 11 are being used for the matrix
 Step 2) Ping Sensor added
 Digital Pins 12 and 13
 Step 3) IR Sensor for motion dection
 Not happy with how the PIR works so no code yet
 Step 4) Light Sensor
 Analog Pin 0 and 5v rail
 
 */
 
#include <Keypad.h>
#include <NewPing.h>

int lightPin = 0; //analog pin0 for photoresistor

#define TRIGGER_PIN  13  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     12  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 200 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm. About 78 Inches
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.

int led0 = 22;
int led1 = 24;
int led2 = 26;
int led3 = 28;
int led4 = 30;
int led5 = 32;
int led6 = 34;
int led7 = 36;

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

#define ledpin 13

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
}

void loop()
{


delay(100);

 char key = kpd.getKey();
 if(key)  // Check for a valid key.
  {
    switch (key)
    {
        default:
 		Serial.print("Key Pressed: ");
 		Serial.println(key);
        
    }
  }
 if (Serial.available()) {
 int readserial = Serial.read();
 //int readserial = Serial.read();
 	Serial.print("I recieved: ");
 	Serial.println(readserial);
 
 if (readserial == 49) {
 
 //This should be a function and should only be called when the BBB asks for a Distance
 unsigned int uS = sonar.ping(); // Send ping, get ping time in microseconds (uS).
  Serial.print("Ping: ");
  Serial.print(uS / US_ROUNDTRIP_IN); // Convert ping time to distance in cm and print result (0 = outside set distance range)
  Serial.println("in");
  
 }
 
 if (readserial == 50) {
 //This should be a function for the IR Sensor and should only be called for when asked from BBB
 /*
 CODE GOES HERE
 */
 }
 
 if (readserial == 51) {
 //This should be a function for the Light Sensor and only be called when the BBB wants the information
 int photor = analogRead(lightPin);
 Serial.print("Photo Resistor: ");
 Serial.println(photor);
  delay(50);
 		}
 	}
}
 
