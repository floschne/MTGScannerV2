//
// Created by p0w3r on 06.03.16.
//

#include <iostream>
#include "SetNameExtractorStage.h"

//singleton global ptr initialization - The pointer is being
// allocated - not the object itself.
SetNameExtractorStage* SetNameExtractorStage::_instance = nullptr;

SetNameExtractorStage *SetNameExtractorStage::getInstance() {
    if (!_instance)
        _instance = new SetNameExtractorStage();

    return _instance;
}

SetNameExtractorStage::~SetNameExtractorStage() {
    std::cout << "Set Name Extractor Stage Offline!" << std::endl;

}

SetNameExtractorStage::SetNameExtractorStage() {
    std::cout << "Set Name Extractor Stage Online!" << std::endl;
}

void SetNameExtractorStage::run() {
    //TODO
    std::cout << "SetNameExtractorStage Running!" << std::endl;
}