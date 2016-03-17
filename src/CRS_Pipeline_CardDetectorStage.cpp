//
// Created by p0w3r on 13.03.16.
//

#include <iostream>
#include "CRS_Pipeline_CardDetectorStage.h"

//singleton global ptr initialization - The pointer is being
// allocated - not the object itself.
CRS_Pipeline_CardDetectorStage* CRS_Pipeline_CardDetectorStage::_instance = nullptr;

CRS_Pipeline_CardDetectorStage* CRS_Pipeline_CardDetectorStage::getInstance() {
    if (!_instance)
        _instance = new CRS_Pipeline_CardDetectorStage();

    return _instance;
}

CRS_Pipeline_CardDetectorStage::~CRS_Pipeline_CardDetectorStage() {
    std::cout << "Card Detector Stage Offline!" << std::endl;

}

CRS_Pipeline_CardDetectorStage::CRS_Pipeline_CardDetectorStage() {
    std::cout << "Card Detector Stage Online!" << std::endl;
}

void CRS_Pipeline_CardDetectorStage::step() {
    //TODO
    std::cout << "CRS_Pipeline_CardDetectorStage Running!" << std::endl;
}