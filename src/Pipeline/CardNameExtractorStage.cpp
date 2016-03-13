//
// Created by p0w3r on 06.03.16.
//

#include <iostream>
#include "CardNameExtractorStage.h"

CardNameExtractorStage *CardNameExtractorStage::getInstance() {
    if (!_instance)
        _instance = new CardNameExtractorStage();

    return _instance;
}

CardNameExtractorStage::~CardNameExtractorStage() {
    std::cout << "Card Name Extractor Stage Offline!" << std::endl;

}

CardNameExtractorStage::CardNameExtractorStage() {
    std::cout << "Card Name Extractor Stage Online!" << std::endl;
}

void CardNameExtractorStage::run() {
    //TODO
    std::cout << "CardNameExtractorStage Running!" << std::endl;
}
