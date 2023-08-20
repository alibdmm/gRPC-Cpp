#include <iostream>
#include <memory>
#include <string>

#include<grpcpp/grpcpp.h>

#include "ClientStream.grpc.pb.h"

using::grpc::Channel;
using::grpc::ClientContext;
using::grpc::Status;
using::grpc::ClientReader;
using::grpc::ClientWriter;
using::C_Stream::StreamRequest;
using::C_Stream::StreamReply;
using::C_Stream::ServiceStream;

class StreamClient {
private:
	std::unique_ptr<ServiceStream::Stub> stub;
    StreamReply reply;
public:
	StreamClient(std::shared_ptr<Channel> channel) : stub(ServiceStream::NewStub(channel)){}

    void SendMessageStream(const std::string message, int lenght)    {
        ClientContext context;
        std::shared_ptr<grpc::ClientWriter<StreamRequest>> writer(stub->SendMessage(&context, &reply));


        for (int i = 0; i < lenght;  i++) {
            StreamRequest request;
            request.set_message(message + " " + std::to_string(i + 1));
            writer->Write(request);
        }
        writer->WritesDone();

        Status status = writer->Finish();

        if (status.ok()) {
            std::cout << "Stream reply: val=" << reply.val() << ", message=" << reply.message() << std::endl;
        }
        else {
            std::cout << "RPC failed: " << status.error_message() << std::endl;
        }
    }
};

int main() {
    StreamClient client(grpc::CreateChannel("localhost:50051", grpc::InsecureChannelCredentials()));
    
    int countNumber;
    while (true)
    {
        std::cout << "Enter the loop time: ";
        std::cin >> countNumber;
        client.SendMessageStream("Hello, gRPC Stream!", countNumber);
    }
}