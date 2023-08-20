

#include <iostream>
#include <memory>
#include <string>

#include <grpcpp/grpcpp.h>

#ifdef BAZEL_BUILD
#include "../proto/unaryMessage.grpc.pb.h"
#else
#include "../proto/unaryMessage.grpc.pb.h"
#endif

using grpc::Channel;
using grpc::ClientContext;
using grpc::Status;
using message::MessageRequest;
using message::MessageReply;
using message::Message;

class MessageClient {
public:
    MessageClient(std::shared_ptr<Channel> channel)
        : stub_(Message::NewStub(channel)) {}

    std::string SendMessage(const std::string& name, const std::string& message) {
        MessageRequest request;
        request.set_name(name);
        request.set_message(message);

        MessageReply reply;

        ClientContext context;

        Status status = stub_->SendMessage(&context, request, &reply);


        return reply.message();

    }

private:
    std::unique_ptr<Message::Stub> stub_;
};

int main(int argc, char** argv) {

    std::cout << "client started..." << std::endl;

    std::string target_str;
    target_str = "localhost:50051";
    MessageClient messageClient(grpc::CreateChannel(
        target_str, grpc::InsecureChannelCredentials()));

    std::string name("name");
    std::string message("message");
    std::string reply = messageClient.SendMessage(name, message);
    std::cout << "Client Received: " << reply << std::endl;

    std::string a;
    std::cin >> a;

    return 0;
}