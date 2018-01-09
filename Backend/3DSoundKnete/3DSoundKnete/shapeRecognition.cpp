#include "shapeRecognition.h"
#include "dsoundknete.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
using namespace cv;
using namespace std;

ShapeRecognition::ShapeRecognition()
{

}

void ShapeRecognition::startProcessing(const VideoFormat& format)
{}

cv::Mat ShapeRecognition::process(const cv::Mat& input)
{
	Mat output(input.rows, input.cols, input.type());
    cv::Mat dst;
    input.copyTo(dst);
	Mat canny_output;
	vector<vector<Point>> contours;
	vector<Vec4i> hierarchy;

	//IplImage* imgGrayScale = cvCreateImage(cvGetSize(img), 8, 1);
	cv::cvtColor(input, output, CV_BGR2GRAY);
	blur(output, output, Size(3, 3));

	
	//use Canny instead of Threshold
//	cv::Canny(output, canny_output, 80, 240, 3);
	cv::threshold(output, canny_output, 100, 255, CV_THRESH_BINARY_INV);
//	canny_output.copyTo(dst);

	//finding all contours in the image
	findContours(canny_output, contours, hierarchy, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_SIMPLE, Point(0, 0));
	
	vector<vector<Point> > contours_poly(contours.size());
	vector<Rect> boundRect(contours.size());
	vector<Point>center(contours.size());

	//iterating through each contour
	for (int i = 0; i < contours.size(); i++)
	{
        drawContours(dst, contours,i, Scalar(0,0,0), 2, 8, hierarchy, 0, Point());
		// Approximate contour with accuracy proportional
		// to the contour perimeter
		cv::approxPolyDP(cv::Mat(contours[i]), contours_poly[i], cv::arcLength(cv::Mat(contours[i]), true)*0.02, true);

		// Skip small or non-convex objects
        if (std::fabs(cv::contourArea(contours[i])) < 100 || !cv::isContourConvex(contours_poly[i]))
        /*
         * The above line might be "too much", as we dont seem to need the second part of if
         * the first check probably is for the min size of recognizable objects
         */
//        if (std::fabs(cv::contourArea(contours[i])) < 100)
			continue;

		if (contours_poly[i].size() == 4)
		{
            center[i]=setLabel(dst, "RECT", contours_poly[i]);
			//create new Data-class and write center[i] and "RECT" in Data-class
            DSoundKnete::objects.push_back(
                        DSoundKnete::createNewObjData(
                            DSoundKnete::RECTANGLE,
                            center[i])
                        );
		}
		else if (contours_poly[i].size() >= 3 && contours_poly[i].size() < 8)
		{
            center[i] = setLabel(dst, "TRI", contours_poly[i]);
			//create new Data-class and write center[i] and "TRI" in Data-class
            DSoundKnete::objects.push_back(
                        DSoundKnete::createNewObjData(
                            DSoundKnete::TRIANGLE,
                            center[i])
                        );
		}
		else if (contours_poly[i].size() >4)
		{
            center[i] = setLabel(dst, "Circle", contours_poly[i]);
			//create new Data-class and write center[i] and "CIRCLE" in Data-class
            DSoundKnete::objects.push_back(
                        DSoundKnete::createNewObjData(
                            DSoundKnete::CIRCLE,
                            center[i])
                        );
		}
		
	}
	return dst;
}

/**
* Helper function to display text in the center of a contour
*/
cv::Point ShapeRecognition::setLabel(cv::Mat& im, const std::string label, std::vector<cv::Point> contour)
{
	int fontface = cv::FONT_HERSHEY_SIMPLEX;
    double scale = 0.8;
    int thickness = 2;
    int baseline = 0;

	cv::Size text = cv::getTextSize(label, fontface, scale, thickness, &baseline);
	cv::Rect r = cv::boundingRect(contour);

	cv::Point pt(r.x + ((r.width - text.width) / 2), r.y + ((r.height + text.height) / 2));
	cv::rectangle(im, pt + cv::Point(0, baseline), pt + cv::Point(text.width, -text.height), CV_RGB(255, 255, 255), CV_FILLED);
	cv::putText(im, label, pt, fontface, scale, CV_RGB(255,0,0), thickness, 8);

	cv::Point c(r.x + (r.width / 2), r.y + (r.height / 2));
	return c;
}



