//
// Created by p0w3r on 06.03.16.
//

#include <opencv2/imgproc/types_c.h>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include "CardDetector.h"

CardDetector::CardDetector() {
    std::cout << "Card Detector Online" << std::endl;
}

cv::Mat CardDetector::detectCard(const cv::Mat &img) {
    if(!img.empty() )
    {
        cv::Mat resultImage = img.clone();
        cv::Mat workingImage = img.clone();
        //convert to greyscale
        cv::cvtColor(img, workingImage, CV_BGR2GRAY);

        //convert to binary black white using canny (for gradient edge detection)
        cv::Canny(workingImage, workingImage, 0, 50, 5); //TODO parameters

        //the contour vector that stores all points of contours
        std::vector<std::vector<cv::Point> > contours;
        //find the contours in the binary image
        cv::findContours(workingImage, contours, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_SIMPLE);

        //iterate over each contour and find the one with the largest area
        int largestAreaIndex = 0;
        double largestArea = 0.0;
        cv::Rect boundingRect;
        for(int i=0;i < contours.size();i++) {
            //calculate the area of the contour
            double area = cv::contourArea(contours[i], false);
            //if the area is larger than the largest set new largest and create bounding rect for the contour
            if(area > largestArea) {
                largestArea = area;
                largestAreaIndex = i;
                boundingRect = cv::boundingRect(contours[i]);
            }
        }

        //draw the bounding rectangle around the biggest contour
        cv::drawContours(resultImage, contours, largestAreaIndex, cv::Scalar(255,0,0), CV_FILLED);
        cv::rectangle(resultImage, boundingRect, cv::Scalar(0,255,0));

        return resultImage;
    }
    return cv::Mat();
}
