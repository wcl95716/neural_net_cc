//
// Created by Panda on 2021/6/21.
//

#ifndef CC_CODEBASE_BASE
#define CC_CODEBASE_BASE


#include <string>
#include <grpcpp/grpcpp.h>
#include "proto_file.grpc.pb.h"

class HelloServiceImpl final : public simple::HelloService::Service {
public:
    grpc::Status SayHello(grpc::ServerContext* context, const simple::HelloRequest* request,
                          simple::HelloReply* reply) override;
};

void RunServer();

#endif //CC_CODEBASE_LIB


