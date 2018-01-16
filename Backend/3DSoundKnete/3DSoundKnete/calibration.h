#ifndef CALIBRATION_H
#define CALIBRATION_H

#include <QThread>
#include <stdio.h>
#include <opencv2/opencv.hpp>

class Calibration
{
public:
    Calibration();
    static cv::Point calcRelative(int globalX, int globalY);
	static int calcZPos(int absolutePositionX, int absolutePositionY, int fillArea,int shape);
    static void calibrate();
    static bool getCalibrated() { return calibrated; }
    static std::vector<int> getGlobalXReferences() { return globalXReferences; }
    static std::vector<int> getGlobalYReferences() { return globalYReferences; }
	static int getCalibrateCounter() { return calibrateCounter; }
	static int getMaxCalTries() { return maxCalTries; }
	static int calibrateCounter;
	static std::vector<int> stdSize;
private:
    static int boardWidth, boardHeight;
    static bool calibrated;
    static std::vector<int> globalXReferences;
    static std::vector<int> globalYReferences;
	static int stdFillArea;	//same order as SHAPE: RECTANGLE, CIRCLE, TRIANGLE
	static int focalLength;
	static cv::Point boardCenter;
	
	
	static int maxCalTries;
};

#endif // CALIBRATION_H
