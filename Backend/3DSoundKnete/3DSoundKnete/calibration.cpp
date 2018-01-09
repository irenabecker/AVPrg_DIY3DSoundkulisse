#include <calibration.h>

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
Calibration::calibrate()
{

    boardWidth = globalXReferences[1] - globalXReferences[0];
    boardHeight = globalYReferences[1] - globalYReferences[0];
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


    return Point(relativeX, relativeY);
}
