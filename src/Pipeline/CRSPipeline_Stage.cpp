//
// Created by p0w3r on 13.03.16.
//

#include "CRSPipeline_Stage.h"

template<class InputBufferType, class OutputBufferType>
void CRSPipeline_Stage<InputBufferType, OutputBufferType>::operator()() {
    this->run();
}

template<class InputBufferType, class OutputBufferType>
void CRSPipeline_Stage<InputBufferType, OutputBufferType>::setOutputBuffer(CRSPipeline_DataBuffer<InputBufferType> *outBuf) {
    _outputBuffer = outBuf;
}

template<class InputBufferType, class OutputBufferType>
void CRSPipeline_Stage<InputBufferType, OutputBufferType>::setInputBuffer(CRSPipeline_DataBuffer<InputBufferType> *inBuf) {
    _inputBuffer = inBuf;
}
