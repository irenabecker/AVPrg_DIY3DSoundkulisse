#include <QFileDialog>
#include "dsoundknete.h"
#include "ui_dsoundknete.h"


DSoundKnete::DSoundKnete(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::DSoundKnete)
	, videoThreadTop(new VideoEngine)
	, videoTreadFront(new VideoEngine)
	//, videoProcessor(new ColorProcessor)
	,shapeRecognition(new ShapeRecognition)
{
	ui->setupUi(this);
	videoThreadTop->setProcessor(shapeRecognition);
	videoTreadFront->setProcessor(shapeRecognition);
	//for top camera
	connect(videoThreadTop, &VideoEngine::sendInputImage,
		ui->inputFrameTop, &VideoWidget::setImage);
	connect(videoThreadTop, &VideoEngine::sendProcessedImage,
		ui->processedFrameTop, &VideoWidget::setImage);
	//for front camera
	connect(videoTreadFront, &VideoEngine::sendInputImage,
		ui->inputFrameFront, &VideoWidget::setImage);
	connect(videoTreadFront, &VideoEngine::sendProcessedImage,
		ui->processedFrameFront, &VideoWidget::setImage);
}


DSoundKnete::~DSoundKnete()
{
	delete videoThreadTop;
	delete videoTreadFront;
	delete ui;
	//delete videoProcessor;
	delete shapeRecognition;
}

void DSoundKnete::on_actionVideo_Top_triggered()
{
	QString fileName = QFileDialog::getOpenFileName(this, tr("Open Movie"), "../../../Backend/Videos");

	if (!fileName.isEmpty()) {
		videoThreadTop->openFile(fileName);
	}
}
void DSoundKnete::on_actionVideo_Front_triggered()
{
	QString fileName = QFileDialog::getOpenFileName(this, tr("Open Movie"), "../../../Videos");

	if (!fileName.isEmpty()) {
		videoTreadFront->openFile(fileName);
	}
}

void DSoundKnete::on_actionPlay_triggered()
{
	videoThreadTop->start();
	videoTreadFront->start();
}