#include<opencv2/opencv.hpp>
#include"opencv2/highgui/highgui.hpp"
#include"opencv2/imgproc/imgproc.hpp"
#include <boost/iterator/iterator_concepts.hpp>
using namespace cv;
//------------------------
#define WINDOW_NAME1 "原始图"
#define WINDOW_NAME2 "效果图"
//--------------------------------------
Mat srcimage,srcimage1,grayimage;
int thresh=30;
int max_thresh=175;
void onCornerHarris(int,void*);
//--------------------------
int main(int argc,char** argv)
{
  srcimage=imread("../image/1.jpg",1);
  if(!srcimage.data)
  {
    printf("读取图片失败");
    return false;
  }
  imshow("image",srcimage);
  srcimage1=srcimage.clone();
  cvtColor(srcimage1,grayimage,COLOR_BGR2GRAY);
  namedWindow(WINDOW_NAME1,CV_WINDOW_AUTOSIZE);
  createTrackbar("阈值",WINDOW_NAME1,&thresh,max_thresh,onCornerHarris);
  onCornerHarris(0,0);
  waitKey(0);
  return 0;
}
//------------------------------
void onCornerHarris(int, void*)
{
   Mat dstimage;
   Mat normimage;
   Mat scaledimage;
   dstimage=Mat::zeros(srcimage.size(),CV_32FC1);
   srcimage1=srcimage.clone();
   cornerHarris(grayimage,dstimage,2,3,0.04,BORDER_DEFAULT);
   normalize(dstimage,normimage,0,255,NORM_MINMAX,CV_32FC1,Mat());
   convertScaleAbs(normimage,scaledimage);
   for(int j=0;j<normimage.rows;j++)
     for(int i=0;i<normimage.cols;i++)
     {
       if((int)normimage.at<float>(j,i)>thresh+80)
       {
	 circle(srcimage1,Point(i,j),5,Scalar(10,10,255),2,8,0);
	 circle(scaledimage,Point(i,j),5,Scalar(0,10,255),2,8,0);
      }
    }
    imshow(WINDOW_NAME1,srcimage1);
   imshow(WINDOW_NAME2,scaledimage);
  }
