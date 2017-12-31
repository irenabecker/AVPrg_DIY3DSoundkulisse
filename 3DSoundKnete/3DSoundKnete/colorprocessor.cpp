#include "colorprocessor.h"
#include <math.h>
using namespace cv;

ColorProcessor::ColorProcessor()
    :threshold(0)
{

}

void ColorProcessor::startProcessing(const VideoFormat& format)
{}

void ColorProcessor::setThreshold(int threshold){
    this->threshold = threshold;
}


cv::Mat ColorProcessor::process(const cv::Mat& input){
   Mat output(input.rows, input.cols, input.type());
   for(int x = 0; x < input.cols; x++){
       for(int y = 0; y < input.rows; y++){
           Vec3b inputPixel = input.at<Vec3b>(y,x);
           int r = inputPixel[2];
           int g = inputPixel[1];
           int b = inputPixel[0];

           int distance = sqrt((r-101)*(r-101) + (g-33)*(g-33) + (b-40)*(b-40));

           if(distance < threshold){
               r = g = b = 255;
           }
           else{
               r = g = b = 0;
           }
           Vec3b outputPixel(b, g, r);
           output.at<Vec3b>(y,x) = outputPixel;
       }
   }
   return output;
}
