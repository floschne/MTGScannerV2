//
// Created by p0w3r on 13.03.16.
//

#include <iostream>
#include "CRS_Pipeline_Controller.h"

CRS_Pipeline_Controller* CRS_Pipeline_Controller::_instance = nullptr;

CRS_Pipeline_Controller* CRS_Pipeline_Controller::getInstance() {
    if (!_instance) {
        _instance = new CRS_Pipeline_Controller();
    }

    return _instance;
}

CRS_Pipeline_Controller::~CRS_Pipeline_Controller() {
    std::cout << "Shutting Down Pipeline..." << std::endl;

    delete _rawCardImage_FIFO;
    delete _roiExtractorStage;
    delete _cardNameExtractorStage;
    delete _setNameExtractorStage;
    delete _multiverseIDResolverStage;

    std::cout << "Pipeline Offline!" << std::endl;

}

CRS_Pipeline_Controller::CRS_Pipeline_Controller() : _nextStepMutexUPtr(std::shared_ptr<std::mutex>(new std::mutex())),
                                                     _nextStepCondVarUPtr(std::shared_ptr<std::condition_variable>(
                                                             new std::condition_variable())) {
    initializePipeline();
}

void CRS_Pipeline_Controller::initializePipeline() {
    std::cout << "Initializing Card Recognition Pipeline..." << std::endl;

    //instantiate stages
    createPipelineStages();

    //instantiate buffers
    createPipelineBuffers();

    //link buffers and stages
    linkPipelineStagesAndBuffers();

    //create pipeline stage threads (note that they're only initialized NOT started or called)
    createPipelineStageThreads();

    joinPipelineStageThreads();

    std::cout << "...Done Initializing Card Recognition Pipeline" << std::endl;
}

void CRS_Pipeline_Controller::linkPipelineStagesAndBuffers() const {
    std::cout << "Linking Stages and Buffers..." << std::endl;
    _cardDetectorStage->setInputBuffer(_rawCardImage_FIFO);
    _cardDetectorStage->setOutputBuffer(_singleCardImage_FIFO);

    //setting two output buffers for RoI ExtractorStage (1st is setNameROIFIFO 2nd is cardROIStringFIFO)
    _roiExtractorStage->setInputBuffer(_singleCardImage_FIFO);
    _roiExtractorStage->setOutputBuffer(_setNameROI_FIFO);
    _roiExtractorStage->setSecondOutputBuffer(_cardNameROI_FIFO);

    _cardNameExtractorStage->setInputBuffer(_cardNameROI_FIFO);
    _cardNameExtractorStage->setOutputBuffer(_cardNameString_FIFO);

    _setNameExtractorStage->setInputBuffer(_setNameROI_FIFO);
    _setNameExtractorStage->setOutputBuffer(_setNameString_FIFO);

    //setting two input buffers for RoI ExtractorStage (1st is setNameStringFIFO 2nd is cardNameStringFIFO)
    _multiverseIDResolverStage->setInputBuffer(_setNameString_FIFO);
    _multiverseIDResolverStage->setSecondInputBuffer(_cardNameString_FIFO);
    _multiverseIDResolverStage->setOutputBuffer(_multiverseIDString_FIFO);
    std::cout << "...Done Linking Stages and Buffers" << std::endl;
}

void CRS_Pipeline_Controller::createPipelineBuffers() {
    std::cout << "Instantiating Pipeline Data Buffer..." << std::endl;
    _rawCardImage_FIFO = new CRS_Pipeline_DataBuffer<cv::Mat*>();
    _singleCardImage_FIFO = new CRS_Pipeline_DataBuffer<cv::Mat*>();
    _cardNameROI_FIFO = new CRS_Pipeline_DataBuffer<cv::Mat*>();
    _setNameROI_FIFO = new CRS_Pipeline_DataBuffer<cv::Mat*>();
    _cardNameString_FIFO = new CRS_Pipeline_DataBuffer<std::__cxx11::string>();
    _setNameString_FIFO = new CRS_Pipeline_DataBuffer<std::__cxx11::string>();
    _multiverseIDString_FIFO = new CRS_Pipeline_DataBuffer<std::__cxx11::string>();
    std::cout << "...Done Instantiating Pipeline Data Buffer" << std::endl;
}

