//MQTT Defines
#define SUB "\"cmd\":\"MQTT-SUB\""
#define PUB "\"cmd\":\"MQTT-PUB\""
#define TOPIC "\"topic\":"
#define MESSAGE "\"message\":"
#define PUBJOKE "\"topic\":\"joke\""
//#define PUBJOKE TOPIC"\"joke\""

void setup() {
 Serial.begin(115200);
 Serial.println("{"SUB",\"topic\":\"src/myTopic/blink\"}");
 //Serial.println("{"PUB","TOPIC"\"status\""MESSAGE"\"this is a message\"}");
 //Serial.println("{"PUB","PUBJOKE","MESSAGE"\"this is a message\"}");
}

void loop() {
  // put your main code here, to run repeatedly:
Serial.println("{"PUB","TOPIC"\"status\","MESSAGE"\"this is a message\"}");
//Serial.println("{\"cmd\":\"MQTT-PUB\",\"topic\":\"topic/status\",\"message\":\"this is a test.\"}");
delay(1000);
}
