//
// Created by p0w3r on 20.03.16.
//

#ifndef CARDRECOGNITIONSYSTEM_CRS_PIPELINESTAGE_H
#define CARDRECOGNITIONSYSTEM_CRS_PIPELINESTAGE_H

#include <thread>
#include <mutex>
#include <vector>
#include "CRS_PipelineBuffer.h"
#include "CRS_PipelineWorkload.h"

template <class InputWorkloadType, class OutputWorkloadType>
class CRS_PipelineStage {
public:
    static unsigned int _ID{0};
    unsigned int _stepCounter;

    void printMessage(std::string msg);
    void startStage();

    CRS_PipelineStage();
    ~CRS_PipelineStage();

private:
    CRS_PipelineStage(const CRS_PipelineStage&) = delete;
    CRS_PipelineStage& operator=(const CRS_PipelineStage&) = delete;

    std::unique_ptr<std::thread> _workerThread;
    std::unique_ptr<std::mutex> _printLock;

    std::vector<CRS_PipelineBuffer<InputWorkloadType>*> _inputBuffers;
    std::vector<CRS_PipelineBuffer<OutputWorkloadType>*> _outputBUffers;

    std::shared_ptr<CRS_PipelineWorkload<InputWorkloadType>> _currentWorkload;

    void firstStep();
    void lastStep();
    void step();

    void fetchWorkLoad();
    void putWorkLoad();
};


#endif //CARDRECOGNITIONSYSTEM_CRS_PIPELINESTAGE_H
