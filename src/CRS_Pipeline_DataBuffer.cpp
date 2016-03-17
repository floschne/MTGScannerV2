//
// Created by p0w3r on 13.03.16.
//

#include <iostream>
#include <opencv2/core/mat.hpp>
#include "CRS_Pipeline_DataBuffer.h"

template <class T>
uint8_t CRS_Pipeline_DataBuffer<T>::_id = 0;

template <class T>
T* CRS_Pipeline_DataBuffer<T>::pop() {
    // the access to this function is mutually exclusive
    std::lock_guard<std::mutex> guard(_lock);
    //get first item of queue
    T* item = &_buffer.front();
    //remove it from queue
    _buffer.pop();

    return item;
}

template <class T>
void CRS_Pipeline_DataBuffer<T>::push(T& item) {
    // the access to this function is mutually exclusive
    std::lock_guard<std::mutex> guard(_lock);
    _buffer.push(item);
}

template <class T>
CRS_Pipeline_DataBuffer<T>::CRS_Pipeline_DataBuffer() : _buffer(std::queue<T>()) {
    std::cout << "Data Buffer with ID '" << _id++ << "' instantiated!" << std::endl;
}


/* EXPLICIT CLASS TEMPLATE INSTANTIATION */
template class CRS_Pipeline_DataBuffer<cv::Mat*>;
template class CRS_Pipeline_DataBuffer<std::string>;