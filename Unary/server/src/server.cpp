
#include <iostream>
#include <memory>
#include <string>

#include <grpc++/grpc++.h>

#include "../proto/unaryMessage.pb.h"
#include "../proto/unaryMessage.grpc.pb.h"

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;
using message::MessageRequest;
using message::MessageReply;
using message::Message;

// Logic and data behind the server's behavior.
class GreeterServiceImpl final : public Message::Service {
    Status SendMessage(ServerContext* context, const MessageRequest* request,
        MessageReply* reply) override {
        std::cout << request->name() << " Received Message: " << request->message() << std::endl;
        std::string prefix = "  Message received successfully";
        reply->set_message(prefix + request->name());
        return Status::OK;
    }
};

void RunServer() {
    std::cout << "Server started..." << std::endl;

    std::string server_address("localhost:50051");
    GreeterServiceImpl service;

    ServerBuilder builder;

    builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());

    builder.RegisterService(&service);

    std::unique_ptr<Server> server(builder.BuildAndStart());
    std::cout << "Server listening on " << server_address << std::endl;

    server->Wait();
}

int main(int argc, char** argv) {
    RunServer();

    return 0;
}
