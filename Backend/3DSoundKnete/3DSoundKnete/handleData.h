#ifndef HANDLEDATA_H
#define HANDLEDATA_H

#include <QThread>
//#include <QImage>
//#include <QMutex>
#include <opencv2/opencv.hpp>
#include <stdio.h>
#include <stdlib.h>
#include "midioutput.h"
#include "dsoundknete.h"

class HandleData 
{
	
public:
	HandleData();
	static void openMidi(QString arg1);
	static void sendData();
private:
	static drumstick::rt::MIDIOutput midiOutput;
	int midichannel;
	int midinote;
	int midivolume;
};

#endif 
