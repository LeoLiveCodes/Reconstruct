#include "Initializer.h"
#include <iostream>
#include <opencv2/core.hpp>

using namespace std;
using namespace cv;

Initializer::Initializer(const SceneGraph& graph, Mat K, const vector<KeyFrame>& keyframes) {
    KeyFrame frame1 = keyframes.at(0);
    KeyFrame frame2 = keyframes.at(1);


/*
    // p_prime = [I|0]
    Mat p_prime;
    Mat id = Mat::eye(3,3,CV_32F);
    Mat z = Mat::zeros(3,1,CV_32F);
    cv::hconcat(id, z, p_prime);
    
    // Extract keypoint vector
    Mat q_prime_i(frame1.get_keypoints().size(), 2, CV_32F);

    for (int i = 0; i < frame1.get_keypoints().size(); ++i) {
        float x = frame1.get_keypoints().at(i).pt.x;
        float y = frame1.get_keypoints().at(i).pt.y;
        
        q_prime_i.at<float>(i,0) = x;
        q_prime_i.at<float>(i,1) = y;
    }

    // Extract Covariance matrix
    Mat covar, mean; 
    calcCovarMatrix(q_prime_i, covar, mean, COVAR_ROWS | COVAR_NORMAL);

    // calibrate keypoints
    Mat K_for_now = Mat::eye(3,3,CV_64F);
    Mat x_prime_i = K_for_now.inv() * q_prime_i;

    // calibrate covariance
    Mat calibCovar = K_for_now.inv() * covar * K_for_now.inv().t();
*/

    
}
