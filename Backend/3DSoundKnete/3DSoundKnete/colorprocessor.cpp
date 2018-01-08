#include "colorprocessor.h"
#include <math.h>
using namespace cv;

ColorProcessor::ColorProcessor()
    :threshold(10)
{

}

void ColorProcessor::startProcessing(const VideoFormat& format)
{}

void ColorProcessor::setThreshold(int threshold){
    this->threshold = threshold;
}


cv::Mat ColorProcessor::process(const cv::Mat& input){
   HSV(input.rows, input.cols, input.type());
   cvtColor(input, HSV, COLOR_BGR2HSV);

   //Loop through each item in the list and colorize it
   for(int i = 0; i < items.size(); i++)
   {
       inRange(HSV,
               Scalar(items[i].H_MIN, items[i].H_MIN, items[i].H_MIN),
               Scalar(items[i].H_MIN, items[i].H_MIN, items[i].H_MIN),
               items[i]);
       morphologicalOpening(items[i]);
       morphologicalClosing(items[i]);
   }

   return output;
}

void ColorProcessor::drawItem(int x, int y, item itemToDraw)
{

}
