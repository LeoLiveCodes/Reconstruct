#include "Reconstructor.h"
#include <opencv2/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>

using namespace cv;

Reconstructor::Reconstructor() {
    extractor = new FeatureExtractor();
    matching = new Matching();
}

Reconstructor::Reconstructor(const Reconstructor& r) {

}

Reconstructor& Reconstructor::operator=(const Reconstructor& r) {

}

Reconstructor::~Reconstructor() {
    delete extractor;
    delete matching;
}

void Reconstructor::addImg(Mat& frame) {
    if (images.size() > 3) return;
    Mat gray;
    cvtColor(frame, gray, COLOR_BGR2GRAY);
    images.push_back(gray);
    extractor->extract(gray);
}

void Reconstructor::reconstruct() {
    matching->match(images, extractor->get_keypoints(), extractor->get_descriptors());
    verifier->verify(images, matching->get_image_pairs(), extractor->get_keypoints(), matching->get_feature_corr());
}
