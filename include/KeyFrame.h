#ifndef KEYFRAME_H
#define KEYFRAME_H

#include <opencv2/core.hpp>

using namespace std;
using namespace cv;

class KeyFrame {
public:
    KeyFrame(const Mat& img);
    vector<KeyPoint> get_keypoints() const;
    Mat get_desc() const;

private:
    Mat img;
    vector<KeyPoint> keypoints;
    Mat descriptors;

};

#endif
