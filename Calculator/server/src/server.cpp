
#include <iostream>
#include <memory>
#include <string>

#include <grpc++/grpc++.h>

#include "Calculator.pb.h"
#include "Calculator.grpc.pb.h"

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;
using calculatorPackage::CalculatorRequest;
using calculatorPackage::CalculatorReply;
using calculatorPackage::calculatorService;

class GreeterServiceImpl final : public calculatorService::Service {
	Status Add(ServerContext* context, const CalculatorRequest* request, CalculatorReply* reply) {
		std::cout << "called the add method..." << std::endl;
		std::cout << "number1: " << request->number1() << std::endl << "number2: " << request->number2() << std::endl;
		double reply_dbl = request->number1() + request->number2();
		std::cout << "response ansver: " << reply_dbl << std::endl;

		reply->set_result(reply_dbl);

  		return Status::OK;
	}
    Status Substract(ServerContext* context, const CalculatorRequest* request, CalculatorReply* reply) {
        std::cout << "called the substract method..." << std::endl;
        std::cout << "number1: " << request->number1() << std::endl << "number2: " << request->number2() << std::endl;
        double reply_dbl = request->number1() - request->number2();
        std::cout << "response ansver: " << reply_dbl << std::endl;

        reply->set_result(reply_dbl);

        return Status::OK;
    }
    Status Multiply(ServerContext* context, const CalculatorRequest* request, CalculatorReply* reply) {
        std::cout << "called the multiply method..." << std::endl;
        std::cout << "number1: " << request->number1() << std::endl << "number2: " << request->number2() << std::endl;
        double reply_dbl = request->number1() * request->number2();
        std::cout << "response ansver: " << reply_dbl << std::endl;

        reply->set_result(reply_dbl);

        return Status::OK;
    }
    Status Divide(ServerContext* context, const CalculatorRequest* request, CalculatorReply* reply) {
        std::cout << "called the divide method..." << std::endl;
        std::cout << "number1: " << request->number1() << std::endl << "number2: " << request->number2() << std::endl;
        double reply_dbl = request->number1() / request->number2();
        std::cout << "response ansver: " << reply_dbl << std::endl;

        reply->set_result(reply_dbl);

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
