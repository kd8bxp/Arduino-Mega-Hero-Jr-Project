/*
Copyright (c) 2019 LeRoy Miller

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses>

If you find this or any of my projects useful or enjoyable please support me.  
Anything I do get goes to buy more parts and make more/better projects.  
https://www.patreon.com/kd8bxp  
https://ko-fi.com/lfmiller  

https://github.com/kd8bxp
https://www.youtube.com/channel/UCP6Vh4hfyJF288MTaRAF36w  
https://kd8bxp.blogspot.com/  
*/

#include <Keypad.h>
int led0 = 46;
int led1 = 44;
int led2 = 42;
int led3 = 40;
int led4 = 38;
int led5 = 36;
int led6 = 34;
int led7 = 32;
int state0 = 1;
int state1 = 1;
int state2 = 1;
int state3 = 1;
int state4 = 1;
int state5 = 1;
int state6 = 1;
int state7 = 1;

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
void setup() {
  Serial.begin(9600);
pinMode(led0, OUTPUT);
   pinMode(led1, OUTPUT);
   pinMode(led2, OUTPUT);
   pinMode(led3, OUTPUT);
   pinMode(led4, OUTPUT);
   pinMode(led5, OUTPUT);
   pinMode(led6, OUTPUT);
   pinMode(led7, OUTPUT);
   
   digitalWrite(led0, 1);
   digitalWrite(led1, 1);
   digitalWrite(led2, 1);
   digitalWrite(led3, 1);
   digitalWrite(led4, 1);
   digitalWrite(led5, 1);
   digitalWrite(led6, 1);
   digitalWrite(led7, 1);
   
}

void loop() {
  Serial.println("cylon LED testing...");
   cylon(1); //was 5
    //led(0);
 int customKey = key();
 Serial.print("Returned: "); Serial.println(customKey);
 //delay(10);
}

int key() {
Serial.print("Hit Key");
delay(100);
//int tempState = state0;
for (uint16_t waiting=0; waiting <= 1000; waiting++) {
//while (key <= 0) {
//Serial.println(waiting);

 char key = kpd.getKey();
    
    if(key)  // Check for a valid key.
  {
    switch (key)
    {
        default:
        Serial.println(" ");
    Serial.print("Key Pressed: ");
    Serial.println(key);
if (key-48>=17) {return (key-55);} else { return(key-48);}
    }
}
//tempState = !tempState;
//digitalWrite(led0, tempState);
//cylon(1);
delay(5);
}
return (-48);
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

void cylon(int times) {
   digitalWrite(led0, 1);
   digitalWrite(led1, 1);
   digitalWrite(led2, 1);
   digitalWrite(led3, 1);
   digitalWrite(led4, 1);
   digitalWrite(led5, 1);
   digitalWrite(led6, 1);
   digitalWrite(led7, 1);
   for (int i = 0; i < times; i++){
     digitalWrite(led0, 0);
    delay(75);
    digitalWrite(led0, 1);
    digitalWrite(led1, 0);
    delay(75);
    digitalWrite(led1, 1);
    digitalWrite(led2, 0);
    delay(75);
    digitalWrite(led2, 1);
    digitalWrite(led3, 0);
    delay(75);
    digitalWrite(led3, 1);
    digitalWrite(led4, 0);
    delay(75);
    digitalWrite(led4, 1);
    digitalWrite(led5, 0);
    delay(75);
    digitalWrite(led5, 1);
    digitalWrite(led6, 0);
    delay(75);
    digitalWrite(led6, 1);
    digitalWrite(led7, 0);
    delay(75);
    digitalWrite(led7, 1);
    digitalWrite(led6, 0);
    delay(75);
    digitalWrite(led6, 1);
    digitalWrite(led5, 0);
    delay(75);
    digitalWrite(led5, 1);
    digitalWrite(led4, 0);
    delay(75);
    digitalWrite(led4, 1);
    digitalWrite(led3, 0);
    delay(75);
    digitalWrite(led3, 1);
    digitalWrite(led2, 0);
    delay(75);
    digitalWrite(led2, 1);
    digitalWrite(led1, 0);
    delay(75);
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
   
}
