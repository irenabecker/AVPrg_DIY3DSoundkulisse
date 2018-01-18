#include <calibration.h>
#include <dsoundknete.h>
#include <algorithm>

bool Calibration::calibrated = false;
int Calibration::maxCalTries = 10;
int Calibration::calibrateCounter = 0;
int Calibration::boardHeight = 0;
int Calibration::boardWidth = 0;
std::vector<int> Calibration::globalXReferences(2);
std::vector<int> Calibration::globalYReferences(2);
int Calibration::stdFillArea=0;
int Calibration::focalLength=0;
cv::Point Calibration::boardCenter(0,0);
std::vector<int> Calibration::stdSize = { 120,50,75 };

Calibration::Calibration()
{
}


/*
 * Calibrate and calculate the room as given by the two
 * calibration objects (black cubes).
 *
 * index 0 = upper left corner
 * index 1 = lower right corner
 */
void Calibration::calibrate()
{
    //make sure the flag is set to false when the process starts
    calibrated = false;
    qDebug() << "calibrate" << endl;
    //loop through all shapes and store calibrationObjects in vector<Point>
    std::vector<cv::Point> calibrationObjectPositions(0);
    for (int i = 0; i < DSoundKnete::objects.size(); i++)
    {
        if(DSoundKnete::objects.at(i).objectShape == DSoundKnete::RECTANGLE
                && DSoundKnete::objects.at(i).objectColor == DSoundKnete::CALIBRATION_COLOR)
        {
            calibrationObjectPositions.push_back(DSoundKnete::objects.at(i).absolutePosition);
			//fill Area for zPos
			stdFillArea = DSoundKnete::objects.at(i).fillArea;	
        }
        qDebug() << "shape: " << DSoundKnete::objects.at(i).objectShape << " col:" << DSoundKnete::objects.at(i).objectColor << " | "<< endl;
    }

    //< 2 calibrationobjects: room can't be calced.
    if(calibrationObjectPositions.size() !=2)
    {
		calibrateCounter = calibrateCounter + 1;;
		if (calibrateCounter >= maxCalTries)
		{
            qDebug() << "ERROR: There was one or more Calibration-Objects missing!" << endl;
		}
        return;
    }

    globalXReferences[0] = std::min(calibrationObjectPositions[0].x, calibrationObjectPositions[1].x);
    globalXReferences[1] = std::max(calibrationObjectPositions[0].x, calibrationObjectPositions[1].x);
    globalYReferences[0] = std::min(calibrationObjectPositions[0].y, calibrationObjectPositions[1].y);
    globalYReferences[1] = std::max(calibrationObjectPositions[0].y, calibrationObjectPositions[1].y);

    //Calc Board Scales
    boardWidth = globalXReferences[1] - globalXReferences[0];
    boardHeight = globalYReferences[1] - globalYReferences[0];
	boardCenter.x = globalXReferences[0] + (boardWidth/2);
	boardCenter.y = globalYReferences[0] + (boardHeight / 2);

	//calculate focal length F=(P*D)/W
	focalLength = (stdFillArea * 112) / stdSize.at(0);	

    calibrated = true;
    qDebug() << "INFO: Calibration done...";
}

/*
 * We need relative positions (%) of each dataObj, in order to
 * achieve accurate positioning via webaudio api later on.
 *
 * globalX and globalY are the coords from the whole camera frame
 *
 * localX and localY are the coords on the board only where (0,0)
 * is the upper left corner, given by calibrate(), stored as a global
 * reference with index 0.
 *
 *  relativeX and relativeY are used to describe a relative point in the room
 */
cv::Point Calibration::calcRelative(int globalX, int globalY)
{
    double localX, localY;
    int relativeX, relativeY;

	localX = globalX - globalXReferences[0];
	localY = globalY - globalYReferences[0];

    relativeX = (double)(localX/ boardWidth)*100;
    relativeY = (double)(localY/ boardHeight)*100;

    return cv::Point((int)relativeX, (int)relativeY);
}

/*
calibrates the relative Z-Coordinate of the object, 100% meaning the object lays on the table.
First the relative distance to the center has to be calibrated, afterwards the distance of the object to the camera is calculated
using focal length.
Having these values triangulation can be used to determine the Z-Coordinate of the object in space.
*/
int Calibration::calcZPos(int absolutePositionX,int absolutePositionY, int fillArea,int shape)
{
	int zPos;
	double distanceToCamera;
	double absDistanceToCenter;
	double relDistanceToCenter;
	absDistanceToCenter = sqrt(pow((boardCenter.x - absolutePositionX), 2) + pow((boardCenter.y - absolutePositionY), 2));
	relDistanceToCenter = (absDistanceToCenter / boardWidth) * 100;
	distanceToCamera = (focalLength * stdSize.at(shape)) / fillArea;	//stdSize has same order as enum SHAPE: REC, CIRCLE, TRI
	zPos= sqrt(pow((distanceToCamera), 2) - pow((relDistanceToCenter), 2));
	if(zPos>100)
	{zPos = 100;}
	return zPos;
}
