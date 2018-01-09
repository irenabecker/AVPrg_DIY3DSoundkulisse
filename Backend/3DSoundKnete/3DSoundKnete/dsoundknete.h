#ifndef DSOUNDKNETE_H
#define DSOUNDKNETE_H

#include <QMainWindow>
#include <QImage>
#include <stdio.h>
#include "videoengine.h"
#include "colorprocessor.h"
#include "shapeRecognition.h"
#include "midioutput.h"

namespace Ui {
	class DSoundKnete;
}

class DSoundKnete : public QMainWindow
{
	Q_OBJECT

public:
	explicit DSoundKnete(QWidget *parent = 0);
    ~DSoundKnete();

    enum COLOR{RED,GREEN,BLUE};
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
	static void sendData();

private slots:
	void on_actionVideo_Top_triggered();
	void on_actionVideo_Front_triggered();
    void on_actionKamera_ffnen_triggered();
	void on_actionPlay_triggered();
	void on_comboBox_activated(const QString &arg1);

private:
	Ui::DSoundKnete *ui;
	VideoEngine *videoThreadTop;
    VideoEngine *videoThreadFront;
	ColorProcessor *colorProcessor;
    ShapeRecognition *shapeRecognition;
	drumstick::rt::MIDIOutput midiOutput;
	int midichannel;
};
#endif // DSOUNDKNETE_H
