#include "colorprocessor.h"
#include "dsoundknete.h"
#include <math.h>
#include <iostream>

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
        //Auslagern in Methode (getColorAtPoint(x,y); && checkForColor(Scalar(bgr)) ???
        int currentX = DSoundKnete::objects[i].absolutePosition.x;
        int currentY = DSoundKnete::objects[i].absolutePosition.y;
		if (currentX < 0 || currentY < 0)
		{
			cout << "error" << endl;
		}
        Vec3b currentPixel = HSV.at<Vec3b>(currentY, currentX);
        int h = currentPixel[0];

        if(h > 155 && h < 180 || h > 0 && h < 15)
            DSoundKnete::objects[i].objectColor = DSoundKnete::RED;
        if(h > 105 && h < 155)
            DSoundKnete::objects[i].objectColor = DSoundKnete::BLUE;
        if(h > 55 && h < 95)
            DSoundKnete::objects[i].objectColor = DSoundKnete::GREEN;

        /*
         * Colors: 0 = RED, 1 = GREEN, 2 = BLUE
         * Shapes: 0 = RECTANGLE, 1 = CIRCLE, 2 = TRIANGLE
         */
        //Blauer Kreis, Blaues Rechteck, rotes dreieck, roter kreis
        std::cout << "i: " << i << ", Shape: " << DSoundKnete::objects[i].objectShape
                  << ", Point: " << DSoundKnete::objects[i].absolutePosition << ", Color: "
                  << DSoundKnete::objects[i].objectColor  << endl;
    }

   return input;
}
