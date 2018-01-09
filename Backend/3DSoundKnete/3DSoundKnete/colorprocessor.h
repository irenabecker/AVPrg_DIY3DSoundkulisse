#ifndef COLORPROCESSOR_H
#define COLORPROCESSOR_H

#include "videoprocessor.h"

class ColorProcessor: public VideoProcessor
{
public:
    ColorProcessor();
    void startProcessing(const VideoFormat& format);
    cv::Mat process(const cv::Mat& input);
    //store the converted image here
    cv::Mat HSV;

 private:
    int getHueAtPoint(int x, int y);
    int checkForColor(int hueToCheck);
};

#endif // COLORPROCESSOR_H
