//
// Created by p0w3r on 13.03.16.
//

#ifndef CARDRECOGNITIONSYSTEM_CRSPIPELINE_H
#define CARDRECOGNITIONSYSTEM_CRSPIPELINE_H


#include <thread>
#include <condition_variable>
#include <mutex>
#include "CRS_Pipeline_CardDetectorStage.h"
#include "CRS_Pipeline_ROIExtractorStage.h"
#include "CRS_Pipeline_CardNameExtractorStage.h"
#include "CRS_Pipeline_SetNameExtractorStage.h"
#include "CRS_Pipeline_MultiverseIDResolverStage.h"
#include "CRS_Pipeline_DataBuffer.h"

class CRS_Pipeline_Controller {
public:
    static CRS_Pipeline_Controller* getInstance();
    ~CRS_Pipeline_Controller();

    /*
     * starts the pipeline
     */
    void startPipeline();


    /*
     * getters and setters
     */
    std::shared_ptr<std::condition_variable> getNextStepCVPtr() {
        return _nextStepCondVarUPtr;
    }

    std::shared_ptr<std::mutex> getNextStepMutexPtr() {
        return _nextStepMutexUPtr;
    }

    bool getNextStepFlag() {
        return _nextStepFlag;
    }

private:
    static CRS_Pipeline_Controller* _instance;

    CRS_Pipeline_Controller(); //only instantiate via getInstance!
    CRS_Pipeline_Controller(const CRS_Pipeline_Controller&) = delete; //no copy con!

    /*
     * Pointer to Stages of the Pipeline
     */
    CRS_Pipeline_CardDetectorStage* _cardDetectorStage;
    CRS_Pipeline_ROIExtractorStage* _roiExtractorStage;
    CRS_Pipeline_CardNameExtractorStage* _cardNameExtractorStage;
    CRS_Pipeline_SetNameExtractorStage* _setNameExtractorStage;
    CRS_Pipeline_MultiverseIDResolverStage* _multiverseIDResolverStage;

    /*
     * Pointer to FIFO Buffers for the Pipeline Stages
     * (if another Buffer Type has to be instantiated it has to be explicitly instantiated (because of template functionality)
     * before in the CRS_Pipeline_DataBuffer.cpp file..)
     */
    CRS_Pipeline_DataBuffer<cv::Mat*>* _rawCardImage_FIFO;
    CRS_Pipeline_DataBuffer<cv::Mat*>* _singleCardImage_FIFO;
    CRS_Pipeline_DataBuffer<cv::Mat*>* _setNameROI_FIFO;
    CRS_Pipeline_DataBuffer<cv::Mat*>* _cardNameROI_FIFO;
    CRS_Pipeline_DataBuffer<std::string>* _setNameString_FIFO;
    CRS_Pipeline_DataBuffer<std::string>* _cardNameString_FIFO;
    CRS_Pipeline_DataBuffer<std::string>* _multiverseIDString_FIFO;

    /*
     * Threads that execute the Pipeline Stages
     */
    std::thread _cardDetectorStageThread;
    std::thread _roiExtractorStageThread;
    std::thread _cardNameExtractorStageThread;
    std::thread _setNameExtractorStageThread;
    std::thread _multiverseIDResolverStageThread;

    /*
     * Thread Synchronization Constructs
     */
    //step synchronization //TODO how to make this accessable in other classes (e.g. stages)?! -> shared_ptr?! super global?
    bool _nextStepFlag{false};
    std::shared_ptr<std::mutex> _nextStepMutexUPtr;
    std::shared_ptr<std::condition_variable> _nextStepCondVarUPtr;

    std::mutex _stepsFinishedMutex;
    std::condition_variable _stepsFinishedCondVar;


    /*
     * Methods
     */
    void createPipelineStages();

    void createPipelineBuffers();

    void linkPipelineStagesAndBuffers() const;

    void joinPipelineStageThreads();

    void createPipelineStageThreads();

    void initializePipeline();

    //operating flag as long this is true pipeline is running
    bool _operating{false}; //TODO maybe get and set from CRS Controller

    //returns true if done flag of all stages is true
    bool allStagesFinishedStep();

    void waitForStagesToFinishSteps();
};


#endif //CARDRECOGNITIONSYSTEM_CRSPIPELINE_H
