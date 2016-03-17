//
// Created by p0w3r on 06.03.16.
//

#include <iostream>
#include "CRS_Pipeline_SetNameExtractorStage.h"

//singleton global ptr initialization - The pointer is being
// allocated - not the object itself.
CRS_Pipeline_SetNameExtractorStage* CRS_Pipeline_SetNameExtractorStage::_instance = nullptr;

CRS_Pipeline_SetNameExtractorStage* CRS_Pipeline_SetNameExtractorStage::getInstance() {
    if (!_instance)
        _instance = new CRS_Pipeline_SetNameExtractorStage();

    return _instance;
}

CRS_Pipeline_SetNameExtractorStage::~CRS_Pipeline_SetNameExtractorStage() {
    std::cout << "Set Name Extractor Stage Offline!" << std::endl;

}

CRS_Pipeline_SetNameExtractorStage::CRS_Pipeline_SetNameExtractorStage() {
    std::cout << "Set Name Extractor Stage Online!" << std::endl;
}

void CRS_Pipeline_SetNameExtractorStage::step() {
    //TODO
    std::cout << "CRS_Pipeline_SetNameExtractorStage Running!" << std::endl;
}