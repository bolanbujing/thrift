cmake_minimum_required(VERSION 2.6)
project(client)
add_compile_options(-std=c++11)
include_directories(./)
include_directories(../../gen-cpp/)
include_directories(/home/xiaobo/workspace/mtsProject/ext/mts_outer/boost_1_64_0/)
include_directories(/home/xiaobo/cpp/thrift-master/lib/cpp/src)

set(CLIENT_FILELIST
  ./main.cpp
  ./TBufferTransports.cpp
  ./binary_protocol.tcc
#  ../../gen-cpp/tutorial_types.cpp
#  ../../gen-cpp/SharedService.cpp
#  ../../gen-cpp/shared_types.cpp
  ./Calculator.cpp)
#  ../../gen-cpp/shared_constants.cpp
#  ../../gen-cpp/tutorial_constants.cpp)

add_executable(calculator_client ${CLIENT_FILELIST})
target_link_libraries(calculator_client pthread)
