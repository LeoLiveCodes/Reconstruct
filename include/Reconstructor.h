#ifndef RECONSTRUCTOR_H
#define RECONSTRUCTOR_H

#include <opencv2/core.hpp>
#include "FeatureExtractor.h"
#include "FeatureMatching.h"

using namespace std;
using namespace cv;

class Reconstructor {
public:
    Reconstructor();

    void addImg(Mat& frame);
    void match();
    
private:
    std::vector<Mat> images;
    FeatureExtractor extractor;
    FeatureMatching matching;
};

#endif
