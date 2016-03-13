cmake_minimum_required(VERSION 3.3)
project(CardRecognitionSystem)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    src/Pipeline/CardDetectorStage.cpp
    src/Pipeline/CardDetectorStage.h
    src/Pipeline/CardNameExtractorStage.cpp
    src/Pipeline/CardNameExtractorStage.h
    src/Pipeline/CRSPipeline_Controller.cpp
    src/Pipeline/CRSPipeline_Controller.h
    src/Pipeline/CRSPipeline_DataBuffer.cpp
    src/Pipeline/CRSPipeline_DataBuffer.h
    src/Pipeline/CRSPipeline_Stage.cpp
    src/Pipeline/CRSPipeline_Stage.h
    src/Pipeline/MultiverseIDResolverStage.cpp
    src/Pipeline/MultiverseIDResolverStage.h
    src/Pipeline/ROIExtractorStage.cpp
    src/Pipeline/ROIExtractorStage.h
    src/Pipeline/SetNameExtractorStage.cpp
    src/Pipeline/SetNameExtractorStage.h
    src/CardDetector.cpp
    src/CardDetector.h
    src/CardRepositoryController.cpp
    src/CardRepositoryController.h
    src/MTGCardRecognitionSystem.cpp)

add_executable(CardRecognitionSystem ${SOURCE_FILES})