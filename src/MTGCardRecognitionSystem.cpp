// The "Square Detector" program.
// It loads several images sequentially and tries to find squares in
// each image

#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "CardDetector.h"

#include <iostream>


int main(int argc, char** argv)
{

    cv::namedWindow( "originalImage", CV_WINDOW_AUTOSIZE);
    cv::namedWindow("detectedImage", CV_WINDOW_AUTOSIZE);

    CardDetector cd;

    for( uint i = 1; i < argc; i++ )
    {
        cv::Mat image = cv::imread(argv[i], -1); //load image as it is (-1)
        if( image.empty() )
        {
            std::cout << "Couldn't load " << argv[i] << std::endl;
            continue;
        }

        cv::Mat detected = cd.detectCard(image);
        cv::imshow("detectedImage", detected);
        cv::imshow("originalImage", image);
        cv::waitKey(0);
    }

    cv::waitKey(0);
    return 0;
}
