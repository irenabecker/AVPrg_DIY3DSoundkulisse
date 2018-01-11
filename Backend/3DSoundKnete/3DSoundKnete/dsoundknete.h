#ifndef DSOUNDKNETE_H
#define DSOUNDKNETE_H

#include <QMainWindow>
#include <QImage>
#include <stdio.h>
#include "videoengine.h"
#include "colorprocessor.h"
#include "shapeRecognition.h"
#include "midioutput.h"

//#include "webcommunication.h"
//#include "QtNetwork\qnetworkaccessmanager.h"
//#include "QtNetwork\qnetworkrequest.h"
//#include "QtNetwork\qnetworkreply.h"
//#include "qurl.h"

namespace Ui {
	class DSoundKnete;
}

class DSoundKnete : public QMainWindow
{
	Q_OBJECT

public:
	explicit DSoundKnete(QWidget *parent = 0);
    ~DSoundKnete();

    enum COLOR{RED,GREEN,BLUE,CALIBRATION_COLOR};
    enum SHAPE{RECTANGLE,CIRCLE,TRIANGLE};

    typedef struct{
        COLOR objectColor;
        SHAPE objectShape;
        cv::Point absolutePosition;
        cv::Point relativePosition;
    } objData;

    static std::vector<objData> objects;
    static void emptyDataList();
    static objData createNewObjData(SHAPE shape, cv::Point point);
    //void sendData();

	public slots:
	void on_dataSend();
	void on_finishCalibrating(const bool &success);

private slots:
	void on_actionVideo_Top_triggered();
	void on_actionVideo_Front_triggered();
    void on_actionKamera_ffnen_triggered();
	void on_actionPlay_triggered();
    void on_comboBox_activated(const QString &arg1);
    void on_calibrateButton_clicked();


private:
	Ui::DSoundKnete *ui;
    VideoEngine *videoThreadTop;
    VideoEngine *videoThreadFront;
    ShapeRecognition *shapeRecognition;
    ColorProcessor *colorProcessor;
	//QNetworkAccessManager *manager;
	drumstick::rt::MIDIOutput midiOutput;
	int midichannel;
	int midinote;
	int midivolume;
};
#endif // DSOUNDKNETE_H
