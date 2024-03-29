// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: Calculator.proto

#include "Calculator.pb.h"
#include "Calculator.grpc.pb.h"

#include <functional>
#include <grpcpp/support/async_stream.h>
#include <grpcpp/support/async_unary_call.h>
#include <grpcpp/impl/channel_interface.h>
#include <grpcpp/impl/client_unary_call.h>
#include <grpcpp/support/client_callback.h>
#include <grpcpp/support/message_allocator.h>
#include <grpcpp/support/method_handler.h>
#include <grpcpp/impl/rpc_service_method.h>
#include <grpcpp/support/server_callback.h>
#include <grpcpp/impl/codegen/server_callback_handlers.h>
#include <grpcpp/server_context.h>
#include <grpcpp/impl/service_type.h>
#include <grpcpp/support/sync_stream.h>
namespace calculatorPackage {

static const char* calculatorService_method_names[] = {
  "/calculatorPackage.calculatorService/Add",
  "/calculatorPackage.calculatorService/Substract",
  "/calculatorPackage.calculatorService/Multiply",
  "/calculatorPackage.calculatorService/Divide",
};

std::unique_ptr< calculatorService::Stub> calculatorService::NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options) {
  (void)options;
  std::unique_ptr< calculatorService::Stub> stub(new calculatorService::Stub(channel, options));
  return stub;
}

calculatorService::Stub::Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options)
  : channel_(channel), rpcmethod_Add_(calculatorService_method_names[0], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_Substract_(calculatorService_method_names[1], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_Multiply_(calculatorService_method_names[2], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_Divide_(calculatorService_method_names[3], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  {}

::grpc::Status calculatorService::Stub::Add(::grpc::ClientContext* context, const ::calculatorPackage::CalculatorRequest& request, ::calculatorPackage::CalculatorReply* response) {
  return ::grpc::internal::BlockingUnaryCall< ::calculatorPackage::CalculatorRequest, ::calculatorPackage::CalculatorReply, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_Add_, context, request, response);
}

void calculatorService::Stub::async::Add(::grpc::ClientContext* context, const ::calculatorPackage::CalculatorRequest* request, ::calculatorPackage::CalculatorReply* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::calculatorPackage::CalculatorRequest, ::calculatorPackage::CalculatorReply, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_Add_, context, request, response, std::move(f));
}

void calculatorService::Stub::async::Add(::grpc::ClientContext* context, const ::calculatorPackage::CalculatorRequest* request, ::calculatorPackage::CalculatorReply* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_Add_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::calculatorPackage::CalculatorReply>* calculatorService::Stub::PrepareAsyncAddRaw(::grpc::ClientContext* context, const ::calculatorPackage::CalculatorRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::calculatorPackage::CalculatorReply, ::calculatorPackage::CalculatorRequest, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_Add_, context, request);
}

::grpc::ClientAsyncResponseReader< ::calculatorPackage::CalculatorReply>* calculatorService::Stub::AsyncAddRaw(::grpc::ClientContext* context, const ::calculatorPackage::CalculatorRequest& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncAddRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status calculatorService::Stub::Substract(::grpc::ClientContext* context, const ::calculatorPackage::CalculatorRequest& request, ::calculatorPackage::CalculatorReply* response) {
  return ::grpc::internal::BlockingUnaryCall< ::calculatorPackage::CalculatorRequest, ::calculatorPackage::CalculatorReply, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_Substract_, context, request, response);
}

void calculatorService::Stub::async::Substract(::grpc::ClientContext* context, const ::calculatorPackage::CalculatorRequest* request, ::calculatorPackage::CalculatorReply* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::calculatorPackage::CalculatorRequest, ::calculatorPackage::CalculatorReply, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_Substract_, context, request, response, std::move(f));
}

void calculatorService::Stub::async::Substract(::grpc::ClientContext* context, const ::calculatorPackage::CalculatorRequest* request, ::calculatorPackage::CalculatorReply* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_Substract_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::calculatorPackage::CalculatorReply>* calculatorService::Stub::PrepareAsyncSubstractRaw(::grpc::ClientContext* context, const ::calculatorPackage::CalculatorRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::calculatorPackage::CalculatorReply, ::calculatorPackage::CalculatorRequest, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_Substract_, context, request);
}

::grpc::ClientAsyncResponseReader< ::calculatorPackage::CalculatorReply>* calculatorService::Stub::AsyncSubstractRaw(::grpc::ClientContext* context, const ::calculatorPackage::CalculatorRequest& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncSubstractRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status calculatorService::Stub::Multiply(::grpc::ClientContext* context, const ::calculatorPackage::CalculatorRequest& request, ::calculatorPackage::CalculatorReply* response) {
  return ::grpc::internal::BlockingUnaryCall< ::calculatorPackage::CalculatorRequest, ::calculatorPackage::CalculatorReply, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_Multiply_, context, request, response);
}

void calculatorService::Stub::async::Multiply(::grpc::ClientContext* context, const ::calculatorPackage::CalculatorRequest* request, ::calculatorPackage::CalculatorReply* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::calculatorPackage::CalculatorRequest, ::calculatorPackage::CalculatorReply, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_Multiply_, context, request, response, std::move(f));
}

