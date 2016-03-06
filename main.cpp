// The "Square Detector" program.
// It loads several images sequentially and tries to find squares in
// each image

#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "CardDetector.h"

#include <iostream>


int main(int /*argc*/, char** /*argv*/)
{
    static const char* names[] = { "./data/pic1.jpg", "./data/pic2.jpg", "./data/pic3.jpg",
                                   "./data/pic4.jpg", 0 };

    cv::namedWindow( "originalImage", CV_WINDOW_AUTOSIZE);
    cv::namedWindow("detectedImage", CV_WINDOW_AUTOSIZE);

    CardDetector cd;

    for( int i = 0; names[i] != 0; i++ )
    {
        cv::Mat image = cv::imread(names[i], 1);
        if( image.empty() )
        {
            std::cout << "Couldn't load " << names[i] << std::endl;
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
