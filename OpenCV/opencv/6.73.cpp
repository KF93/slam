#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<iostream>
#include <boost/concept_check.hpp>
using namespace cv;
using namespace std;
//---------------------
#define WINDOW_NAME "程序窗口"
//------------------
int ThresholdValue=100;
int TypeThreshold=3;
Mat srcimage, dstimage, grayimage,dstimage2;
//-----------------------
static void ShowHelpText();
void onThreshold(int,void*);
//----------------
int main()
{
  srcimage=imread("../image/6.jpg");
  if(!srcimage.data)
  {
    printf("读取图片错误\n");
    return 0;
  }
  cvtColor(srcimage,grayimage,COLOR_RGB2GRAY);
  namedWindow(WINDOW_NAME,WINDOW_AUTOSIZE);
  createTrackbar("模式",WINDOW_NAME,&TypeThreshold,4,onThreshold);
  createTrackbar("参数值",WINDOW_NAME,&ThresholdValue,255,onThreshold);
  onThreshold(0,0);
  while(1)
  {
    int key;
    key=waitKey(20);
    if((char)key==27)
    {
      break;
    }
  } 
}
//--------------------------------
void onThreshold(int, void*)
{
  threshold(grayimage,dstimage,ThresholdValue,255,TypeThreshold);
  imshow(WINDOW_NAME,dstimage);
  adaptiveThreshold(grayimage,dstimage2,ThresholdValue,CV_ADAPTIVE_THRESH_GAUSSIAN_C,CV_THRESH_BINARY,5,0);
  imshow("adaptiveThreshold",dstimage2);
} 