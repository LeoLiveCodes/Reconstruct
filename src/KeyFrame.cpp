#include "KeyFrame.h"
#include <opencv2/xfeatures2d.hpp>

using namespace cv;
using namespace cv::xfeatures2d;

KeyFrame::KeyFrame(const Mat& img) : img(img) 
{
    Ptr<SIFT> sift = SIFT::create();
    sift->detectAndCompute(img, Mat(), keypoints, descriptors);
}

vector<KeyPoint> KeyFrame::get_keypoints() const {
    return keypoints;
}

Mat KeyFrame::get_desc() const {
    return descriptors;
}
