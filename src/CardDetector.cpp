//
// Created by p0w3r on 06.03.16.
//

#include <opencv2/imgproc/types_c.h>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include <cmath>
#include <opencv2/highgui.hpp>
#include "CardDetector.h"

CardDetector::CardDetector() {
    std::cout << "Card Detector Online" << std::endl;
}

cv::Mat CardDetector::detectCard(const cv::Mat &img) {
    if (!img.empty()) {
        cv::Mat resultImage = img.clone();
        cv::Mat workingImage = img.clone();

        //convert to greyscale
        cv::cvtColor(img, workingImage, CV_BGR2GRAY);


        int lowThreshold = 1000;
        int ratio = 3;
        int kernelSize = 5;
        /*
         * The Canny Edge detector was developed by John F. Canny in 1986. Also known to many as the optimal detector, Canny algorithm aims to satisfy three main criteria:
         *   Low error rate: Meaning a good detection of only existent edges.
         *   Good localization: The distance between edge pixels detected and real edge pixels have to be minimized.
         *   Minimal response: Only one detector response per edge.
         *
         *
         * Canny does use two thresholds (upper and lower):
         *  If a pixel gradient is higher than the upper threshold, the pixel is accepted as an edge
         *  If a pixel gradient value is below the lower threshold, then it is rejected.
         *  If the pixel gradient is between the two thresholds, then it will be accepted only if it is connected to a pixel that is above the upper threshold.
         *  Canny recommended a upper:lower ratio between 2:1 and 3:1.
         */
        cv::Canny(workingImage, workingImage, lowThreshold, lowThreshold * ratio, kernelSize);
        cv::namedWindow("blur", CV_WINDOW_AUTOSIZE);
        cv::imshow("blur", workingImage);

        //the contour vector that stores all points of all contours
        std::vector<std::vector<cv::Point> > contours;
        //find the contours in the binary image
        cv::findContours(workingImage, contours, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_SIMPLE);

        //TODO approxPoly vergessen -> auf 4 eck testen ?!

        //iterate over each contour and find the one with the largest area
        int largestAreaIndex = 0;
        double largestArea = 0.0;
        cv::Rect boundingRect = cv::Rect();
        for (uint i = 0; i < contours.size(); i++) {
            // The array for storing the approximation curve
            std::vector<cv::Point> approx;
            // Approximate contour with accuracy proportional
            // to the contour perimeter
            cv::approxPolyDP(
                    cv::Mat(contours[i]),
                    approx,
                    cv::arcLength(cv::Mat(contours[i]), true) * 0.02,
                    true
            );

            // Skip small or non-convex objects
            if (std::fabs(cv::contourArea(contours[i])) < 100 || !cv::isContourConvex(approx))
                continue;

            if (approx.size()== 4) {
                //calculate the area of the contour
                double area = cv::contourArea(contours[i], false);
                //if the area is larger than the largest set new largest and create bounding rect for the contour
                if (area > largestArea) {
                    largestArea = area;
                    largestAreaIndex = i;
                    boundingRect = cv::boundingRect(contours[i]);
                    double aspectRatio = (double) boundingRect.width / boundingRect.height;

                    double aspcetRatioDiff = std::fabs(aspectRatio - MTGCARD_ASPECT_RATIO);
                    double areaDiff = std::fmod(area, MTG_CARD_AREA);

                    std::cout << "ratDiff " << aspcetRatioDiff << " - areaDiff " << areaDiff << std::endl;

                    //compare aspect ratios -> when their absolute diff is in treshholds -> detected card -> break loop
                    if (aspcetRatioDiff <= ASPECT_RATIO_DIFFERENCE_TRESHHOLD) {
                        //compare areas -> when their absolute diff is in treshholds -> detected card -> break loop
                        if (areaDiff <= AREA_MODULO_TRESHHOLD) {
                        }
                        break;
                    }
                }

            }


        }

        //draw the bounding rectangle around the biggest contour and fill contour blue
        cv::drawContours(resultImage, contours, largestAreaIndex, cv::Scalar(255, 0, 0), CV_FILLED);
        //cv::rectangle(resultImage, boundingRect, cv::Scalar(0,255,0));

        cv::Mat cardRoI = resultImage.clone();
        cardRoI = resultImage(boundingRect);

        if (!cardRoI.empty())
            return cardRoI;
        else {
            return resultImage;
        }
    }
    return cv::Mat();
}
