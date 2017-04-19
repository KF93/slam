#include"opencv2/core.hpp"
#include"opencv2/highgui/highgui.hpp"
#include"opencv2/imgproc/imgproc.hpp"
using namespace cv;
//------------------
int main()
{
  Mat image=imread("../image/2.jpg");
  namedWindow("方框滤波原图");
  namedWindow("方框滤波");
  imshow("方框滤波原图",image);
  Mat out1,out2,out3;
  boxFilter(image,out1,-1,Size(5,5));
  imshow("方框滤波",out1);
  blur(image,out2,Size(7,7));
  imshow("均值滤波",out2);
  GaussianBlur(image,out3,Size(3,3),0,0);
  imshow("高斯滤波",out3);
  waitKey(0);
}