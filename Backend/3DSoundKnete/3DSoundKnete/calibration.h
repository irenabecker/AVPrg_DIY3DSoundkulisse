#ifndef CALIBRATION_H
#define CALIBRATION_H

#include <stdio.h>
#include <opencv2/opencv.hpp>

class Calibration {
public:
    Calibration();
    static cv::Point calcRelative(int globalX, int globalY);
    static void calibrate();
    static bool getCalibrated() {return calibrated;}
private:
    static int boardWidth, boardHeight;
    static bool calibrated;
    static std::vector<int> globalXReferences;
    static std::vector<int> globalYReferences;
};

#endif // CALIBRATION_H
