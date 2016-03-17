//
// Created by p0w3r on 06.03.16.
//

#include <iostream>
#include "CRS_Pipeline_CardNameExtractorStage.h"

//singleton global ptr initialization - The pointer is being
// allocated - not the object itself.
CRS_Pipeline_CardNameExtractorStage* CRS_Pipeline_CardNameExtractorStage::_instance = nullptr;

CRS_Pipeline_CardNameExtractorStage* CRS_Pipeline_CardNameExtractorStage::getInstance() {
    if (!_instance)
        _instance = new CRS_Pipeline_CardNameExtractorStage();

    return _instance;
}

CRS_Pipeline_CardNameExtractorStage::~CRS_Pipeline_CardNameExtractorStage() {
    std::cout << "Card Name Extractor Stage Offline!" << std::endl;

}

CRS_Pipeline_CardNameExtractorStage::CRS_Pipeline_CardNameExtractorStage() {
    std::cout << "Card Name Extractor Stage Online!" << std::endl;
}

void CRS_Pipeline_CardNameExtractorStage::step() {
    //TODO
    std::cout << "CRS_Pipeline_CardNameExtractorStage Running!" << std::endl;
}
