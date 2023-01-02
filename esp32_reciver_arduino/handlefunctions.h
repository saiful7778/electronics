void webpage(){server.send(200,"text/html", webpageCode);};

void notFound(){server.send(404, "text/html", erroeCode);};

void webSocketEvent(uint8_t num, WStype_t type, uint8_t * payload, size_t length) {
  switch (type) 
  {
    case WStype_DISCONNECTED:
      Serial.printf("[%u] Disconnected!\n", num);
      break;
    case WStype_CONNECTED: {
        IPAddress ip = webSocket.remoteIP(num);
        Serial.printf("[%u] Connected from %d.%d.%d.%d url: %s\n", num, ip[0], ip[1], ip[2], ip[3], payload);
      }
      break;
    case WStype_TEXT:
      Serial.printf("[%u] get Text: %s\n", num, payload);
      String message = String((char*)( payload));
      Serial.println(message);
     DynamicJsonDocument doc(200);
    // deserialize the data
    DeserializationError error = deserializeJson(doc, message);
    // parse the parameters we expect to receive (TO-DO: error handling)
      // Test if parsing succeeds.
  if (error) {
    Serial.print("deserializeJson() failed: ");
    Serial.println(error.c_str());
    return;
  }
  int relay1_status = doc["LED_1"];
  int relay2_status = doc["LED_2"];
  int relay3_status = doc["LED_3"];
  int relay4_status = doc["LED_4"];
  digitalWrite(relay_1, relay1_status);
  digitalWrite(relay_2, relay2_status);
  digitalWrite(relay_3, relay3_status);
  digitalWrite(relay_4, relay4_status);
  }
}

void sendData(){
  // JSON_Data = {"temp":t,"hum":h}
  String JSON_Data = "{\"relay_1\":";
         JSON_Data += digitalRead(relay_1);
         JSON_Data += ",\"relay_2\":";
         JSON_Data += digitalRead(relay_2);
         JSON_Data += ",\"relay_3\":";
         JSON_Data += digitalRead(relay_3);
         JSON_Data += ",\"relay_4\":";
         JSON_Data += digitalRead(relay_4);
         JSON_Data += "}";
  Serial.println(JSON_Data);
  webSocket.broadcastTXT(JSON_Data);
}
