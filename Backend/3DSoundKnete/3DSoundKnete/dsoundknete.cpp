#include <QFileDialog>
#include "dsoundknete.h"
#include "ui_dsoundknete.h"
#include "calibration.h"

//for web
//#include "webcommunication.h"
//#include "QtNetwork\qnetworkaccessmanager.h"
//#include "QtNetwork\qnetworkrequest.h"
//#include "QtNetwork\qnetworkreply.h"
//#include "qurl.h"

//#include "client_ws.hpp"
//#include "server_ws.hpp"
//
//using namespace std;
//
//using WsServer = SimpleWeb::SocketServer<SimpleWeb::WS>;
//using WsClient = SimpleWeb::SocketClient<SimpleWeb::WS>;

std::vector<DSoundKnete::objData> DSoundKnete::objects(5);

DSoundKnete::DSoundKnete(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::DSoundKnete)
	, videoThreadTop(new VideoEngine)
    , videoThreadFront(new VideoEngine)
	, colorProcessor(new ColorProcessor)
    , shapeRecognition(new ShapeRecognition)
	//, manager(new QNetworkAccessManager(this))
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
		ui->inputFrameFront,&VideoWidget::setImage);
    connect(videoThreadFront, &VideoEngine::sendProcessedImage,
        ui->processedFrameFront, &VideoWidget::setImage);

	//for calibration
	bool test = connect(videoThreadTop, &VideoEngine::sendCalibratFinished,
		this, &DSoundKnete::on_finishCalibrating);

	//for MIDI connection
	QStringList connections = midiOutput.connections(true);
	ui->comboBox->addItems(connections);
	connect(videoThreadTop, &VideoEngine::sendDataSignal,
				this,&DSoundKnete::on_dataSend);
	std::cout << test << endl;


	//QNetworkAccessManager *manager = new QNetworkAccessManager(this);
	//connect(manager, SIGNAL(finished(QNetworkReply*)),
	//	this, SLOT(syncRequestFinished(QNetworkReply*)));
	//QUrl url("localhost/test/PHP/db-requests.php");
	//QNetworkRequest request(url);

	//request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
	//QByteArray jsonString = "{\"type\":\"test\",\"loginName\":\"username@domain.com\",\"password\":\"mypass\"}";

	//// Use QNetworkReply * QNetworkAccessManager::post(const QNetworkRequest & request, const QByteArray & data); to send your request. Qt will rearrange everything correctly.
	//QNetworkReply * reply = manager->post(request, jsonString);



	//// WebSocket (WS)-server at port 8080 using 1 thread
	//WsServer server;
	//server.config.port = 8080;

	//// Example 1: echo WebSocket endpoint
	//// Added debug messages for example use of the callbacks
	//// Test with the following JavaScript:
	////   var ws=new WebSocket("ws://localhost:8080/echo");
	////   ws.onmessage=function(evt){console.log(evt.data);};
	////   ws.send("test");


	//auto &echo = server.endpoint["^/echo/?$"];

	//echo.on_message = [](shared_ptr<WsServer::Connection> connection, shared_ptr<WsServer::Message> message) {
	//	auto message_str = message->string();

	//	cout << "Server: Message received: \"" << message_str << "\" from " << connection.get() << endl;

	//	cout << "Server: Sending message \"" << message_str << "\" to " << connection.get() << endl;

	//	auto send_stream = make_shared<WsServer::SendStream>();
	//	*send_stream << message_str;
	//	// connection->send is an asynchronous function
	//	connection->send(send_stream, [](const SimpleWeb::error_code &ec) {
	//		if (ec) {
	//			cout << "Server: Error sending message. " <<
	//				// See http://www.boost.org/doc/libs/1_55_0/doc/html/boost_asio/reference.html, Error Codes for error code meanings
	//				"Error: " << ec << ", error message: " << ec.message() << endl;
	//		}
	//	});
	//};

	//echo.on_open = [](shared_ptr<WsServer::Connection> connection) {
	//	cout << "Server: Opened connection " << connection.get() << endl;
	//};

	//// See RFC 6455 7.4.1. for status codes
	//echo.on_close = [](shared_ptr<WsServer::Connection> connection, int status, const string & /*reason*/) {
	//	cout << "Server: Closed connection " << connection.get() << " with status code " << status << endl;
	//};

	//// See http://www.boost.org/doc/libs/1_55_0/doc/html/boost_asio/reference.html, Error Codes for error code meanings
	//echo.on_error = [](shared_ptr<WsServer::Connection> connection, const SimpleWeb::error_code &ec) {
	//	cout << "Server: Error in connection " << connection.get() << ". "
	//		<< "Error: " << ec << ", error message: " << ec.message() << endl;
	//};
}


DSoundKnete::~DSoundKnete()
{
	delete videoThreadTop;
    delete videoThreadFront;
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

void DSoundKnete::emptyDataList()
{
    objects.clear();
}

void DSoundKnete::on_dataSend()
{
	QByteArray data;
	data.resize(6);
	
	
	for (int i = 0; i < objects.size(); i++)
	{
		data[0] = 0xf0;	//start byte
		data[1] = (objects[i].objectShape << 4) | (objects[i].objectColor);	//first 4 bit: shape; second 4 bit: color
		data[2] = objects[i].relativePosition.x;	//xPos
		data[3] = objects[i].relativePosition.y;	//yPos
		data[4] = objects[i].zPos;	//zPos

		data[5] = 0xf7;	//end byte
		midiOutput.sendSysex(data);
        /*
         * Colors: 0 = RED, 1 = GREEN, 2 = BLUE
         * Shapes: 0 = RECTANGLE, 1 = CIRCLE, 2 = TRIANGLE
         */
        //Blauer Kreis, Blaues Rechteck, rotes dreieck, roter kreis
		
		/*qDebug() << "i: " << i << ", Shape: " << objects[i].objectShape
			<< ", AbsPoint: " << objects[i].absolutePosition.x<<", "<< objects[i].absolutePosition.y
			<< ", RelPoint: " << objects[i].relativePosition.x << ", " << objects[i].relativePosition.y
			<< ", Color: " << objects[i].objectColor;*/
		/*midichannel = objects[i].objectColor;
		midinote = objects[i].relativePosition.x;
		midivolume = objects[i].relativePosition.y;
		switch (objects[i].objectShape)
		{
			case RECTANGLE:
				midiOutput.sendNoteOn(midichannel, midinote, midivolume);
				break;
			case CIRCLE:
				midiOutput.sendNoteOff(midichannel, midinote, midivolume);
				break;
			case TRIANGLE:
				midiOutput.sendController(midichannel, midinote, midivolume);
				break;
		}*/
		
	}
	midiOutput.sendProgram(0,0);


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
    videoThreadTop->openCamera(1);
}

void DSoundKnete::on_comboBox_activated(const QString &arg1)
{
    midiOutput.open(arg1);
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
