#include "colorprocessor.h"
#include "dsoundknete.h"
#include <math.h>
#include <iostream>

using namespace std;
using namespace cv;

ColorProcessor::ColorProcessor()
    :threshold(10)
{
    items.push_back(createNewItem("red", 160,255, 157, 255, 127, 255));
    items.push_back(createNewItem("yellow", 48, 22, 101, 205, 164, 253));
}

void ColorProcessor::startProcessing(const VideoFormat& format)
{}

cv::Mat ColorProcessor::process(const cv::Mat& input){
    /*
     *  Foreach dataobj in the static vector, look for the color
     *  in nearby pixels
     */

    cvtColor(input, HSV, COLOR_BGR2HSV);

    for(int i = 0; i < DSoundKnete::objects.size(); i++)
    {
        //Auslagern in Methode (getColorAtPoint(x,y); && checkForColor(Scalar(bgr)) ???
        int currentX = DSoundKnete::objects[i].position.x;
        int currentY = DSoundKnete::objects[i].position.y;
        Vec3b currentPixel = input.at<Vec3b>(currentY, currentX);
        int v = currentPixel[2];
        int s = currentPixel[1];
        int h = currentPixel[0];

        cout << "Values: " << h << "," << s << "," << v << endl;

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
                  << ", Point: " << DSoundKnete::objects[i].position << ", Color: "
                  << DSoundKnete::objects[i].objectColor  << endl;
    }

   /*
    *   ColorProcessor to detect colorized objects
    * //HSV(input.rows, input.cols, input.type());
   cvtColor(input, HSV, COLOR_BGR2HSV);
   inRange(HSV,
           Scalar(H_MIN,S_MIN,V_MIN),
           Scalar(H_MAX, S_MAX, V_MAX),
           dynamicTestItem.threshold);
    morphologicalOpening(dynamicTestItem.threshold);
    morphologicalClosing(dynamicTestItem.threshold);
   //Loop through each item in the list and colorize it
   for(int i = 0; i < items.size(); i++)
   {
       inRange(HSV,
               Scalar(items[i].H_MIN, items[i].S_MIN, items[i].V_MIN),
               Scalar(items[i].H_MAX, items[i].S_MAX, items[i].V_MAX),
               items[i].threshold);
       morphologicalOpening(items[i].threshold);
       morphologicalClosing(items[i].threshold);
       drawItem(items[i].x, items[i].y, items[i], HSV);
   }*/

   return input;
}

void ColorProcessor::drawItem(int x, int y, item itemToDraw, Mat &frame)
{
}

void ColorProcessor::morphologicalOpening(Mat &thresh)
{
    erode(thresh, thresh, erodeElement);
    dilate(thresh, thresh, erodeElement);
}

void ColorProcessor::morphologicalClosing(Mat &thresh)
{
    dilate(thresh, thresh, dilateElement);
    erode(thresh, thresh, dilateElement);
}

ColorProcessor::item ColorProcessor::createNewItem(std::string name, int hmin, int hmax, int smin, int smax, int vmin, int vmax)
{
    item temp;

    temp.name = name;
    temp.H_MIN = hmin;
    temp.H_MAX = hmax;
    temp.S_MIN = smin;
    temp.S_MAX = smax;
    temp.V_MIN = vmin;
    temp.V_MAX = vmax;

    return temp;
}
