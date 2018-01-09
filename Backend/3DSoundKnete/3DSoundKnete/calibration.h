#ifndef CALIBRATION_H
#define CALIBRATION_H

#include <stdio.h>

class Calibration {
public:
    cv::Point calcRelative(int globalX, int globalY);
    void calibrate();
private:
    int boardWidth, boardHeight;
    std::vector<int> globalXReferences;
    std::vector<int> globalYReferences;
};

#endif // CALIBRATION_H
