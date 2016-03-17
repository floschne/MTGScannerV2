//
// Created by p0w3r on 06.03.16.
//

#include <iostream>
#include "CRS_Pipeline_MultiverseIDResolverStage.h"

//singleton global ptr initialization - The pointer is being
// allocated - not the object itself.
CRS_Pipeline_MultiverseIDResolverStage* CRS_Pipeline_MultiverseIDResolverStage::_instance = nullptr;

CRS_Pipeline_MultiverseIDResolverStage* CRS_Pipeline_MultiverseIDResolverStage::getInstance() {
    if (!_instance)
        _instance = new CRS_Pipeline_MultiverseIDResolverStage();

    return _instance;
}

CRS_Pipeline_MultiverseIDResolverStage::~CRS_Pipeline_MultiverseIDResolverStage() {
    std::cout << "MultiverseID Resolver Stage Offline!" << std::endl;

}

CRS_Pipeline_MultiverseIDResolverStage::CRS_Pipeline_MultiverseIDResolverStage() {
    std::cout << "MultiverseID Resolver Stage Online!" << std::endl;
}

void CRS_Pipeline_MultiverseIDResolverStage::step() {
    //TODO
    std::cout << "CRS_Pipeline_MultiverseIDResolverStage Running!" << std::endl;
}

void CRS_Pipeline_MultiverseIDResolverStage::setSecondInputBuffer(CRS_Pipeline_DataBuffer<std::string>* inBuf) {
    _secondInputBuffer = inBuf;
}
