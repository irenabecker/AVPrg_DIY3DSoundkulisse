#ifndef COLORPROCESSOR_H
#define COLORPROCESSOR_H

#include "videoprocessor.h"

class ColorProcessor: public VideoProcessor
{
public:
    ColorProcessor();
    void startProcessing(const VideoFormat& format);
    cv::Mat process(const cv::Mat& input);
    void setThreshold(int threshold);
	int getX(int pObject);
	int getY(int pObject);
 private:
    int threshold;
	int avrX[1];
	int avrY[1];
	int counterX[1];
	int counterY[1];
};

#endif // COLORPROCESSOR_H
