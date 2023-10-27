#include <ESP8266WiFi.h>

WiFiServer server(8080);

void init_wifi() {
  WiFi.begin("cj", "password");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(300);
  }
  Serial.printf("\nConncted IP Address: ");
  Serial.println(WiFi.localIP().toString());
  server.begin();
}

void setup() {
  Serial.begin(9600);
  init_wifi();
}

void loop() {
  WiFiClient client = server.available();
  if (!client) {
    return;
  }

  while (!client.available()) {
    delay(1);
  }

  String ret_msg = "10";

  client.println("HTTP/1.0 200 OK");
  client.println("Content-Type: text/html");
  client.println("");
  client.println(ret_msg);
  delay(1);
}