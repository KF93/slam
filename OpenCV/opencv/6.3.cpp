#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<iostream>
using namespace std;
using namespace cv;
//------------------
int main()
{
  //_---------------------
  Mat image=imread("../image/2.jpg");
  imshow("原图",image);
  Mat element=getStructuringElement(MORPH_RECT,Size(15,15));
  Mat out,out2;
  dilate(image,out,element);
  imshow("膨胀效果图",out);
  erode(image,out2,element);
  imshow("腐蚀效果图",out2);
  waitKey(0);
  return 0;
}