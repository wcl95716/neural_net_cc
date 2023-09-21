#include <iostream>
#include "../lib.h"
#include "basic_head/lib.h"



int main(int argc, char **argv) {
    // 获取 HttpServer 的单例实例
    HttpServer& server = HttpServer::getInstance();
    // 添加自定义路由
    server.addRoute(HttpServer::GET, "/welcome", [](const httplib::Request&, httplib::Response& res) {
        res.set_content("Welcome to our server!", "text/plain");
    });

    server.addRoute(HttpServer::POST, "/data", [](const httplib::Request& req, httplib::Response& res) {
        // 假设POST数据中有一个名为"data"的字段
        std::string data = req.get_param_value("data");
        res.set_content("Received data: " + data, "text/plain");
    });
    
    // 添加路由，用于处理查询参数 
    // 例如：http://localhost:8080/query?name=John
    server.addRoute(HttpServer::GET, "/query", [](const httplib::Request& req, httplib::Response& res) {
        // 从查询参数中提取"name"的值
        std::string nameValue = req.get_param_value("name");

        if (!nameValue.empty()) {
            res.set_content("Received name: " + nameValue, "text/plain");
        } else {
            res.set_content("Name not provided.", "text/plain");
        }
    });

    // 开始监听 localhost 上的 8080 端口
    server.listen("127.0.0.1", 8080);

}
