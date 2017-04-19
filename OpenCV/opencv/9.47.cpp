#include"opencv2/imgproc/imgproc.hpp"
#include"opencv2/highgui/highgui.hpp"
using namespace cv;
//-------------------
#define WINDOW_NAME1 "原始图"
//------------------
Mat srcimage;
Mat hsvimage;
Mat hueimage;
int bins=30;
//-----------------------------
void onBinChange(int,void*);
//-----------------------
int main()
{
  srcimage=imread("../image/5.jpg",1);
  if(!srcimage.data)
  {
    printf("读取图片错误");
    return false;
  }
  cvtColor(srcimage,hsvimage,COLOR_BGR2HSV);
  hueimage.create(hsvimage.size(),hsvimage.depth());
  int ch[]={0,0};
  mixChannels(&hsvimage,1,&hueimage,1,ch,1);
  namedWindow(WINDOW_NAME1, CV_WINDOW_AUTOSIZE);
  createTrackbar("色调组距",WINDOW_NAME1,&bins,180,onBinChange);
  onBinChange(0,0);
  imshow(WINDOW_NAME1,srcimage);
  waitKey(0);
  return 0;
}
//-------------------
void onBinChange(int, void*)
{
  MatND hist;
  int histSize=MAX(bins,2);
  float hue_range[]={0,180};
  const float* ranges={hue_range};
  calcHist(&hueimage,1,0,Mat(),hist,1,&histSize,&ranges,true,false);
  normalize(hist,hist,0,255,NORM_MINMAX,-1,Mat());
  MatND backproj;
  calcBackProject(&hueimage,1,0,hist,backproj,&ranges,1,true);
  imshow("反向投影",backproj);
  int w=400;
  int h=400;
  int bin_w=cvRound((double)w/histSize);
  Mat histimg=Mat::zeros(w,h,CV_8UC3);
  for(int i=0;i<bins;i++)
  {
    rectangle(histimg,Point(i*bin_w,h),Point((i+1)*bin_w,h-cvRound(hist.at<float>(i)*h/255.0)),Scalar(100,123,255),-1);
  }
  imshow("直方图",histimg);
}
