//
// Created by p0w3r on 13.03.16.
//

#ifndef CARDRECOGNITIONSYSTEM_CRSPIPELINE_H
#define CARDRECOGNITIONSYSTEM_CRSPIPELINE_H


#include "CardDetectorStage.h"
#include "ROIExtractorStage.h"
#include "CardNameExtractorStage.h"
#include "SetNameExtractorStage.h"
#include "MultiverseIDResolverStage.h"

class CRSPipeline {
public:
    static CRSPipeline* getInstance();
    ~CRSPipeline();

private:
    static CRSPipeline* _instance;
    CRSPipeline(); //only instantiate via getInstance!
    CRSPipeline(const CRSPipeline&); //no copy con!

    /*
     * Stages of the Pipeline
     */
    CardDetectorStage _cardDetectorStage;
    ROIExtractorStage _roiExtractorStage;
    CardNameExtractorStage _cardNameExtractorStage;
    SetNameExtractorStage _setNameExtractorStage;
    MultiverseIDResolverStage _multiverseIDResolverStage;

    /*
     * FIFO Buffers of the Pipeline
     */
    CRSPipelineStageDataBuffer<cv::Mat> _rawCardImage_FIFO;
    CRSPipelineStageDataBuffer<cv::Mat> _singleCardImage_FIFO;
    CRSPipelineStageDataBuffer<cv::Mat> _setNameROI_FIFO;
    CRSPipelineStageDataBuffer<cv::Mat> _cardNameROI_FIFO;
    CRSPipelineStageDataBuffer<std::string> _setNameString_FIFO;
    CRSPipelineStageDataBuffer<std::string> _cardNameString_FIFO;
    CRSPipelineStageDataBuffer<std::string> _multiverseIDString_FIFO;
};


#endif //CARDRECOGNITIONSYSTEM_CRSPIPELINE_H
