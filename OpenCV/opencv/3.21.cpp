#include<opencv2/opencv.hpp>
#include "opencv2/highgui/highgui.hpp"
using namespace cv;
#define WINDOW_NAME "【线性混合实例】"

const int g_nMaxValue=100;
int g_nAlphaValueSlider;
double g_dAlphaValue;
double g_dBetaValue;

Mat g_srcImage1;
Mat g_srcImage2;
Mat g_dstImage;
//响应滑动条的回调函数
void on_Trackbar(int,void*)
{
  //求出当前Alpha值相对于最大值的比例
  g_dAlphaValue=(double) g_nAlphaValueSlider/g_nMaxValue;
  //bate值为1减去Alpha的值
  g_dBetaValue=(1.0-g_dAlphaValue);
  //根据Alpha和beta值进行线性混合
  addWeighted(g_srcImage1,g_dAlphaValue,g_srcImage2,g_dBetaValue,0.0,g_dstImage);
  imshow(WINDOW_NAME,g_dstImage);
}
//----------------------------------------
//----------------------------------------
int main(int argc,char** argv)
{
  g_srcImage1=imread("../image/1.jpg");
  g_srcImage2=imread("../image/2.jpg");
  if(!g_srcImage1.data||!g_srcImage2.data)
  {
    printf("读取图片错误");
    return-1;
  }
  g_srcImage1=g_srcImage1(Rect(300,300,g_srcImage2.cols,g_srcImage2.rows));  //设置滑动条初值70
  g_nAlphaValueSlider=70;
  namedWindow(WINDOW_NAME, 1);
  //创建滑动条控件
  char Trackbarname[50];
  sprintf(Trackbarname,"透明值");
  createTrackbar(Trackbarname,WINDOW_NAME,&g_nAlphaValueSlider,g_nMaxValue,on_Trackbar);
  on_Trackbar(g_nAlphaValueSlider,0);
  waitKey(0);
  return 0;
}
