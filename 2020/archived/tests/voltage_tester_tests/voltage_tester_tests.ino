#define voltPin A1

//variables
float val11; 
float val2;

float voltage;

void setup() {
 Serial.begin(115200);
 pinMode(voltPin, INPUT);
// pinMode(lightPin, INPUT_PULLUP);
}

void loop() {
  Serial.println(volt());
  delay(1000);
}

float volt() {
float temp;       
val11=analogRead(voltPin);
temp=val11/4;       
val11=temp;       
val2=((val11)/10);
//Serial.print("val2: ");
//Serial.println(val2);
//Serial.print("val11: ");
//Serial.println(val11);
//Serial.print("temp: ");
//Serial.println(temp);
return(val2);

}
