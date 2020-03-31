#include "Matching.h"
#include <opencv2/core.hpp>
#include <opencv2/features2d.hpp>
#include <opencv2/xfeatures2d.hpp>
#include <iostream>

using namespace std;
using namespace cv;
using namespace cv::xfeatures2d;

Matching::Matching() {

}

void Matching::match(const vector<Mat>& images, const vector<vector<KeyPoint>>& kps, const vector<Mat>& descs) {
    for (int i = 0; i < images.size()-1; ++i) {
        for (int j = i + 1; j < images.size(); ++j) {
            Mat desc1 = descs.at(i);
            Mat desc2 = descs.at(j);
            Ptr<DescriptorMatcher> matcher = DescriptorMatcher::create(DescriptorMatcher::FLANNBASED);
            vector<DMatch> matches;
            matcher->match(desc1, desc2, matches);
            image_pairs.push_back(make_pair(images.at(i), images.at(j)));
            feature_corr.push_back(matches);
        }
    }
}

vector<pair<Mat, Mat>> Matching::get_image_pairs() {
    return image_pairs;

}

vector<vector<DMatch>> Matching::get_feature_corr() {
    return feature_corr;
}
