#include"opencv2/opencv.hpp"
#include"opencv2/highgui/highgui.hpp"
#include"opencv2/imgproc/imgproc.hpp"
#include"boost/format.hpp"
#include"time.h"
#include <chrono>
#include <boost/concept_check.hpp>
using namespace cv;
using namespace std;
//-----------------------------------  
VideoWriter writer;
boost::format fmt("../video/%s.avi");
int n=1;
 chrono::steady_clock::time_point t1=chrono::steady_clock::now();
float FindContours(Mat& image,Mat& dstimage);
void Motion(Mat& image,Mat& image1,float area);
//----------------------------
int main(int argc,char**argv)
{
  VideoCapture capture(0);
  if(!capture.isOpened())
  {
    printf("打开摄像头失败");
    return -1;
  }

  namedWindow("mask",CV_WINDOW_AUTOSIZE);
  namedWindow("frame",CV_WINDOW_AUTOSIZE);
  Mat frame,mask,mask1;
  float sumArea;
  int delay=1000/capture.get(CV_CAP_PROP_FPS);
  Ptr<BackgroundSubtractorMOG2> bgSubtractor=createBackgroundSubtractorMOG2();
  bgSubtractor->setVarThreshold(50);
  while(1)
  {
    capture>>frame;
    bgSubtractor->apply(frame,mask,0.001);
    //GaussianBlur(mask,mask,Size(3,3),0,0);
    medianBlur(mask,mask,3);
    sumArea=FindContours(mask,frame);
    //cout<<frame.cols<<"\t"<<frame.rows;
   
    imshow("frame",frame);
    imshow("mask",mask);
    //writer<<frame;
    Motion(mask,frame,sumArea);
    if(waitKey(delay)>=0)
      break;
  }
  return 0;
}
//--------------------
float FindContours(Mat& image,Mat& dstimage)
 {   Mat imageCopy=image.clone();
     Mat drawing=Mat::zeros(dstimage.size(),CV_8UC3);
     vector<vector<Point> >contours;
     vector<Vec4i>hierarchy;
   Canny(image,imageCopy,3,9,3);
    findContours(imageCopy,contours,hierarchy,CV_RETR_CCOMP,CV_CHAIN_APPROX_SIMPLE,Point(0,0));
    vector<Moments> mu(contours.size()); 
    vector<vector<Point> >contours_poly(contours.size()); 
    vector<Rect> boundRect(contours.size());
    float area=0;
    for(unsigned int i=0;i<contours.size();i++)
    { 
      area=area+contourArea(contours[i]);
      //printf("\t轮廓[%d]面积:%.2f",i,contourArea(contours[i]));
      approxPolyDP(Mat(contours[i]),contours_poly[i],2,true);
      boundRect[i]=boundingRect(Mat(contours_poly[i]));
      rectangle(drawing,boundRect[i].tl(),boundRect[i].br(),Scalar(0,0,255),2,8,0);
     }
     //cout<<"\n轮廓总面积"<<area<<"\t";
     imshow("drawing",drawing);
     return area;
 }
void Motion(Mat& image,Mat& image1,float area)
{ 
    if(area>=800)
    { 
      if(n==1)
      {  time_t rawtime;
        //获得日历时间
	//time(&rawtime);
	cout<<time(&rawtime)<<endl;
	//转换日历时间，获得世界时间和当地时间
	//struct tm *timeinfo;
	//timeinfo=localtime(&rawtime);
	//cout<<"localtime当地时间;"<<timeinfo->tm_hour<<endl;
	//cout<<"asctime显示时间"<<asctime(timeinfo)<<endl;
	//cout<<"ctime自动把世界转化为本地时间"<<ctime(&rawtime)<<endl; 
         
	 n=0;
	 cout<<"创建新视频\t"<<(fmt%(ctime(&rawtime))).str()<<endl;
	 writer.open((fmt%(ctime(&rawtime))).str(),CV_FOURCC('M','J','P','G'),25.0,Size(640,480));	 
	 writer<<image1;
	 
	
      }
	 writer<<image1;
    }
    else
    {    //t1=chrono::duration_cast<chrono::duration<double>>(chrono::steady_clock::now()-t1);
	 //if(t1>=600)
	 {
           n=1;
	   //cout<<ctime(&rawtime)<<endl;
	 }
    }
}

  