//
// Created by p0w3r on 06.03.16.
//

#ifndef MTGSCANNERV2_SETNAMEEXTRACTOR_H
#define MTGSCANNERV2_SETNAMEEXTRACTOR_H

#include <opencv2/core/mat.hpp>
#include "CRSPipeline_Stage.h"

class SetNameExtractorStage : public CRSPipeline_Stage<cv::Mat, std::string> {
public:
    static SetNameExtractorStage* getInstance();
    ~SetNameExtractorStage();

private:
    SetNameExtractorStage();
    SetNameExtractorStage(const SetNameExtractorStage&);
    static SetNameExtractorStage* _instance;

    virtual void run();
};


#endif //MTGSCANNERV2_SETNAMEEXTRACTOR_H
