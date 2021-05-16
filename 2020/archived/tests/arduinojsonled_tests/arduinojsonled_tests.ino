#include <ArduinoJson.h>

String inputString = "{\"cmd\":\"MQTT-PUB\",\"topic\":\"sub/topic/led\",\"message\":[1,2,03,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24]}";

//String states[9];
int states[9][3];
int count;

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

count = 0;
for (int j=0; j<8; j++) {

  //Serial.print("Count: "); Serial.println(count);
  states[j][0] = root["message"][count];
  states[j][1] = root["message"][count+1];
  states[j][2] = root["message"][count+2];
  count=count+3;
   
}

  Serial.print("Topic: "); Serial.println(topic);

  for (int i=0; i<8; i++) {
    Serial.print(states[i][0]); Serial.print(","); Serial.print(states[i][1]); Serial.print(","); Serial.println(states[i][2]);
  }
}

void loop() {
  
}
