#include"opencv2/highgui/highgui.hpp"
#include"opencv2/imgproc/imgproc.hpp"
#include <boost/concept_check.hpp>
using namespace cv;
using namespace std;
//___________________
#define WINDOW_NAME1 "原始图"
#define WINDOW_NAME2 "效果图"
//-------------------------
Mat srcimage;
Mat grayimage;
int Thresh=50;
int MaxThresh=255;
RNG rng(12345);
//-------------------------
void onContoursChange(int,void*);
//---------------
int main()
{
  srcimage=imread("../image/1.jpg",1);
  if(!srcimage.data)
  {
    printf("载入图片错误\n");
    return false;
  }
  cvtColor(srcimage,grayimage,COLOR_BGR2GRAY);
  blur(grayimage,grayimage,Size(3,3));
  namedWindow(WINDOW_NAME2,CV_WINDOW_AUTOSIZE);
  imshow(WINDOW_NAME1,srcimage);
  createTrackbar("Value",WINDOW_NAME2,&Thresh,MaxThresh,onContoursChange);
  onContoursChange(0,0);
  waitKey(0);
  return 0;
}
//---------------------------------
void onContoursChange(int, void*)
{
  Mat threshold_output;
  vector<vector<Point> > contours;
  vector<Vec4i> hierarchy;
  threshold(grayimage,threshold_output,Thresh,255,THRESH_BINARY);
  findContours(threshold_output,contours,hierarchy,RETR_TREE,CHAIN_APPROX_SIMPLE,Point(0,0));
  vector<vector<Point> >contours_poly(contours.size());
  vector<Rect> boundRect(contours.size());
  vector<Point2f>center(contours.size());
  vector<float>radius(contours.size());
  for(unsigned int i=0;i<contours.size();i++)
  {
    approxPolyDP(Mat(contours[i]),contours_poly[i],3,true);
    boundRect[i]=boundingRect(Mat(contours_poly[i]));
    minEnclosingCircle(contours_poly[i],center[i],radius[1]);
  }
  Mat drawing=Mat::zeros(threshold_output.size(),CV_8UC3);
  for(int unsigned i=0;i<contours.size();i++)
  {
    Scalar color=Scalar(rng.uniform(0,255),rng.uniform(0,255),rng.uniform(0,255));
    drawContours(drawing,contours_poly,i,color,1,8,vector<Vec4i>(),0,Point());
    rectangle(drawing,boundRect[i].tl(),boundRect[i].br(),color,2,8,0);
    circle(drawing,center[i],(int)radius[1],color,2,8,0);
  }
  imshow(WINDOW_NAME2,drawing); 
}