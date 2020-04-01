#include "Reconstructor.h"
#include <opencv2/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include <opencv2/features2d.hpp>
#include "SceneGraph.h"
#include <opencv2/calib3d.hpp>
#include "Initializer.h"

using namespace cv;
using namespace std;

Reconstructor::Reconstructor() {

}

Reconstructor::Reconstructor(const Reconstructor& r) {

}

Reconstructor& Reconstructor::operator=(const Reconstructor& r) {

}

Reconstructor::~Reconstructor() {
    delete init;
    init = nullptr;
}

void Reconstructor::addImg(Mat& frame) {
    if (keyframes.size() > 3) return;
    
    // convert to grayscale
    Mat gray;
    cvtColor(frame, gray, COLOR_BGR2GRAY);

    KeyFrame kf(gray);
    keyframes.push_back(gray);
}

void Reconstructor::reconstruct() {
    vector<pair<vector<KeyPoint>,vector<KeyPoint>>> keypoint_pairs;
    vector<vector<DMatch>> image_pair_matches;
    SceneGraph* graph = new SceneGraph(keyframes.size());
    for (int i = 0; i < keyframes.size()-1; ++i) {
        for (int j = i+1; j < keyframes.size(); ++j) {
            Mat desc1 = keyframes.at(i).get_desc();
            Mat desc2 = keyframes.at(i).get_desc();
            Ptr<DescriptorMatcher> matcher = DescriptorMatcher::create(DescriptorMatcher::FLANNBASED);
            vector<DMatch> matches;
            matcher->match(desc1, desc2, matches);
            keypoint_pairs.push_back(make_pair(keyframes.at(i).get_keypoints(), keyframes.at(j).get_keypoints()));
            image_pair_matches.push_back(matches);
            
            //sort matches by score
            sort(matches.begin(), matches.end());

            //remove bad matches
            const int num_good_matches = matches.size() * 0.1;
            matches.erase(matches.begin()+num_good_matches, matches.end());

            // verification
            vector<Point2f> points1, points2;
            for (size_t k = 0; k < matches.size(); k++) {
                points1.push_back(keyframes.at(i).get_keypoints().at(matches[k].queryIdx).pt);
                points2.push_back(keyframes.at(j).get_keypoints().at(matches[k].trainIdx).pt);
            }
            
            Mat mask;
            Mat f = findFundamentalMat(points1, points2, mask);
            int inliers = 0;
            for (int row = 0; row < mask.rows; ++row) {
                if (mask.at<uchar>(row, 0) == 1) inliers++;
            }
            if (inliers > 100) {
                graph->addEdge(i,j);
            }
        }
    }
    Mat K;
    init = new Initializer(*graph, K, keyframes);
}
