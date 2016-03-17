//
// Created by p0w3r on 06.03.16.
//

#ifndef MTGSCANNERV2_CARDNAMEEXTRACTOR_H
#define MTGSCANNERV2_CARDNAMEEXTRACTOR_H


#include <opencv2/core/mat.hpp>
#include "CRS_Pipeline_Stage.h"

class CRS_Pipeline_CardNameExtractorStage : public CRS_Pipeline_Stage<cv::Mat*, std::string> {
public:
    static CRS_Pipeline_CardNameExtractorStage* getInstance();
    virtual ~CRS_Pipeline_CardNameExtractorStage();

private:
    static CRS_Pipeline_CardNameExtractorStage* _instance;
    CRS_Pipeline_CardNameExtractorStage();
    CRS_Pipeline_CardNameExtractorStage(const CRS_Pipeline_CardNameExtractorStage&) = delete;
    CRS_Pipeline_CardNameExtractorStage& operator=(const CRS_Pipeline_CardNameExtractorStage&) = delete;


    virtual void step() override;
};


#endif //MTGSCANNERV2_CARDNAMEEXTRACTOR_H
