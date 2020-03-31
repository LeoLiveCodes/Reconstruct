#ifndef MATCHING_H
#define MATCHING_H

#include <vector>
#include <opencv2/core.hpp>


using namespace std;
using namespace cv;


class Matching {

public:
    Matching();
    void match(const vector<Mat>& images, const vector<vector<cv::KeyPoint>>& kps, const vector<Mat>& descs);
    vector<pair<Mat, Mat>> get_image_pairs();
    vector<vector<DMatch>> get_feature_corr();

private:
    vector<pair<Mat, Mat>> image_pairs;
    vector<vector<DMatch>> feature_corr;
};

#endif
