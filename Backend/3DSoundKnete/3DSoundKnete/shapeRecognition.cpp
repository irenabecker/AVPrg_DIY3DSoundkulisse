#include "shapeRecognition.h"
#include "dsoundknete.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <calibration.h>
#include <math.h>       /* acos */
#include "DSoundKnete.h"

#define PI 3.14159265
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
	Mat HSV;
	Mat canny_output;
	vector<vector<Point>> contours;
	vector<Vec4i> hierarchy;

	input.copyTo(output);
	if (Calibration::getCalibrated())
	{
		cvtColor(output, HSV, CV_BGR2HSV);
		Mat mask;
        inRange(HSV, Scalar(0, 0, 0), Scalar(179, 80, 100), mask);		//look for all colorless pixels
		output.setTo(Scalar(255, 255, 255), mask);						//set them as white pixels in output
	}
	
	output.copyTo(dst);
	cv::cvtColor(output, output, CV_BGR2GRAY);
	blur(output, output, Size(3, 3));
	
	//ust threshold to convert grayscale to black-and-white image
	cv::threshold(output, canny_output, 100, 255, CV_THRESH_BINARY_INV);
	//canny_output.copyTo(dst);

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
        if (std::fabs(cv::contourArea(contours[i])) < 200 || !cv::isContourConvex(contours_poly[i]))
			continue;

		if (contours_poly[i].size() >=4 && contours_poly[i].size()<8 && rightAngles(contours_poly[i]))
		{
				center[i] = setLabel(dst, "RECT", contours_poly[i]);
				//create new Data-class and write center[i] and "RECT" in Data-class
				if (!(center[i].x == -1 || center[i].y == -1))
					DSoundKnete::objects.push_back(
						DSoundKnete::createNewObjData(
							DSoundKnete::RECTANGLE,
							center[i],
							std::fabs(cv::contourArea(contours[i]))
							));
			
		}
		else if (contours_poly[i].size() >= 3 && contours_poly[i].size() < 8)
		{
            center[i] = setLabel(dst, "TRI", contours_poly[i]);
			//create new Data-class and write center[i] and "TRI" in Data-class
            if(!(center[i].x == -1 || center[i].y == -1))
                DSoundKnete::objects.push_back(
                        DSoundKnete::createNewObjData(
                            DSoundKnete::TRIANGLE,
                            center[i],
							std::fabs(cv::contourArea(contours[i]))
                        ));
		}
		else if (contours_poly[i].size() >4)
		{
            center[i] = setLabel(dst, "Circle", contours_poly[i]);
			//create new Data-class and write center[i] and "CIRCLE" in Data-class
            if(!(center[i].x == -1 || center[i].y == -1))
                DSoundKnete::objects.push_back(
                        DSoundKnete::createNewObjData(
                            DSoundKnete::CIRCLE,
                            center[i],
							std::fabs(cv::contourArea(contours[i])))
                        );
		}
		
	}
	return dst;
}

bool ShapeRecognition::rightAngles(std::vector<cv::Point> contourPoints)
{
	int degreeTolerance = 20;
	int rightAnglesCounter = 0;
	cv::Point a = contourPoints.at(0);
	cv::Point b = contourPoints.at(1);
	cv::Point c = contourPoints.at(2);
	cv::Point d = contourPoints.at(3);
	double sideALength = ShapeRecognition::distanceBetween(c,b);
	double sideBLength = ShapeRecognition::distanceBetween(c, d);
	double sideCLength = ShapeRecognition::distanceBetween(a, d);
	double sideDLength = ShapeRecognition::distanceBetween(a, b);
	double sideELength = ShapeRecognition::distanceBetween(c, a);
	double sideFLength = ShapeRecognition::distanceBetween(b, d);
	std::vector<double> angle(4);
	angle[0] = acos((pow(sideALength, 2) + pow(sideDLength, 2) - pow(sideFLength, 2))/(2 * sideALength*sideDLength)) *(180.0/PI);
	angle[1] = acos((pow(sideALength, 2) + pow(sideBLength, 2) - pow(sideELength, 2)) / (2 * sideALength*sideBLength)) *(180.0 / PI);
	angle[2] =acos((pow(sideBLength, 2) + pow(sideCLength, 2) - pow(sideFLength, 2)) / (2 * sideBLength*sideCLength)) *(180.0 / PI);
	angle[3] = acos((pow(sideCLength, 2) + pow(sideDLength, 2) - pow(sideELength, 2)) / (2 * sideDLength*sideCLength)) *(180.0 / PI);
	for (int i = 0; i < angle.size(); i++)
	{
		if (angle[i] > 90 - degreeTolerance && angle[i] < 90 + degreeTolerance)
		{
			rightAnglesCounter++;
		}
	}
	if (rightAnglesCounter>=3)
	{
		return true;
	}
	else
	{
		return false;
	}
}

double ShapeRecognition::distanceBetween(cv::Point a, cv::Point b)
{
	double distance;
	distance = sqrt(pow(abs(a.x-b.x), 2) + pow(abs(a.y-b.y), 2));
	return distance;
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

    if(Calibration::getCalibrated())
    {
        if(!((c.x > Calibration::getGlobalXReferences()[0] && c.x < Calibration::getGlobalXReferences()[1])
                && (c.y > Calibration::getGlobalYReferences()[0] && c.y < Calibration::getGlobalYReferences()[1])))
        {
            c.x = -1;
            c.y = -1;
        }
    }

    return c;
}



