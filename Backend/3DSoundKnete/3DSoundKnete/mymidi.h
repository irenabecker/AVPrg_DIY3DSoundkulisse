#ifndef MYMIDI_H
#define MYMIDI_H

#include <opencv2/opencv.hpp>
#include <stdio.h>
#include <stdlib.h>
#include "midioutput.h"

//bit 7&8 of first byte for color
#define COLOR_BLACK		   0x80
#define COLOR_RED          0xa0
#define COLOR_GREEN		   0xC0
#define COLOR_BLUE		   0xE0	

//bit 3&4 of first byte for form
#define FORM_RECTANGLE		0x04
#define FORM_CIRCLE			0x08
#define FORM_TRIANGLE		0x0C

class MyMidi : public drumstick::rt::MIDIOutput
{
public:
	MyMidi();
	

private:
	
};

#endif 
