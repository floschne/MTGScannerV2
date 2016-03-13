//
// Created by p0w3r on 13.03.16.
//

#include <iostream>
#include "CRSPipeline_Controller.h"

CRSPipeline_Controller *CRSPipeline_Controller::getInstance() {
    if (!_instance)
        _instance = new CRSPipeline_Controller();

    return _instance;
}

CRSPipeline_Controller::~CRSPipeline_Controller() {
    std::cout << "Pipeline Offline!" << std::endl;

}

CRSPipeline_Controller::CRSPipeline_Controller() {

    //instantiate stages
    _cardDetectorStage = *CardDetectorStage::getInstance();
    _roiExtractorStage = *ROIExtractorStage::getInstance();
    _cardNameExtractorStage = *CardNameExtractorStage::getInstance();
    _setNameExtractorStage = *SetNameExtractorStage::getInstance();
    _multiverseIDResolverStage = *MultiverseIDResolverStage::getInstance();

    std::cout << "Pipeline Online!" << std::endl;
}
