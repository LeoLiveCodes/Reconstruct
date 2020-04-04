#include <iostream>
#include <stdio.h>
#include <opencv2/core.hpp>
#include "Reconstructor.h"
#include <opencv2/imgproc.hpp>  // Gaussian Blur
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>

using namespace cv;

int main() {
    Reconstructor* r = new Reconstructor();
    string filename = "SampleVideo_1280x720_1mb.mp4";
    VideoCapture capture(filename);
    Mat frame;

    if( !capture.isOpened() )
        throw "Error when reading steam_avi";
    
    std::cout << "Extracting features..." << std::endl;
    for( ; ; )
    {
        capture >> frame;
        if(frame.empty())
            break;
        r->addImg(frame);
    }
    std::cout << "Starting reconstruction..." << std::endl;
    r->reconstruct();
}

