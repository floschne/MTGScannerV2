//
// Created by p0w3r on 06.03.16.
//

#ifndef MTGSCANNERV2_CARDNAMEEXTRACTOR_H
#define MTGSCANNERV2_CARDNAMEEXTRACTOR_H


#include <opencv2/core/mat.hpp>
#include "CRSPipeline_Stage.h"

class CardNameExtractorStage : public CRSPipeline_Stage<cv::Mat, std::string> {
public:
    static CardNameExtractorStage* getInstance();
    ~CardNameExtractorStage();

private:
    static CardNameExtractorStage* _instance;
    CardNameExtractorStage();
    CardNameExtractorStage(const CardNameExtractorStage&);

    virtual void run();
};


#endif //MTGSCANNERV2_CARDNAMEEXTRACTOR_H
