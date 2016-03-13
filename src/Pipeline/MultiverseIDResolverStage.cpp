//
// Created by p0w3r on 06.03.16.
//

#include <iostream>
#include "MultiverseIDResolverStage.h"

MultiverseIDResolverStage *MultiverseIDResolverStage::getInstance() {
    if (!_instance)
        _instance = new MultiverseIDResolverStage();

    return _instance;
}

MultiverseIDResolverStage::~MultiverseIDResolverStage() {
    std::cout << "MultiverseID Resolver Stage Offline!" << std::endl;

}

MultiverseIDResolverStage::MultiverseIDResolverStage() {
    std::cout << "MultiverseID Resolver Stage Online!" << std::endl;
}

void MultiverseIDResolverStage::run() {
    //TODO
    std::cout << "MultiverseIDResolverStage Running!" << std::endl;
}