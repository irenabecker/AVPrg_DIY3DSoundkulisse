#include "position.h"
#include <math.h>

PositionProcessor::PositionProcessor()
	:zeroTop()
	, zeroFront()
{

}

void PositionProcessor::setZero(int top[2], int front[2])
{
	zeroTop[0] = top[0];
	zeroTop[1] = top[1];
	zeroFront[0] = front[0];
	zeroFront[1] = front[1];
}

void PositionProcessor::findPosition(int pObject)
{
	int posX=
}