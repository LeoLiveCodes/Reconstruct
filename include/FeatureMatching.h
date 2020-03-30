#ifndef FEATURE_MATCHING_H
#define FEATURE_MATCHING_H

#include <vector>
#include <opencv2/core.hpp>


using namespace std;
using namespace cv;


class FeatureMatching {

public:
   FeatureMatching();
   void match(const vector<vector<cv::KeyPoint>>& kps, const vector<Mat>& descs);

private:


};

#endif
