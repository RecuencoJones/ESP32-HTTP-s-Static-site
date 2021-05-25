#include <string>
#include <HTTPServer.hpp>

using namespace httpsserver;

class Router {
    public:
        Router(HTTPServer * server);
        void get(const std::string path, const HTTPSCallbackFunction * callback);
        void put(const std::string path, const HTTPSCallbackFunction * callback);
        void post(const std::string path, const HTTPSCallbackFunction * callback);
        void del(const std::string path, const HTTPSCallbackFunction * callback);
        void fallback(const HTTPSCallbackFunction * callback);
    private:
        HTTPServer * _server;
};