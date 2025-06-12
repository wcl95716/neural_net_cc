//
// Created by Panda on 2023/9/18.
//

#include "lib.h"
using std::swap;

// 构造函数实现
HttpServer::HttpServer() {
    svr.Get("/hi", [](const httplib::Request&, httplib::Response& res) {
        res.set_content("Hello World!", "text/plain");
    });
}

// 获取实例方法实现
HttpServer& HttpServer::getInstance() {
    static HttpServer instance;
    return instance;
}

// 添加路由方法实现
bool HttpServer::addRoute(HttpMethod method, const char* path, const httplib::Server::Handler& handler) {
    std::unique_lock<std::mutex> lock(mtx);

    if (registeredPaths.find(path) != registeredPaths.end()) {
        return false;
    }

    switch (method) {
        case GET:
            svr.Get(path, handler);
            break;
        case POST:
            svr.Post(path, handler);
            break;
        case PUT:
            svr.Put(path, handler);
            break;
        case DELETE:
            svr.Delete(path, handler);
            break;
        // ...可以为其他HTTP方法添加相应的case
        default:
            return false;  // 不支持的HTTP方法
    }

    registeredPaths.insert(path);
    return true;
}

// 监听方法实现
void HttpServer::listen(const char* host, int port) {
    svr.listen(host, port);
}
