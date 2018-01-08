#include "shapeRecognition.h"
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

	//smooth the original image using Gaussian kernel to remove noise
	//cvSmooth(input, input, CV_GAUSSIAN, 3, 3);

	//converting the original image into grayscale
	//IplImage* imgGrayScale = cvCreateImage(cvGetSize(img), 8, 1);
	cv::cvtColor(input, output, CV_BGR2GRAY);
	blur(output, output, Size(3, 3));

	//cvNamedWindow("GrayScale Image");
	//cvShowImage("GrayScale Image", imgGrayScale);

	//thresholding the grayscale image to get better results
	//cvThreshold(imgGrayScale, imgGrayScale, 100, 255, CV_THRESH_BINARY_INV);

	cv::Mat dst;
	Mat canny_output;
	vector<vector<Point>> contours;
	vector<Vec4i> hierarchy;
	

	//use Canny instead of Threshold
//	cv::Canny(output, canny_output, 80, 240, 3);
	cv::threshold(output, canny_output, 100, 255, CV_THRESH_BINARY_INV);
	canny_output.copyTo(dst);
	//cvNamedWindow("Thresholded Image");
	//cvShowImage("Thresholded Image", imgGrayScale);

	//CvSeq* contour;  //hold the pointer to a contour
	//CvSeq* result;   //hold sequence of points of a contour
	//CvMemStorage *storage = cvCreateMemStorage(0); //storage area for all contours

	//finding all contours in the image
	//findContours(canny_output, storage, &contour, sizeof(CvContour), CV_RETR_LIST, CV_CHAIN_APPROX_SIMPLE, cvPoint(0, 0));
	findContours(canny_output, contours, hierarchy, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_SIMPLE, Point(0, 0));
	

	vector<vector<Point> > contours_poly(contours.size());
	vector<Rect> boundRect(contours.size());
	vector<Point>center(contours.size());
	//iterating through each contour
	for (int i = 0; i < contours.size(); i++)
	{
		// Approximate contour with accuracy proportional
		// to the contour perimeter
		cv::approxPolyDP(cv::Mat(contours[i]), contours_poly[i], cv::arcLength(cv::Mat(contours[i]), true)*0.02, true);

		// Skip small or non-convex objects
		if (std::fabs(cv::contourArea(contours[i])) < 100 || !cv::isContourConvex(contours_poly[i]))
			continue;

		if (contours_poly[i].size() == 4)
		{
			center[i]=setLabel(dst, "RECT", contours_poly[i]);
		}
		else if (contours_poly[i].size() >= 3 && contours_poly[i].size() < 8)
		{
			center[i] = setLabel(dst, "TRI", contours_poly[i]);
		}
		else if (contours_poly[i].size() >4)
		{
			center[i] = setLabel(dst, "Circle", contours_poly[i]);
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
	double scale = 0.4;
	int thickness = 1;
	int baseline = 0;

	cv::Size text = cv::getTextSize(label, fontface, scale, thickness, &baseline);
	cv::Rect r = cv::boundingRect(contour);

	cv::Point pt(r.x + ((r.width - text.width) / 2), r.y + ((r.height + text.height) / 2));
	cv::rectangle(im, pt + cv::Point(0, baseline), pt + cv::Point(text.width, -text.height), CV_RGB(255, 255, 255), CV_FILLED);
	cv::putText(im, label, pt, fontface, scale, CV_RGB(255,0,0), thickness, 8);

	return pt;
}

