//
// Created by p0w3r on 13.03.16.
//

#ifndef MTGSCANNERV2_CRSPIPELINESTAGE_H
#define MTGSCANNERV2_CRSPIPELINESTAGE_H


#include <queue>
#include <mutex>
#include "CRSPipeline_DataBuffer.h"

template<class InputBufferType, class OutputBufferType>
class CRSPipeline_Stage {

public:
    CRSPipeline_Stage();
    virtual ~CRSPipeline_Stage();

    //for multithreading (to put a class as parameter for std::thread)
    void operator()();

protected:

    //operator() calls pure virtual run method -> this is the thread entry point for a stage
    virtual void run() = 0;

    /*
     * Pointer to Input and Output FIFO Buffers
     */
    CRSPipeline_DataBuffer<InputBufferType>* _inputBuffer;
    CRSPipeline_DataBuffer<OutputBufferType>* _outputBuffer;

};

#endif //MTGSCANNERV2_CRSPIPELINESTAGE_H