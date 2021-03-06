#ifndef RECONSTRUCTOR_H
#define RECONSTRUCTOR_H

#include <opencv2/core.hpp>
#include "KeyFrame.h"
#include "Initializer.h"

using namespace std;
using namespace cv;

class Reconstructor {
public:
    Reconstructor();
    Reconstructor(const Reconstructor& r);
    Reconstructor& operator=(const Reconstructor& r);
    ~Reconstructor();

    void addImg(Mat& frame);
    void reconstruct();
    
private:
    std::vector<KeyFrame> keyframes;
    Initializer* init;

};

#endif
