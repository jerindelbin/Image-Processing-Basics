#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;

int main()
{
    cv::Mat img = imread("C:/Users/Jerin/Desktop/Pictures/Scenery1.jpg");
    cv::namedWindow("Test iamge", WINDOW_AUTOSIZE);
    cv::imshow("Test image", img);
    cv::waitKey(10);
    cv::destroyWindow("Test image");
    return 0;
}