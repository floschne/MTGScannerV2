//
// Created by p0w3r on 13.03.16.
//

#include <opencv2/core/mat.hpp>
#include <iostream>
#include "CRS_Pipeline_Stage.h"
#include "CRS_Pipeline_Controller.h"

template<class InputBufferType, class OutputBufferType>
void CRS_Pipeline_Stage<InputBufferType, OutputBufferType>::operator()() {

    while(_online) {
        waitForNextStep();
        step();
    }
}

template<class InputBufferType, class OutputBufferType>
void CRS_Pipeline_Stage<InputBufferType, OutputBufferType>::setOutputBuffer(CRS_Pipeline_DataBuffer<OutputBufferType>* outBuf) {
    _outputBuffer = outBuf;
}

template<class InputBufferType, class OutputBufferType>
void CRS_Pipeline_Stage<InputBufferType, OutputBufferType>::setInputBuffer(CRS_Pipeline_DataBuffer<InputBufferType>* inBuf) {
    _inputBuffer = inBuf;
}

template<class InputBufferType, class OutputBufferType>
void CRS_Pipeline_Stage<InputBufferType, OutputBufferType>::waitForNextStep() {
    CRS_Pipeline_Controller* controller = CRS_Pipeline_Controller::getInstance();
    std::shared_ptr<std::condition_variable> nextStepCV = controller->getNextStepCVPtr();//TODO maybe error here? copy assignment operator and sharedPtr?!
    std::shared_ptr<std::mutex> stepMutex = controller->getNextStepMutexPtr();//TODO maybe error here? copy assignment operator and sharedPtr?!

    std::unique_lock<std::mutex> stepLock(*stepMutex); //acquire step lock
    std::cout << "Waiting for next step.." << std::endl;
    nextStepCV->wait(stepLock, [&]{return controller->getNextStepFlag();}); //waitForNextStep until controller sets nextStepFlag to true
}


/* EXPLICIT CLASS TEMPLATE INSTANTIATION */
template class CRS_Pipeline_Stage<cv::Mat*, cv::Mat*>;
template class CRS_Pipeline_Stage<cv::Mat*, std::string>;
template class CRS_Pipeline_Stage<std::string, std::string>;
