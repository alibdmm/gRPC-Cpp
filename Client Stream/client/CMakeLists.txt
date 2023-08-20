cmake_minimum_required( VERSION 3.1)

project( ClientStream )

find_package(absl CONFIG REQUIRED)
find_package(gRPC CONFIG REQUIRED)

find_package( Protobuf REQUIRED )

add_executable( client src/client.cpp src/ClientStream.grpc.pb.cc src/ClientStream.pb.cc)

target_link_libraries( client PRIVATE gRPC::grpc++ gRPC::grpc++_reflection gRPC::gpr gRPC::grpc gRPC::grpc++ protobuf::libprotoc protobuf::libprotobuf protobuf::libprotobuf-lite )