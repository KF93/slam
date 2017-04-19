#include<opencv2/opencv.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<iostream>
using namespace std;
using namespace cv;
//-----------------
Mat srcimage,dstimage,midimage;
vector<Vec4i> lines;
int Threshold=100;
//-----------------
static void onHoughLines(int,void*);
//------------
main ()
{
  Mat srcimage=imread("../image/6.jpg");
  imshow("image",srcimage);
  namedWindow("dstimage",1);
  createTrackbar("value","dstimage",&Threshold,200,onHoughLines);
  Canny(srcimage,midimage,50,200,3);
  cvtColor(midimage,dstimage,COLOR_GRAY2BGR);
  onHoughLines(Threshold,0);
  //HoughLinesP(midimage,lines,1,CV_PI/180,80,50,10);
  //imshow("dstimage",dstimage);
  waitKey(0);
  return 0;
}
//--------------------------
void onHoughLines(int, void*)
{
  Mat dstimage1=dstimage.clone();
  Mat midimage1=midimage.clone();
  vector<Vec4i> mylines;
  HoughLinesP(midimage1,mylines,1,CV_PI/180,Threshold+1,50,10);
  for(size_t i=0;i<mylines.size();i++)
  {
    Vec4i l=mylines[i];
    line(dstimage1,Point(l[0],l[1]),Point(l[2],l[3]),Scalar(23,180,55),1,LINE_AA);
  }
  imshow("dstimage",dstimage1);
}
