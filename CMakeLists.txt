cmake_minimum_required(VERSION 3.3)
project(CardRecognitionSystem)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    src/CardDetector.cpp
    src/CardDetector.h
    src/CardRepositoryController.cpp
    src/CardRepositoryController.h
    src/MTGCardRecognitionSystem.cpp src/CRS_PipelineStage.cpp src/CRS_PipelineStage.h src/CRS_PipelineLoad.cpp src/CRS_PipelineLoad.h src/CRS_PipelineBuffer.cpp src/CRS_PipelineBuffer.h src/CRS_Pipeline.cpp src/CRS_Pipeline.h src/CRS_PipelineWorkload.cpp src/CRS_PipelineWorkload.h)

add_executable(CardRecognitionSystem ${SOURCE_FILES})