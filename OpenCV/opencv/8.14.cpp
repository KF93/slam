#include"opencv2/highgui/highgui.hpp"
#include"opencv2/imgproc/imgproc.hpp"
#include<iostream>
#include <boost/concept_check.hpp>
using namespace cv;
using namespace std;
//---------------------
#define WINDOW_NAME1 "原始图"
#define WINDOW_NAME2 "轮廓图"
//-------------
Mat srcimage;
Mat grayimage;
int Thresh=80;
int Thresh_max=255;
RNG rng(12345);
Mat cannyMat_output;
vector<vector<Point> > Contours;
vector<Vec4i> Hierarchy;
//--------------------------------
void onThreshChange(int,void*);
//-----------------
int main (int argc,char** argv)
{
  srcimage=imread("../image/5.jpg",1);
  if(!srcimage.data)
  {
    printf("加载图片失败\n");
    return false;
  }
  cvtColor(srcimage,grayimage,COLOR_BGR2GRAY);
  blur(grayimage,grayimage,Size(3,3));
  namedWindow(WINDOW_NAME2,CV_WINDOW_AUTOSIZE);
  imshow(WINDOW_NAME1,srcimage);
  createTrackbar("cannyValue",WINDOW_NAME2,&Thresh,Thresh_max,onThreshChange);
  onThreshChange(0,0);
  waitKey(0);
  return 0;
}
//-----------------------
void onThreshChange(int, void*)
{
  Canny(grayimage,cannyMat_output,Thresh,Thresh*2,3);
  findContours(cannyMat_output,Contours,Hierarchy,RETR_TREE,CHAIN_APPROX_SIMPLE,Point(0,0));
  Mat drawing=Mat::zeros(cannyMat_output.size(),CV_8UC3);
  for(int i=0;i<Contours.size();i++)
  {
    Scalar color=Scalar(rng.uniform(0,255),rng.uniform(0,255),rng.uniform(0,255));
    drawContours(drawing,Contours,i,color,2,8,Hierarchy,0,Point());
  }
  imshow(WINDOW_NAME2,drawing);
}
