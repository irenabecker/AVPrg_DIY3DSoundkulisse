#ifndef DSOUNDKNETE_H
#define DSOUNDKNETE_H

#include <QMainWindow>
#include <QImage>
#include <stdio.h>
#include "videoengine.h"
#include "colorprocessor.h"
#include "shapeRecognition.h"
#include "midioutput.h"
#include "handleData.h"

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

    enum COLOR{RED,GREEN,BLUE,CALIBRATION_COLOR,UNKNOWN_COLOR};
    enum SHAPE{RECTANGLE,CIRCLE,TRIANGLE};

    typedef struct{
        COLOR objectColor;
        SHAPE objectShape;
		int fillArea;
        cv::Point absolutePosition;
        cv::Point relativePosition;
		int zPos;
		
    } objData;

    static std::vector<objData> objects;
	static std::vector<std::vector<DSoundKnete::objData>>savedObjects;
	static std::vector<objData>dataToSendObjects;
    static objData createNewObjData(SHAPE shape, cv::Point point,int fillArea);

	public slots:
	void on_dataSend();
	void on_finishCalibrating(const bool &success);

private slots:
	void on_actionVideo_Top_triggered();
    void on_actionKamera_ffnen_triggered();
	void on_actionPlay_triggered();
    void on_comboBox_activated(const QString &arg1);
    void on_calibrateButton_clicked();
	void on_radioButton2D_clicked();
	void on_radioButton3D_clicked();


private:
	Ui::DSoundKnete *ui;
    VideoEngine *videoThreadTop;
    ShapeRecognition *shapeRecognition;
    ColorProcessor *colorProcessor;
};
#endif // DSOUNDKNETE_H
