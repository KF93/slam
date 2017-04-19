#include"opencv2/highgui/highgui.hpp"
#include"opencv2/imgproc/imgproc.hpp"
#include<iostream>
#include <boost/concept_check.hpp>
using namespace cv;
using namespace std;
//--------------
#define WINDOW_NAME "SHINee—Tomasi角点检测"
Mat srcimage,grayimage;
int maxCornerNumber=33;
int maxTrackbarNumber=500;
RNG rng(12345);
//-----------
void onGoodFeaturesToTrack(int,void*)
{
  if(maxCornerNumber<=1)
  {
    maxCornerNumber=1;
  }
  vector<Point2f>corners;
  double qualityLevel=0.01;
  double minDistance=10;
  int bloockSize=3;
  double k=0.04;
  Mat copy=srcimage.clone();
  goodFeaturesToTrack(grayimage,corners,maxCornerNumber,qualityLevel,minDistance,Mat(),bloockSize,false,k);
  cout<<" >此次检测到的角点数量为："<<corners.size()<<endl;
  int r=4;
  for(unsigned int i=0;i<corners.size();i++)
  {
    circle(copy,corners[i],r,Scalar(rng.uniform(0,255),rng.uniform(0,255),rng.uniform(0,255)),-1,8,0);
  }
  imshow(WINDOW_NAME,copy);
  //--------------------------
  Size winSize=Size(5,5);
  Size zeroZone=Size(-1,-1);
  TermCriteria criteria=TermCriteria(TermCriteria::EPS+TermCriteria::MAX_ITER,40,0.001);
  cornerSubPix(grayimage,corners,winSize,zeroZone,criteria);
  for(int i=0;i<corners.size();i++)
  {
    cout<<"\t>精确点坐标["<<i<<"]("<<corners[i].x<<","<<corners[i].y<<")"<<endl;
  }
}
//------------------------
int main()
{
  srcimage=imread("../image/1.jpg",1);
  cvtColor(srcimage,grayimage,COLOR_BGR2GRAY);
  namedWindow(WINDOW_NAME,CV_WINDOW_AUTOSIZE);
  createTrackbar("最大角点数",WINDOW_NAME,&maxCornerNumber,maxTrackbarNumber,onGoodFeaturesToTrack);
  imshow(WINDOW_NAME,srcimage);
  onGoodFeaturesToTrack(0,0);
  waitKey(0);
  return 0;
}