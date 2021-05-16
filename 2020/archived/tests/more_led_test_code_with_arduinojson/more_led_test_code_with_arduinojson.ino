#include <ArduinoJson.h>

//cheerlight colors
/*
 * RED 256, 00, 00
 * GREEN 00, 256, 00
 * BLUE 00, 00, 256
 * CYAN 00FFFF
 * WHITE FFFFFF
 * OLDLACE FDF5E6
 * PURPLE 800080
 * MAGENTA FF00FF
 * YELLOW FFFF00
 * ORANGE FFA500
 * PINK FFC0CB
 * 
 */

String inputString = "{\"cmd\":\"MQTT-PUB\",\"topic\":\"sub/topic/led\",\"message\":[red,green,blue,magenta,off,yellow,purple,cyan]}";

String states[9];
//int states[9][3];
//int count;

void setup() {
  Serial.begin(115200);
  StaticJsonBuffer<250> jsonBuffer;
char json[inputString.length()+1];

inputString.toCharArray(json, inputString.length()+1);
Serial.println(json);
  JsonObject& root = jsonBuffer.parseObject(json);
  // Test if parsing succeeds.
  if (!root.success()) {
    Serial.println("parseObject() failed");
    return;
  }

const char* topic = root["topic"];

//count = 0;
for (int j=0; j<8; j++) {

states[j] = root["message"][j].as<String>();
  //Serial.print("Count: "); Serial.println(count);
  //states[j][0] = root["message"][count];
  //states[j][1] = root["message"][count+1];
  //states[j][2] = root["message"][count+2];
  //count=count+3;
   
}

  Serial.print("Topic: "); Serial.println(topic);

  for (int i=0; i<8; i++) {

   if (states[i] == "red") {
  Serial.println("Red");
 } else
 if (states[i] == "green") {
  Serial.println("Green");
 } else
 if (states[i] == "blue") {
  Serial.println("Blue");
 } else
 if (states[i] == "cyan") {
  Serial.println("Cyan");
 } else
 if (states[i] == "white") {
  Serial.println("White");
 } else
 if (states[i] == "oldlace") {
  Serial.println("Oldlace");
 } else
 if (states[i] == "purple") {
  Serial.println("Purple");
 } else
 if (states[i] == "magenta") {
  Serial.println("Magenta");
 } else
 if (states[i] == "yellow") {
  Serial.println("Yellow");
 } else
 if (states[i] == "orange") {
  Serial.println("Orange");
 } else
 if (states[i] == "pink") {
  Serial.println("Pink");
 } else
 if (states[i] == "off") {
  Serial.println("Off");
 } else 
 {Serial.println("Unknown"); }
 //strip.show();
 }
}

void loop() {
  
}
