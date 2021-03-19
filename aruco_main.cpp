#include <vector>
#include <iostream>
#include <cmath>
#include <opencv2/core.hpp>
#include "opencv2/markerdetector.h"
#include <opencv2/flann.hpp>

using namespace std;

int main(in argc, char **argv){

    // read input image
    cv::VideoCapture cam;
    cv::Mat InImage=cv::imread(argv[1]);
    aruco::MarkerDetector MDetector;

    //detect
    vector<aruco::Marker> Markers = MDetector.detect(InImage);

    for (unsinged int i = 0; i < Markers.size(); i++)
    {
        cout << endl << Markers[i] << endl;
        Markers[i].draw(InImage, cv::Scalar(0, 0, 255), 2);
    }

    // Show image with augmentation
    cv::namedWindow("Input", 1);
    cv::imshow("Input", InImage);

    // Wait for esc to be pressed
    while (char(cv::waitKey(0)) != 27)
        ;

    cam.open(argv[1]);
    while(cam.grab())
    {
        // run same code for a video
        // retrieving one key frame at a time
        // while cam is open

        cam.retrieve(InImage);
        vector<aruco::Marker> Markers_Cam = MDetector.detect(InImage);

        for (unsinged int i = 0; i < Markers_Cam.size(); i++)
        {
            cout << endl << Markers_Cam[i] << endl;
            Markers_Cam[i].draw(InImage, cv::Scalar(0, 0, 255), 2);
        }

        // Show image with augmentation
        cv::namedWindow("Input", 1);
        cv::imshow("Input", InImage);

        // Wait for esc to be pressed
        while (char(cv::waitKey(0)) != 27)
            ;

    }
}
