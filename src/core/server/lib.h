#include <httplib.h>
#include <unordered_set>
#include <string>
#include <mutex>

class HttpServer {

private:
    // httplib 库中的 Server 类
    httplib::Server svr;
    // 用于记录已注册的路由
    std::unordered_set<std::string> registeredPaths;
    // 多线程中 用于保护 registeredPaths 的互斥量  
    std::mutex mtx;

    HttpServer();

    // 禁止拷贝构造和赋值
    HttpServer(const HttpServer&) = delete;
    HttpServer& operator=(const HttpServer&) = delete;

public:
    enum HttpMethod {
        GET,
        POST,
        PUT,
        DELETE
        // ...可以继续添加其他HTTP方法
    };

    static HttpServer& getInstance();

    bool addRoute(HttpMethod method, const char* path, const httplib::Server::Handler& handler );
    void listen(const char* host, int port);

};
