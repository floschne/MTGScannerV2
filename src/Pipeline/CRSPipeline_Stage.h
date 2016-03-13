//
// Created by p0w3r on 13.03.16.
//

#ifndef MTGSCANNERV2_CRSPIPELINESTAGE_H
#define MTGSCANNERV2_CRSPIPELINESTAGE_H

#endif //MTGSCANNERV2_CRSPIPELINESTAGE_H

#include <queue>
#include <mutex>
#include "CRSPipelineStageDataBuffer.h"

template<class InputBufferType, class OutputBufferType>
class CRSPipelineStage {

public:
    CRSPipelineStage();
    virtual ~CRSPipelineStage();

    //for multithreading (to put a class as parameter for std::thread)
    void operator()();

protected:

    //operator() calls pure virtual run method -> this is the thread entry point for a stage
    virtual void run() = 0;

    /*
     * Pointer to Input and Output FIFO Buffers
     */
    CRSPipelineStageDataBuffer<InputBufferType>* _inputBuffer;
    CRSPipelineStageDataBuffer<OutputBufferType>* _outputBuffer;

};