void CRS_Pipeline_Controller::createPipelineStages() {
    std::cout << "Instantiating Pipeline Stages..." << std::endl;
    _cardDetectorStage = CRS_Pipeline_CardDetectorStage::getInstance();
    _roiExtractorStage = CRS_Pipeline_ROIExtractorStage::getInstance();
    _cardNameExtractorStage = CRS_Pipeline_CardNameExtractorStage::getInstance();
    _setNameExtractorStage = CRS_Pipeline_SetNameExtractorStage::getInstance();
    _multiverseIDResolverStage = CRS_Pipeline_MultiverseIDResolverStage::getInstance();
    std::cout << "...Done Instantiating Pipeline Stages" << std::endl;
}

void CRS_Pipeline_Controller::createPipelineStageThreads() {
    std::cout << "Instantiating Pipeline Stage Threads..." << std::endl;
    //standard ctor of std::thread only creates the thread but does NOT call or start it!
    _cardNameExtractorStageThread = std::thread();
    _cardDetectorStageThread = std::thread();
    _roiExtractorStageThread = std::thread();
    _cardNameExtractorStageThread = std::thread();
    _setNameExtractorStageThread = std::thread();
    _multiverseIDResolverStageThread = std::thread();
    std::cout << "...Done Instantiating Pipeline Stage Threads" << std::endl;
}

void CRS_Pipeline_Controller::startPipeline() {
    std::cout << "Starting Card Recognition Pipeline..." << std::endl;

    //set all stages to online (turns on endless loop)
    _cardDetectorStage->goOnline(true);
    _roiExtractorStage->goOnline(true);
    _cardNameExtractorStage->goOnline(true);
    _setNameExtractorStage->goOnline(true);
    _multiverseIDResolverStage->goOnline(true);

    //TODO how to give a singleton stage object as parameter to thread?!?!?
    //c++11 move ctors / semantics?!
    _cardNameExtractorStageThread = std::thread();
    _cardDetectorStageThread = std::thread();
    _roiExtractorStageThread = std::thread();
    _cardNameExtractorStageThread = std::thread();
    _setNameExtractorStageThread = std::thread();
    _multiverseIDResolverStageThread = std::thread();

    //joining threads (waitForNextStep for them to be finished before finishing this thread)
    joinPipelineStageThreads();

    _operating = true; //TODO maybe get and set from CRS Controller

    std::cout << "...Done Starting Card Recognition Pipeline" << std::endl;
    std::cout << "Card Recognition Pipeline Online!" << std::endl;

    while (_operating) {
        _nextStepFlag = false;
        waitForStagesToFinishSteps();
        //all steps finished -> next step and notify all the waiting stages
        _nextStepFlag = true;
        _nextStepCondVarUPtr->notify_all();
    }

}

void CRS_Pipeline_Controller::waitForStagesToFinishSteps() {
    std::unique_lock<std::mutex> stepsFinishedLock(_stepsFinishedMutex);
    std::cout << "Pipeline Controller :  Waiting for Stages to finish steps!" << std::endl;
    _stepsFinishedCondVar.wait(stepsFinishedLock, [this]{return this->allStagesFinishedStep();}); //TODO how or where to notify _stepsFinishedCondVar??
    std::cout << "Pipeline Controller : All Stages finished Steps!" << std::endl;
}

/*
 * joins all stage threads with this thread
 */
void CRS_Pipeline_Controller::joinPipelineStageThreads() {
    _cardNameExtractorStageThread.join();
    _cardDetectorStageThread.join();
    _roiExtractorStageThread.join();
    _cardNameExtractorStageThread.join();
    _setNameExtractorStageThread.join();
    _multiverseIDResolverStageThread.join();
}


bool CRS_Pipeline_Controller::allStagesFinishedStep() {
    //TODO possible to notify _stepsFinishedCondVar here?!
    return _cardDetectorStage->stepFinished() && _roiExtractorStage->stepFinished() &&
           _cardNameExtractorStage->stepFinished() &&
           _setNameExtractorStage->stepFinished() &&
           _multiverseIDResolverStage->stepFinished();
}