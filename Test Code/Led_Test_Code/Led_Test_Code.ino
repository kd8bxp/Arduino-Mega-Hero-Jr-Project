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
 
int led0 = 22;
int led1 = 24;
int led2 = 26;
int led3 = 28;
int led4 = 30;
int led5 = 32;
int led6 = 34;
int led7 = 36;


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
	
 digitalWrite(led0, HIGH);
 	digitalWrite(led1, HIGH);
 	digitalWrite(led2, HIGH);
 	digitalWrite(led3, HIGH);
 	digitalWrite(led4, HIGH);
 	digitalWrite(led5, HIGH);
 	digitalWrite(led6, HIGH);
 	digitalWrite(led7, HIGH);
 	delay(1000);

 	digitalWrite(led0, LOW);
 	digitalWrite(led1, LOW);
 	digitalWrite(led2, LOW);
 	digitalWrite(led3, LOW);
 	digitalWrite(led4, LOW);
 	digitalWrite(led5, LOW);
 	digitalWrite(led6, LOW);
 	digitalWrite(led7, LOW);
 	delay(1000);

 	}