void calculatorService::Stub::async::Multiply(::grpc::ClientContext* context, const ::calculatorPackage::CalculatorRequest* request, ::calculatorPackage::CalculatorReply* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_Multiply_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::calculatorPackage::CalculatorReply>* calculatorService::Stub::PrepareAsyncMultiplyRaw(::grpc::ClientContext* context, const ::calculatorPackage::CalculatorRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::calculatorPackage::CalculatorReply, ::calculatorPackage::CalculatorRequest, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_Multiply_, context, request);
}

::grpc::ClientAsyncResponseReader< ::calculatorPackage::CalculatorReply>* calculatorService::Stub::AsyncMultiplyRaw(::grpc::ClientContext* context, const ::calculatorPackage::CalculatorRequest& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncMultiplyRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status calculatorService::Stub::Divide(::grpc::ClientContext* context, const ::calculatorPackage::CalculatorRequest& request, ::calculatorPackage::CalculatorReply* response) {
  return ::grpc::internal::BlockingUnaryCall< ::calculatorPackage::CalculatorRequest, ::calculatorPackage::CalculatorReply, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_Divide_, context, request, response);
}

void calculatorService::Stub::async::Divide(::grpc::ClientContext* context, const ::calculatorPackage::CalculatorRequest* request, ::calculatorPackage::CalculatorReply* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::calculatorPackage::CalculatorRequest, ::calculatorPackage::CalculatorReply, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_Divide_, context, request, response, std::move(f));
}

void calculatorService::Stub::async::Divide(::grpc::ClientContext* context, const ::calculatorPackage::CalculatorRequest* request, ::calculatorPackage::CalculatorReply* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_Divide_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::calculatorPackage::CalculatorReply>* calculatorService::Stub::PrepareAsyncDivideRaw(::grpc::ClientContext* context, const ::calculatorPackage::CalculatorRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::calculatorPackage::CalculatorReply, ::calculatorPackage::CalculatorRequest, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_Divide_, context, request);
}

::grpc::ClientAsyncResponseReader< ::calculatorPackage::CalculatorReply>* calculatorService::Stub::AsyncDivideRaw(::grpc::ClientContext* context, const ::calculatorPackage::CalculatorRequest& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncDivideRaw(context, request, cq);
  result->StartCall();
  return result;
}

calculatorService::Service::Service() {
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      calculatorService_method_names[0],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< calculatorService::Service, ::calculatorPackage::CalculatorRequest, ::calculatorPackage::CalculatorReply, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](calculatorService::Service* service,
             ::grpc::ServerContext* ctx,
             const ::calculatorPackage::CalculatorRequest* req,
             ::calculatorPackage::CalculatorReply* resp) {
               return service->Add(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      calculatorService_method_names[1],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< calculatorService::Service, ::calculatorPackage::CalculatorRequest, ::calculatorPackage::CalculatorReply, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](calculatorService::Service* service,
             ::grpc::ServerContext* ctx,
             const ::calculatorPackage::CalculatorRequest* req,
             ::calculatorPackage::CalculatorReply* resp) {
               return service->Substract(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      calculatorService_method_names[2],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< calculatorService::Service, ::calculatorPackage::CalculatorRequest, ::calculatorPackage::CalculatorReply, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](calculatorService::Service* service,
             ::grpc::ServerContext* ctx,
             const ::calculatorPackage::CalculatorRequest* req,
             ::calculatorPackage::CalculatorReply* resp) {
               return service->Multiply(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      calculatorService_method_names[3],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< calculatorService::Service, ::calculatorPackage::CalculatorRequest, ::calculatorPackage::CalculatorReply, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](calculatorService::Service* service,
             ::grpc::ServerContext* ctx,
             const ::calculatorPackage::CalculatorRequest* req,
             ::calculatorPackage::CalculatorReply* resp) {
               return service->Divide(ctx, req, resp);
             }, this)));
}

calculatorService::Service::~Service() {
}

::grpc::Status calculatorService::Service::Add(::grpc::ServerContext* context, const ::calculatorPackage::CalculatorRequest* request, ::calculatorPackage::CalculatorReply* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status calculatorService::Service::Substract(::grpc::ServerContext* context, const ::calculatorPackage::CalculatorRequest* request, ::calculatorPackage::CalculatorReply* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status calculatorService::Service::Multiply(::grpc::ServerContext* context, const ::calculatorPackage::CalculatorRequest* request, ::calculatorPackage::CalculatorReply* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status calculatorService::Service::Divide(::grpc::ServerContext* context, const ::calculatorPackage::CalculatorRequest* request, ::calculatorPackage::CalculatorReply* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}


}  // namespace calculatorPackage

