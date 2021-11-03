#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main()
{
    Mat image = imread("sample.bmp");
    Mat correction_image = imread("correction.bmp");
    int col = image.cols;
    int row = image.rows;
    Mat create_image = Mat::zeros(row, col, CV_8UC3);
    string name;

    printf("image col %d row %d\n", col, row);
    printf("create image col %d row %d\n", create_image.cols, create_image.rows);

    if (image.empty()||correction_image.empty() == true) {
        printf("nothing\n");
        return 0;
    }

    //printf("%d %d %d\n", correction_image.data[row*col+1]);
    for (int i = 0; i < 3*row; i++) {
        for (int m = 0; m < col; m++) {
            //create_image.data[i * col + m] = correction_image.data[i * col + m];
            //printf("%d %d %d\n", m, i, create_image.data[i * row + m]);
            
            if (correction_image.data[i * row + m] + image.data[i * row + m] <= 255) {
                create_image.data[i * col + m] = correction_image.data[i * col + m] + image.data[i * col + m];
            }
            else {
                create_image.data[i * col + m] = correction_image.data[i * col + m] + image.data[i * col + m] - 255;
            } 
            
        }
    }
    
    imshow("sample.bmp", create_image);
    waitKey(0);
    destroyAllWindows();

    cout << "please input this picture name\n";
    cin >> name;
    imwrite(name + ".bmp", create_image);
}