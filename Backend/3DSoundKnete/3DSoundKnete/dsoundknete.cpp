#include <QFileDialog>
#include "dsoundknete.h"
#include "ui_dsoundknete.h"

std::vector<DSoundKnete::objData> DSoundKnete::objects(5);

DSoundKnete::DSoundKnete(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::DSoundKnete)
	, videoThreadTop(new VideoEngine)
    , videoThreadFront(new VideoEngine)
	, colorProcessor(new ColorProcessor)
    ,shapeRecognition(new ShapeRecognition)
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
<<<<<<< HEAD

	//for MIDI connection
	//QStringList connections = midiOutput.connections(true);
	//ui->comboBox->addItems(connections);
	//midiOutput.open("Microsoft GS Wavetable Synth");
	midichannel = 1;
=======
>>>>>>> 032ddc56fe7611807f960f332a9a3b51f94a0a16
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

    return temp;
}

void DSoundKnete::emptyDataList()
{
    objects.clear();
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
}

void DSoundKnete::on_actionKamera_ffnen_triggered()
{
    videoThreadTop->openCamera();
}
<<<<<<< HEAD

void DSoundKnete::on_comboBox_activated(const QString &arg1)
{
	//midiOutput.open(arg1);
}

void DSoundKnete::on_hmax_valueChanged(int value)
{
    colorProcessor->H_MAX = value;
}


void DSoundKnete::on_smin_valueChanged(int value)
{
	colorProcessor->S_MIN = value;
}

void DSoundKnete::on_smax_valueChanged(int value)
{
	colorProcessor->S_MAX = value;
}

void DSoundKnete::on_vmin_valueChanged(int value)
{
	colorProcessor->V_MIN = value;
}

void DSoundKnete::on_vmax_valueChanged(int value)
{
	colorProcessor->V_MAX = value;
}

void DSoundKnete::on_hmin_valueChanged(int value)
{
	colorProcessor->V_MIN = value;
}
=======
>>>>>>> 032ddc56fe7611807f960f332a9a3b51f94a0a16
