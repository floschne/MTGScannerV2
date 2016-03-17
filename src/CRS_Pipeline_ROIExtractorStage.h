//
// Created by p0w3r on 06.03.16.
//

#ifndef MTGSCANNERV2_ROIEXTRACTOR_H
#define MTGSCANNERV2_ROIEXTRACTOR_H

#include <opencv2/core/mat.hpp>
#include "CRS_Pipeline_Stage.h"

class CRS_Pipeline_ROIExtractorStage : public CRS_Pipeline_Stage<cv::Mat*, cv::Mat*> {
public:
    static CRS_Pipeline_ROIExtractorStage* getInstance();
    virtual ~CRS_Pipeline_ROIExtractorStage();

    void setSecondOutputBuffer(CRS_Pipeline_DataBuffer<cv::Mat*>* outBuf2);

private:
    static CRS_Pipeline_ROIExtractorStage* _instance;
    CRS_Pipeline_ROIExtractorStage();
    CRS_Pipeline_ROIExtractorStage(const CRS_Pipeline_ROIExtractorStage&);

    //special stage with two output buffers! //TODO make own class ?! Multi In- & Output Buffer Stages
    CRS_Pipeline_DataBuffer<cv::Mat*>* _secondOutputBuffer;

    virtual void step() override;
};


#endif //MTGSCANNERV2_ROIEXTRACTOR_H
