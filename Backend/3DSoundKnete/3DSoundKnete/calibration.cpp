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
   /* localX = globalX - abs(globalXReferences[0]-globalX );
    localY = globalY - abs(globalYReferences[0]-globalY);*/

    relativeX = (double)(localX/ boardWidth)*100;
    relativeY = (double)(localY/ boardHeight)*100;


    return cv::Point((int)relativeX, (int)relativeY);
}
