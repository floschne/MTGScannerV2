//
// Created by p0w3r on 06.03.16.
//

#include <iostream>
#include "CRS_Pipeline_ROIExtractorStage.h"


//singleton global ptr initialization - The pointer is being
// allocated - not the object itself.
CRS_Pipeline_ROIExtractorStage* CRS_Pipeline_ROIExtractorStage::_instance = nullptr;

CRS_Pipeline_ROIExtractorStage* CRS_Pipeline_ROIExtractorStage::getInstance() {
    if (!_instance)
        _instance = new CRS_Pipeline_ROIExtractorStage();

    return _instance;
}

CRS_Pipeline_ROIExtractorStage::~CRS_Pipeline_ROIExtractorStage() {
    std::cout << "RoI Extractor Stage Offline!" << std::endl;

}

CRS_Pipeline_ROIExtractorStage::CRS_Pipeline_ROIExtractorStage() {
    std::cout << "RoI Extractor Stage Online!" << std::endl;
}

void CRS_Pipeline_ROIExtractorStage::step() {
    //TODO
    std::cout << "CRS_Pipeline_ROIExtractorStage Running!" << std::endl;
}

void CRS_Pipeline_ROIExtractorStage::setSecondOutputBuffer(CRS_Pipeline_DataBuffer<cv::Mat *> *outBuf2) {
    _secondOutputBuffer = outBuf2;
}
