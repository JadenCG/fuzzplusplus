cmake_minimum_required(VERSION 3.27)
project(fuzzpp)

set(CMAKE_CXX_STANDARD 17)

add_executable(fuzzpp source/main.cpp source/execution/Executor.cpp source/input/GuidedInput.cpp source/navigator/Navigator.cpp source/recorder/Recorder.cpp)

add_executable(simpleinput source/test_programs/simpleInput.cpp)
