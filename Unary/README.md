Requirements:

    	cmake= should be used to compile the cpp project https://cmake.org/download/ 

	protoc= should be downloaded at https://github.com/protocolbuffers/protobuf/releases and path should be given to environment variables 

	vcpkg= vcpkg should be used as c++ package manager, the necessary grpc protobuf libraries will be downloaded here

	gRPC installation= vcpkg install grpc:x64-windows

	install protobuf = vcpkg install protobuf protobuf protobuf:x64-windows
                            vcpkg integrate install
	(NOTE: the issue to be considered here is that the protoc tool and the proto package in the vcpkg must be compatible, otherwise it will cause errors when the project runs)


Compilation:

	running proto file: 
        	create the necessary cpp file for message structures = protoc --cpp_out=. <YourProtoFile>.proto
        	create the necessary cpp file for the service interface = protoc --grpc_out=. --plugin=protoc-gen-grpc="<vcpkg_install_path>\packages\grpc_x64-windows\tools\grpc\grpc\grpc_cpp_plugin.exe" <YourProtoFile>.proto                           
    
    	Build with cmake:   
        	cmake -DCMAKE_TOOLCHAIN_FILE=<vcpkg_install_path>/scripts/buildsystems/vcpkg.cmake
        	cmake --build .
