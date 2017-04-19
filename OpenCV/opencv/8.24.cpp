#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <boost/concept_check.hpp>
using namespace cv;
using namespace std;
//------------------
#define WINDOW_NAME1 "原始图"
#define WINDOW_NAME2 "效果图"
Mat srcimage;
Mat grayimage;
int Thresh=50;
int maxThresh=255;
RNG rng(12345);
Mat srcimage_copy=srcimage.clone();
Mat thresholdImage_output;
vector<vector<Point> > Contours;
vector<Vec4i> Hierarchy;
//------------------------
void onThreshChange(int,void*);
//----------------
int main()
{
  srcimage=imread("../image/2.jpg",1);
  cvtColor(srcimage,grayimage,COLOR_BGR2GRAY);
  blur(grayimage,grayimage,Size(3,3));
  namedWindow(WINDOW_NAME2,CV_WINDOW_AUTOSIZE);
  imshow(WINDOW_NAME1,grayimage);
  createTrackbar("阈值",WINDOW_NAME2,&Thresh,maxThresh,onThreshChange);
  onThreshChange(0,0);
  waitKey(0);
  return(0);
}
//----------------------------------
void onThreshChange(int,void*)
{
  threshold(grayimage,thresholdImage_output,Thresh,255,THRESH_BINARY);
  findContours(thresholdImage_output,Contours,Hierarchy,RETR_TREE,CHAIN_APPROX_SIMPLE,Point(0,0));
  vector<vector<Point> >hull(Contours.size());
  for(unsigned int i=0;i<Contours.size();i++)
  {
    convexHull(Mat (Contours[i]),hull[i],false);
  }
  Mat drawing=Mat::zeros(thresholdImage_output.size(),CV_8UC3);
  for(unsigned int i=0;i<Contours.size();i++)
  {
    Scalar color=Scalar(rng.uniform(0,255),rng.uniform(0,255),rng.uniform(2,255));
    drawContours(drawing,hull,i,color,1,8,vector<Vec4i>(),0,Point());
  }
  imshow(WINDOW_NAME2,drawing);
}