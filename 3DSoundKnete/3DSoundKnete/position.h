#ifndef POSITIONPROCESSOR_H
#define POSITIONPROCESSOR_H


class PositionProcessor : public PositionProcessor
{
public:
	PositionProcessor();
	void setZero(int top[2], int front[2]);
	void findPosition(int pObject);

private:
	int zeroTop[2] = {};
	int zeroFront[2] = {};
	
};

#endif // POSITIONPROCESSOR_H

