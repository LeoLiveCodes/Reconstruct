#ifndef INITIALIZER_H
#define INITIALIZER_H

#include "SceneGraph.h"
#include <opencv2/core/mat.hpp>
#include "KeyFrame.h"

using namespace cv;

class Initializer {
public:
    Initializer(const SceneGraph& graph, Mat K, const vector<KeyFrame>& keyframes);
private:
  

};

#endif
