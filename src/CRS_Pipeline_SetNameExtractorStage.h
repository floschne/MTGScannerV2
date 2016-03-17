//
// Created by p0w3r on 06.03.16.
//

#ifndef MTGSCANNERV2_SETNAMEEXTRACTOR_H
#define MTGSCANNERV2_SETNAMEEXTRACTOR_H

#include <opencv2/core/mat.hpp>
#include "CRS_Pipeline_Stage.h"

class CRS_Pipeline_SetNameExtractorStage : public CRS_Pipeline_Stage<cv::Mat*, std::string> {
public:
    static CRS_Pipeline_SetNameExtractorStage* getInstance();
    virtual ~CRS_Pipeline_SetNameExtractorStage();

private:
    CRS_Pipeline_SetNameExtractorStage();
    CRS_Pipeline_SetNameExtractorStage(const CRS_Pipeline_SetNameExtractorStage&);
    static CRS_Pipeline_SetNameExtractorStage* _instance;

    virtual void step() override;
};


#endif //MTGSCANNERV2_SETNAMEEXTRACTOR_H
