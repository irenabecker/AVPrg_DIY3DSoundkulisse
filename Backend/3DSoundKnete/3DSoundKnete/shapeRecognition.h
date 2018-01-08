#ifndef SHAPERECOGNITION_H
#define SHAPERECOGNITION_H

#include <opencv2/opencv.hpp>
#include "videoprocessor.h"
#include <stdio.h>
#include <stdlib.h>

class ShapeRecognition : public VideoProcessor
{
public:
	ShapeRecognition();
	cv::Mat process(const cv::Mat& input);
	void startProcessing(const VideoFormat& format);
	
private:
	cv::Point setLabel(cv::Mat& im, const std::string label, std::vector<cv::Point> contour);
};

#endif 