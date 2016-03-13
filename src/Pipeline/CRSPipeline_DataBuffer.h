//
// Created by p0w3r on 13.03.16.
//

#ifndef CARDRECOGNITIONSYSTEM_CRSPIPELINESTAGEDATABUFFER_H
#define CARDRECOGNITIONSYSTEM_CRSPIPELINESTAGEDATABUFFER_H

#include <queue>
#include <mutex>

template <class T>
class CRSPipeline_DataBuffer {

public:
    CRSPipeline_DataBuffer();

    T* pop();
    void push(T& item);


private:
    std::queue<T> _buffer;
    std::mutex _lock;
};


#endif //CARDRECOGNITIONSYSTEM_CRSPIPELINESTAGEDATABUFFER_H
