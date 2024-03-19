#include <ArduinoJson.h>

JsonDocument doc;
char jsonOut[128];

void setup(){
  Serial.begin(115200);
  pinMode(D3, OUTPUT);
   pinMode(D5, OUTPUT);
    pinMode(D6, OUTPUT);
}

void loop(){
  CreateJson();
  int ldr_value = analogRead(A0);
  Serial.println(ldr_value);
  delay(200);

  if (ldr_value < 500){
  digitalWrite(D3, HIGH);
   delay(500);
   digitalWrite(D3, LOW);
   digitalWrite(D5, HIGH);
   delay(200);
   digitalWrite(D5, LOW);
   digitalWrite(D6, HIGH);
   delay(100);
   digitalWrite(D6, LOW);
  
    }
}

void CreateJson(){
  doc["licht"] = "300";
  doc["licht2"] = "450";

  serializeJson(doc, jsonOut);

  serializeJson(doc, Serial);
}
