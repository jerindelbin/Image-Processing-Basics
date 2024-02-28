#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;

//=================================================================================================================================
//=================================================================================================================================
//Gaussian Filter block
//Gaussian blur filter 
    // 1 2 1
    // 2 4 2 
    // 1 2 1


int gaussfilter(cv::Mat& img, cv::Mat& dst)
{
    
    for (int i = 1; i < img.rows - 1; i++)
    {
        for (int j = 1; j < img.cols - 1; j++)
        {
            for (int k = 0; k < img.channels(); k++)
            {
                int sum = img.at<cv::Vec3b>(i - 1, j - 1)[k]
                    + 2 * img.at<cv::Vec3b>(i - 1, j)[k]
                    + img.at<cv::Vec3b>(i - 1, j + 1)[k]
                    + 2 * img.at<cv::Vec3b>(i, j - 1)[k]
                    + 4 * img.at<cv::Vec3b>(i, j)[k]
                    + 2 * img.at<cv::Vec3b>(i, j + 1)[k]
                    + img.at<cv::Vec3b>(i + 1, j - 1)[k]
                    + 2 * img.at<cv::Vec3b>(i + 1, j)[k]
                    + img.at<cv::Vec3b>(i + 1, j + 1)[k];

                sum /= 16;

                dst.at<cv::Vec3b>(i, j)[k] = sum;

            }
        }

    }
    return 0;
}
//=================================================================================================================================
//=================================================================================================================================



int main()
{
    /*Mat img = imread("C:/Users/Jerin/Desktop/Pictures/Scenery1.jpg");
    cv::namedWindow("First OpenCV Application", WINDOW_AUTOSIZE);
    cv::imshow("First OpenCV Application", img);
    cv::moveWindow("First OpenCV Application", 0, 45);
    cv::waitKey(0);
    cv::destroyAllWindows();
    return 0;*/
    
  

   
    //reading the image
    cv::Mat img = imread("C:/Users/Jerin/Desktop/Pictures/Eagle.jpg"); 
    cv::namedWindow("Test iamge", WINDOW_AUTOSIZE);
    cv::imshow("Test image", img);
    //cv::waitKey(10);
    //cv::destroyWindow("Test image");


    //creating a destination image to apply filter
    cv::Mat dst;
    dst.create(img.size(), img.type());
    img.copyTo(dst);

    //calling the filter 
    gaussfilter(img, dst);

    //creating window and displaying destinantion image 
    cv::namedWindow("dst image", WINDOW_AUTOSIZE);
    cv::imshow("dst image", dst);
    cv::waitKey(0);

    
              
    /*
    // checking whether image was read
    if (img.data == NULL) 
    {
    cout << "unable to read image";
    }

    //getting the height and width of the image
    cout << "Image height and width =" << img.size().width<<"\n" << img.size().height<<endl; 
    float w = img.size().width;
    float h = img.size().height;
    cout << "Width ="<<w << "\n" <<"Height =" << h<<endl;
    //also to find rows and columns
    //endl at the end for escape sequence 
    int r = img.rows;
    int c = img.cols; 
    cout <<"Rows:"<<r<<"\nColumns:"<<c<<endl;
    */


    //getting color channels 
    cout << "Channel count" << img.channels()<<endl;
    cout << "Element size" << img.elemSize()<<endl;
    cout << "Bytes per channel=" << img.elemSize() / img.channels()<<endl;
    

    /*displaying the image
    cv::namedWindow("Scenery Image", WINDOW_FULLSCREEN); //creating window for image with name Scenery Image
    cv::imshow("Scenery Image", img); //displaying the image in the created window
    cv::waitKey(0); //waiting for instruction (0 is waiting for key press)
    cv::destroyWindow("Scenery Image"); /closing the window if needed
    
    //gaussfilter(img,dst);

    // swapping red and green channels
    /*for (int i = 0; i < img.rows; i++)
    {
        for (int j = 0; j < img.cols; j++)
        {
            uchar temp = img.at<cv::Vec3b>(i, j)[1];
            img.at<cv::Vec3b>(i, j)[1] = img.at<cv::Vec3b>(i, j)[2];
            img.at<cv::Vec3b>(i, j)[2] = temp;

        }
    }
    cv::namedWindow("Swapped colors", 1);
    cv::imshow("Swapped colors", img);
    cv:waitKey(0); 
    *

    //swapping channels using pointer method
    //this method is faster as it uses pointer to access the rows
    /*for (int i = 0; i < img.rows; i++)
    {
        cv::Vec3b* ptr = img.ptr<cv::Vec3b>(i);
        for (int j = 0; i < img.cols; j++) {
            uchar temp = ptr[j][1];
            ptr[j][1] = ptr[j][2];
            ptr[j][2] = temp;
        }
    }
    cv::namedWindow("Swapped colors", 1);
    cv::imshow("Swapped colors", img);
    cv:waitKey(0);
    */

    //-------------------------------------------------------------------------------------

   
   
    
}



