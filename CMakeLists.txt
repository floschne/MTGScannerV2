cmake_minimum_required(VERSION 3.3)
project(MTGScannerV2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

find_package(OpenCV REQUIRED)

set(SOURCE_FILES main.cpp CardDetector.cpp CardDetector.h)
add_executable(MTGScannerV2 ${SOURCE_FILES})

include_directories(${OpenCV_INCLUDE_DIRS})
target_link_libraries(MTGScannerV2 ${OpenCv_LIBS})