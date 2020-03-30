#include "Reconstructor.h"
#include "FeatureExtractor.h"
#include <opencv2/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>

using namespace cv;

Reconstructor::Reconstructor() {

}

void Reconstructor::addImg(Mat& frame) {
    Mat gray;
    cvtColor(frame, gray, COLOR_BGR2GRAY);
    images.push_back(gray);
    extractor.extract(gray);
}

void Reconstructor::match() {
    matching.match(extractor.get_keypoints(), extractor.get_descriptors());
}
