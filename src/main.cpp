#ifndef WIFI_SSID
#define WIFI_SSID "DEFAULT_SSID"
#endif

#ifndef WIFI_PSK
#define WIFI_PSK  "DEFAULT_PSK"
#endif

#include <Arduino.h>
#include <SPIFFS.h>
#include <WiFi.h>
#include <functional>

#include <HTTPServer.hpp>
#include <HTTPRequest.hpp>
#include <HTTPResponse.hpp>
#include <WebServer.h>
#include "Router.hpp"
#include "API.hpp"
#include "Static.hpp"

using namespace httpsserver;

HTTPServer server = HTTPServer();

void setup() {
  Serial.begin(115200);
  SPIFFS.begin(true);

  Serial.println("Setting up WiFi");
  WiFi.begin(WIFI_SSID, WIFI_PSK);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.print("Connected. IP=");
  Serial.println(WiFi.localIP());

  Router router = Router(&server);

  router.get("/api", &getAll);
  router.fallback(&getStatic);

  Serial.println("Starting HTTP server...");
  server.start();
  if (server.isRunning()) {
    Serial.println("Server ready.");
  }
}

void loop() {
  server.loop();

  delay(1);
}