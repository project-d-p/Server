#!/bin/bash

# abseil install for protubuf
cd /app/
mkdir Source && cd Source
git clone https://github.com/abseil/abseil-cpp.git

cd abseil-cpp
mkdir build && cd build
cmake -DABSL_BUILD_TESTING=ON -DABSL_USE_GOOGLETEST_HEAD=ON -DCMAKE_CXX_STANDARD=14 ..
cmake --build . --target all

ctest

# install protobuf
cd /app/
mkdir src && cd src
git clone -b v26.1 https://github.com/protocolbuffers/protobuf.git

cd protobuf
# Remember to update any submodules if you are using git clone
git submodule update --init --recursive

# 마찬가지로 C++14을 표준으로 사용함
cmake -S. -Bcmake-out -DCMAKE_CXX_STANDARD=14
cd cmake-out/
#build
cmake --build .
# test
ctest --verbose
# install
sudo make install

# install grpc
cd /app/src/
git clone -b v1.63.0 https://github.com/grpc/grpc
cd grpc
git submodule update --init --recursive

cmake -S. -Bcmake-out -DgRPC_INSTALL=ON -DCMAKE_CXX_STANDARD=14
cd cmake-out/
cmake --build .
sudo make install
