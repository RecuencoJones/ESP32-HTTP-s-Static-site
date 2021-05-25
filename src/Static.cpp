#include <FS.h>
#include <SPIFFS.h>
#include "Static.hpp"

#define DIR_PUBLIC "/w"

String getContentType(String filename) {
    if (filename.endsWith(".html")) {
        return "text/html";
    } else if (filename.endsWith(".js")) {
        return "text/javascript";
    } else if (filename.endsWith(".css")) {
        return "text/css";
    } else {
        return "application/octet-stream";
    }
}

// Implementation reference
// https://github.com/fhessel/esp32_https_server/blob/de1876cf6fe717cf236ad6603a97e88f22e38d62/examples/REST-API/REST-API.ino#L305
void getStatic(HTTPRequest * req, HTTPResponse * res) {
    req->discardRequestBody();

    if (req->getMethod() != "GET") {
        res->setStatusCode(405);
        res->setStatusText("Method not allowed");
        res->println("405 Method not allowed");
        return;
    }

    String filename = String(DIR_PUBLIC) + req->getRequestString().c_str();

    if (filename.endsWith("/")) {
        filename += "index.html";
    }

    Serial.println(filename);

    if (!SPIFFS.exists(filename.c_str())) {
        res->setStatusCode(404);
        res->setStatusText("Not Found");
        res->println("404 Not Found");
        return;
    }

    File file = SPIFFS.open(filename.c_str());

    Serial.println(file.name());

    res->setStatusCode(200);
    res->setStatusText("Ok");
    res->setHeader("Content-Length", httpsserver::intToString(file.size()));
    res->setHeader("Content-Type", getContentType(filename).c_str());

    uint8_t buffer[256];
    size_t length = 0;
    do {
      length = file.read(buffer, 256);
      res->write(buffer, length);
    } while (length > 0);

    file.close();
};