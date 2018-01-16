#include "colorprocessor.h"
#include <math.h>
#include <iostream>
#include "dsoundknete.h"
#include "calibration.h"
#include "DSoundKnete.h"

using namespace std;
using namespace cv;

ColorProcessor::ColorProcessor()
{
}

void ColorProcessor::startProcessing(const VideoFormat& format)
{}

/*
 *  Foreach dataobj in the static vector, look for the color
 *  in nearby pixels
 */
cv::Mat ColorProcessor::process(const cv::Mat& input){
    cvtColor(input, HSV, COLOR_BGR2HSV);
    for(int i = 0; i < DSoundKnete::objects.size(); i++)
    {
        int currentX = DSoundKnete::objects[i].absolutePosition.x;
        int currentY = DSoundKnete::objects[i].absolutePosition.y;
        Vec3b hsv = getHSVAtPoint(currentX, currentY);
		DSoundKnete::objects[i].objectColor = (DSoundKnete::COLOR) checkForColor(hsv[0],hsv[1],hsv[2]);
		if (DSoundKnete::objects[i].objectColor == DSoundKnete::UNKNOWN_COLOR) //remove from list, if unknown color.
		{
			DSoundKnete::objects.erase(DSoundKnete::objects.begin() + (i));}
		else if (Calibration::getCalibrated() && DSoundKnete::objects[i].objectColor == DSoundKnete::CALIBRATION_COLOR)
		{
			DSoundKnete::objects.erase(DSoundKnete::objects.begin() + (i));}
    }

   return input;
}

Vec3b ColorProcessor::getHSVAtPoint(int x, int y)
{
    Vec3b temp = HSV.at<Vec3b>(y,x);
    return temp;
}

int ColorProcessor::checkForColor(int hueToCheck, int satToCeck, int valToCheck)
{
    if(valToCheck < 85&&!Calibration::getCalibrated())
        return DSoundKnete::CALIBRATION_COLOR;
    if(hueToCheck > 155 && hueToCheck < 180 || hueToCheck > 0 && hueToCheck < 15)
        return DSoundKnete::RED;
    if(hueToCheck > 105 && hueToCheck < 155)
        return DSoundKnete::BLUE;
    if(hueToCheck > 55 && hueToCheck < 95)
        return DSoundKnete::GREEN;

    return DSoundKnete::UNKNOWN_COLOR;
}
