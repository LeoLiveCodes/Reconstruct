#include "FeatureExtractor.h"
#include <opencv2/core.hpp>
#include <opencv2/xfeatures2d/nonfree.hpp>
#include <opencv2/xfeatures2d.hpp>
#include <opencv2/features2d.hpp>
#include <opencv2/highgui.hpp>

using namespace cv;
using namespace cv::xfeatures2d;

FeatureExtractor::FeatureExtractor() {

}

void FeatureExtractor::extract(const Mat& img) {
   if (keypoints.size() > 1) return;
   Ptr<SIFT> sift = SIFT::create();
   vector<KeyPoint> kp;
   Mat desc;
   sift->detectAndCompute(img, Mat(), kp, desc);
   keypoints.push_back(kp);
   descriptors.push_back(desc);
}

std::vector<std::vector<KeyPoint>> FeatureExtractor::get_keypoints() {
    return keypoints;
}

std::vector<Mat> FeatureExtractor::get_descriptors() {
    return descriptors;
}
