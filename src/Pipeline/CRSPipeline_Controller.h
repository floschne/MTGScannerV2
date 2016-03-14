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
#include "CRSPipeline_DataBuffer.h"

class CRSPipeline_Controller {
public:
    static CRSPipeline_Controller *getInstance();

    ~CRSPipeline_Controller();

private:
    static CRSPipeline_Controller *_instance;

    CRSPipeline_Controller(); //only instantiate via getInstance!
    CRSPipeline_Controller(const CRSPipeline_Controller &); //no copy con!

    /*
     * Pointer to Stages of the Pipeline
     */
    CardDetectorStage *_cardDetectorStage;
    ROIExtractorStage *_roiExtractorStage;
    CardNameExtractorStage *_cardNameExtractorStage;
    SetNameExtractorStage *_setNameExtractorStage;
    MultiverseIDResolverStage *_multiverseIDResolverStage;

    /*
     * Pointer to FIFO Buffers for the Pipeline Stages
     */
    CRSPipeline_DataBuffer<cv::Mat *> *_rawCardImage_FIFO;
    CRSPipeline_DataBuffer<cv::Mat *> *_singleCardImage_FIFO;
    CRSPipeline_DataBuffer<cv::Mat *> *_setNameROI_FIFO;
    CRSPipeline_DataBuffer<cv::Mat *> *_cardNameROI_FIFO;
    CRSPipeline_DataBuffer<std::string> *_setNameString_FIFO;
    CRSPipeline_DataBuffer<std::string> *_cardNameString_FIFO;
    CRSPipeline_DataBuffer<std::string> *_multiverseIDString_FIFO;
};


#endif //CARDRECOGNITIONSYSTEM_CRSPIPELINE_H
