//
// Created by p0w3r on 13.03.16.
//

#include "CRSPipeline_DataBuffer.h"

template <class T>
T* CRSPipelineStageDataBuffer::pop() {
    // the access to this function is mutually exclusive
    std::lock_guard<std::mutex> guard(_lock);
    //get first item of queue
    T item = _buffer.front();
    //remove it from queue
    _buffer.pop();

    return item;
}

template <class T>
void CRSPipelineStageDataBuffer::push(T& item) {
    // the access to this function is mutually exclusive
    std::lock_guard<std::mutex> guard(_lock);
    _buffer.push(item);
}

template <class T>
CRSPipelineStageDataBuffer::CRSPipelineStageDataBuffer() : _buffer(std::queue<T>()) {

}
