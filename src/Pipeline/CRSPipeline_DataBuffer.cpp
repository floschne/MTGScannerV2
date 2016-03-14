//
// Created by p0w3r on 13.03.16.
//

#include <iostream>
#include <opencv2/core/mat.hpp>
#include "CRSPipeline_DataBuffer.h"

template <class T>
uint8_t CRSPipeline_DataBuffer<T>::_id = 0;

template <class T>
T* CRSPipeline_DataBuffer<T>::pop() {
    // the access to this function is mutually exclusive
    std::lock_guard<std::mutex> guard(_lock);
    //get first item of queue
    T* item = &_buffer.front();
    //remove it from queue
    _buffer.pop();

    return item;
}

template <class T>
void CRSPipeline_DataBuffer<T>::push(T& item) {
    // the access to this function is mutually exclusive
    std::lock_guard<std::mutex> guard(_lock);
    _buffer.push(item);
}

template <class T>
CRSPipeline_DataBuffer<T>::CRSPipeline_DataBuffer() : _buffer(std::queue<T>()) {
    std::cout << "Data Buffer with ID '" << _id++ << "' instantiated!" << std::endl;
}


/* EXPLICIT CLASS TEMPLATE INSTANTIATION */
template class CRSPipeline_DataBuffer<cv::Mat*>;
template class CRSPipeline_DataBuffer<std::string>;