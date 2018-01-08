#ifndef COLORPROCESSOR_H
#define COLORPROCESSOR_H

#include "videoprocessor.h"

class ColorProcessor: public VideoProcessor
{
public:
    ColorProcessor();
    void startProcessing(const VideoFormat& format);
    cv::Mat process(const cv::Mat& input);
    const cv::Mat erodeElement = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(8,8));
    const cv::Mat dilateElement = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(8,8));
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
    std::vector<item> items;
    //Paint the item with its info
    void drawItem(int x, int y, item itemToDraw, cv::Mat &frame);
    //dynamic item for testing and setup
    int H_MIN, H_MAX, S_MIN, S_MAX, V_MIN, V_MAX;
    item dynamicTestItem;
    //used for new item creation
    item createNewItem(std::string name, int hmin, int hmax, int smin, int smax, int vmin, int vmax);
 private:
    int threshold;
};

#endif // COLORPROCESSOR_H
