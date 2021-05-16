//Only need ground and source, doesn't need power

#define lightPin A0 //analog pin0 for photoresistor

void setup() {
  Serial.begin(115200);
// pinMode(voltPin, INPUT);
 pinMode(lightPin, INPUT_PULLUP);
}

void loop() {

  //light();
  Serial.println(light());
  delay(1000);

}

int light() {
  int photor = analogRead(lightPin);
  //Serial.println(photor);
  delay(50);
  return(map(photor,0,1023,100,0)); 
  //this is a percentage, a low number is dark, 100% is bright light
}
