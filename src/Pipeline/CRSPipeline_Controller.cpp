//
// Created by p0w3r on 13.03.16.
//

#include <iostream>
#include "CRSPipeline_Controller.h"

CRSPipeline_Controller* CRSPipeline_Controller::_instance = nullptr;

CRSPipeline_Controller *CRSPipeline_Controller::getInstance() {
    if (!_instance)
        _instance = new CRSPipeline_Controller();

    return _instance;
}

CRSPipeline_Controller::~CRSPipeline_Controller() {
    std::cout << "Pipeline Offline!" << std::endl;

}

CRSPipeline_Controller::CRSPipeline_Controller() {

    std::cout << "Initializing Card Recognition Pipeline!" << std::endl;

    //instantiate stages
    std::cout << "Instantiating Pipeline Stages..." << std::endl;
    _cardDetectorStage = CardDetectorStage::getInstance();
    _roiExtractorStage = ROIExtractorStage::getInstance();
    _cardNameExtractorStage = CardNameExtractorStage::getInstance();
    _setNameExtractorStage = SetNameExtractorStage::getInstance();
    _multiverseIDResolverStage = MultiverseIDResolverStage::getInstance();

    //instantiate buffers (if another Buffer Type has to be instantiated it has to be explicitly instantiated before in the CRSPipeline_DataBuffer.cpp file..)
    std::cout << "Instantiating Pipeline Data Buffer..." << std::endl;
    _rawCardImage_FIFO = new CRSPipeline_DataBuffer<cv::Mat*>();
    _singleCardImage_FIFO = new CRSPipeline_DataBuffer<cv::Mat*>();
    _cardNameROI_FIFO = new CRSPipeline_DataBuffer<cv::Mat*>();
    _setNameROI_FIFO = new CRSPipeline_DataBuffer<cv::Mat*>();
    _cardNameString_FIFO = new CRSPipeline_DataBuffer<std::string>();
    _setNameString_FIFO = new CRSPipeline_DataBuffer<std::string>();
    _multiverseIDString_FIFO = new CRSPipeline_DataBuffer<std::string>();

    //link buffers and stages
    std::cout << "Linking Stages and Buffers.." << std::endl;
    _cardDetectorStage->setInputBuffer(_rawCardImage_FIFO);
    _cardDetectorStage->setOutputBuffer(_singleCardImage_FIFO);

    _roiExtractorStage->setInputBuffer(_singleCardImage_FIFO);
    //TODO setting two output buffers for RoI ExtractorStage
    _roiExtractorStage->setOutputBuffer(_setNameROI_FIFO); //wont work like this..
    _roiExtractorStage->setOutputBuffer(_cardNameROI_FIFO);

    _cardNameExtractorStage->setInputBuffer(_cardNameROI_FIFO);
    _cardNameExtractorStage->setOutputBuffer(_cardNameString_FIFO);

    _setNameExtractorStage->setInputBuffer(_setNameROI_FIFO);
    _setNameExtractorStage->setOutputBuffer(_setNameString_FIFO);

    //TODO setting two output buffers for RoI ExtractorStage
    _multiverseIDResolverStage->setInputBuffer(_setNameString_FIFO);//wont work like this..
    _multiverseIDResolverStage->setInputBuffer(_cardNameString_FIFO);
    _multiverseIDResolverStage->setOutputBuffer(_multiverseIDString_FIFO);

    std::cout << "Pipeline Online!" << std::endl;
}
