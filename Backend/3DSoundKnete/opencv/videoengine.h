#ifndef VIDEOENGINE_H
#define VIDEOENGINE_H

#include <QThread>
#include <QImage>
#include <QMutex>
#include "videoprocessor.h"
#include "cvmattoqimage.h"
#include "videoformat.h"


class VideoEngine : public QThread
{
    Q_OBJECT
public:
    VideoEngine();
    ~VideoEngine();
    void openFile(const QString& file);
    void openCamera(int device = 0);
    void setProcessor(VideoProcessor*,VideoProcessor*);
    const VideoFormat& videoFormat() const;
    int framePosition();
protected:
    void run();
public slots:
    void stop();
signals:
    void sendInputImage(const QImage&);
    void sendProcessedImage(const QImage&);
	void sendDataSignal();
	void sendCalibratFinished(const bool&);
private:
    cv::VideoCapture videoCapture;
    VideoFormat _videoFormat;
    bool stopped;
    QMutex mutex;
    VideoProcessor* shapeProcessor;
	VideoProcessor* colorProcessor;
    bool usingCamera;
    const int SEND_DATA_FRAME_THRESHOLD = 24;
    int currentFrameCount;
};


#endif // VIDEOENGINE_H
