//
// Created by p0w3r on 13.03.16.
//

#ifndef CARDRECOGNITIONSYSTEM_CARDDETECTORSTAGE_H
#define CARDRECOGNITIONSYSTEM_CARDDETECTORSTAGE_H

#include <opencv2/core/mat.hpp>
#include "CRSPipeline_Stage.h"

class CardDetectorStage : public CRSPipeline_Stage<cv::Mat*, cv::Mat*> {
public:
    static CardDetectorStage* getInstance();
    ~CardDetectorStage();

private:
    static CardDetectorStage* _instance;
    CardDetectorStage();
    CardDetectorStage(const CardDetectorStage&);

    virtual void run();
};


#endif //CARDRECOGNITIONSYSTEM_CARDDETECTORSTAGE_H
