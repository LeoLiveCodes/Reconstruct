#include "FeatureMatching.h"
#include <opencv2/core.hpp>
#include <opencv2/features2d.hpp>
#include <opencv2/xfeatures2d.hpp>

using namespace std;
using namespace cv;
using namespace cv::xfeatures2d;

FeatureMatching::FeatureMatching() {

}

void FeatureMatching::match(const std::vector<std::vector<KeyPoint>>& kps, const std::vector<Mat>& descs) {
    Mat desc1 = descs.at(0);
    Mat desc2 = descs.at(1);
    Ptr<DescriptorMatcher> matcher = DescriptorMatcher::create(DescriptorMatcher::FLANNBASED);
    vector<DMatch> matches;
    matcher->match(desc1, desc2, matches);
}
