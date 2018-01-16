#include "handleData.h"
#include "dsoundknete.h"
#include "calibration.h"

drumstick::rt::MIDIOutput HandleData::midiOutput;
int HandleData::toleranceRadius = 10;
int HandleData::tolearanceArea = 100;

HandleData::HandleData()
{
	QStringList connections = midiOutput.connections(true);
	midiOutput.open("LoopBe Internal MIDI");
}

void HandleData::openMidi(QString arg1)
{
	midiOutput.open(arg1);
}

void HandleData::sendData()
{
	HandleData::getObjectsToSend();
	QByteArray data;
	data.resize(6);

	//qDebug() << DSoundKnete::objects.size();
	//for (int i = 0; i < DSoundKnete::objects.size(); i++)
	for (int i = 0; i < DSoundKnete::dataToSendObjects.size(); i++)
	{
		/*data[0] = 0xf0;	//start byte
		data[1] = (DSoundKnete::objects[i].objectShape << 4) | (DSoundKnete::objects[i].objectColor);	//first 4 bit: shape; second 4 bit: color
		data[2] = DSoundKnete::objects[i].relativePosition.x;	//xPos
		data[3] = DSoundKnete::objects[i].relativePosition.y;	//yPos
		data[4] = DSoundKnete::objects[i].zPos;	//zPos

		data[5] = 0xf7;	//end byte*/
		data[0] = 0xf0;	//start byte
		data[1] = (DSoundKnete::dataToSendObjects[i].objectShape << 4) | (DSoundKnete::dataToSendObjects[i].objectColor);	//first 4 bit: shape; second 4 bit: color
		data[2] = DSoundKnete::dataToSendObjects[i].relativePosition.x;	//xPos
		data[3] = DSoundKnete::dataToSendObjects[i].relativePosition.y;	//yPos
		data[4] = DSoundKnete::dataToSendObjects[i].zPos;	//zPos

		data[5] = 0xf7;	//end byte*
		midiOutput.sendSysex(data);
		/*
		* Colors: 0 = RED, 1 = GREEN, 2 = BLUE
		* Shapes: 0 = RECTANGLE, 1 = CIRCLE, 2 = TRIANGLE
		*/
		//Blauer Kreis, Blaues Rechteck, rotes dreieck, roter kreis		
		/*qDebug() << "Sending: " << DSoundKnete::objects[i].objectShape << ", "
			<< DSoundKnete::objects[i].objectColor << ", "
			<< DSoundKnete::objects[i].relativePosition.x << ", "
			<< DSoundKnete::objects[i].relativePosition.y << ", "
			<< DSoundKnete::objects[i].zPos;*/
	}
	midiOutput.sendProgram(0, 0);
	DSoundKnete::savedObjects.clear();
	DSoundKnete::dataToSendObjects.clear();
}

