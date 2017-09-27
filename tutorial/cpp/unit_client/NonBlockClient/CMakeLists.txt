cmake_minimum_required(VERSION 2.6)
project(client)
set(CMAKE_CXX_FLAGS "-std=c++11 ${CMAKE_CXX_FLAGS}")
set(CLIENT_FILELIST
  ./main.cpp
  ./TBufferTransports.cpp
  ./binary_protocol.tcc
  ./gen-cpp/tutorial_types.cpp
  ./gen-cpp/SharedService.cpp
  ./gen-cpp/shared_types.cpp
  ./gen-cpp/Calculator.cpp
  ./gen-cpp/shared_constants.cpp
  ./gen-cpp/tutorial_constants.cpp)

add_executable(calculator_client ${CLIENT_FILELIST})
target_link_libraries(calculator_client pthread)
