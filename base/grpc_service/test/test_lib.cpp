#include <iostream>
#include <memory>
#include <string>
#include <grpcpp/grpcpp.h>
#include "proto_file.grpc.pb.h"

using grpc::Channel;
using grpc::ClientContext;
using grpc::Status;
using simple::HelloRequest;
using simple::HelloReply;
using simple::HelloService;

class HelloClient {
public:
    HelloClient(std::shared_ptr<Channel> channel)
            : stub_(HelloService::NewStub(channel)) {}

    std::string SayHello(const std::string& name) {
        HelloRequest request;
        request.set_name(name);

        HelloReply reply;
        ClientContext context;

        Status status = stub_->SayHello(&context, request, &reply);
        if (status.ok()) {
            return reply.message();
        } else {
            return "RPC failed.";
        }
    }

private:
    std::unique_ptr<HelloService::Stub> stub_;
};

int main() {
    std::string server_address = "localhost:50051";

    HelloClient client(grpc::CreateChannel(server_address, grpc::InsecureChannelCredentials()));

    std::string name = "Panda2";
    std::string response = client.SayHello(name);
    std::cout << "Received: " << response << std::endl;

    return 0;
}
