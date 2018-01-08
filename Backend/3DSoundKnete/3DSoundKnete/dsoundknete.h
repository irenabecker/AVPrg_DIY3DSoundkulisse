#ifndef DSOUNDKNETE_H
#define DSOUNDKNETE_H

#include <QMainWindow>
#include <QImage>
#include "videoengine.h"
//#include "copyprocessor.h"
//#include "brightnessprocessor.h"
#include "colorprocessor.h"

namespace Ui {
	class DSoundKnete;
}

class DSoundKnete : public QMainWindow
{
	Q_OBJECT

public:
	explicit DSoundKnete(QWidget *parent = 0);
	~DSoundKnete();

	private slots:
	void on_actionVideo_Top_triggered();
	void on_actionVideo_Front_triggered();
	//void on_actionKamera_ffnen_triggered();
	void on_actionPlay_triggered();

private:
	Ui::DSoundKnete *ui;
	VideoEngine *videoThreadTop;
	VideoEngine *videoTreadFront;
	ColorProcessor *videoProcessor;
};

#endif // DSOUNDKNETE_H