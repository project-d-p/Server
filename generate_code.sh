#!/bin/bash

# build code
cd /app/Server/

rm -rf ./build
rm -rf ./dummy_client/grpc_test/build
rm -rf ./dummy_client/grpc_test/generated
rm -rf ./generated

# build
cmake -S. -Bcmake-out
cd cmake-out/
make
./game_server &

# client
cd /app/Server/dummy_test/grpc_test/
cmake -S. -Bcmake-out
cd cmake-out/
make
./grpc_client
