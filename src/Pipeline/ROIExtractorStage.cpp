//
// Created by p0w3r on 06.03.16.
//

#include <iostream>
#include "ROIExtractorStage.h"


//singleton global ptr initialization - The pointer is being
// allocated - not the object itself.
ROIExtractorStage* ROIExtractorStage::_instance = nullptr;

ROIExtractorStage *ROIExtractorStage::getInstance() {
    if (!_instance)
        _instance = new ROIExtractorStage();

    return _instance;
}

ROIExtractorStage::~ROIExtractorStage() {
    std::cout << "RoI Extractor Stage Offline!" << std::endl;

}

ROIExtractorStage::ROIExtractorStage() {
    std::cout << "RoI Extractor Stage Online!" << std::endl;
}

void ROIExtractorStage::run() {
    //TODO
    std::cout << "ROIExtractorStage Running!" << std::endl;
}