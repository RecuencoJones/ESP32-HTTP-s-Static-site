#include "API.hpp"

void getAll(HTTPRequest * req, HTTPResponse * res) {
    res->setHeader("Content-Type", "application/json");
    res->setStatusCode(200);
    res->setStatusText("Ok");
    res->println("{}");
};