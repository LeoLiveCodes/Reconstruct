#include "Verifier.h"
#include "SceneGraph.h"
#include <opencv2/core.hpp>
#include <opencv2/calib3d.hpp>

using namespace cv;

Verifier::Verifier() {

}

void Verifier::verify(const vector<Mat>& images, const vector<pair<Mat, Mat>>& image_pairs, const vector<vector<KeyPoint>>& kps, const vector<vector<DMatch>>& matches) {
    SceneGraph* graph = new SceneGraph(images.size());
    cout << "asdf" << endl;
    cout << "Image Pairs: " << image_pairs.size() << endl;
    for (int i = 0; i < image_pairs.size(); i++) {
        vector<Point2f> points1, points2;
        for( size_t j = 0; i < matches.at(i).size(); j++ ) {
            cout << 1 << endl;
            int k = (matches[i][j].queryIdx);
            cout << 5 << endl;
	          points1.push_back( kps.at(i).at(matches[i][j].queryIdx).pt );
            cout << 2 << endl;
	          points2.push_back( kps.at(i).at(matches[i][j].trainIdx).pt );
            cout << 3 << endl;
	      }
        Mat h = findHomography(points1, points2, RANSAC);
    }
    cout << "asdf" << endl;
}
