#include <QFileDialog>
#include "dsoundknete.h"
#include "ui_dsoundknete.h"
#include "calibration.h"

std::vector<DSoundKnete::objData> DSoundKnete::objects(5);

DSoundKnete::DSoundKnete(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::DSoundKnete)
	, videoThreadTop(new VideoEngine)
    , videoThreadFront(new VideoEngine)
	, colorProcessor(new ColorProcessor)
    , shapeRecognition(new ShapeRecognition)
{
    ui->setupUi(this);
	videoThreadTop->setProcessor(colorProcessor,shapeRecognition);
    videoThreadFront->setProcessor(colorProcessor,shapeRecognition);

	//for top camera
	connect(videoThreadTop, &VideoEngine::sendInputImage,
		ui->inputFrameTop, &VideoWidget::setImage);
	connect(videoThreadTop, &VideoEngine::sendProcessedImage,
		ui->processedFrameTop, &VideoWidget::setImage);

	//for front camera
    connect(videoThreadFront, &VideoEngine::sendInputImage,
		ui->inputFrameFront, &VideoWidget::setImage);
    connect(videoThreadFront, &VideoEngine::sendProcessedImage,
        ui->processedFrameFront, &VideoWidget::setImage);

	//for MIDI connection
	QStringList connections = midiOutput.connections(true);
	ui->comboBox->addItems(connections);
	midiOutput.open("Microsoft GS Wavetable Synth");
	midichannel = 1;
}


DSoundKnete::~DSoundKnete()
{
	delete videoThreadTop;
    delete videoThreadFront;
	delete ui;
	delete colorProcessor;
	delete shapeRecognition;
}

DSoundKnete::objData DSoundKnete::createNewObjData(SHAPE shape, cv::Point point)
{
    objData temp;

    temp.objectShape = shape;
    temp.absolutePosition = point;

    if(Calibration::getCalibrated())
        temp.relativePosition = Calibration::calcRelative(temp.absolutePosition.x, temp.absolutePosition.y);

    return temp;
}

void DSoundKnete::emptyDataList()
{
    objects.clear();
}

void DSoundKnete::sendData()
{
	for (int i = 0; i < objects.size(); i++)
	{
        /*
         * Colors: 0 = RED, 1 = GREEN, 2 = BLUE
         * Shapes: 0 = RECTANGLE, 1 = CIRCLE, 2 = TRIANGLE
         */
        //Blauer Kreis, Blaues Rechteck, rotes dreieck, roter kreis
        std::cout << "i: " << i << ", Shape: " << objects[i].objectShape
                  << ", AbsPoint: " << objects[i].absolutePosition
                  << ", RelPoint: " << objects[i].relativePosition
                  << ", Color: " << objects[i].objectColor  << endl;
	}
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
        videoThreadFront->openFile(fileName);
	}
}

void DSoundKnete::on_actionPlay_triggered()
{
	videoThreadTop->start();
    videoThreadFront->start();
    ui->calibrateButton->setEnabled(true);
}

void DSoundKnete::on_actionKamera_ffnen_triggered()
{
    videoThreadTop->openCamera();
}

void DSoundKnete::on_comboBox_activated(const QString &arg1)
{
    midiOutput.open(arg1);
}

void DSoundKnete::on_calibrateButton_clicked()
{
    Calibration::calibrate();
}
