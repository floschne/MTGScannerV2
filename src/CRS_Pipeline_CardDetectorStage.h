//
// Created by p0w3r on 13.03.16.
//

#ifndef CARDRECOGNITIONSYSTEM_CARDDETECTORSTAGE_H
#define CARDRECOGNITIONSYSTEM_CARDDETECTORSTAGE_H

#include <opencv2/core/mat.hpp>
#include "CRS_Pipeline_Stage.h"

class CRS_Pipeline_CardDetectorStage : public CRS_Pipeline_Stage<cv::Mat*, cv::Mat*> {
public:
    static CRS_Pipeline_CardDetectorStage* getInstance();
    ~CRS_Pipeline_CardDetectorStage();

private:
    static CRS_Pipeline_CardDetectorStage* _instance;
    CRS_Pipeline_CardDetectorStage();
    CRS_Pipeline_CardDetectorStage(const CRS_Pipeline_CardDetectorStage&) = delete;
    CRS_Pipeline_CardDetectorStage& operator=(const CRS_Pipeline_CardDetectorStage&) = delete;

    virtual void step() override;
};


#endif //CARDRECOGNITIONSYSTEM_CARDDETECTORSTAGE_H
