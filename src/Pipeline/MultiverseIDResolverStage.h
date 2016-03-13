//
// Created by p0w3r on 06.03.16.
//

#ifndef MTGSCANNERV2_CARDDATABASE_H
#define MTGSCANNERV2_CARDDATABASE_H


#include <opencv2/core/mat.hpp>
#include "CRSPipeline_Stage.h"

class MultiverseIDResolverStage : public CRSPipeline_Stage<std::string, std::string> {
public:
    static MultiverseIDResolverStage* getInstance();
    ~MultiverseIDResolverStage();

private:
    static MultiverseIDResolverStage* _instance;
    MultiverseIDResolverStage();
    MultiverseIDResolverStage(const MultiverseIDResolverStage&);

    virtual void run();
};


#endif //MTGSCANNERV2_CARDDATABASE_H
