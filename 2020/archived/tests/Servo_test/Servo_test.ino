
#include <Servo.h>

#define mapPos(a) map(a,0,180,65,122)
Servo steering;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos;    // variable to store the servo position

void setup() {
  steering.attach(4);  // attaches the servo on pin 4 to the servo object for hero jr
pos = map(90, 0, 180, 65, 122); //1st number is angle to goto 90 is center
    steering.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
 

}

void loop() {
 for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    steering.write(mapPos(pos));              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    steering.write(mapPos(pos));              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
}
