//
// Created by p0w3r on 13.03.16.
//

#include <iostream>
#include "CardDetectorStage.h"

CardDetectorStage *CardDetectorStage::getInstance() {
    if (!_instance)
        _instance = new CardDetectorStage();

    return _instance;
}

CardDetectorStage::~CardDetectorStage() {
    std::cout << "Card Detector Stage Offline!" << std::endl;

}

CardDetectorStage::CardDetectorStage() {
    std::cout << "Card Detector Stage Online!" << std::endl;
}

void CardDetectorStage::run() {
    //TODO
    std::cout << "CardDetectorStage Running!" << std::endl;
}