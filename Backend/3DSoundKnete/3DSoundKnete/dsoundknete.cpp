#include <QFileDialog>
#include "dsoundknete.h"
#include "ui_dsoundknete.h"
#include "calibration.h"


std::vector<DSoundKnete::objData> DSoundKnete::objects(1);
std::vector<DSoundKnete::objData> DSoundKnete::dataToSendObjects(0);
std::vector<std::vector<DSoundKnete::objData>> DSoundKnete::savedObjects(1);


DSoundKnete::DSoundKnete(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::DSoundKnete)
	, videoThreadTop(new VideoEngine)
	, colorProcessor(new ColorProcessor)
    , shapeRecognition(new ShapeRecognition)
{
    ui->setupUi(this);
	videoThreadTop->setProcessor(colorProcessor,shapeRecognition);

	//for top camera
	connect(videoThreadTop, &VideoEngine::sendInputImage,
		ui->inputFrameTop, &VideoWidget::setImage);
	connect(videoThreadTop, &VideoEngine::sendProcessedImage,
		ui->processedFrameTop, &VideoWidget::setImage);

	//for calibration
	bool test = connect(videoThreadTop, &VideoEngine::sendCalibratFinished,
		this, &DSoundKnete::on_finishCalibrating);

	//for MIDI connection
	HandleData::openMidi("LoopBe Internal MIDI");
	//ui->comboBox->addItems(connections);
	connect(videoThreadTop, &VideoEngine::sendDataSignal,
				this,&DSoundKnete::on_dataSend);
	std::cout << test << endl;

	for (int i = 0; i < DSoundKnete::savedObjects.size(); i++)
	{
		DSoundKnete::savedObjects[i].push_back({});
	}
}


DSoundKnete::~DSoundKnete()
{
	delete videoThreadTop;
	delete ui;
	delete colorProcessor;
	delete shapeRecognition;
}

DSoundKnete::objData DSoundKnete::createNewObjData(SHAPE shape, cv::Point point, int fillArea)
{
    objData temp;

    temp.objectShape = shape;
    temp.absolutePosition = point;
	temp.fillArea = fillArea;

	if (Calibration::getCalibrated())
	{
		temp.relativePosition = Calibration::calcRelative(temp.absolutePosition.x, temp.absolutePosition.y);
		temp.zPos = Calibration::calcZPos(temp.absolutePosition.x,temp.absolutePosition.y,temp.fillArea,temp.objectShape);
	}

    return temp;
}


void DSoundKnete::on_dataSend()
{
	HandleData::sendData();
}

void DSoundKnete::on_actionVideo_Top_triggered()
{

	QString fileName = QFileDialog::getOpenFileName(this, tr("Open Movie"), "../../../Backend/Videos");

	if (!fileName.isEmpty()) {
		videoThreadTop->openFile(fileName);
	}
}

void DSoundKnete::on_actionPlay_triggered()
{
	videoThreadTop->start();
    ui->calibrateButton->setEnabled(true);
}

void DSoundKnete::on_actionKamera_ffnen_triggered()
{
    videoThreadTop->openCamera(1);
}

void DSoundKnete::on_comboBox_activated(const QString &arg1)
{
	HandleData::openMidi(arg1);
}

void DSoundKnete::on_calibrateButton_clicked()
{
	ui->calibrateButton->setEnabled(false);
    Calibration::calibrate();
	ui->calibrateButton->setEnabled(Calibration::getCalibrated());
}

void DSoundKnete::on_finishCalibrating(const bool &success)
{
	ui->calibrateButton->setEnabled(true);
	if (success)
	{
		ui->calibrateLabel->setStyleSheet("QLabel { color: green }");
		ui->calibrateLabel->setText("Calibration successfull");
	}
	else
	{
		ui->calibrateLabel->setStyleSheet("QLabel { color: red }");
		ui->calibrateLabel->setText("Calibration failed!");
	}
	//output success to label
}

void DSoundKnete::on_radioButton2D_clicked()
{
	Calibration::stdSize = { 100,75,50 };		//RECT, CIRCLE, TRI
}
void DSoundKnete::on_radioButton3D_clicked()
{
	Calibration::stdSize = { 120,50,75 };	//RECT,CIRCLE,TRI
}
