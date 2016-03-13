//
// Created by p0w3r on 06.03.16.
//

#ifndef MTGSCANNERV2_ROIEXTRACTOR_H
#define MTGSCANNERV2_ROIEXTRACTOR_H

#include <opencv2/core/mat.hpp>
#include "CRSPipeline_Stage.h"

class ROIExtractorStage : public CRSPipeline_Stage<cv::Mat, cv::Mat> {
public:
    static ROIExtractorStage* getInstance();
    ~ROIExtractorStage();

private:
    static ROIExtractorStage* _instance;
    ROIExtractorStage();
    ROIExtractorStage(const ROIExtractorStage&);

    virtual void run();
};


#endif //MTGSCANNERV2_ROIEXTRACTOR_H
