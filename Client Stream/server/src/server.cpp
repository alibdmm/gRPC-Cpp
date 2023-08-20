#include <iostream>
#include <memory>
#include <string>
#include <grpcpp/grpcpp.h>
#include <grpcpp/server.h>
#include <grpcpp/server_builder.h>
#include <grpcpp/server_context.h>
#include "ClientStream.grpc.pb.h"  // .proto dosyasýndan üretilen header dosyasý

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;
using C_Stream::ServiceStream;
using C_Stream::StreamRequest;
using C_Stream::StreamReply;

class StreamServiceImpl final : public ServiceStream::Service {
    Status SendMessage(ServerContext* context, grpc::ServerReader<StreamRequest>* reader, StreamReply* reply) override {
        StreamRequest request;
        uint64_t totalVal = 0;

        while (reader->Read(&request)) {
            std::cout << "Received message: " << request.message() << std::endl;
            totalVal ++;  // Just an example of processing
        }

        reply->set_val(totalVal);
        reply->set_message("Messages processed on the server.");

        return Status::OK;
    }
};

void RunServer() {
    std::string server_address("0.0.0.0:50051");
    StreamServiceImpl service;

    ServerBuilder builder;
    builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
    builder.RegisterService(&service);

    std::unique_ptr<Server> server(builder.BuildAndStart());
    std::cout << "Server listening on " << server_address << std::endl;
    server->Wait();
}

int main() {
    RunServer();
    return 0;
}
