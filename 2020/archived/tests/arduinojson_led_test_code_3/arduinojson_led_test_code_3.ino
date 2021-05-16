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

String inputString = "{\"cmd\":\"MQTT-PUB\",\"topic\":\"sub/topic/led\",\"message\":\"[red,green,blue,magenta,off,yellow,purple,cyan,]\"}";

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
char* cmd = root["message"];
//count = 0;
Serial.println(cmd);
for (int j=0; j<8; j++) {

states[j] = getValue(cmd, ',', j);
   
}
states[0] = removeBrace(states[0]);
//states[7] = getValue(cmd, ']', 1);

  Serial.print("Topic: "); Serial.println(topic);

  for (int i=0; i<8; i++) {
    Serial.println(states[i]); 
    }
}

void loop() {
  
}

//found at https://stackoverflow.com/questions/9072320/split-string-into-string-array
String getValue(String data, char separator, int index)
{
  int found = 0;
  int strIndex[] = {0, -1};
  int maxIndex = data.length()-1;

  for(int i=0; i<=maxIndex && found<=index; i++){
    if(data.charAt(i)==separator || i==maxIndex){
        found++;
        strIndex[0] = strIndex[1]+1;
        strIndex[1] = (i == maxIndex) ? i+1 : i;
    }
  }

  return found>index ? data.substring(strIndex[0], strIndex[1]) : "";
}


//based on code found at: https://stackoverflow.com/questions/40093116/remove-character-from-string-c-arduino-uno
String removeQuotes(String data) {
  char c;
    char no = '\"'; //character I want removed.

    for (int i=0; i<data.length();++i){
        c = data.charAt(i);
        if(c==no){
            data.remove(i, 1);
        }
    }
    return data;
}

String removeBrace(String data) {
  char c;
    char no = '['; //character I want removed.

    for (int i=0; i<data.length();++i){
        c = data.charAt(i);
        if(c==no){
            data.remove(i, 1);
        }
    }
    return data;
}
