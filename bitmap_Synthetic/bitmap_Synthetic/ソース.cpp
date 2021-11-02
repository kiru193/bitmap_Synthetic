#include <opencv2/opencv.hpp>

using namespace cv;

int main()
{
    
    Mat image = imread("sample.bmp");
    Mat correction_image = imread("correction.bmp");
    int col = image.cols;
    int row = image.rows;
    Mat create_image = Mat::zeros(row, col, CV_8U);
    printf("image col %d row %d\n", col, row);
    printf("create image col %d row %d", create_image.cols, create_image.rows);

    if (image.empty()||correction_image.empty() == true) {
        printf("nothing");
        return 0;
    }

    for (int i = 0; i < row; i++) {
        for (int m = 0; m < col; m++) {
            //create_image.at<unsigned char>(i, m) = correction_image.at<unsigned char>(i, m);
            //printf("%d %d\n", m, i);
            
            if (correction_image.at<unsigned char>(i, m) + image.at<unsigned char>(i, m) <= 255) {
                create_image.at<unsigned char>(i, m) = correction_image.at<unsigned char>(i, m) + image.at<unsigned char>(i, m);
            }
            else {
                create_image.at<unsigned char>(i, m) = correction_image.at<unsigned char>(i, m) + image.at<unsigned char>(i, m)-255;
            }
            
        }
    }
    
    imshow("sample.bmp", create_image);
    waitKey(0);
}