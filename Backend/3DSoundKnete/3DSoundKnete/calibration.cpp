#include <calibration.h>
#include <dsoundknete.h>

bool Calibration::calibrated = false;
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
std::cout << "calibrate" << endl;
    //loop through all shapes and store calibrationObjects in vector<Point>
    std::vector<cv::Point> calibrationObjectPositions(0);
    for (int i = 0; i < DSoundKnete::objects.size(); i++)
    {
        if(DSoundKnete::objects.at(i).objectShape == DSoundKnete::RECTANGLE
                && DSoundKnete::objects.at(i).objectColor == DSoundKnete::CALIBRATION_COLOR)
        {
            calibrationObjectPositions.push_back(DSoundKnete::objects.at(i).absolutePosition);
        }
    }

    //< 2 calibrationobjects: room can't be calced.
    if(calibrationObjectPositions.size() == 0)
    {
        std::cout << "ERROR: There was one or more Calibration-Objects missing!" << endl;
        return;
    }

    //Fill globalReferences with data from calibrationObjectPositions
    for(int i = 0; i < calibrationObjectPositions.size(); i++)
    {
        globalXReferences[i] = calibrationObjectPositions[i].x;
        globalYReferences[i] = calibrationObjectPositions[i].y;
    }

    boardWidth = globalXReferences[1] - globalXReferences[0];
    boardHeight = globalYReferences[1] - globalYReferences[0];

    calibrated = true;
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
    int localX, localY;
    int relativeX, relativeY;

    localX = globalX - (globalX - globalXReferences[0]);
    localY = globalY - (globalY - globalYReferences[0]);

    relativeX = boardWidth/localX;
    relativeY = boardHeight/localY;


    return cv::Point(relativeX, relativeY);
}
