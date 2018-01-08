#ifndef COLORPROCESSOR_H
#define COLORPROCESSOR_H

#include "videoprocessor.h"

class ColorProcessor: public VideoProcessor
{
public:
    ColorProcessor();
    void startProcessing(const VideoFormat& format);
    cv::Mat process(const cv::Mat& input);

    //those methods are used to elimante noises in and outside of the tracked images
    void morphologicalOpening(cv::Mat &thresh);
    void morphologicalClosing(cv::Mat &thresh);
    //store the converted image here
    cv::Mat HSV;
    //This struct will help to determine the tracked items
    typedef struct {
        std::string name;
        int x;
        int y;
        int H_MIN = H_MIN;
        int H_MAX = H_MAX;
        int S_MIN = S_MIN;
        int S_MAX = S_MAX;
        int V_MIN = V_MIN;
        int V_MAX = V_MAX;
        cv::Mat threshold;
    } item;
    //store all tracked items here
    std::vector<item> objects;
    //Paint the item with its info
    void drawItem(int x, int y, item itemToDraw);
    //dynamic item for testing and setup
    int H_MIN, H_MAX, S_MIN, S_MAX, V_MIN, V_MAX;
    item dynamicTestObject;
 private:
    int threshold;
};

#endif // COLORPROCESSOR_H
