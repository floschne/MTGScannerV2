//
// Created by p0w3r on 06.03.16.
//

#ifndef MTGSCANNERV2_RECTANGLEDETECTOR_H
#define MTGSCANNERV2_RECTANGLEDETECTOR_H


#include <opencv2/core.hpp>


class CardDetector {
public:
    CardDetector();
    cv::Mat detectCard(const cv::Mat &img);
private:

};


#endif //MTGSCANNERV2_RECTANGLEDETECTOR_H
