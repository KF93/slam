#include<opencv2/opencv.hpp>
using namespace cv;
int main()
{
	Mat srcImage=imread("./1.jpg");
	imshow("【原始图】",srcImage);
	waitKey(0);
	return 0;
}

