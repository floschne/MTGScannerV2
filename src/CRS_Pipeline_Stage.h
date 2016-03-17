//
// Created by p0w3r on 13.03.16.
//

#ifndef MTGSCANNERV2_CRSPIPELINESTAGE_H
#define MTGSCANNERV2_CRSPIPELINESTAGE_H


#include <queue>
#include <mutex>
#include <condition_variable>
#include "CRS_Pipeline_DataBuffer.h"

template<class InputBufferType, class OutputBufferType>
class CRS_Pipeline_Stage {

public:
    //for multithreading (to put a class as parameter for std::thread)
    void operator()();

    void setInputBuffer(CRS_Pipeline_DataBuffer<InputBufferType>* inBuf);
    void setOutputBuffer(CRS_Pipeline_DataBuffer<OutputBufferType>* outBuf);

    void goOnline(bool on) {
        _online = on;
    }

    bool stepFinished() const {
        return _stepFinished;
    }

protected:
    //operator() calls pure virtual step method in a loop that runs as long as _online is true -> this is the thread entry point for a stage
    virtual void step() = 0;
    bool _online{false};

    /*
     * Synchronization Constructs
     */
    bool _stepFinished{false}; //flag that signals when stage is ready with work (step) and can get new work (next step)
    std::mutex _stepMutex;

    /*
     * Pointer to Input and Output FIFO Buffers -> managed by Pipeline Controller (do not delete in dtor)
     */
    CRS_Pipeline_DataBuffer<InputBufferType>* _inputBuffer;
    CRS_Pipeline_DataBuffer<OutputBufferType>* _outputBuffer;

    void waitForNextStep();
};

#endif //MTGSCANNERV2_CRSPIPELINESTAGE_H