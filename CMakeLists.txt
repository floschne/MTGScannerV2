cmake_minimum_required(VERSION 3.3)
project(CardRecognitionSystem)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
        src/CRS_Pipeline_CardDetectorStage.cpp
        src/CRS_Pipeline_CardDetectorStage.h
        src/CRS_Pipeline_CardNameExtractorStage.cpp
        src/CRS_Pipeline_CardNameExtractorStage.h
        src/CRS_Pipeline_Controller.cpp
        src/CRS_Pipeline_Controller.h
        src/CRS_Pipeline_DataBuffer.cpp
        src/CRS_Pipeline_DataBuffer.h
        src/CRS_Pipeline_Stage.cpp
        src/CRS_Pipeline_Stage.h
        src/CRS_Pipeline_MultiverseIDResolverStage.cpp
        src/CRS_Pipeline_MultiverseIDResolverStage.h
        src/CRS_Pipeline_ROIExtractorStage.cpp
        src/CRS_Pipeline_ROIExtractorStage.h
        src/CRS_Pipeline_SetNameExtractorStage.cpp
        src/CRS_Pipeline_SetNameExtractorStage.h
    src/CardDetector.cpp
    src/CardDetector.h
    src/CardRepositoryController.cpp
    src/CardRepositoryController.h
    src/MTGCardRecognitionSystem.cpp)

add_executable(CardRecognitionSystem ${SOURCE_FILES})