#include "Initializer.h"
#include <iostream>
#include <opencv2/core.hpp>

using namespace std;
using namespace cv;

Initializer::Initializer(const SceneGraph& graph, Mat K, const vector<KeyFrame>& keyframes) {
    KeyFrame frame1 = keyframes.at(0);

    Mat p_prime;
    Mat id = Mat::eye(3,3,CV_32F);
    Mat z = Mat::zeros(3,1,CV_32F);
    cv::hconcat(id, z, p_prime);
    
    // Extract keypoint vector
    Mat q_prime_i(frame1.get_keypoints().size(), 2, CV_32F);
    for (int i = 0; i < frame1.get_keypoints().size(); ++i) {
        q_prime_i.at<float>(i,0) = frame1.get_keypoints().at(i).pt.x;
        q_prime_i.at<float>(i,1) = frame1.get_keypoints().at(i).pt.y;
    }

    Mat K_for_now = Mat::eye(3,3,CV_32F);
    Mat covariance;
    /*
    Mat x_prime_i = K_for_now.inv().dot(q_prime_i);
    Mat c_prime_i = K_for_now.inv().dot(covariance).dot(K_for_now.inv().t());
    */
}
