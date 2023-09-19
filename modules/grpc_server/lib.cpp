//
// Created by Panda on 2021/6/21.
//

#include "lib.h"

grpc::Status HelloServiceImpl::SayHello(grpc::ServerContext* context, const simple::HelloRequest* request,
                                        simple::HelloReply* reply) {
    std::string prefix = "Hello, ";
    reply->set_message(prefix + request->name());
    return grpc::Status::OK;
}


void RunServer() {
    std::string server_address = "0.0.0.0:50051";
    HelloServiceImpl service;

    grpc::ServerBuilder builder;
    builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
    builder.RegisterService(&service);

    std::unique_ptr<grpc::Server> server(builder.BuildAndStart());
    std::cout << "Server listening on " << server_address << std::endl;
    server->Wait();
}
