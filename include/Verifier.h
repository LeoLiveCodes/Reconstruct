#ifndef VERIFIER_H
#define VERIFIER_H

#include <opencv2/core.hpp>

using namespace cv;
using namespace std;

class Verifier {
public:
    Verifier();
    void verify(const vector<Mat>& images, const vector<pair<Mat,Mat>>& image_pairs, const vector<vector<KeyPoint>>& keypoints, const vector<vector<DMatch>>& matches);

private:

};

#endif
