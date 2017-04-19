#include"opencv2/highgui/highgui.hpp"
#include"opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <boost/concept_check.hpp>
using namespace cv;
using namespace std;
//-----------------
#define WINDOW_NAME1 "原始图"
#define WINDOW_NAME2 "图像轮廓"
//----------------------
Mat srcimage;
Mat grayimage;
int Thresh=100;
int MaxThresh=255;
RNG rng(12345);
Mat cannyMat_output;
vector<vector<Point> > Contours;
vector<Vec4i> Hierarchy;
//---------------------------
void onThreshChange(int,void*);
//-------------------------
int main(int argc, char** argv)
{
  srcimage=imread("../image/2.jpg",1);
  cvtColor(srcimage,grayimage,COLOR_BGR2GRAY);
  blur(grayimage,grayimage,Size(3,3));
  namedWindow(WINDOW_NAME2,CV_WINDOW_AUTOSIZE);
  imshow(WINDOW_NAME1,srcimage);
  createTrackbar("阈值",WINDOW_NAME2,&Thresh,MaxThresh,onThreshChange);
  onThreshChange(0,0);
  waitKey(0);
  return(0);
}
//-----------------------------------
void onThreshChange(int,void*)
{
  Canny(grayimage,cannyMat_output,Thresh,Thresh*2,3);
  findContours(cannyMat_output,Contours,Hierarchy,RETR_TREE,CHAIN_APPROX_SIMPLE,Point(0,0));
  vector<Moments> mu(Contours.size());
  for(unsigned int i=0;i<Contours.size();i++)
  {
    mu[i]=moments(Contours[i],false);
  }
  vector<Point2f> mc(Contours.size());
  for(unsigned int i=0;i<Contours.size();i++)
  {
    mc[i]=Point2f(static_cast<float>(mu[i].m10/mu[i].m00),static_cast<float>(mu[i].m01/mu[i].m00));
  }
  Mat drawing=Mat::zeros(cannyMat_output.size(),CV_8UC3);
  for(unsigned int i=0;i<Contours.size();i++)
  {
    Scalar color=Scalar(rng.uniform(0,255),rng.uniform(0,255),rng.uniform(0,255));
    drawContours(drawing,Contours,i,color,2,8,Hierarchy,0,Point(0,0));
    circle(drawing,mc[i],4,color,-1,8,0);
  }
  imshow(WINDOW_NAME2,drawing);
  printf("/t输出内容：面积和轮廓长度\n");
  for(unsigned int i=0;i<Contours.size();i++)
  {
    printf("通过m00计算出轮廓[%d]的面积：(M_00)=%.2f\n OpenCV函数计算出的面积=%.2f,长度：%.2f\n\n",i,mu[i].m00,contourArea(Contours[i]),arcLength(Contours[i],true));
    Scalar color=Scalar(rng.uniform(0,255),rng.uniform(0,255),rng.uniform(0,255));
    //drawContours(drawing,Contours,i,color,2,8,Hierarchy,0,Point());
    //circle(drawing,mc[i],4,color,-1,8,0);
  }
}