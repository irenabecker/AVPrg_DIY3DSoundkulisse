#include "handleData.h"
#include "dsoundknete.h"

drumstick::rt::MIDIOutput HandleData::midiOutput;

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
	
	QByteArray data;
	data.resize(6);

	qDebug() << DSoundKnete::objects.size();
	for (int i = 0; i < DSoundKnete::objects.size(); i++)
	{
		data[0] = 0xf0;	//start byte
		data[1] = (DSoundKnete::objects[i].objectShape << 4) | (DSoundKnete::objects[i].objectColor);	//first 4 bit: shape; second 4 bit: color
		data[2] = DSoundKnete::objects[i].relativePosition.x;	//xPos
		data[3] = DSoundKnete::objects[i].relativePosition.y;	//yPos
		data[4] = DSoundKnete::objects[i].zPos;	//zPos

		data[5] = 0xf7;	//end byte
		midiOutput.sendSysex(data);
		/*
		* Colors: 0 = RED, 1 = GREEN, 2 = BLUE
		* Shapes: 0 = RECTANGLE, 1 = CIRCLE, 2 = TRIANGLE
		*/
		//Blauer Kreis, Blaues Rechteck, rotes dreieck, roter kreis		
		qDebug() << "Sending: " << DSoundKnete::objects[i].objectShape << ", "
			<< DSoundKnete::objects[i].objectColor << ", "
			<< DSoundKnete::objects[i].relativePosition.x << ", "
			<< DSoundKnete::objects[i].relativePosition.y << ", "
			<< DSoundKnete::objects[i].zPos;
	}
	midiOutput.sendProgram(0, 0);
}