void HandleData::getObjectsToSend()
{
	
	
	for (int i = 0; i < DSoundKnete::savedObjects.size(); i++)
	{
		if (DSoundKnete::savedObjects[i].size()>10)
		{
			DSoundKnete::objData temp;
			std::vector<int> colorCounter(5);
			std::vector<int>shapeCounter(3);
			for (int j = 0; j < DSoundKnete::savedObjects[i].size(); j++)
			{
				colorCounter[DSoundKnete::savedObjects[i][j].objectColor]++;
				shapeCounter[DSoundKnete::savedObjects[i][j].objectShape]++;
			}
			if(colorCounter[0]>=colorCounter[1]&&colorCounter[0]>=colorCounter[2] && colorCounter[0] >= colorCounter[3] && colorCounter[0] >= colorCounter[4])
			{temp.objectColor = DSoundKnete::COLOR::RED;}
			else if(colorCounter[1] >= colorCounter[0] && colorCounter[1] >= colorCounter[2] && colorCounter[1] >= colorCounter[3] && colorCounter[1] >= colorCounter[4])
			{temp.objectColor = DSoundKnete::COLOR::GREEN;}
			else if (colorCounter[2] >= colorCounter[0] && colorCounter[2] >= colorCounter[1] && colorCounter[2] >= colorCounter[3] && colorCounter[2] >= colorCounter[4])
			{temp.objectColor = DSoundKnete::COLOR::BLUE;}

			if (shapeCounter[0] >= shapeCounter[1] && shapeCounter[0] >= shapeCounter[2] )
			{temp.objectShape = DSoundKnete::SHAPE::RECTANGLE;}
			else if (shapeCounter[1] >= shapeCounter[0] && shapeCounter[1] >= shapeCounter[2])
			{temp.objectShape = DSoundKnete::SHAPE::CIRCLE;}
			else if (shapeCounter[2] >= shapeCounter[0] && shapeCounter[2] >= shapeCounter[1] )
			{temp.objectShape = DSoundKnete::SHAPE::TRIANGLE;}
			colorCounter.clear();
			shapeCounter.clear();
			temp.relativePosition = DSoundKnete::savedObjects[i][DSoundKnete::savedObjects[i].size() - 1].relativePosition;
			temp.zPos= DSoundKnete::savedObjects[i][DSoundKnete::savedObjects[i].size() - 1].zPos;
			temp.fillArea= DSoundKnete::savedObjects[i][DSoundKnete::savedObjects[i].size() - 1].fillArea;
			DSoundKnete::dataToSendObjects.push_back(temp);
		}
	}
}

void HandleData::emptyDataList()
{
	if (Calibration::getCalibrated())
	{
		bool gotMatched;
		for (int i = 0; i < DSoundKnete::objects.size(); i++)
		{
			gotMatched = false;
			for (int j = 0; j < DSoundKnete::savedObjects.size(); j++)
			{
				int posX1 = DSoundKnete::objects[i].relativePosition.x;
				int posX2 = DSoundKnete::savedObjects[j][DSoundKnete::savedObjects[j].size() - 1].relativePosition.x;
				int posY1 = DSoundKnete::objects[i].relativePosition.y;
				int posY2 = DSoundKnete::savedObjects[j][DSoundKnete::savedObjects[j].size() - 1].relativePosition.y;
				//if similar positions, fill Areas
				if (DSoundKnete::objects[i].relativePosition.x > DSoundKnete::savedObjects[j][DSoundKnete::savedObjects[j].size() - 1].relativePosition.x - toleranceRadius
					&&DSoundKnete::objects[i].relativePosition.x < DSoundKnete::savedObjects[j][DSoundKnete::savedObjects[j].size() - 1].relativePosition.x + toleranceRadius
					&& DSoundKnete::objects[i].relativePosition.y > DSoundKnete::savedObjects[j][DSoundKnete::savedObjects[j].size() - 1].relativePosition.y - toleranceRadius
					&&DSoundKnete::objects[i].relativePosition.y < DSoundKnete::savedObjects[j][DSoundKnete::savedObjects[j].size() - 1].relativePosition.y + toleranceRadius
					&&DSoundKnete::objects[i].fillArea>DSoundKnete::savedObjects[j][DSoundKnete::savedObjects[j].size() - 1].fillArea- tolearanceArea
					&&DSoundKnete::objects[i].fillArea<DSoundKnete::savedObjects[j][DSoundKnete::savedObjects[j].size() - 1].fillArea + tolearanceArea
					&&!gotMatched)
				{
					DSoundKnete::savedObjects[j].push_back(DSoundKnete::objects[i]);
					gotMatched = true;
				}
			}
			if (!gotMatched)
			{
				DSoundKnete::savedObjects.push_back({});
				DSoundKnete::savedObjects[DSoundKnete::savedObjects.size()-1].push_back(DSoundKnete::objects[i]);
			}
		}
	}
	
	DSoundKnete::objects.clear();
}