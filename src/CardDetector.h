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
    const double MTGCARD_WIDTH = 63.0; //[mm]
    const double MTGCARD_HEIGHt = 88.0; //[mm]
    const double MTGCARD_ASPECT_RATIO = MTGCARD_WIDTH / MTGCARD_HEIGHt; //~aspect ration of original MTG Card in w/h [mm]
    const double ASPECT_RATIO_DIFFERENCE_TRESHHOLD = 0.01; //for comparing aspect ratios
private:

};


#endif //MTGSCANNERV2_RECTANGLEDETECTOR_H
