
#include <iostream>
#include <memory>
#include <string>

#include <grpc++/grpc++.h>

#include "Calculator.pb.h"
#include "Calculator.grpc.pb.h"

using grpc::Channel;
using grpc::ClientContext;
using grpc::Status;
using calculatorPackage::CalculatorRequest;
using calculatorPackage::CalculatorReply;
using calculatorPackage::calculatorService;

class CalculatorClient {
private:
	std::unique_ptr<calculatorService::Stub> stub_;
public: 
	CalculatorRequest request;

	CalculatorClient(std::shared_ptr<Channel> channel)
		: stub_(calculatorService::NewStub(channel)){}

	void prepareRequest(const double& number1, const double& number2) {
		request.set_number1(number1);
		request.set_number2(number2);
	}

	double Add() {
		CalculatorReply reply;
		ClientContext context;
		Status status = stub_->Add(&context, request, &reply);
		return reply.result();
	}

	double Substract() {
		CalculatorReply reply;
		ClientContext context;
		Status status = stub_->Substract(&context, request, &reply);
		return reply.result();
	}

	double Multiply() {
		CalculatorReply reply;
		ClientContext context;
		Status status = stub_->Multiply(&context, request, &reply);
		return reply.result();
	}

	double Divide() {
		CalculatorReply reply;
		ClientContext context;
		Status status = stub_->Divide(&context, request, &reply);
		return reply.result();
	}
};

int main(int argc, char** argv) {
	std::cout << "client started..." << std::endl;

	std::string target_str = "localhost:50051";
	CalculatorClient calculatorClient(grpc::CreateChannel(
		target_str, grpc::InsecureChannelCredentials()));

	//std::cout << "Client Received: " << calculatorClient.Add(3, 4) << std::endl;

	while (true) {
		std::cout << "\nSelect the operation: " << std::endl;
		int selection_type;
		std::cout << "Add -> 1" << std::endl << "Substract -> 2" << std::endl << "Multiply -> 3" << std::endl << "Divide -> 4" << std::endl;
		std::cout << "Select: ";
		std::cin >> selection_type;

		std::cout << "You have to enter two number..." << std::endl;

		double number1;
		double number2;

		std::cout << "Number1: ";
		std::cin >> number1;
		std::cout << "Number2: ";
		std::cin >> number2;

		std::cout << "Client Received: ";

		calculatorClient.prepareRequest(number1, number2);
		switch (selection_type)
		{
		case 1:
			std::cout << calculatorClient.Add() << std::endl;
			break;
		case 2:
			std::cout << calculatorClient.Substract() << std::endl;
			break;
		case 3:
			std::cout << calculatorClient.Multiply() << std::endl;
			break;
		case 4:
			std::cout << calculatorClient.Divide() << std::endl;
			break;
		default:
			break;
		}
		 
	}

	return 0;
}