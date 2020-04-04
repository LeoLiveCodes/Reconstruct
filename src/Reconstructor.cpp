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
    // if (keyframes.size() > 10) return;
    
    // convert to grayscale
    Mat gray;
    cvtColor(frame, gray, COLOR_BGR2GRAY);

    KeyFrame kf(gray);
    keyframes.push_back(gray);
}

void Reconstructor::reconstruct() {
    cout << keyframes.size() << " total images" << endl;
    vector<pair<vector<KeyPoint>,vector<KeyPoint>>> keypoint_pairs;
    vector<vector<DMatch>> image_pair_matches;
    SceneGraph* graph = new SceneGraph(keyframes.size());

    for (int i = 0; i < keyframes.size(); ++i) {        
        for (int k = 1; k < 3; ++k) {
            if ((i+k) >= keyframes.size()) continue;
            int j = i+k;
            Mat desc1 = keyframes.at(i).get_desc();
            Mat desc2 = keyframes.at(j).get_desc();
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
    
    cout << "Finding initial image pair..." << endl;
    // find initial image pair
    pair<int,int> initial_image_pair;
    // get all images with correspondences
    vector<KeyFrame> images_with_corr;
    vector<int> img1_idx;
    graph->GetNodesWithMatches(img1_idx);
    cout << img1_idx.size() << " images with matches" << endl;
    bool flag = false;
    for (const auto &idx1 : img1_idx) {
        KeyFrame &im1 = keyframes.at(idx1);
        // get all matches
        list<int> img2_idx = graph->GetImageMatches(idx1);
        cout << "Image " << idx1 << " has " << img2_idx.size() << " matches." << endl;
        for (const auto &idx2 : img2_idx) {
            KeyFrame &im2 = keyframes.at(idx2);
            // Check im1, im2 pair for initialization
            // ...
            initial_image_pair = make_pair(idx1,idx2);
            flag = true;
            break;
        }
        if (flag == true)
            break;
    }
    cout << "Initial image pair: (" << initial_image_pair.first << ", " << initial_image_pair.second << ")" << endl;
    
    // Initialize using initial_image_pair
}
