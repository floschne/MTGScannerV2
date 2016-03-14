//
// Created by p0w3r on 13.03.16.
//

#include <opencv2/core/mat.hpp>
#include "CRSPipeline_Stage.h"

template<class InputBufferType, class OutputBufferType>
void CRSPipeline_Stage<InputBufferType, OutputBufferType>::operator()() {
    this->run();
}

template<class InputBufferType, class OutputBufferType>
void CRSPipeline_Stage<InputBufferType, OutputBufferType>::setOutputBuffer(CRSPipeline_DataBuffer<OutputBufferType>* outBuf) {
    _outputBuffer = outBuf;
}

template<class InputBufferType, class OutputBufferType>
void CRSPipeline_Stage<InputBufferType, OutputBufferType>::setInputBuffer(CRSPipeline_DataBuffer<InputBufferType>* inBuf) {
    _inputBuffer = inBuf;
}

/* EXPLICIT CLASS TEMPLATE INSTANTIATION */
template class CRSPipeline_Stage<cv::Mat*, cv::Mat*>;
template class CRSPipeline_Stage<cv::Mat*, std::string>;
template class CRSPipeline_Stage<std::string, std::string>;
