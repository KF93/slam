#include"opencv2/highgui/highgui.hpp"
#include"opencv2/imgproc/imgproc.hpp"
#include<iostream>
using namespace cv;
//----------------------
#define WINDOW_NAME1 "原始图"
#define WINDOW_NAME2 "效果图"
//---------------------
Mat srcimage;
Mat templateimage;
Mat resultimage;
int MatchMethod;
int MaxTrackbarNum=5;
//----------------------
void onMatching(int,void*);
//-------------------------
int main()
{
  srcimage=imread("../image/5.jpg",1);
  templateimage=srcimage(Rect(0,0,30,30)).clone();
  namedWindow(WINDOW_NAME1,CV_WINDOW_AUTOSIZE);
  createTrackbar("方法",WINDOW_NAME1,&MatchMethod,MaxTrackbarNum,onMatching);
  onMatching(0,0);
  waitKey(0);
  return 0;
}
//--------------------------
void onMatching(int, void*)
{
  Mat srcimage1;
  srcimage.copyTo(srcimage1);
  int resultimage_cols=srcimage.cols-templateimage.cols+1;
  int resultimage_rows=srcimage.rows-templateimage.rows+1;
  resultimage.create(resultimage_cols,resultimage_rows,CV_32FC1);
  matchTemplate(srcimage,templateimage,resultimage,MatchMethod);
  normalize(resultimage,resultimage,0,1,NORM_MINMAX,-1,Mat());
  double minValue;
  double maxValue;
  Point minLocation;
  Point maxLocation;
  Point matchLocation;
  minMaxLoc(resultimage,&minValue,&maxValue,&minLocation,&maxLocation,Mat());
  if(MatchMethod==TM_SQDIFF||MatchMethod==TM_SQDIFF_NORMED)
  {
    matchLocation=minLocation;
  }
  else
  {
    matchLocation=maxLocation;
  }
  std::cout<<matchLocation.x<<std::endl;
  rectangle(srcimage1,matchLocation,Point(matchLocation.x+templateimage.cols,matchLocation.y+templateimage.rows),Scalar(0,0,255),2,8,0);
  rectangle(resultimage,matchLocation,Point(matchLocation.x+templateimage.cols,matchLocation.y+templateimage.rows),Scalar(0,0,255),2,8,0);
  imshow(WINDOW_NAME1,srcimage1);
  imshow(WINDOW_NAME2,resultimage);
}