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
    //for multithreading (to put a class as parameter for std::thread)
    void operator()();

    void setInputBuffer(CRSPipeline_DataBuffer<InputBufferType>* inBuf);
    void setOutputBuffer(CRSPipeline_DataBuffer<InputBufferType>* outBuf);

protected:

    //operator() calls pure virtual run method -> this is the thread entry point for a stage
    virtual void run() = 0;

    /*
     * Pointer to Input and Output FIFO Buffers -> managed by Pipeline Controller (do not delete in dtor)
     */
    CRSPipeline_DataBuffer<InputBufferType>* _inputBuffer;
    CRSPipeline_DataBuffer<OutputBufferType>* _outputBuffer;

};

#endif //MTGSCANNERV2_CRSPIPELINESTAGE_H