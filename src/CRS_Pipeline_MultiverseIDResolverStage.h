//
// Created by p0w3r on 06.03.16.
//

#ifndef MTGSCANNERV2_CARDDATABASE_H
#define MTGSCANNERV2_CARDDATABASE_H


#include <opencv2/core/mat.hpp>
#include "CRS_Pipeline_Stage.h"

class CRS_Pipeline_MultiverseIDResolverStage : public CRS_Pipeline_Stage<std::string, std::string> {
public:
    static CRS_Pipeline_MultiverseIDResolverStage* getInstance();
    virtual ~CRS_Pipeline_MultiverseIDResolverStage();

    void setSecondInputBuffer(CRS_Pipeline_DataBuffer<std::string>* inBuf);

private:
    static CRS_Pipeline_MultiverseIDResolverStage* _instance;
    CRS_Pipeline_MultiverseIDResolverStage();
    CRS_Pipeline_MultiverseIDResolverStage(const CRS_Pipeline_MultiverseIDResolverStage&);


    CRS_Pipeline_DataBuffer<std::string>* _secondInputBuffer;

    virtual void step() override;
};


#endif //MTGSCANNERV2_CARDDATABASE_H
