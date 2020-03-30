#ifndef FEATURE_EXTRACTOR_H
#define FEATURE_EXTRACTOR_H

#include <opencv2/core.hpp>

using namespace std;
using namespace cv;

class FeatureExtractor {
public:
    FeatureExtractor();

    void extract(const Mat& img);
    vector<vector<KeyPoint>> get_keypoints();
    vector<Mat> get_descriptors();

private:
    vector<vector<KeyPoint>> keypoints;
    vector<Mat> descriptors;

};

#endif