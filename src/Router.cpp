#include "Router.hpp"

Router::Router(HTTPServer * server) {
    _server = server;
};

void Router::get(const std::string path, const HTTPSCallbackFunction * callback) {
    _server->registerNode(new ResourceNode(path, "GET", callback));
};

void Router::put(const std::string path, const HTTPSCallbackFunction * callback) {
    _server->registerNode(new ResourceNode(path, "PUT", callback));
};

void Router::post(const std::string path, const HTTPSCallbackFunction * callback) {
    _server->registerNode(new ResourceNode(path, "POST", callback));
};

void Router::del(const std::string path, const HTTPSCallbackFunction * callback) {
    _server->registerNode(new ResourceNode(path, "DELETE", callback));
};

void Router::fallback(const HTTPSCallbackFunction * callback) {
    _server->setDefaultNode(new ResourceNode("", "", callback));
};