#include <opencv2/opencv.hpp>
#include <QImage>
#include <QMutexLocker>
#include <QDir>
#include <QDebug>
#include <string>
#include "videoengine.h"
#include "dsoundknete.h"
#include "calibration.h"

// http://stackoverflow.com/questions/7801522/integrating-opencv-with-larger-programs

VideoEngine::VideoEngine()
    : stopped(false)
    , shapeProcessor(0)
	, colorProcessor(0)
    , usingCamera(false)
{
}
VideoEngine::~VideoEngine(){
    stop();
    wait();
}
const VideoFormat& VideoEngine::videoFormat() const{
    return _videoFormat;
}
void VideoEngine::setProcessor(VideoProcessor *cprocessor, VideoProcessor *sprocessor){
    this->shapeProcessor = sprocessor;
	this->colorProcessor = cprocessor;
}

void VideoEngine::openFile(const QString& file){
    try {
        bool success = videoCapture.open(file.toStdString());
        if (!success){
            qDebug() << "Error: cannot open File: " << file;
        }
        else{
            _videoFormat.setFormat(videoCapture);
            qDebug() << _videoFormat.toString().c_str();
        }
    } catch (cv::Exception e) {
        qDebug() << e.err.c_str();
    }
}

void VideoEngine::openCamera(int device){
    try {
        bool success = videoCapture.open(0  + device);
        if (!success){
            qDebug() << "Error: cannot open camera ";
        }
        else{
            _videoFormat.setFormat(videoCapture);
            qDebug() << _videoFormat.toString().c_str();
        }
    } catch (cv::Exception e) {
        qDebug() << e.err.c_str();
    }
}

void VideoEngine::stop()
{
    QMutexLocker locker(&mutex);
    stopped = true;
}

void VideoEngine::run()
{
    if (videoCapture.isOpened()){
        int milliSeconds = 1000/_videoFormat.framesPerSecond();
        int frameNumber = 0;
        while(!stopped)
        {
            cv::Mat cvFrame;
            if (false == videoCapture.grab()){
                qDebug() << "grab() failed";
                break;
            }
            if (false == videoCapture.retrieve(cvFrame, 0)){
                qDebug() << "retrieve() failed (1)";
                if (false == videoCapture.retrieve(cvFrame, 0)){
                    qDebug() << "retrieve() failed (2)";
                    break;
                }
            }
            // retrieve Mat::type()
            frameNumber++;
            if (frameNumber == 1){
                _videoFormat.setType(cvFrame.type());
                if (shapeProcessor != 0){
					shapeProcessor->startProcessing(_videoFormat);
                }
				if (colorProcessor != 0)
				{
					colorProcessor->startProcessing(_videoFormat);
				}
            }

            // queue the image to the gui
            emit sendInputImage(cvMatToQImage(cvFrame));
			cv::Mat shapeProcessedFrame;
            // Process Video Frame
            if (shapeProcessor != 0){
                HandleData::emptyDataList();
                shapeProcessedFrame = shapeProcessor->process(cvFrame);
                cvFrame = colorProcessor->process(cvFrame);
                //Only send data to frontend, when camera is calibrated and enough frames have been processed
				if (!Calibration::getCalibrated())
				{
					if (Calibration::getCalibrateCounter()>0)	//calibration got started from button in dsoundknete
					{
						Calibration::calibrate();					//repeat calibrating untill getCalibrated()=true, or counter runs out
					}
					if(Calibration::getCalibrateCounter()>=Calibration::getMaxCalTries())	//counter runs out
					{
						Calibration::calibrateCounter = 0;
						emit sendCalibratFinished(false);
					}
				}
				else
				{emit sendCalibratFinished(true); }
				if (Calibration::getCalibrated() && frameNumber % SEND_DATA_FRAME_THRESHOLD == 0)
				{emit sendDataSignal();}
            }
			//emit sendDataSignal();
            emit sendProcessedImage(cvMatToQImage(shapeProcessedFrame));

            // check if stopped
            QMutexLocker locker(&mutex);
            if (stopped) {
                break;
            }

            if (usingCamera == false){
                msleep(milliSeconds);
            }
        }
    }
}

int VideoEngine::framePosition(){
    return videoCapture.get(CV_CAP_PROP_POS_FRAMES);
}
