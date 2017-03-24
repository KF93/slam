#include"opencv2/highgui/highgui.hpp"
#include"opencv2/imgproc/imgproc.hpp"
using namespace cv;
int main()
{
	Mat srcImage=imread("./1.jpg");
	imshow("均值滤波【原图】",srcImage);
	Mat dstImage;
	blur(srcImage,dstImage,Size(7,7));
	imshow("均值滤波【效果图】",dstImage);
	waitKey(0);
	return 0;
}
